#! /usr/bin/bash
ifconfig | grep broadcast | awk '{print $2}'

