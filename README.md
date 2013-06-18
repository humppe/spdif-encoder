SPDIF Encoder
=============

This application inputs linear PCM, signed 32 bit stereo audio samples and
encodes them so that they can be output through Raspberry Pi I2S audio hardware
to SPDIF transceiver. The output is IEC958 and Biphase Mark Encoded bitstream.

How-to:
-------

0. Get a proper SPDIF hardware interface. I soldered a TOTX177L TOSLINK module
/1/ to the board using the application schematic in the datasheet (i.e. 0.1uF
capacitor and the module). See /2/ for other possibilities.

1. Get new Kernel with ASoC support.
    http://blog.koalo.de/2013_05_01_archive.html
    https://github.com/koalo/linux

2. Add patch to the kernel;
    patch -p1 < spdif-hack.patch

3. Build the Kernel according to the instructions in koalo's blog.

4. Install e.g. avconv application for decoding your audio files
    apt-get install libav-tools

5..gcc -O3 spdif-encoder.c -o spdif-encoder

6. Load kernel modules -- the spdif-output-hack is applied to tda1541a -drivers.

7. create ~/.asoundrc  (or /etc/alsa.conf) file with following content:
    pcm.!default {
      type hw
      card 1
      device 0
      subdevice -1
    }

8. ./play.sh <your-audio-file.mp3>


License:
--------

Code is free for use from my perspective; but you need to know that I have
shamelessly copied from ALSA Plugins, pcm_iec958.c /3/ and adapted a code clip
from jeroenst /4/.



/1/ http://www.robomaa.com/index.php?main_page=product_info&cPath=1005_1139&products_id=597&zenid=nkpmp9g939j7sc0uam9t1lbpn2
/2/ http://www.epanorama.net/documents/audio/spdif.html
/3/ http://gitorious.org/alsa/alsa-lib/blobs/8ed98db2590e284dd7ca884135c91566fee6069c/src/pcm/pcm_iec958.c
/4/ http://www.raspberrypi.org/phpBB3/viewtopic.php?f=44&t=8496&p=202411&hilit=spdif#p202411

