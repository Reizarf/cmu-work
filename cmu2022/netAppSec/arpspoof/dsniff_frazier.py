from scapy.all import sniff, TCP, Raw
import sys
import time
import re


def check_packet(packet):
    if not packet.haslayer(TCP) or not packet.haslayer(Raw):
        return
    raw_data = packet[Raw].load
    payload = bytes(packet[TCP].payload).decode('UTF8','replace')
    if re.match("[a-zA-Z0-9]+.*", payload):
        print(f"Sniffed plaintext packet: '{payload.strip()}'")


if __name__ == "__main__":
    print("Sniffing ALL - CTRL+C (x2) to stop")
    inter = False
    while not inter:
        try:
            sniff(
                prn=check_packet,
                filter="tcp",
            )
            time.sleep(1)
        except KeyboardInterrupt:
            print("[!!!] KeyboardInterrupt: Sniff stopped")
            