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
Created on Thu Apr 16 12:12:13 2015

@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]
"""

import logging
import logging.config
import os
import pkg_resources
from e3sim.tasks.change_energy import change_energy
from e3sim.config.specific_machine import machine
try:
    # For Python 3.0 and later
    import configparser
except ImportError:
    # Fall back to Python 2
    import ConfigParser

# Set Energy range in GeV
energyList = [
#    '1.E0',
#    '1.E1',
#    '1.E2',
#    '1.E3',
    '1.E4',
#    '1.E5',
#    '1.E6',
#    '1.E7',
#    '1.E8'
    ]

if __name__ == '__main__':

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
    corsikaMasterInput = parser.get(machine, 'corsikaEnergyInput')
    startRunNumber = int(parser.get(machine, 'startRunNumber'))
    outputDir = parser.get(machine, 'outputDir')
    resultFile = parser.get(machine, 'resultFile')

    # Set logging options
    logging.config.fileConfig(logConfigFile)
    logger = logging.getLogger('full')
    logger.info('Started')

    # Call the function to change the energy
    change_energy(corsikaBin,
                  corsikaPath,
                  corsikaMasterInput,
                  startRunNumber,
                  outputDir,
                  resultFile,
                  energyList)

    # Save general info
    with open(os.path.join(outputDir, 'e3run_summary.txt'), "w") as w:
        w.write('General Info about this Run\n')
        w.write('machine = ' + machine + '\n')
        w.write('corsikaBin = ' + corsikaBin + '\n')
        w.write('corsikaMasterInput = ' + corsikaMasterInput + '\n')
        w.write('energyList = ' + str(energyList) + '\n')

    # Final log message
    logger.info('Finished')
