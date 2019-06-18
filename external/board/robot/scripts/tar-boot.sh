#!/bin/sh
if [ ! -d ${BINARIES_DIR}/boot ] 
then
	mkdir ${BINARIES_DIR}/boot
fi

mcopy -si ${BINARIES_DIR}/boot.vfat ::* ${BINARIES_DIR}/boot/ 

if [ -f ${BR2_EXTERNAL_EMB22109_PATH}/board/robot/dt_overlays/i2c-nunchuk.dtbo ]
then	
	cp ${BR2_EXTERNAL_EMB22109_PATH}/board/robot/dt_overlays/i2c-nunchuk.dtbo ${BINARIES_DIR}/boot/overlays/
fi

cat << __EOF__ >> "${BINARIES_DIR}/boot/config.txt"

# Enable i2c
dtparam=i2c_arm=on
__EOF__

(cd ${BINARIES_DIR}/boot && tar -zcvf ../boot.tar.gz *)

if [ -f ${BINARIES_DIR}/rootfs.tar.gz ]
then
	rm ${BINARIES_DIR}/rootfs.tar
fi

rm -rf ${BINARIES_DIR}/boot

exit $?
