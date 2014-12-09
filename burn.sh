export JAVA_HOME=/usr/java/jre1.8.0_25/
export FLIP_HOME=/home/naveen/bin/flip.3.2.1/bin
export USB_DEVFS_PATH=/dev/bus/usb
cd $FLIP_HOME
ls
./batchisp3.sh -device at89c5131 -hardware usb -operation erase f memory flash blankcheck loadbuffer /home/naveen/Documents/Keil_work_sorted/osc_char.hex program verify
