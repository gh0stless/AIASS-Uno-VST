/*
  ==============================================================================

    sid_definitions.h
    Created: 13 Nov 2024 7:39:18am
    Author:  andre

  ==============================================================================
*/

#pragma once

struct SIDWriteSet {
	Uint8 SIDRegister;
	Uint8 SIDData;
};

enum SID_TYPE {
	SID_TYPE_NONE = 0, SID_TYPE_6581, SID_TYPE_8580
};

#define NUMSIDREGS 0x18 // numbers of (writable) SID-registers
#define SIDWRITEDELAY 14 // lda $xxxx,x 4 cycles, sta $d400,x 5 cycles, dex 2 cycles, bpl 3 cycles
#define HARDSID_FLUSH_CYCLES 1000
#define HARDSID_FLUSH_MS 50
#define PAL_FRAMERATE 50
#define PAL_CLOCKRATE 985248
#define NTSC_FRAMERATE 60
#define NTSC_CLOCKRATE 1022727 //This is for machines with 6567R8 VIC. 6567R56A is slightly different.
#define FRAME_IN_CYCLES 19705 //( 17734475 / 18 / 50 )   // 50Hz in cycles for PAL clock

#define MY_BUFFER_SIZE 8192*2

