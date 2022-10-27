PROGRAM_NAME = arpspoof_frazier.py
build:
	echo 1 | sudo tee /proc/sys/net/ipv4/ip_forward
	sudo chown root:root $(PROGRAM_NAME)
	sudo chmod +x $(PROGRAM_NAME)
run:
	./$(PROGRAM_NAME)
