*installation and use under linux*

Download D2XX driver from:
https://ftdichip.com/drivers/d2xx-drivers/

Please install FTDI drivers explained in chapter '2 Installing the D2XX driver' from here:
https://www.ftdichip.com/Support/Documents/AppNotes/AN_220_FTDI_Drivers_Installation_Guide_for_Linux.pdf

If device still cannot be used, please install a workaround mentioned in chapter '1.1 Overview' :
$ sudo vi /etc/udev/rules.d/91-sidblaster.rules
ACTION=="add", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6001", MODE="0666",  RUN+="/bin/sh -c 'rmmod ftdi_sio && rmmod usbserial'"
$ sudo udevadm control --reload-rules && udevadm trigger

Copy libhardsid.so to /usr/local/lib/
apply chmod 0755 on libhardsid.so
Copy hardsid.hpp to /usr/local/include/

With SIDBlasterTool you can check if library and device communication works.

Depending on your system, tunes with high data rates (multispeed tunes or digitunes) may 
play slower if the latency of the USB driver is too high. This can be remedied by setting
the driver write buffer size to a larger value, for instance:

export SIDBLASTERUSB_WRITEBUFFER_SIZE=8

Even down to 0, works on fast machines.

---
*hardsid library was created by Stein Pedersen
*linux & mac port was made by Ken Händel
*distributed for crazy-midi.de by Andreas Schumm