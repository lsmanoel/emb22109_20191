#!/bin/bash

echo $USERNAME

if [ ! $1 ] 
then
  echo "Usage: ./updateSD.sh projectName [get]"
  exit -1  
fi

SERVER_IP="172.16.153.82" 
SERVER_PATH="~/emb22109_20181/projects/$1/images/*.tar.gz"

if [ "$2" = "get" ]
then
	printf "Getting files from LPDE server ($SERVER_IP)... \n"
	scp $USERNAME@$SERVER_IP:$SERVER_PATH .
	printf "... OK!\n"
fi

printf "Copying BOOT files to SD Card... \n"
if [ -d /media/$USERNAME/boot ]
then
	rm -rf /media/$USERNAME/boot/*
	tar -C /media/$USERNAME/boot/ -zxf boot.tar.gz
	echo "... OK!"
else
	echo "ERROR: BOOT partition not found!"
fi


printf "Updating ROOTFS on SD Card... \n"
if [ -d /media/$USERNAME/rootfs ]
then
	sudo rm -rf /media/$USERNAME/rootfs/*
	sudo tar -C /media/$USERNAME/rootfs/ -zxf rootfs.tar.gz
else
	echo "ERROR: rootfs on SD Card not found !"
fi

