/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.1.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AiassAudioProcessorEditor  : public AudioProcessorEditor,
                                   private Timer,
                                   public juce::ComboBox::Listener
{
public:
    //==============================================================================
    AiassAudioProcessorEditor (AiassAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~AiassAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
	typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
	typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;

	//==============================================================================
	AiassAudioProcessor& getProcessor() const
	{
		return static_cast<AiassAudioProcessor&> (processor);
	}

	void set_LED_On(void) {
		Led->setState(juce::Button::buttonDown);
	}
	void set_LED_Off(void) {
		Led->setState(juce::Button::buttonNormal);
	}

	void timerCallback() override;


    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* redledoff_png;
    static const int redledoff_pngSize;
    static const char* redledon_png;
    static const int redledon_pngSize;
    static const char* reset_png;
    static const int reset_pngSize;
    static const char* aiasshintergrund_png;
    static const int aiasshintergrund_pngSize;
    static const char* init_png;
    static const int init_pngSize;
    static const char* sidblaster02_png;
    static const int sidblaster02_pngSize;
    static const char* kippschalter_off_c_png;
    static const int kippschalter_off_c_pngSize;
    static const char* kippschalter_on_c_png;
    static const int kippschalter_on_c_pngSize;
    static const char* typenschild_a_png;
    static const int typenschild_a_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.

       //AiassAudioProcessor& processor;
	   AudioProcessorValueTreeState& valueTreeState;
	   std::unique_ptr<SliderAttachment>SidVolAttachment;
       std::unique_ptr<ButtonAttachment>VelvolAttachment;
	   std::unique_ptr<SliderAttachment>Attack1Attachment;
	   std::unique_ptr<SliderAttachment>Attack2Attachment;
	   std::unique_ptr<SliderAttachment>Attack3Attachment;
	   std::unique_ptr<SliderAttachment>Decay1Attachment;
	   std::unique_ptr<SliderAttachment>Decay2Attachment;
	   std::unique_ptr<SliderAttachment>Decay3Attachment;
	   std::unique_ptr<SliderAttachment>Sustain1Attachment;
	   std::unique_ptr<SliderAttachment>Sustain2Attachment;
	   std::unique_ptr<SliderAttachment>Sustain3Attachment;
	   std::unique_ptr<SliderAttachment>Release1Attachment;
	   std::unique_ptr<SliderAttachment>Release2Attachment;
	   std::unique_ptr<SliderAttachment>Release3Attachment;
	   std::unique_ptr<SliderAttachment>Pulsw1Attachment;
	   std::unique_ptr<SliderAttachment>Pulsw2Attachment;
	   std::unique_ptr<SliderAttachment>Pulsw3Attachment;
	   std::unique_ptr<ButtonAttachment>Voice1Attachment;
	   std::unique_ptr<ButtonAttachment>Voice2Attachment;
	   std::unique_ptr<ButtonAttachment>Voice3Attachment;
	   std::unique_ptr<SliderAttachment>Octave1Attachment;
	   std::unique_ptr<SliderAttachment>Octave2Attachment;
	   std::unique_ptr<SliderAttachment>Octave3Attachment;
	   std::unique_ptr<SliderAttachment>Semi1Attachment;
	   std::unique_ptr<SliderAttachment>Semi2Attachment;
	   std::unique_ptr<SliderAttachment>Semi3Attachment;
	   std::unique_ptr<SliderAttachment>Cent1Attachment;
	   std::unique_ptr<SliderAttachment>Cent2Attachment;
	   std::unique_ptr<SliderAttachment>Cent3Attachment;
	   std::unique_ptr<ButtonAttachment>Noise1Attachment;
	   std::unique_ptr<ButtonAttachment>Noise2Attachment;
	   std::unique_ptr<ButtonAttachment>Noise3Attachment;
	   std::unique_ptr<ButtonAttachment>Pulse1Attachment;
	   std::unique_ptr<ButtonAttachment>Pulse2Attachment;
	   std::unique_ptr<ButtonAttachment>Pulse3Attachment;
	   std::unique_ptr<ButtonAttachment>Saw1Attachment;
	   std::unique_ptr<ButtonAttachment>Saw2Attachment;
	   std::unique_ptr<ButtonAttachment>Saw3Attachment;
	   std::unique_ptr<ButtonAttachment>Tria1Attachment;
	   std::unique_ptr<ButtonAttachment>Tria2Attachment;
	   std::unique_ptr<ButtonAttachment>Tria3Attachment;
	   std::unique_ptr<ButtonAttachment>Ringmod1Attachment;
	   std::unique_ptr<ButtonAttachment>Ringmod2Attachment;
	   std::unique_ptr<ButtonAttachment>Ringmod3Attachment;
	   std::unique_ptr<ButtonAttachment>Sync1Attachment;
	   std::unique_ptr<ButtonAttachment>Sync2Attachment;
	   std::unique_ptr<ButtonAttachment>Sync3Attachment;
	   std::unique_ptr<SliderAttachment>FilterfreqAttachment;
	   std::unique_ptr<SliderAttachment>ResonanceAttachment;
	   std::unique_ptr<ButtonAttachment>FilterscaleAttachment;
	   std::unique_ptr<ButtonAttachment>Filter1Attachment;
	   std::unique_ptr<ButtonAttachment>Filter2Attachment;
	   std::unique_ptr<ButtonAttachment>Filter3Attachment;
	   std::unique_ptr<ButtonAttachment>FilterinAttachment;
	   std::unique_ptr<ButtonAttachment>FilterLPAttachment;
	   std::unique_ptr<ButtonAttachment>FilterBPAttachment;
	   std::unique_ptr<ButtonAttachment>FilterHPAttachment;
	   std::unique_ptr<ButtonAttachment>Filter3OFFAttachment;
	   std::unique_ptr<ComboBoxAttachment>LegatoModeAttachment;
	   std::unique_ptr<ComboBoxAttachment>NotePriorityModeAttachment;
       std::unique_ptr<ComboBoxAttachment>MidiChannelAttachment;
       std::unique_ptr<ButtonAttachment>ResetAttachment;
       std::unique_ptr<ButtonAttachment>InitAttachment;
       std::unique_ptr<ButtonAttachment>LinkAttachment;
       std::unique_ptr<SliderAttachment>PitchbendAttachment;
       std::unique_ptr<ButtonAttachment>Bend1Attachment;
       std::unique_ptr<ButtonAttachment>Bend2Attachment;
       std::unique_ptr<ButtonAttachment>Bend3Attachment;
       std::unique_ptr<ButtonAttachment>ModeAttachment;

	   TooltipWindow tooltipWindow; // to add tooltips to an application, you
									// just need to create one of these and leave it
									// there to do its work..

	   Sid * m_sid;

	   int hz1 = 0; //for error-LED flashing

       bool Link_State = false;
       bool Mode_State = false;


  public:
       juce::MidiKeyboardComponent keyboardComponent;

  private:

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> tonegroup;
    std::unique_ptr<juce::GroupComponent> semigroup;
    std::unique_ptr<juce::GroupComponent> octavegroup;
    std::unique_ptr<juce::Slider> Semi1;
    std::unique_ptr<juce::Slider> Cent1;
    std::unique_ptr<juce::Slider> Attack1;
    std::unique_ptr<juce::Slider> Decay1;
    std::unique_ptr<juce::Slider> Sustain1;
    std::unique_ptr<juce::GroupComponent> soundgroup;
    std::unique_ptr<juce::Slider> Release1;
    std::unique_ptr<juce::Slider> Octave1;
    std::unique_ptr<juce::GroupComponent> releasegroup;
    std::unique_ptr<juce::GroupComponent> sustaingroup;
    std::unique_ptr<juce::GroupComponent> decaygroup;
    std::unique_ptr<juce::GroupComponent> attackgroup;
    std::unique_ptr<juce::GroupComponent> centgroup;
    std::unique_ptr<juce::Slider> Decay2;
    std::unique_ptr<juce::GroupComponent> pulsewidhgroup;
    std::unique_ptr<juce::Slider> Pulsew1;
    std::unique_ptr<juce::GroupComponent> controlgroup;
    std::unique_ptr<juce::GroupComponent> waveformgroup;
    std::unique_ptr<juce::GroupComponent> filtergroup;
    std::unique_ptr<juce::Slider> sidvolume;
    std::unique_ptr<juce::Slider> Octave2;
    std::unique_ptr<juce::Slider> Octave3;
    std::unique_ptr<juce::Slider> Semi2;
    std::unique_ptr<juce::Slider> Semi3;
    std::unique_ptr<juce::Slider> Cent2;
    std::unique_ptr<juce::Slider> Cent3;
    std::unique_ptr<juce::Slider> Attack2;
    std::unique_ptr<juce::Slider> Attack3;
    std::unique_ptr<juce::Slider> Decay3;
    std::unique_ptr<juce::Slider> Sustain2;
    std::unique_ptr<juce::Slider> Sustain3;
    std::unique_ptr<juce::Slider> Release2;
    std::unique_ptr<juce::Slider> Release3;
    std::unique_ptr<juce::Slider> Pulsew2;
    std::unique_ptr<juce::Slider> Pulsew3;
    std::unique_ptr<juce::ToggleButton> Velvol;
    std::unique_ptr<juce::ComboBox> legatomode;
    std::unique_ptr<juce::ComboBox> noteprioritymode;
    std::unique_ptr<juce::HyperlinkButton> hyperlinkButton;
    std::unique_ptr<juce::ToggleButton> Filter1;
    std::unique_ptr<juce::ToggleButton> Filter2;
    std::unique_ptr<juce::ToggleButton> Filter3off;
    std::unique_ptr<juce::ToggleButton> Filter3;
    std::unique_ptr<juce::ToggleButton> Filterin;
    std::unique_ptr<juce::ToggleButton> Filterlp;
    std::unique_ptr<juce::ToggleButton> Filterhp;
    std::unique_ptr<juce::ToggleButton> Filterbp;
    std::unique_ptr<juce::ToggleButton> Filterscale;
    std::unique_ptr<juce::Slider> CutOff;
    std::unique_ptr<juce::Slider> Resonace;
    std::unique_ptr<juce::ToggleButton> Noise1;
    std::unique_ptr<juce::ToggleButton> Noise2;
    std::unique_ptr<juce::ToggleButton> Noise3;
    std::unique_ptr<juce::ToggleButton> Pulse1;
    std::unique_ptr<juce::ToggleButton> Pulse2;
    std::unique_ptr<juce::ToggleButton> Pulse3;
    std::unique_ptr<juce::ToggleButton> Saw1;
    std::unique_ptr<juce::ToggleButton> Saw2;
    std::unique_ptr<juce::ToggleButton> Saw3;
    std::unique_ptr<juce::ToggleButton> Tria1;
    std::unique_ptr<juce::ToggleButton> Tria2;
    std::unique_ptr<juce::ToggleButton> Tria3;
    std::unique_ptr<juce::ToggleButton> Ringmod1;
    std::unique_ptr<juce::ToggleButton> Ringmod2;
    std::unique_ptr<juce::ToggleButton> Ringmod3;
    std::unique_ptr<juce::ToggleButton> Sync1;
    std::unique_ptr<juce::ToggleButton> Sync2;
    std::unique_ptr<juce::ToggleButton> Sync3;
    std::unique_ptr<juce::ToggleButton> Voice2;
    std::unique_ptr<juce::ToggleButton> Voice3;
    std::unique_ptr<juce::ImageButton> Led;
    std::unique_ptr<juce::ComboBox> midichannel;
    std::unique_ptr<juce::ToggleButton> link_button;
    std::unique_ptr<juce::ToggleButton> Voice1;
    std::unique_ptr<juce::ImageButton> reset_button;
    std::unique_ptr<juce::GroupComponent> keyboard_group;
    std::unique_ptr<juce::Slider> Pitchbend;
    std::unique_ptr<juce::ImageButton> init_button;
    std::unique_ptr<juce::ToggleButton> Bend1;
    std::unique_ptr<juce::ToggleButton> Bend2;
    std::unique_ptr<juce::ToggleButton> Bend3;
    std::unique_ptr<juce::ImageButton> mode__imageButton;
    std::unique_ptr<juce::Label> mono__label;
    std::unique_ptr<juce::Label> poly__label2;
    juce::Image cachedImage_aiasshintergrund_png_1;
    juce::Image cachedImage_typenschild_a_png_2;
    juce::Image cachedImage_sidblaster02_png_3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AiassAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...



//[/EndFile]

