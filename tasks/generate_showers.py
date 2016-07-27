# -*- coding: utf-8 -*-
"""
Created on Thu Apr 23 15:11:38 2015

@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]
"""

import random
import logging
import os
import sys


def generate_showers(corsikaBin,
                     corsikaPath,
                     corsikaMasterInput,
                     outputDir,
                     lowenergy,
                     highenergy,
                     numberOfShowers,
                     startRunNumber,
                     coreId,
                     altitude):
    '''Routine to generate showers
    '''

    # Logger
    logger = logging.getLogger('plain')
    logger.info('Function ' + sys._getframe().f_code.co_name + ' started')
    logger = logging.getLogger('full')

    # Random Seed
    random.seed()

    # Main Loop
    for iShower in range(numberOfShowers):
        run_number = startRunNumber + iShower

        # Check if the file DATXXXXXX exists
        if os.path.isfile(os.path.join(outputDir, "DAT" + str(run_number).zfill(6))):
            logger.info("File DAT" + str(run_number).zfill(6) + " exists. Skipping.")    
            continue

        # Generate Random seed1 and seed2 for corsika input file
        seed1 = random.randint(1, 900000000)
        seed2 = random.randint(1, 900000000)

        # Write corsika input file
        with open(os.path.join(outputDir, "input-energy-" +
                               str(run_number).zfill(6)),
                  "wt") as outfile:
            with open(corsikaMasterInput, "rt") as infile:
                for line in infile:
                    line = line.replace('run_number', str(run_number))
                    line = line.replace('energy_1',
                                        "{0:4.2E}".format(lowenergy))
                    line = line.replace('energy_2',
                                        "{0:4.2E}".format(highenergy))
                    line = line.replace('seed_1', str(seed1))
                    line = line.replace('seed_2', str(seed2))
                    line = line.replace('altitude_meters', str(altitude))
                    line = line.replace('output_dir', outputDir + "/")
                    outfile.write(line)

        # Define corsika command and the spedific input file
        cmd = "cd " + corsikaPath + "; " +\
            os.path.join(corsikaPath, corsikaBin) + " < " +\
            os.path.join(outputDir, "input-energy-" +
                         str(run_number).zfill(6)) + " > " +\
            os.path.join(outputDir, "output-" + str(run_number).zfill(6))
        
        logger.info('Exec: ' + cmd)
        os.system(cmd)

    logger.info('Function finished')
    return True
