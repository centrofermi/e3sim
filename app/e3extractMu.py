#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 15:26:23 2015

@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]
"""

import logging
import logging.config
import os
import pkg_resources
from e3sim.tasks.extract_muon_number import extract_muon_number
from e3sim.config.specific_machine import machine
try:
    # For Python 3.0 and later
    import configparser
except ImportError:
    # Fall back to Python 2
    import ConfigParser

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
    outputDir = parser.get(machine, 'outputDir')
    extractMuFile = parser.get(machine, 'extractMuFile')

    # Set logging options
    logging.config.fileConfig(logConfigFile)
    logger = logging.getLogger('full')
    logger.info('Started')

    # Call the function to extract muons number
    extract_muon_number(outputDir, extractMuFile)

    # Final log message
    logger.info('Finished')
