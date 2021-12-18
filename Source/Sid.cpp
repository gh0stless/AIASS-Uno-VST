/*
  ==============================================================================

    Sid.cpp
    Created: 31 Oct 2017 5:48:50pm
    Author:  Andreas Schumm (gh0stless)

  ==============================================================================
*/

#include "Sid.h"
#include <chrono>
#include <thread>

#if defined(__linux) || defined(__APPLE__)
#include "libhardsid.h"
#endif

//------------------------------------------------------------------------------

	Sid::Sid()
	{
		

		#if defined(_WIN32) || defined(_WIN64)
		hardsiddll = LoadLibrary("hardsid.dll");
		// Check to see if the library was loaded successfully 
		if (hardsiddll != 0) {
			HardSID_Version = (lpHardSID_Version)GetProcAddress(hardsiddll, "HardSID_Version");
			HardSID_Devices = (lpHardSID_Devices)GetProcAddress(hardsiddll, "HardSID_Devices");
			HardSID_Delay = (lpHardSID_Delay)GetProcAddress(hardsiddll, "HardSID_Delay");
			HardSID_Write = (lpHardSID_Write)GetProcAddress(hardsiddll, "HardSID_Write");
			HardSID_Read = (lpHardSID_Read)GetProcAddress(hardsiddll, "HardSID_Read");
			HardSID_Flush = (lpHardSID_Flush)GetProcAddress(hardsiddll, "HardSID_Flush");
			HardSID_SoftFlush = (lpHardSID_SoftFlush)GetProcAddress(hardsiddll, "HardSID_SoftFlush");
			HardSID_Lock = (lpHardSID_Lock)GetProcAddress(hardsiddll, "HardSID_Lock");
			HardSID_Filter = (lpHardSID_Filter)GetProcAddress(hardsiddll, "HardSID_Filter");
			HardSID_Reset = (lpHardSID_Reset)GetProcAddress(hardsiddll, "HardSID_Reset");
			HardSID_Sync = (lpHardSID_Sync)GetProcAddress(hardsiddll, "HardSID_Sync");
			HardSID_Mute = (lpHardSID_Mute)GetProcAddress(hardsiddll, "HardSID_Mute");
			HardSID_MuteAll = (lpHardSID_MuteAll)GetProcAddress(hardsiddll, "HardSID_MuteAll");
			InitHardSID_Mapper = (lpInitHardSID_Mapper)GetProcAddress(hardsiddll, "InitHardSID_Mapper");
			GetHardSIDCount = (lpGetHardSIDCount)GetProcAddress(hardsiddll, "GetHardSIDCount");
			WriteToHardSID = (lpWriteToHardSID)GetProcAddress(hardsiddll, "WriteToHardSID");
			ReadFromHardSID = (lpReadFromHardSID)GetProcAddress(hardsiddll, "ReadFromHardSID");
			MuteHardSID_Line = (lpMuteHardSID_Line)GetProcAddress(hardsiddll, "MuteHardSID_Line");
			HardSID_Reset2 = (lpHardSID_Reset2)GetProcAddress(hardsiddll, "HardSID_Reset2");
			HardSID_Unlock = (lpHardSID_Unlock)GetProcAddress(hardsiddll, "HardSID_Unlock");
			HardSID_Try_Write = (lpHardSID_Try_Write)GetProcAddress(hardsiddll, "HardSID_Try_Write");
			HardSID_ExternalTiming = (lpHardSID_ExternalTiming)GetProcAddress(hardsiddll, "HardSID_ExternalTiming");
			//Check Version & Device-count
			DLL_Version = (int)HardSID_Version();
			if (DLL_Version < 515) {
				dll_initialized = false;
				error_state = 2;
			}
			else {
				Number_Of_Devices = (int)HardSID_Devices();
				if (Number_Of_Devices == 0)
				{
					error_state = 3;
				}
				dll_initialized = true;
			}
		}
		else {
			dll_initialized = false;
			error_state = 1;
		}
		#endif
		
		#if defined(__linux) || defined(__APPLE__)
		dll_initialized = true;
		error_state = 0;
		DLL_Version = (int)HardSID_Version();
		if (DLL_Version < 515) {
			error_state = 2;
		}
        Number_Of_Devices = (int)HardSID_Devices();
        if (Number_Of_Devices == 0)
        {
            error_state = 3;
        }
        #endif
	}

	Sid::~Sid()
	{
		#if defined(_WIN32) || defined(_WIN64)
		if (hardsiddll != 0) FreeLibrary(hardsiddll);
		#endif
	}

//------------------------------------------------------------------------------

	void Sid::init(void)
	{
		if (dll_initialized && !error_state)
		{
			//Init SID
			HardSID_Reset(My_Device);
			HardSID_Lock(My_Device);
			HardSID_Flush(My_Device);

			//Init Registers
			push_event(0, 0x00);
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			BYTE r;
			for (r = 0; r <= NUMSIDREGS; r++) {
				push_event(r, 0x00);
			}
		}
		SID_Voice1.FREQ_LO = 0;
		SID_Voice1.FREQ_HI = 0;
		SID_Voice1.PULSE = 0;
		SID_Voice1.WAVEFORM = 0;
		SID_Voice1.CONTROL = 0;
		SID_Voice1.GATE = 0;
		SID_Voice1.ATTACK = 0;
		SID_Voice1.DECAY = 0;
		SID_Voice1.SUSTAIN = 0;
		SID_Voice1.RELEASE = 0;

		SID_Voice1.VOLUME = 0;
		SID_Voice1.FILTER = 0;
		SID_Voice1.FIL_FREQ_LOW = 0;
		SID_Voice1.FIL_FREQ_HIGH = 0;
		SID_Voice1.FILT = 0;
		SID_Voice1.RES = 0;

		SID_Voice2.FREQ_LO = 0;
		SID_Voice2.FREQ_HI = 0;
		SID_Voice2.PULSE = 0;
		SID_Voice2.WAVEFORM = 0;
		SID_Voice2.CONTROL = 0;
		SID_Voice2.GATE = 0;
		SID_Voice2.ATTACK = 0;
		SID_Voice2.DECAY = 0;
		SID_Voice2.SUSTAIN = 0;
		SID_Voice2.RELEASE = 0;

		SID_Voice2.VOLUME = 0;
		SID_Voice2.FILTER = 0;
		SID_Voice2.FIL_FREQ_LOW = 0;
		SID_Voice2.FIL_FREQ_HIGH = 0;
		SID_Voice2.FILT = 0;
		SID_Voice2.RES = 0;

		SID_Voice3.FREQ_LO = 0;
		SID_Voice3.FREQ_HI = 0;
		SID_Voice3.PULSE = 0;
		SID_Voice3.WAVEFORM = 0;
		SID_Voice3.CONTROL = 0;
		SID_Voice3.GATE = 0;
		SID_Voice3.ATTACK = 0;
		SID_Voice3.DECAY = 0;
		SID_Voice3.SUSTAIN = 0;
		SID_Voice3.RELEASE = 0;

		SID_Voice3.VOLUME = 0;
		SID_Voice3.FILTER = 0;
		SID_Voice3.FIL_FREQ_LOW = 0;
		SID_Voice3.FIL_FREQ_HIGH = 0;
		SID_Voice3.FILT = 0;
		SID_Voice3.RES = 0;
	}
	void Sid::push_event(Uint8 reg, Uint8 val)
	{
		Uint8 RS = 0;
		if (dll_initialized && !error_state)
		{
			while (RS != HSID_USB_WSTATE_OK)
			{
				RS = HardSID_Try_Write(My_Device, 0, reg, val);
				if (RS == HSID_USB_WSTATE_BUSY) std::this_thread::sleep_for(std::chrono::milliseconds(20));
			}
			HardSID_SoftFlush(My_Device);
		}
	}
	void Sid::set_a(Uint8 Voice, Uint8 a)
	{
		switch (Voice)
		{
		case 1: SID_Voice1.ATTACK = a;
			push_event(5, (Uint8)((a << 4) + SID_Voice1.DECAY));
			break;
		case 2: SID_Voice2.ATTACK = a;
			push_event(12, (Uint8)((a << 4) + SID_Voice2.DECAY));
			break;
		case 3: SID_Voice3.ATTACK = a;
			push_event(19, (Uint8)((a << 4) + SID_Voice3.DECAY));
			break;
		default:
			//error
			;
		}
	}
	void Sid::set_d(Uint8 Voice, Uint8 d)
	{
		Uint8 h = 0;
		switch (Voice)
		{
		case 1: SID_Voice1.DECAY = d;
			h = SID_Voice1.ATTACK;
			push_event(5, (Uint8)((h << 4) + d));
			break;
		case 2: SID_Voice2.DECAY = d;
			h = SID_Voice2.ATTACK;
			push_event(12, (Uint8)((h << 4) + d));
			break;
		case 3: SID_Voice3.DECAY = d;
			h = SID_Voice3.ATTACK;
			push_event(19, (Uint8)((h << 4) + d));
			break;
		default:
			//error
			;
		}
	}
	void Sid::set_s(Uint8 Voice, Uint8 s)
	{
		switch (Voice)
		{
		case 1: SID_Voice1.SUSTAIN = s;
			push_event(6, (Uint8)((s << 4) + SID_Voice1.RELEASE));
			break;
		case 2: SID_Voice2.SUSTAIN = s;
			push_event(13, (Uint8)((s << 4) + SID_Voice2.RELEASE));
			break;
		case 3: SID_Voice3.SUSTAIN = s;
			push_event(20, (Uint8)((s << 4) + SID_Voice3.RELEASE));
			break;
		default:
			//error
			;
		}
	}
	void Sid::set_r(Uint8 Voice, Uint8 r)
	{
		Uint8 h = 0;
		switch (Voice)
		{
		case 1: SID_Voice1.RELEASE = r;
			h = SID_Voice1.SUSTAIN;
			push_event(6, (Uint8)((h << 4) + r));
			break;
		case 2: SID_Voice2.RELEASE = r;
			h = SID_Voice2.SUSTAIN;
			push_event(13, (Uint8)((h << 4) + r));
			break;
		case 3: SID_Voice3.RELEASE = r;
			h = SID_Voice3.SUSTAIN;
			push_event(20, (Uint8)((h << 4) + r));
			break;
		default:
			//error
			;
		}
	}
	void Sid::set_pulsw(Uint8 Voice, Uint16 w)
	{
				Uint8 l = (Uint8)w;
				Uint16 a = (w & 0b0000111100000000) >> 8;
				Uint8 h = (Uint8)a;
				if (w >= 0 && w <= 4095) {
					switch (Voice) {
					case 1: 
						push_event(2, (Uint8)l);
						push_event(3, (Uint8)h);
						SID_Voice1.PULSE = w;
						break;
					case 2: 
						push_event(9, (Uint8)l);
						push_event(10, (Uint8)h);
						SID_Voice2.PULSE = w;
						break;
					case 3: 
						push_event(16, (Uint8)l);
						push_event(17, (Uint8)h);
						SID_Voice3.PULSE = w;
						break;
					default: 
						break;
					}
				}
				else {
					//post("sid(pulse): error!!! value out of range!");
				}
			
		
		
		
	}
	void Sid::set_freq(Uint8 Voice, float f)
	{
		//OK: n is a real frequency
		//Calculate SID-frequency
		float SF = (17.02841924F * f);
		SF += 0.5;
		int SID_FREQ = SF;
		if ((SID_FREQ >= 0) && (SID_FREQ <= 65535))
		{
			int SF_HI = SID_FREQ / 256;
			int SF_LOW = SID_FREQ - (256 * SF_HI);

			switch (Voice)
			{
			case 1:
				//set frequency of voice #1
				push_event(0, (Uint8)SF_LOW);
				push_event(1, (Uint8)SF_HI);
				SID_Voice1.FREQ_LO = SF_LOW;
				SID_Voice1.FREQ_HI = SF_HI;
				break;
			case 2:
				//set frequency of voice #2
				push_event(7, (Uint8)SF_LOW);
				push_event(8, (Uint8)SF_HI);
				SID_Voice2.FREQ_LO = SF_LOW;
				SID_Voice2.FREQ_HI = SF_HI;
				break;
			case 3:
				//set frequency of voice #3
				push_event(14, (Uint8)SF_LOW);
				push_event(15, (Uint8)SF_HI);
				SID_Voice3.FREQ_LO = SF_LOW;
				SID_Voice3.FREQ_HI = SF_HI;
				break;
			default:
				;
				//Error

			}
		}
		else {
			//post("SID (freq1) error! value out of range");
		}

	}
	void Sid::set_volume(Uint8 vol)
	{
		//vol is volume 0-15
		if ((vol >= 0) && (vol <= 15))
		{
			Uint8 m = SID_Voice1.FILTER; // Get Filter
			push_event(24, (Uint8)(vol + (m << 4)));
			SID_Voice1.VOLUME = vol; //store volume
		}
		else
		{
			//post("sid(volume): error!!! value out of range");
		}
	}
	void Sid::set_waveform(Uint8 Voice, Uint8 w)
	{
		Uint8 m = 0;
		switch (Voice)
		{
		case 1:
			m = SID_Voice1.CONTROL;	// Get Control-Nible
			if (w >= 8) m = m | 0b00001000; //Rausch-Bug
			push_event(4, (Uint8)((w << 4) + m));
			SID_Voice1.WAVEFORM = w;		//Store Waveform
			break;
		case 2:
			m = SID_Voice2.CONTROL;	// Get Control-Nible
			if (w >= 8) m = m | 0b00001000;
			push_event(11, (Uint8)((w << 4) + m));
			SID_Voice2.WAVEFORM = w;		//Store Waveform
			break;
		case 3:
			m = SID_Voice3.CONTROL;	// Get Control-Nible
			if (w >= 8) m = m | 0b00001000;
			push_event(18, (Uint8)((w << 4) + m));
			SID_Voice3.WAVEFORM = w;		//Store Waveform
			break;
		default:
			;
			//Error
		}
	}
	void Sid::set_ringmod(Uint8 Voice, bool Status)
	{
		switch (Voice)
		{
			case 1: 
				if (Status)
				{
					Uint8 r = SID_Voice1.CONTROL; //load backup
					Uint8 s = r | 0b00000100; //set Bit
					Uint8 t = SID_Voice1.WAVEFORM;
					Uint8 u = (t << 4) + s; //restore register
					push_event(4, (Uint8)u); //write to SID
					SID_Voice1.CONTROL = s; //do backup
				}
				else
				{
					Uint8 r = SID_Voice1.CONTROL; //load backup
					Uint8 s = r & 0b11111011; //clear bit
					Uint8 t = SID_Voice1.WAVEFORM;
					Uint8 u = (t << 4) + s; //restore register
					push_event(4, (Uint8)u); //write to SID
					SID_Voice1.CONTROL = s; //do backup

				}
			break;
					
			case 2:
				if (Status)
				{
					Uint8 r = SID_Voice2.CONTROL; //load backup
					Uint8 s = r | 0b00000100; //set Bit
					Uint8 t = SID_Voice2.WAVEFORM;
					Uint8 u = (t << 4) + s; //restore register
					push_event(11, (Uint8)u); //write to SID
					SID_Voice2.CONTROL = s; //do backup
				}
				else
				{
					Uint8 r = SID_Voice2.CONTROL; //load backup
					Uint8 s = r & 0b11111011; //clear bit
					Uint8 t = SID_Voice2.WAVEFORM;
					Uint8 u = (t << 4) + s; //restore register
					push_event(11, (Uint8)u); //write to SID
					SID_Voice2.CONTROL = s; //do backup
				}
			break;
		
			case 3: 
				if (Status)
				{
					Uint8 r = SID_Voice3.CONTROL; //load backup
					Uint8 s = r | 0b00000100; //set Bit
					Uint8 t = SID_Voice3.WAVEFORM;
					Uint8 u = (t << 4) + s; //restore register
					push_event(18, (Uint8)u); //write to SID
					SID_Voice3.CONTROL = s; //do backup
				}
				else
				{
					Uint8 r = SID_Voice3.CONTROL; //load backup
					Uint8 s = r & 0b11111011; //clear bit
					Uint8 t = SID_Voice3.WAVEFORM;
					Uint8 u = (t << 4) + s; //restore register
					push_event(18, (Uint8)u); //write to SID
					SID_Voice3.CONTROL = s; //do backup
				}
			break;

			default:
			
			break;
		}
	
	}
	void Sid::set_sync(Uint8 Voice, bool Status)
	{
		switch (Voice)
		{
		case 1:
			if (Status)
			{
				Uint8 r = SID_Voice1.CONTROL; //load backup
				Uint8 s = r | 0b00000010; //set Bit
				Uint8 t = SID_Voice1.WAVEFORM;
				Uint8 u = (t << 4) + s; //restore register
				push_event(4, (Uint8)u); //write to SID
				SID_Voice1.CONTROL = s; //do backup
			}
			else
			{
				Uint8 r = SID_Voice1.CONTROL; //load backup
				Uint8 s = r & 0b11111101; //clear bit
				Uint8 t = SID_Voice1.WAVEFORM;
				Uint8 u = (t << 4) + s; //restore register
				push_event(4, (Uint8)u); //write to SID
				SID_Voice1.CONTROL = s; //do backup
			}
			break;
		case 2:
			if (Status)
			{
				Uint8 r = SID_Voice2.CONTROL; //load backup
				Uint8 s = r | 0b00000010; //set Bit
				Uint8 t = SID_Voice2.WAVEFORM;
				Uint8 u = (t << 4) + s; //restore register
				push_event(11, (Uint8)u); //write to SID
				SID_Voice2.CONTROL = s; //do backup
			}
			else
			{
				Uint8 r = SID_Voice2.CONTROL; //load backup
				Uint8 s = r & 0b11111101; //clear bit
				Uint8 t = SID_Voice2.WAVEFORM;
				Uint8 u = (t << 4) + s; //restore register
				push_event(11, (Uint8)u); //write to SID
				SID_Voice2.CONTROL = s; //do backup
			}
			break;
		
		case 3: 
			if (Status)
			{
				Uint8 r = SID_Voice3.CONTROL; //load backup
				Uint8 s = r | 0b00000010; //set Bit
				Uint8 t = SID_Voice3.WAVEFORM;
				Uint8 u = (t << 4) + s; //restore register
				push_event(18, (Uint8)u); //write to SID
				SID_Voice3.CONTROL = s; //do backup
			}
			else 
			{
				Uint8 r = SID_Voice3.CONTROL; //load backup
				Uint8 s = r & 0b11111101; //clear bit
				Uint8 t = SID_Voice3.WAVEFORM;
				Uint8 u = (t << 4) + s; //restore register
				push_event(18, (Uint8)u); //write to SID
				SID_Voice3.CONTROL = s; //do backup
			}
			break;
		}
	}
	void Sid::settest(Uint8 Voice, bool Status)
	{
			switch (Voice)
			{
					case 1:
						if (Status)
						{
							Uint8 r = SID_Voice1.CONTROL; //load backup
							Uint8 s = r | 0b00001000; //set Bit
							Uint8 t = SID_Voice1.WAVEFORM;
							Uint8 u = (t << 4) + s; //restore register
							push_event(4, (Uint8)u); //write to SID
							SID_Voice1.CONTROL = s; //do backup
						}
						else
						{
							Uint8 r = SID_Voice1.CONTROL; //load backup
							Uint8 s = r & 0b11110111; //clear bit
							Uint8 t = SID_Voice1.WAVEFORM;
							Uint8 u = (t << 4) + s; //restore register
							push_event(4, (Uint8)u); //write to SID
							SID_Voice1.CONTROL = s; //do backup
						}
						break;
					case 2:
						if (Status)
						{
							Uint8 r = SID_Voice2.CONTROL; //load backup
							Uint8 s = r | 0b00001000; //set Bit
							Uint8 t = SID_Voice2.WAVEFORM;
							Uint8 u = (t << 4) + s; //restore register
							push_event(11, (Uint8)u); //write to SID
							SID_Voice2.CONTROL = s; //do backup
						}
						else
						{
							Uint8 r = SID_Voice2.CONTROL; //load backup
							Uint8 s = r & 0b11110111; //clear bit
							Uint8 t = SID_Voice2.WAVEFORM;
							Uint8 u = (t << 4) + s; //restore register
							push_event(11, (Uint8)u); //write to SID
							SID_Voice2.CONTROL = s; //do backup
						}
						break;
					case 3: 
						if (Status)
						{
							Uint8 r = SID_Voice3.CONTROL; //load backup
							Uint8 s = r | 0b00001000; //set Bit
							Uint8 t = SID_Voice3.WAVEFORM;
							Uint8 u = (t << 4) + s; //restore register
							push_event(18, (Uint8)u); //write to SID
							SID_Voice3.CONTROL = s; //do backup
						}
						else
						{
							Uint8 r = SID_Voice3.CONTROL; //load backup
							Uint8 s = r & 0b11110111; //clear bit
							Uint8 t = SID_Voice3.WAVEFORM;
							Uint8 u = (t << 4) + s; //restore register
							push_event(18, (Uint8)u); //write to SID
							SID_Voice3.CONTROL = s; //do backup
						}
						break;
			}
	}

	void Sid::play(Uint8 Voice)
	{
		Uint8 w = 0;
		Uint8 c = 0;

		switch (Voice)
		{
		case 1:
			w = SID_Voice1.WAVEFORM;	// Get Waveform-Nible
			c = SID_Voice1.CONTROL;
			c = c | 0b00000001;
			push_event(4, (Uint8)((w << 4) + (c)));
			SID_Voice1.CONTROL = c;
			break;
		case 2:
			w = SID_Voice2.WAVEFORM;	// Get Waveform-Nible
			c = SID_Voice2.CONTROL;
			c = c | 0b00000001;
			push_event(11, (Uint8)((w << 4) + (c)));
			SID_Voice2.CONTROL = c;
			break;
		case 3:
			w = SID_Voice3.WAVEFORM;	// Get Waveform-Nible
			c = SID_Voice3.CONTROL;
			c = c | 0b00000001;
			push_event(18, (Uint8)((w << 4) + (c)));
			SID_Voice3.CONTROL = c;
			break;
		default:
			;
			//Error
		}
	}
	void Sid::stop(Uint8 Voice)
	{
		Uint8 w = 0;
		Uint8 c = 0;
		switch (Voice)
		{
		case 1:
			w = SID_Voice1.WAVEFORM;	// Get Waveform-Nible
			c = SID_Voice1.CONTROL;
			c = c & 0b11111110;
			push_event(4, (Uint8)((w << 4) + (c)));
			SID_Voice1.CONTROL = c;
			break;
		case 2:
			w = SID_Voice2.WAVEFORM;	// Get Waveform-Nible
			c = SID_Voice2.CONTROL;
			c = c & 0b11111110;
			push_event(11, (Uint8)((w << 4) + (c)));
			SID_Voice2.CONTROL = c;
			break;
		case 3:
			w = SID_Voice3.WAVEFORM;	// Get Waveform-Nible
			c = SID_Voice3.CONTROL;
			c = c & 0b11111110;
			push_event(18, (Uint8)((w << 4) + (c)));
			SID_Voice3.CONTROL = c;
			break;
		default:
			;
			//Error
		}
	}

	void Sid::set_filterfreq(Uint16 freq)
	{
		if ((freq >= 0) && (freq <= 2047)) {
			//OK: n is a real frequency
			Uint16 m = (Uint16)freq;
			Uint16 LO = m & 0b0000000000000111;
			Uint16 HI = m >> 3;
			//set filterfrequency
			push_event(21, (Uint8)LO);
			push_event(22, (Uint8)HI);
			SID_Voice1.FIL_FREQ_LOW = LO;
			SID_Voice1.FIL_FREQ_HIGH = HI;
		}
		else {
			//post("sid(freq): error!!! value out of range");
		}
	}
	void Sid::set_filterres(Uint8 res)
	{
		if ((res >= 0) && (res <= 15))
		{
			Uint8 m = (Uint8)res;
			Uint8 o = SID_Voice1.FILT;
			Uint8 p = (Uint8)((m << 4) + o);
			push_event(23, (Uint8)p);
			SID_Voice1.RES = m;
		}
		else
		{
		//	post("sid(res): error!!! value out of range");
		}
	}
	void Sid::set_filterfilt(Uint8 filt)
	{
		if (filt >= 0 && filt <= 15)
		{
			Uint8 m = SID_Voice1.RES;	// Get res-Nible
			push_event(23, (Uint8)(filt + (m << 4)));
			SID_Voice1.FILT = filt;		//Store filt
		}
		else
		{
			//post("sid(filt): error!!! value out of range!");
		}
	}
	void Sid::set_filtermode(Uint8 fmode)
	{
		if (fmode >= 0 && fmode <= 15)
		{
			Uint8 m = SID_Voice1.VOLUME;	// Get vol-Nible
			push_event(24, (Uint8)((fmode << 4) + m));
			SID_Voice1.FILTER = fmode;		//Store filt
		}
		else 
		{
			//post("sid(mode): error!!! value out of range!");
		}
	}
