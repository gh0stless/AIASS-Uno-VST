/*
  ==============================================================================

    Sid.h
    Created: 31 Oct 2017 5:48:50pm
    Author:  Andreas Schumm (gh0stless)

  ==============================================================================
*/

#pragma once
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif

#include "../JuceLibraryCode/JuceHeader.h"

#define NUMSIDREGS 0x18 // numbers of (writable) SID-registers
#define SIDWRITEDELAY 14 // lda $xxxx,x 4 cycles, sta $d400,x 5 cycles, dex 2 cycles, bpl 3 cycles
#define HARDSID_FLUSH_CYCLES 1000
#define HARDSID_FLUSH_MS 50
#define PAL_FRAMERATE 50
#define PAL_CLOCKRATE 985248
#define NTSC_FRAMERATE 60
#define NTSC_CLOCKRATE 1022727 //This is for machines with 6567R8 VIC. 6567R56A is slightly different.
#define FRAME_IN_CYCLES 19705 //( 17734475 / 18 / 50 )   // 50Hz in cycles for PAL clock
#define MY_BUFFER_SIZE 10000

typedef unsigned char Uint8;
typedef unsigned short Uint16;
typedef unsigned char  BYTE;

class Sid
{

	public:
		Sid();
		~Sid();

		void init(void);
		void push_event(Uint8 reg, Uint8 val);
		void set_a(Uint8 Voice, Uint8 a);
		void set_d(Uint8 Voice, Uint8 d);
		void set_s(Uint8 Voice, Uint8 s);
		void set_r(Uint8 Voice, Uint8 r);
		void set_pulsw(Uint8 Voice, Uint16 w);
		void set_freq(Uint8 Voice, float f);
		void set_volume(Uint8 vol);
		void set_waveform(Uint8 Voice, uint8 w);
		void set_ringmod(Uint8 Voice, bool Status);
		void set_sync(Uint8 Voice, bool Status);
		void settest(Uint8 Voice, bool Status);
		void play(Uint8 Voice);
		void stop(Uint8 Voice);
		void set_filterfreq(Uint16 freq);
		void set_filterres(Uint8 res);
		void set_filterfilt(Uint8 filt);
		void set_filtermode(Uint8 fmode);

		int error_state = 0;

	private:
				
		int Nr_Of_Instances = 0;
		int Number_Of_Devices = 0;
		int DLL_Version = 0;
		#if defined(_WIN32) || defined(_WIN64)
		bool hardsiddll = false;
		#endif
		bool dll_initialized = false;

		juce::DynamicLibrary hardsidlibrary;

		enum HSID_STATES{
			HSID_USB_WSTATE_OK = 1, HSID_USB_WSTATE_BUSY,
			HSID_USB_WSTATE_ERROR, HSID_USB_WSTATE_END
		};
	    #if defined(_WIN32) || defined(_WIN64)
		typedef Uint16(CALLBACK* lpHardSID_Version)(void);
		typedef Uint8   (CALLBACK* lpHardSID_Devices)(void);
		typedef void    (CALLBACK* lpHardSID_Delay)(Uint8 DeviceID, Uint16 Cycles);
		typedef void    (CALLBACK* lpHardSID_Write)(Uint8 DeviceID, Uint16 Cycles, Uint8 SID_reg, Uint8 Data);
		typedef Uint8   (CALLBACK* lpHardSID_Read)(Uint8 DeviceID, Uint16 Cycles, Uint8 SID_reg);
		typedef void    (CALLBACK* lpHardSID_Flush)(Uint8 DeviceID);
		typedef void    (CALLBACK* lpHardSID_SoftFlush)(Uint8 DeviceID);
		typedef boolean (CALLBACK* lpHardSID_Lock)(Uint8 DeviceID);
		typedef void    (CALLBACK* lpHardSID_Filter)(Uint8 DeviceID, boolean Filter);
		typedef void    (CALLBACK* lpHardSID_Reset)(Uint8 DeviceID);
		typedef void    (CALLBACK* lpHardSID_Sync)(Uint8 DeviceID);
		typedef void    (CALLBACK* lpHardSID_Mute)(Uint8 DeviceID, Uint8 Channel, boolean Mute);
		typedef void    (CALLBACK* lpHardSID_MuteAll)(Uint8 DeviceID, boolean Mute);
		typedef void    (CALLBACK* lpInitHardSID_Mapper)(void);
		typedef Uint8   (CALLBACK* lpGetHardSIDCount)(void);
		typedef void    (CALLBACK* lpWriteToHardSID)(Uint8 DeviceID, Uint8 SID_reg, Uint8 Data);
		typedef Uint8   (CALLBACK* lpReadFromHardSID)(Uint8 DeviceID, Uint8 SID_reg);
		typedef void    (CALLBACK* lpMuteHardSID_Line)(int Mute);
		typedef void    (CALLBACK* lpHardSID_Reset2)(Uint8 DeviceID, Uint8 Volume);
		typedef void    (CALLBACK* lpHardSID_Unlock)(Uint8 DeviceID);
		typedef Uint8   (CALLBACK* lpHardSID_Try_Write)(Uint8 DeviceID, Uint16 Cycles, Uint8 SID_reg, Uint8 Data);
		typedef BOOL    (CALLBACK* lpHardSID_ExternalTiming)(Uint8 DeviceID);
		


		
		lpHardSID_Version HardSID_Version = NULL;
		lpHardSID_Devices HardSID_Devices = NULL;
		lpHardSID_Delay HardSID_Delay = NULL;
		lpHardSID_Write HardSID_Write = NULL;
		lpHardSID_Read HardSID_Read = NULL;
		lpHardSID_Flush HardSID_Flush = NULL;
		lpHardSID_SoftFlush HardSID_SoftFlush = NULL;
		lpHardSID_Lock HardSID_Lock = NULL;
		lpHardSID_Filter HardSID_Filter = NULL;
		lpHardSID_Reset HardSID_Reset = NULL;
		lpHardSID_Sync HardSID_Sync = NULL;
		lpHardSID_Mute HardSID_Mute = NULL;
		lpHardSID_MuteAll HardSID_MuteAll = NULL;
		lpInitHardSID_Mapper InitHardSID_Mapper = NULL;
		lpGetHardSIDCount GetHardSIDCount = NULL;
		lpWriteToHardSID WriteToHardSID = NULL;
		lpReadFromHardSID ReadFromHardSID = NULL;
		lpMuteHardSID_Line MuteHardSID_Line = NULL;
		lpHardSID_Reset2 HardSID_Reset2 = NULL;
		lpHardSID_Unlock HardSID_Unlock = NULL;
		lpHardSID_Try_Write HardSID_Try_Write = NULL;
		lpHardSID_ExternalTiming HardSID_ExternalTiming = NULL;
		#endif
		struct SID_Voice {
			Uint8 FREQ_LO;
			Uint8 FREQ_HI;
			Uint16 PULSE;
			Uint8 WAVEFORM;
			Uint8 CONTROL;
			Uint8 GATE;
			Uint8 ATTACK;
			Uint8 DECAY;
			Uint8 SUSTAIN;
			Uint8 RELEASE;
			Uint8 VOLUME;
			Uint8 FILTER;
			Uint8 FIL_FREQ_LOW;
			Uint8 FIL_FREQ_HIGH;
			Uint8 RES;
			Uint8 FILT;
		} SID_Voice1, SID_Voice2, SID_Voice3;

		int My_Device = 0;

};
