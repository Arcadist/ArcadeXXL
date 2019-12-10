#!/bin/bash

ARCADE_SCRIPTS=arcadeScripts.tar

tar cf ${ARCADE_SCRIPTS} \
--transform 's,^, /usr/local/bin/,' startup.py onStart.py onEnd.py

tar rf ${ARCADE_SCRIPTS} \
--transform 's,^, /opt/retropie/configs/all/,' runcommand-onstart.sh runcommand-onend.sh
