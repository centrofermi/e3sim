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
Created on Thu Jun 25 14:21:00 2015

@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]
"""

import logging
import logging.config
import os
import argparse
import pkg_resources
from e3sim.config.specific_machine import machine
try:
    # For Python 3.0 and later
    import configparser
except ImportError:
    # Fall back to Python 2
    import ConfigParser

if __name__ == '__main__':

    # Set last version
    version = "version 0.2 (Rev. 2015-06-25)"

    # Using argparse
    aparser = argparse.ArgumentParser(
        description='Convert showers from fortran binary DAT to .root',
        epilog='Questions at fabrizio.coccetti@centrofermi.it')
    aparser.add_argument("-s", "--start", type=int, required=True,
                         help="Start number of the run \
                         (i.e. 100000)")
    aparser.add_argument("-e", "--end", type=int, required=True,
                         help="End number of the run \
                         (i.e. 109999)")
    aparser.add_argument("-i", "--inputdir", type=str, required=True,
                         help="Input Directory full path [STR]")
    aparser.add_argument("-o", "--outputdir", type=str, default=".",
                         help="Output Directory full path [STR]")
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

    # Set logging options
    logging.config.fileConfig(logConfigFile)
    logger = logging.getLogger('full')
    logger.info('Conversion started...')

    cmd = "cd " + args.outputdir + "; "
    os.system(cmd)
    for fileNumber in range(args.start, args.end + 1):
        cmd = '/home/eeesoft/corsika/coast-v4r5/installation/bin/corsika2root ' +\
            os.path.join(args.inputdir, 'DAT' + str(fileNumber))
        os.system(cmd)
        logger.info("Converted file DAT" + str(fileNumber))

    # Final log message
    logger.info('Finished')

