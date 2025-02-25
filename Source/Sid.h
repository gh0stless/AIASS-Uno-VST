/*
  ==============================================================================

    Sid.h
    Created: 31 Oct 2017 5:48:50pm
    Author:  Andreas Schumm (gh0stless)

  ==============================================================================
*/
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "hardsid.h"
#include "sid_definitions.h"
#include "ThreadSafeRingBuffer.h"
#include "SIDWriteThread.h"

//==============================================================================

class Sid {
	public:
		Sid();
		~Sid();

		int GetDLLVersion(void);
		int GetSidType(int device);
		int GetErrorState(void);
		int GetNoOfDevices(void);
		void init(void);
		void push_event(Uint8 reg, Uint8 val);
		void startPlayerThread(void);
		void stopPlayerThread(void);
		bool isPlayerThreadRuning(void);

		void set_a(Uint8 Voice, Uint8 a);
		void set_d(Uint8 Voice, Uint8 d);
		void set_s(Uint8 Voice, Uint8 s);
		void set_r(Uint8 Voice, Uint8 r);
		void set_pulsw(Uint8 Voice, Uint16 w);
		void set_freq(Uint8 Voice, float f);
		void set_volume(Uint8 vol);
		void set_waveform(Uint8 Voice, Uint8 w);
		void set_ringmod(Uint8 Voice, bool Status);
		void set_sync(Uint8 Voice, bool Status);
		void settest(Uint8 Voice, bool Status);
		void play(Uint8 Voice);
		void stop(Uint8 Voice);
		void set_filterfreq(Uint16 freq);
		void set_filterres(Uint8 res);
		void set_filterfilt(Uint8 filt);
		void set_filtermode(Uint8 fmode);

		
		
	private:
				
		int Number_Of_Devices = 0;
		int DLL_Version = 0;
		bool hardsiddll = false;
		bool dll_initialized = false;
		int error_state = 0;

		typedef Uint16  (*lpHardSID_Version)(void);
		typedef Uint8   (*lpHardSID_Devices)(void);
		typedef void    (*lpHardSID_Delay)(Uint8 DeviceID, Uint16 Cycles);
		typedef void    (*lpHardSID_Write)(Uint8 DeviceID, Uint16 Cycles, Uint8 SID_reg, Uint8 Data);
		typedef Uint8   (*lpHardSID_Read)(Uint8 DeviceID, Uint16 Cycles, Uint8 SID_reg);
		typedef void    (*lpHardSID_Flush)(Uint8 DeviceID);
		typedef void    (*lpHardSID_SoftFlush)(Uint8 DeviceID);
		typedef bool    (*lpHardSID_Lock)(Uint8 DeviceID);
		typedef void    (*lpHardSID_Filter)(Uint8 DeviceID, bool Filter);
		typedef void    (*lpHardSID_Reset)(Uint8 DeviceID);
		typedef void    (*lpHardSID_Sync)(Uint8 DeviceID);
		typedef void    (*lpHardSID_Mute)(Uint8 DeviceID, Uint8 Channel, bool Mute);
		typedef void    (*lpHardSID_MuteAll)(Uint8 DeviceID, bool Mute);
		typedef void    (*lpInitHardSID_Mapper)(void);
		typedef Uint8   (*lpGetHardSIDCount)(void);
		typedef void    (*lpWriteToHardSID)(Uint8 DeviceID, Uint8 SID_reg, Uint8 Data);
		typedef Uint8   (*lpReadFromHardSID)(Uint8 DeviceID, Uint8 SID_reg);
		typedef void    (*lpMuteHardSID_Line)(int Mute);
		typedef void    (*lpHardSID_Reset2)(Uint8 DeviceID, Uint8 Volume);
		typedef void    (*lpHardSID_Unlock)(Uint8 DeviceID);
		typedef Uint8   (*lpHardSID_Try_Write)(Uint8 DeviceID, int Cycles, Uint8 SID_reg, Uint8 Data);
		typedef bool    (*lpHardSID_ExternalTiming)(Uint8 DeviceID);
		typedef void    (*lpHardSID_Uninitialize)(void);
		typedef int 	(*lpHardSID_GetSIDType)(Uint8 DeviceID);

		lpHardSID_Version My_HardSID_Version = nullptr;
		lpHardSID_Devices My_HardSID_Devices = nullptr;
		lpHardSID_Delay My_HardSID_Delay = nullptr;
		lpHardSID_Write My_HardSID_Write = nullptr;
		lpHardSID_Read My_HardSID_Read = nullptr;
		lpHardSID_Flush My_HardSID_Flush = nullptr;
		lpHardSID_SoftFlush My_HardSID_SoftFlush = nullptr;
		lpHardSID_Lock My_HardSID_Lock = nullptr;
		lpHardSID_Filter My_HardSID_Filter = nullptr;
		lpHardSID_Reset My_HardSID_Reset = nullptr;
		lpHardSID_Sync My_HardSID_Sync = nullptr;
		lpHardSID_Mute My_HardSID_Mute = nullptr;
		lpHardSID_MuteAll My_HardSID_MuteAll = nullptr;
		lpInitHardSID_Mapper My_InitHardSID_Mapper = nullptr;
		lpGetHardSIDCount My_GetHardSIDCount = nullptr;
		lpWriteToHardSID My_WriteToHardSID = nullptr;
		lpReadFromHardSID My_ReadFromHardSID = nullptr;
		lpMuteHardSID_Line My_MuteHardSID_Line = nullptr;
		lpHardSID_Reset2 My_HardSID_Reset2 = nullptr;
		lpHardSID_Unlock My_HardSID_Unlock = nullptr;
		lpHardSID_Try_Write My_HardSID_Try_Write = nullptr;
		lpHardSID_ExternalTiming My_HardSID_ExternalTiming = nullptr;
		lpHardSID_Uninitialize My_HardSID_Uninitialize = nullptr;
		lpHardSID_GetSIDType My_HardSID_GetSIDType = nullptr;

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

		juce::DynamicLibrary hardsidlibrary;

		ThreadSafeRingBuffer<SIDWriteSet, MY_BUFFER_SIZE> ringBuffer;
		SIDWriteThread playerThread;
		
		int My_Device = 0;

};
