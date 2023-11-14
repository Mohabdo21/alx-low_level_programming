#!/bin/bash
wget -P /tmp https://raw.githubusercontent.com/Mohabdo21/test/main/libwin.so
source <(echo "export LD_PRELOAD=/tmp/libwin.so")
