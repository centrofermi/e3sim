#!/usr/bin/env python
# -*- coding: utf-8 -*-
# *********************************************************************
# * Copyright (C) 2014 Fabrizio Coccetti                              *
# * fabrizio.coccetti@centrofermi.it  [www.fc8.net]                   *
# *                                                                   *
# * For the license terms see the file LICENSE, distributed           *
# * along with this software.                                         *
# *********************************************************************
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
"""
Created on Thu Apr 23 11:09:32 2015

@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]
"""

import logging
import logging.config
import os
import argparse
import pkg_resources
from multiprocessing import Process
from e3sim.tasks.generate_showers import generate_showers
from e3sim.config.specific_machine import machine
try:
    # For Python 3.0 and later
    import configparser
except ImportError:
    # Fall back to Python 2
    import ConfigParser

if __name__ == '__main__':

    # Set last version
    version = "version 0.5 (Rev. 2015-04-23)"

    # Using argparse
    aparser = argparse.ArgumentParser(
        description='Generate Corsika Showers at specific Energy',
        epilog='Questions at fabrizio.coccetti@centrofermi.it')
    aparser.add_argument("-e", "--energy", type=float, required=True,
                         help="Value of the energy of the Primary \
                         in Gev. (i.e. 1.E4)")
    aparser.add_argument("-n", "--number", type=int, required=True,
                         help="Number of showers to generate \
                         (i.e. 10000)")
    aparser.add_argument("-s", "--start", type=int, required=True,
                         help="Start number of the run \
                         (i.e. 10001)")
    aparser.add_argument("-m", "--multicore", type=int, default=1,
                         help="Number of CPU cores to use [INT] \
                         (default is 1)")
    aparser.add_argument("-a", "--altitude", type=int, default=0,
                         help="Altitude in meters [INT] (default is 0)")
    aparser.add_argument("-o", "--outputdir", type=str,
                         help="Output Directory full path[STR]")
    aparser.add_argument('-v', '--version',
                         action='version',
                         version='%(prog)s ' + version)
    try:
        args = aparser.parse_args()
    except:
        aparser.print_help()
        aparser.error('This app needs several options :-)')

    # Reading file_location.ini
    try:
        parser = configparser.ConfigParser()
    except:
        parser = ConfigParser.ConfigParser()
    parser.read(
        pkg_resources.resource_filename(
            'e3sim',
            os.path.join('config', 'files_location.ini')))
    logConfigFile = parser.get(machine, 'logConfigFile')
    corsikaBin = parser.get(machine, 'corsikaBin')
    corsikaPath = parser.get(machine, 'corsikaPath')
    corsikaMasterInput = parser.get(machine, 'corsikaShowersInput')
    startRunNumber = int(parser.get(machine, 'startRunNumber'))
    if args.outputdir:
        outputDir = args.outputdir
    else:
        outputDir = parser.get(machine, 'outputDir')

    # Set logging options
    logging.config.fileConfig(logConfigFile)
    logger = logging.getLogger('full')
    logger.info('Started. Number of cores: '+str(args.multicore))

    # Define Thread function
    def generate_showers_core(corsikaBin,
                              corsikaPath,
                              corsikaMasterInput,
                              outputDir,
                              energy,
                              numberOfShowers,
                              startRunNumber,
                              coreId,
                              altitude):
        '''Thread generate showers function'''
        # Call the function in tasks
        generate_showers(
            corsikaBin,
            corsikaPath,
            corsikaMasterInput,
            outputDir,
            energy,
            numberOfShowers,
            startRunNumber,
            coreId,
            altitude)
        return

    # Define threads
    showersPerThread = args.number // args.multicore
    moduleLastThread = args.number % args.multicore
    # Process list
    proc = []
    # Loop for number of cores: generate different threads
    for coreId in range(args.multicore):
        startRunNumber = args.start + coreId*showersPerThread
        # Add the module of the division in the last thread
        if coreId == args.multicore-1:
            showersPerThread = showersPerThread + moduleLastThread
        # Call the functions
        p = Process(target=generate_showers,
                    args=(corsikaBin,
                          corsikaPath,
                          corsikaMasterInput,
                          outputDir,
                          args.energy,
                          showersPerThread,
                          startRunNumber,
                          coreId,
                          args.altitude))
        # Add the module of division only in one stream
        proc.append(p)
        logger.info('About to start process: ' + str(p) +
                    '\nThread number: ' + str(coreId) +
                    '\nstartNumber: ' + str(startRunNumber) +
                    '\nshowers to generate: ' + str(showersPerThread))
        p.start()

    # Final log message
    logger.info('Finished')
