# -*- coding: utf-8 -*-
"""
Created on Thu Apr 16 13:04:02 2015

@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]
"""
import logging
import os
import sys
import time


def change_energy(corsikaBin,
                  corsikaPath,
                  corsikaMasterInput,
                  outputDir,
                  resultFile,
                  energyList):
    '''Routine to change the primary energy in a range and
    measure the CPU time of each shower generation
    '''
    logger = logging.getLogger('plain')
    logger.info('Function ' + sys._getframe().f_code.co_name + ' started')
    run_number = 0

    # Writing headers to the output file
    with open(os.path.join(outputDir, resultFile), 'w') as w:
        w.write('Energy (GeV)' + "\t" + 'CPU Time' + "\n")

    logger = logging.getLogger('full')
    # Main Loop
    for energy in energyList:
        # Write corsika input file
        with open(os.path.join(outputDir, "input-energy-" + str(energy)),
                  "wt") as outfile:
            with open(corsikaMasterInput, "rt") as infile:
                for line in infile:
                    line = line.replace('run_number', str(run_number))
                    line = line.replace('energy_1', str(energy))
                    line = line.replace('energy_2', str(energy))
                    line = line.replace('seed_1', '123')
                    line = line.replace('seed_2', '456')
                    line = line.replace('output_dir', outputDir + "/")
                    outfile.write(line)

        # Define corsika command and the spedific input file
        cmd = "cd " + corsikaPath + "; " +\
            os.path.join(corsikaPath, corsikaBin) + " < " +\
            os.path.join(outputDir, "input-energy-" + str(energy)) + " > " +\
            os.path.join(outputDir, "output-" + str(energy))

        # Run command
        logger.info('About to exec: ' + cmd)
        startTime = time.time()
        os.system(cmd)
        elapsedTime = time.time() - startTime

        # Appending results
        with open(os.path.join(outputDir, resultFile), "a") as w:
            w.write(str(energy) + "\t" + str(elapsedTime) + "\n")
        run_number += 1

    logger.info('Function finished')
    return True
