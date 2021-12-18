/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Sid.h"
#include <math.h>

//==============================================================================


class AiassAudioProcessor : public AudioProcessor
	, private AudioProcessorValueTreeState::Listener

{
public:
	//==============================================================================
	AiassAudioProcessor();
	~AiassAudioProcessor();


	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(AudioSampleBuffer&, MidiBuffer&) override;

	Sid* getSid() {
		return m_sid;
	}

	bool LED = false;
	bool LINK = false;
	bool RESET = false;
	bool INIT = false;
	float PITCHBEND = 0.0f;
	bool MIDIBENDACTIVE = false;
	bool MODE = false;

	AudioProcessorValueTreeState parameters;

	//==============================================================================
	AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const String getProgramName(int index) override;
	void changeProgramName(int index, const String& newName) override;

	//==============================================================================
	void getStateInformation(MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

private:
	void parameterChanged(const String& parameterID, float newValue) override;
	void setWaveformStatus(BYTE Voice, BYTE Waveform, bool State);
private:
	void setFilterStatus(BYTE FilterStatusBit, bool State);
	void setFilterMode(BYTE FilterModeBit, bool State);
	void noteOn(MidiMessage mm, bool triggernote, int VoiceNo);
	void noteOff(MidiMessage mm, int VoiceNo);
	void handlepitch(bool newnote);
	float scaleInterval(float  Wert, float minActualInterval, float maxActualInterval, float minDesiredInterval, float maxDesiredInterval);

	//==============================================================================

	enum PlayModes { Retrigger, Legato, LastStep };
	enum PriorityModes { LastNote, HighNote, LowNote };

	Sid* m_sid;

	bool VOICE1 = true;
	bool VOICE2 = true;
	bool VOICE3 = true;
	bool V1isPlaying = false;
	bool V2isPlaying = false;
	bool V3isPlaying = false;
	int OCTAVE1 = 0;
	int OCTAVE2 = 0;
	int OCTAVE3 = 0;
	int SEMI1 = 0;
	int SEMI2 = 0;
	int SEMI3 = 0;
	float CENT1 = 0;
	float CENT2 = 0;
	float CENT3 = 0;

	bool TRIA1 = false;
	bool SAW1 = false;
	bool PULSE1 = true;
	bool NOISE1 = false;
	bool TRIA2 = false;
	bool SAW2 = false;
	bool PULSE2 = true;
	bool NOISE2 = false;
	bool TRIA3 = false;
	bool SAW3 = false;
	bool PULSE3 = true;
	bool NOISE3 = false;

	bool RINGMOD1 = false;
	bool RINGMOD2 = false;
	bool RINGMOD3 = false;
	bool SYNC1 = false;
	bool SYNC2 = false;
	bool SYNC3 = false;

	int FILTERFREQ = 0;
	int FILTERRES = 0;

	bool FILTERSCALE = false;

	bool FILTER1 = false;
	bool FILTER2 = false;
	bool FILTER3 = false;
	bool FILTERIN = false;

	bool LOWPASS = false;
	bool BANDPASS = false;
	bool HIGHPASS = false;
	bool F3OFF = false;

	bool VELVOL = false;

	bool BEND1 = true;
	bool BEND2 = true;
	bool BEND3 = true;

	int SIDVOL = 15;
	int ATTACK1 = 1;
	int ATTACK2 = 1;
	int ATTACK3 = 1;
	int DECAY1 = 7;
	int DECAY2 = 7;
	int DECAY3 = 7;
	int SUSTAIN1 = 7;
	int SUSTAIN2 = 7;
	int SUSTAIN3 = 7;
	int RELEASE1 = 7;
	int RELEASE2 = 7;
	int RELEASE3 = 7;
	int PULSEW1 = 1024;
	int PULSEW2 = 1024;
	int PULSEW3 = 1024;

	double MyFreq1 = 0.0;
	double MyFreq2 = 0.0;
	double MyFreq3 = 0.0;
	double newFreq1 = 0.0;
	double newFreq2 = 0.0;
	double newFreq3 = 0.0;

	PlayModes LEGATOMODE = Retrigger;
	PriorityModes NOTEPRIORITYMODE = LastNote;

	int	MIDICHANNEL = 0;

	Array<MidiMessage> heldNotesList{};
	MidiMessage isPlaying;

	struct SIDStateVoice {
		int VoiceNo;
		MidiMessage PlayingNote;
	};

	Array <SIDStateVoice> SIDSTATE {};
		
	int MyProgram = 0;
	
	public:
	juce::MidiKeyboardState keyboardState; 
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AiassAudioProcessor)
};
