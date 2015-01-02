echo -e "Making moto g 4g (peregrine) zImage\n"
export PATH=$PATH:/opt/toolchain/bin/
export ARCH=arm
export SUBARCH=arm
export CROSS_COMPILE=arm-linux-gnueabi-

make peregrine_defconfig

make -j7

# modules
find ./ -type f -name '*.ko' -exec cp -f {} ../zip/system/lib/modules/ \;
mv ../zip/system/lib/modules/wlan.ko ../zip/system/lib/modules/pronto/pronto_wlan.ko

# copy zImage
cp -f arch/arm/boot/zImage-dtb ../zip/kernel/
ls -l ../zip/kernel/zImage-dtb
cd ../zip
zip -r -9 moggy_vN.zip * > /dev/null
mv moggy_vN.zip ../
