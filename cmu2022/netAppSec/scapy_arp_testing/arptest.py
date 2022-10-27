#!/usr/bin/env python
import os
import sys
import signal
import logging
from scapy.all import (
    get_if_hwaddr,
    getmacbyip,
    ARP,
    Ether,
    sendp
)
from optparse import OptionParser
from time import sleep
from scapy.all import *
# from scapy_arp import *

request = scapy.ARP()
print(request.summary())