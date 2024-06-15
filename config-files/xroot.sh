#!/bin/sh
export DISPLAY=:0

while true
do
DATE=$(/bin/date +"%d %b (%a) %H:%M")
CPU_USAGE=$({ head -n1 /proc/stat; sleep 0.2; head -n1 /proc/stat; } | awk '/^cpu /{u=$2-u;s=$4-s;i=$5-i;w=$6-w}END{print int(0.5+100*(u+s+w)/(u+s+i+w))}')
MEMORY_USAGE=$(free | grep Mem | awk '{print int($3/$2 * 100)}')
xsetroot -name "$DATE | CPU: $CPU_USAGE% | RAM: $MEMORY_USAGE%"
sleep 5
done
