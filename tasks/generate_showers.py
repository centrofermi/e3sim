# -*- coding: utf-8 -*-
"""
Created on Thu Apr 23 15:11:38 2015

@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]
"""

import logging
import os
import sys


def generate_showers(corsikaBin,
                     corsikaPath,
                     corsikaMasterInput,
                     outputDir,
                     energy,
                     numberOfShowers,
                     startRunNumber,
                     altitude):
    '''Routine to generate showers
    '''

    # Logger
    logger = logging.getLogger('plain')
    logger.info('Function ' + sys._getframe().f_code.co_name + ' started')
    logger = logging.getLogger('full')

    # Main Loop
    for iShower in range(numberOfShowers):
        run_number = startRunNumber + iShower
        # Write corsika input file
        with open(os.path.join(outputDir, "input-energy-" +
                               str(run_number).zfill(6)),
                  "wt") as outfile:
            with open(corsikaMasterInput, "rt") as infile:
                for line in infile:
                    line = line.replace('run_number', str(run_number))
                    line = line.replace('energy_1',
                                        "{:4.2E}".format(energy))
                    line = line.replace('energy_2',
                                        "{:4.2E}".format(energy))
                    line = line.replace('seed_1', str(run_number))
                    line = line.replace('seed_2', str(run_number+1))
                    line = line.replace('altitude_meters', str(altitude))
                    line = line.replace('output_dir', outputDir + "/")
                    outfile.write(line)

        # Define corsika command and the spedific input file
        cmd = "cd " + corsikaPath + "; " +\
            os.path.join(corsikaPath, corsikaBin) + " < " +\
            os.path.join(outputDir, "input-energy-" +
                         str(run_number).zfill(6)) + " > " +\
            os.path.join(outputDir, "output-" + str(run_number).zfill(6))

        print(cmd)

    logger.info('Function finished')
    return True
