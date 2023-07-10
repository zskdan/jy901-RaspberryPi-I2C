#!/bin/bash

fileout=jy901-`date +"%F-%Hh%Mm%Ss"`.log

sudo mkdir -p /camera
#sudo mount /dev/mmcblk0p3 /camera/ -o uid=1000,gid=1000
cd /camera

i2cdetect -y 1 > $fileout
/home/pi/jy901/jy901-RaspberryPi-I2C/jy901-read >> $fileout
