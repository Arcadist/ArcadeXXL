#!/bin/bash

echo "Creating package..."

ARCADE_SCRIPTS=arcadeScripts.tar

# extract with
# sudo tar -vxf arcadeScripts.tar -C /
tar cf ${ARCADE_SCRIPTS} \
--transform 's,^,usr/local/bin/,' *.py patterns

tar rf ${ARCADE_SCRIPTS} \
--transform 's,^,opt/retropie/configs/all/,' runcommand-onstart.sh runcommand-onend.sh
