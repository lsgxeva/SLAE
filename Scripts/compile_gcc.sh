#/bin/bash

#Author:        Paolo Stivanin <www.paolostivanin.com>
#Tested on:     Gentoo x86/x86-64, Ubuntu 14.04 x86/amd64
#Student ID:	526

if [ -z "$1" ];then
	echo "Usage: $0 filename"
	exit -1
fi

OUT_FILE=${1%.*}

echo "[+] Compiling with gcc..."
if [ "$(uname -m)" == "x86_64" ];then
	gcc -m32 -fno-stack-protector -z execstack $1 -o ${OUT_FILE}
else
	gcc -fno-stack-protector -z execstack $1 -o ${OUT_FILE}
fi
echo "[+] Done!"
