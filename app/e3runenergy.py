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
from e3sim.tasks.change_energy import change_energy
from e3sim.config.files_location import (logConfigFile,
                                         corsikaBin,
                                         corsikaPath,
                                         corsikaMasterInput,
                                         outputDir,
                                         resultFile)
# Set Energy range in GeV
energyList = [
    '1.E0',
    '1.E1',
    '1.E2',
    '1.E3',
    '1.E4',
    '1.E5',
    '1.E6',
    '1.E7',
    '1.E8']

if __name__ == '__main__':

    # Set logging options
    logging.config.fileConfig(logConfigFile)
    logger = logging.getLogger('full')
    logger.info('Started')

    change_energy(corsikaBin,
                  corsikaPath,
                  corsikaMasterInput,
                  outputDir,
                  resultFile,
                  energyList)

    # Final log message
    logger.info('Finished')
