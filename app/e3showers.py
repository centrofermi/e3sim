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
    parser = argparse.ArgumentParser(
        description='Generate Corsika Showers at specific Energy',
        epilog='Questions at fabrizio.coccetti@centrofermi.it')
    parser.add_argument("-e", "--energy", type=float, required=True,
                        help="Value of the energy of the Primary \
                        in Gev. (i.e. 1.E4)")
    parser.add_argument("-n", "--number", type=int, required=True,
                        help="Number of showers to generate \
                        (i.e. 10000)")
    parser.add_argument("-s", "--start", type=int, required=True,
                        help="Start number of the run \
                        (i.e. 10001)")
    parser.add_argument("-a", "--altitude", type=int, default=0,
                        help="Altitude in meters [INT] (default is 0)")
    parser.add_argument('-v', '--version',
                        action='version',
                        version='%(prog)s ' + version)
    args = parser.parse_args()

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
    outputDir = parser.get(machine, 'outputDir')

    # Set logging options
    logging.config.fileConfig(logConfigFile)
    logger = logging.getLogger('full')
    logger.info('Started')

    # Call the functions
    generate_showers(
        corsikaBin,
        corsikaPath,
        corsikaMasterInput,
        outputDir,
        args.energy,
        args.number,
        args.start,
        args.altitude)

    # Final log message
    logger.info('Finished')
