# AIASS-Uno VST

... is a quick and dirty VST-Plugin for use with SIDBlaster-USB, made by Juce Framework.

Compiled binary files also on www.crazy-midi.de.

I hope that the source code can be a basis to create more VST plugins for the SIDBlaster-USB. 

Perhaps you are also interested in the sister project AIASS for Max4Live:

https://github.com/gh0stless/AIASS-for-MAX4LIVE

![](./docs/AIASS-Uno-VST-Preview.jpg)

## Description
In the event of errors (wrong or missing DLL, no SIDBlaster connected) the red LED flashes.

## Build

##### windows

Open project in Projucer (part of juce package)(status: version 6.1.2) and export to and compile with Visual Studio 2019.

Under Windows, the correct DLL (32 or 64 bit) must be in the same folder as the host exe or, in the case of the standalone version, in its folder.

##### linux
Open project in Projucer then build with "make CONFIG=Release".

##### macOS
Open Project in Projucer and export an build with XCode.

## Hardware

https://github.com/gh0stless/SIDBlaster-USB-Tic-Tac-Edition

## hardsid.dll

https://github.com/Galfodo/SIDBlasterUSB_HardSID-emulation-driver

https://haendel.ddns.net/~ken/sidblaster.html

## License

AIASS-Uno VST is under GPL v3:

https://www.gnu.org/licenses/gpl-3.0.en.html

Please also note the end user license of Juce: 

https://juce.com/juce-5-license

The original SIDBlaster-USB was created by Davey:

https://github.com/stg/SIDBlaster-USB

hardsid.dll for SIDBlaster-USB is by Stein Petersen:

https://github.com/Galfodo/SIDBlasterUSB_HardSID-emulation-driver

linux/mac port of hardsid.dll by Ken Händel:

https://haendel.ddns.net/~ken/

https://haendel.ddns.net/~ken/sidblaster.html

## Thanks

Thanks a lot: Wilfred Bos, Stein Pedersen & Ken Händel for your help. 

Thanks Davey for the SIDBlaster-USB.

And to my bride-to-be, Borjana Konstantinowa,  for your patience with me 

***-Andreas Schumm (gh0stless) in December 2021***

