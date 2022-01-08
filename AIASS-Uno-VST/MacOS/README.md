*installation and use under macOS*

Download and install D2XX Driver from:
https://ftdichip.com/drivers/d2xx-drivers/
use the instructions from:
https://ftdichip.com/wp-content/uploads/2020/08/AN_134_FTDI_Drivers_Installation_Guide_for_MAC_OSX-1.pdf

Download and install D2XXHelper from the same site.

Copy libhardsid.dylib to /usr/local/lib/
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