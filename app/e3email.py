#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Tue Aug  2 09:04:40 2016

@author: Fabrizio Coccetti (fabrizio.coccetti@centrofermi.it) [www.fc8.net]
Send email to say a job is finished
"""

import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import os
import pkg_resources
import logging
import logging.config
from datetime import datetime
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
logConfigFile = parser.get(machine, 'logConfigFile')
emailConfigFile = parser.get(machine, 'emailConfigFile')

# Set up logging
logging.config.fileConfig(logConfigFile)
logger = logging.getLogger('full')
logger.info('Started')
logger = logging.getLogger('plain')

# Reading Email Config File
logger.info('Reading ' + emailConfigFile)
parser = ConfigParser.ConfigParser()
parser.read(emailConfigFile)
smtpServer = parser.get('gmail', 'smtpServer')
smtpPort = parser.get('gmail', 'smtpPort')
emailFrom = parser.get('gmail', 'emailFrom')
emailTo = parser.get('gmail', 'emailTo')
passwd = parser.get('gmail', 'passwd')

# Create message container - the correct MIME type is multipart/alternative.
today = datetime.today()
todayStr = today.strftime("%H:%M %a %d %B %Y")
msg = MIMEMultipart('alternative')
msg['Subject'] = "Cosmic Shower Simulation Ended " + todayStr
msg['From'] = emailFrom
msg['To'] = emailTo

# Create the body of the message (a plain-text and an HTML version).
text = "The message is in html format. It looks like your client does not support it"
html = """
<html>
<head></head>
<body>
The Cosmic Ray Simulation is ended.
</body>
</html>
"""

# Record the MIME types of both parts - text/plain and text/html.
part1 = MIMEText(text, 'plain')
part2 = MIMEText(html, 'html')

# Attach parts into message container.
# According to RFC 2046, the last part of a multipart message, in this case
# the HTML message, is best and preferred.
msg.attach(part1)
msg.attach(part2)

# Sending message
logger.info('Sending message via Gmail')
s = smtplib.SMTP(smtpServer + ":" + smtpPort)
s.starttls()
s.login(emailFrom, passwd)
s.sendmail(emailFrom, emailTo, msg.as_string())
s.quit()

logger.info('Finished')
