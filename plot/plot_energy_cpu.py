#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Created on 21/04/2015
@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]
"""
import matplotlib.pyplot as plt
import numpy as np
import os
import pkg_resources
from e3sim.config.specific_machine import machine
try:
    # For Python 3.0 and later
    import configparser
except ImportError:
    # Fall back to Python 2
    import ConfigParser

# Reading file_location.ini
try:
    parser = configparser.ConfigParser()
except:
    parser = ConfigParser.ConfigParser()
parser.read(
    pkg_resources.resource_filename(
        'e3sim',
        os.path.join('config', 'files_location.ini')))
outputDir = parser.get(machine, 'outputDir')
resultFile = parser.get(machine, 'resultFile')


data = np.loadtxt(os.path.join(outputDir, resultFile), skiprows=1)
# data = np.loadtxt('energy_vs_mu.dat', skiprows=1)

fig = plt.figure()
ax = fig.add_subplot(111)

ax.plot(data[:, 0], data[:, 1], 'ro')

ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlim(-1.E2, 1.E9)
ax.set_ylim(-100, 1.E6)
# ? ax.xcorr(x, y, usevlines=True, maxlags=50, normed=True, lw=2)
ax.grid(True)
ax.axhline(0, color='black', lw=2)

ax.set_title('Coriska Simulation CPU time')
ax.set_xlabel('Energy of the Primary (GeV)')
ax.set_ylabel('CPU time (s)')

plt.show()
