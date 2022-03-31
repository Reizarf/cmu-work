#! /usr/bin/bash
#Check our system information
echo "Memory:"
free -h

echo "Disk Usage: "
df -h

echo "Uptime: "
uptime

echo "Check system's time: "
TIME="$(date)"
echo $TIME
exit