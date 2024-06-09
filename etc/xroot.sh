#!/bin/sh
export DISPLAY=:0

while true
do
DATE=$(/bin/date +"%d %b (%a) %H:%M")
#echo $ROOT 
xsetroot -name "$DATE"
sleep 5
done
