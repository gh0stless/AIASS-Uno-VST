*installation and use under windows*

Copy the hardsid.dll into the program directory of the program with which you want to use it.
The 64 bit version is required by the 64 bit version of vice and also by the 64 bit versions of AIASS.

With SIDBlasterTool you can check if library and device communication works.


Depending on your system, tunes with high data rates (multispeed tunes or digitunes) may 
play slower if the latency of the USB driver is too high. This can be remedied by setting
the driver write buffer size to a larger value, for instance:

SET SIDBLASTERUSB_WRITEBUFFER_SIZE=8

Even down to 0, works on fast machines.


---
*hardsid library was created by Stein Pedersen
*linux & mac port was made by Ken Händel
*distributed for crazy-midi.de by Andreas Schumm