# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 15:35:23 2015

@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]

Reference:
https://developers.google.com/edu/python/regular-expressions

"""

import logging
import os
import sys
import re


def extract_muon_number(outputDir, extractMuFile):
    ''' Extract the number of Mu from the corsika output files
    '''

    logger = logging.getLogger('plain')
    logger.info('Function ' + sys._getframe().f_code.co_name + ' started')

    # Writing headers to the output file
    with open(os.path.join(outputDir, extractMuFile), 'w') as w:
        w.write('Energy (GeV)' + "\t" + 'Muons' + "\n")

    # Loop for output-E files in outputDir
    for file in os.listdir(outputDir):
        if file.startswith('output'):
            # Get the value of the energy
            energy = file.split('-')[1]
            # Open the file and get the MU+ and MU- numbers
            with open(os.path.join(outputDir, file), "r") as r:
                for line in r:
                    # Using a bit of regex
                    match = re.search(r'\sNO OF MU \+\s+=\s*(\d+)\.$', line)
                    if match:
                        muPlus = match.group(1)
                    match = re.search(r'\sNO OF MU \-\s+=\s*(\d+)\.$', line)
                    if match:
                        muMinus = match.group(1)
            with open(os.path.join(outputDir, extractMuFile), 'a') as w:
                w.write(energy + '\t' +
                        str(int(muPlus) + int(muMinus)) + '\n')
            logger.info('E: ' + energy + '\tMu+: ' + muPlus +
                        '\tMu-: ' + muMinus + '\tTot Mu: ' +
                        str(int(muPlus)+int(muMinus)))

    logger.info('Function finished')
    return True
