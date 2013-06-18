#!/bin/bash

# TODO: check args and give info
# Usage: play.sh filename

AVINFO=`avconv -i $1 |& grep Stream | grep Hz`
SAMPLERATE=`echo $AVINFO | awk -F " " '{print $5}'`
OUTPUTRATE=$(expr $SAMPLERATE \* 2)

avconv -i $1 -f s32le - | ./spdif-encoder | aplay -f s32 -c 2 -r $OUTPUTRATE

