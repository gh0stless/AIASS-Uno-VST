/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.1.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...


//[/MiscUserDefs]

//==============================================================================
AiassAudioProcessorEditor::AiassAudioProcessorEditor (AiassAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p),
      valueTreeState (vts),
      m_sid(p.getSid()),
      keyboardComponent (p.keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
    //[Constructor_pre] You can add your own custom stuff here..


    //[/Constructor_pre]

    tonegroup.reset (new juce::GroupComponent ("tone group",
                                               TRANS("Tone")));
    addAndMakeVisible (tonegroup.get());
    tonegroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    tonegroup->setColour (juce::GroupComponent::textColourId, juce::Colours::yellow);

    tonegroup->setBounds (8, 72, 230, 218);

    semigroup.reset (new juce::GroupComponent ("semi group",
                                               TRANS("Sem")));
    addAndMakeVisible (semigroup.get());
    semigroup->setTextLabelPosition (juce::Justification::centredLeft);
    semigroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::brown);
    semigroup->setColour (juce::GroupComponent::textColourId, juce::Colour (0xff239a0f));

    semigroup->setBounds (118, 82, 52, 204);

    octavegroup.reset (new juce::GroupComponent ("octave group",
                                                 TRANS("Oct")));
    addAndMakeVisible (octavegroup.get());
    octavegroup->setTextLabelPosition (juce::Justification::centredLeft);
    octavegroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::brown);
    octavegroup->setColour (juce::GroupComponent::textColourId, juce::Colour (0xff239a0f));

    octavegroup->setBounds (60, 82, 52, 204);

    Semi1.reset (new juce::Slider ("semi1 slider"));
    addAndMakeVisible (Semi1.get());
    Semi1->setTooltip (TRANS("Semitone1 Up/Down (CC79)\n"));
    Semi1->setRange (-12, 12, 1);
    Semi1->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Semi1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Semi1->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Semi1->setBounds (112, 90, 66, 66);

    Cent1.reset (new juce::Slider ("cent1 slider"));
    addAndMakeVisible (Cent1.get());
    Cent1->setTooltip (TRANS("Cent1 Up/Down (CC70)\n"));
    Cent1->setRange (-100, 100, 1);
    Cent1->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Cent1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Cent1->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Cent1->setBounds (170, 90, 66, 66);

    Attack1.reset (new juce::Slider ("attack1 slider"));
    addAndMakeVisible (Attack1.get());
    Attack1->setTooltip (TRANS("Attack 1 (CC73)"));
    Attack1->setRange (0, 15, 1);
    Attack1->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Attack1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Attack1->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Attack1->setBounds (240, 90, 66, 66);

    Decay1.reset (new juce::Slider ("decay1 slider"));
    addAndMakeVisible (Decay1.get());
    Decay1->setTooltip (TRANS("Decay 1 (CC75)"));
    Decay1->setRange (0, 15, 1);
    Decay1->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Decay1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Decay1->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Decay1->setBounds (300, 90, 66, 66);

    Sustain1.reset (new juce::Slider ("sustain1 slider"));
    addAndMakeVisible (Sustain1.get());
    Sustain1->setTooltip (TRANS("Sustain 1 (CC76)"));
    Sustain1->setRange (0, 15, 1);
    Sustain1->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Sustain1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Sustain1->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Sustain1->setBounds (360, 90, 66, 66);

    soundgroup.reset (new juce::GroupComponent ("sound group",
                                                TRANS("Sound")));
    addAndMakeVisible (soundgroup.get());
    soundgroup->setTextLabelPosition (juce::Justification::centredLeft);
    soundgroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    soundgroup->setColour (juce::GroupComponent::textColourId, juce::Colours::yellow);

    soundgroup->setBounds (238, 72, 252, 218);

    Release1.reset (new juce::Slider ("release1 slider"));
    addAndMakeVisible (Release1.get());
    Release1->setTooltip (TRANS("Release 1 (CC72)"));
    Release1->setRange (0, 15, 1);
    Release1->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Release1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Release1->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Release1->setBounds (420, 90, 66, 66);

    Octave1.reset (new juce::Slider ("octave1 slider"));
    addAndMakeVisible (Octave1.get());
    Octave1->setTooltip (TRANS("Octave1 Up/Down (CC78)\n"));
    Octave1->setRange (-4, 4, 1);
    Octave1->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Octave1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Octave1->setColour (juce::Slider::textBoxTextColourId, juce::Colours::white);
    Octave1->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Octave1->setBounds (54, 90, 66, 66);

    releasegroup.reset (new juce::GroupComponent ("release group",
                                                  TRANS("R")));
    addAndMakeVisible (releasegroup.get());
    releasegroup->setTextLabelPosition (juce::Justification::centred);
    releasegroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::brown);
    releasegroup->setColour (juce::GroupComponent::textColourId, juce::Colour (0xff239a0f));

    releasegroup->setBounds (427, 82, 52, 204);

    sustaingroup.reset (new juce::GroupComponent ("sustain group",
                                                  TRANS("S")));
    addAndMakeVisible (sustaingroup.get());
    sustaingroup->setTextLabelPosition (juce::Justification::centred);
    sustaingroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::brown);
    sustaingroup->setColour (juce::GroupComponent::textColourId, juce::Colour (0xff239a0f));

    sustaingroup->setBounds (367, 82, 52, 204);

    decaygroup.reset (new juce::GroupComponent ("decay group",
                                                TRANS("D")));
    addAndMakeVisible (decaygroup.get());
    decaygroup->setTextLabelPosition (juce::Justification::centred);
    decaygroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::brown);
    decaygroup->setColour (juce::GroupComponent::textColourId, juce::Colour (0xff239a0f));

    decaygroup->setBounds (307, 82, 52, 204);

    attackgroup.reset (new juce::GroupComponent ("attack group",
                                                 TRANS("A")));
    addAndMakeVisible (attackgroup.get());
    attackgroup->setTextLabelPosition (juce::Justification::centred);
    attackgroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::brown);
    attackgroup->setColour (juce::GroupComponent::textColourId, juce::Colour (0xff239a0f));

    attackgroup->setBounds (247, 82, 52, 204);

    centgroup.reset (new juce::GroupComponent ("cent group",
                                               TRANS("Cen")));
    addAndMakeVisible (centgroup.get());
    centgroup->setTextLabelPosition (juce::Justification::centredLeft);
    centgroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::brown);
    centgroup->setColour (juce::GroupComponent::textColourId, juce::Colour (0xff239a0f));

    centgroup->setBounds (176, 82, 52, 204);

    Decay2.reset (new juce::Slider ("decay2 slider"));
    addAndMakeVisible (Decay2.get());
    Decay2->setTooltip (TRANS("Decay 2 (CC21)"));
    Decay2->setRange (0, 15, 1);
    Decay2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Decay2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Decay2->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Decay2->setBounds (300, 152, 66, 66);

    pulsewidhgroup.reset (new juce::GroupComponent ("pulsewidh group",
                                                    TRANS("Pulse")));
    addAndMakeVisible (pulsewidhgroup.get());
    pulsewidhgroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    pulsewidhgroup->setColour (juce::GroupComponent::textColourId, juce::Colours::yellow);

    pulsewidhgroup->setBounds (490, 72, 60, 218);

    Pulsew1.reset (new juce::Slider ("pulsew1 slider"));
    addAndMakeVisible (Pulsew1.get());
    Pulsew1->setTooltip (TRANS("Pulse width 1 (CC77)"));
    Pulsew1->setRange (1, 4094, 1);
    Pulsew1->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Pulsew1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Pulsew1->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Pulsew1->setBounds (487, 90, 66, 66);

    controlgroup.reset (new juce::GroupComponent ("control group",
                                                  TRANS("Control")));
    addAndMakeVisible (controlgroup.get());
    controlgroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    controlgroup->setColour (juce::GroupComponent::textColourId, juce::Colours::yellow);

    controlgroup->setBounds (380, 296, 631, 148);

    waveformgroup.reset (new juce::GroupComponent ("waveform group",
                                                   TRANS("Waveform")));
    addAndMakeVisible (waveformgroup.get());
    waveformgroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    waveformgroup->setColour (juce::GroupComponent::textColourId, juce::Colours::yellow);

    waveformgroup->setBounds (550, 72, 460, 218);

    filtergroup.reset (new juce::GroupComponent ("filter group",
                                                 TRANS("Filter")));
    addAndMakeVisible (filtergroup.get());
    filtergroup->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    filtergroup->setColour (juce::GroupComponent::textColourId, juce::Colours::yellow);

    filtergroup->setBounds (8, 296, 372, 148);

    sidvolume.reset (new juce::Slider ("sidvolume slider"));
    addAndMakeVisible (sidvolume.get());
    sidvolume->setTooltip (TRANS("SID-Volume (CC7)"));
    sidvolume->setRange (0, 15, 1);
    sidvolume->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    sidvolume->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    sidvolume->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    sidvolume->setBounds (574, 300, 66, 66);

    Octave2.reset (new juce::Slider ("octave2 slider"));
    addAndMakeVisible (Octave2.get());
    Octave2->setTooltip (TRANS("Octave2 Up/Down (CC85)\n"));
    Octave2->setRange (-4, 4, 1);
    Octave2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Octave2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Octave2->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Octave2->setBounds (54, 152, 66, 66);

    Octave3.reset (new juce::Slider ("octave3 slider"));
    addAndMakeVisible (Octave3.get());
    Octave3->setTooltip (TRANS("Octave3 Up/Down (CC88)\n"));
    Octave3->setRange (-4, 4, 1);
    Octave3->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Octave3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Octave3->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Octave3->setBounds (54, 212, 66, 66);

    Semi2.reset (new juce::Slider ("semi2 slider"));
    addAndMakeVisible (Semi2.get());
    Semi2->setTooltip (TRANS("Semitone2 Up/Down (CC86)\n"));
    Semi2->setRange (-12, 12, 1);
    Semi2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Semi2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Semi2->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Semi2->setBounds (112, 152, 66, 66);

    Semi3.reset (new juce::Slider ("semi3 slider"));
    addAndMakeVisible (Semi3.get());
    Semi3->setTooltip (TRANS("Semitone3 Up/Down (CC89)\n"));
    Semi3->setRange (-12, 12, 1);
    Semi3->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Semi3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Semi3->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Semi3->setBounds (112, 212, 66, 66);

    Cent2.reset (new juce::Slider ("cent2 slider"));
    addAndMakeVisible (Cent2.get());
    Cent2->setTooltip (TRANS("Cent2 Up/Down (CC87)\n"));
    Cent2->setRange (-100, 100, 1);
    Cent2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Cent2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Cent2->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Cent2->setBounds (170, 152, 66, 66);

    Cent3.reset (new juce::Slider ("cent3 slider"));
    addAndMakeVisible (Cent3.get());
    Cent3->setTooltip (TRANS("Cent3 Up/Down (CC90)\n"));
    Cent3->setRange (-100, 100, 1);
    Cent3->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Cent3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Cent3->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Cent3->setBounds (170, 212, 66, 66);

    Attack2.reset (new juce::Slider ("attack2 slider"));
    addAndMakeVisible (Attack2.get());
    Attack2->setTooltip (TRANS("Attack 2 (CC20)"));
    Attack2->setRange (0, 15, 1);
    Attack2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Attack2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Attack2->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Attack2->setBounds (240, 152, 66, 66);

    Attack3.reset (new juce::Slider ("attack3 slider"));
    addAndMakeVisible (Attack3.get());
    Attack3->setTooltip (TRANS("Attack 3 (CC25)"));
    Attack3->setRange (0, 15, 1);
    Attack3->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Attack3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Attack3->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Attack3->setBounds (240, 212, 66, 66);

    Decay3.reset (new juce::Slider ("decay3 slider"));
    addAndMakeVisible (Decay3.get());
    Decay3->setTooltip (TRANS("Decay 3 (CC26)"));
    Decay3->setRange (0, 15, 1);
    Decay3->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Decay3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Decay3->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Decay3->setBounds (300, 212, 66, 66);

    Sustain2.reset (new juce::Slider ("sustain2 slider"));
    addAndMakeVisible (Sustain2.get());
    Sustain2->setTooltip (TRANS("Sustain 2 (CC22)"));
    Sustain2->setRange (0, 15, 1);
    Sustain2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Sustain2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Sustain2->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Sustain2->setBounds (360, 152, 66, 66);

    Sustain3.reset (new juce::Slider ("sustain3 slider"));
    addAndMakeVisible (Sustain3.get());
    Sustain3->setTooltip (TRANS("Sustain 3 (CC27)"));
    Sustain3->setRange (0, 15, 1);
    Sustain3->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Sustain3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Sustain3->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Sustain3->setBounds (360, 212, 66, 66);

    Release2.reset (new juce::Slider ("release2 slider"));
    addAndMakeVisible (Release2.get());
    Release2->setTooltip (TRANS("Release 2 (CC23)"));
    Release2->setRange (0, 15, 1);
    Release2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Release2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Release2->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Release2->setBounds (420, 152, 66, 66);

    Release3.reset (new juce::Slider ("release3 slider"));
    addAndMakeVisible (Release3.get());
    Release3->setTooltip (TRANS("Release 3 (CC28)"));
    Release3->setRange (0, 15, 1);
    Release3->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Release3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Release3->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Release3->setBounds (420, 212, 66, 66);

    Pulsew2.reset (new juce::Slider ("pulsew2 slider"));
    addAndMakeVisible (Pulsew2.get());
    Pulsew2->setTooltip (TRANS("Pulse width 2 (CC24)"));
    Pulsew2->setRange (1, 4094, 1);
    Pulsew2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Pulsew2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Pulsew2->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Pulsew2->setBounds (487, 152, 66, 66);

    Pulsew3.reset (new juce::Slider ("pulsew3 slider"));
    addAndMakeVisible (Pulsew3.get());
    Pulsew3->setTooltip (TRANS("Pulse width 3 (CC29)"));
    Pulsew3->setRange (1, 4094, 1);
    Pulsew3->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Pulsew3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Pulsew3->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Pulsew3->setBounds (487, 212, 66, 66);

    Velvol.reset (new juce::ToggleButton ("Vel2Vol button"));
    addAndMakeVisible (Velvol.get());
    Velvol->setTooltip (TRANS("maps Velocity to Volume"));
    Velvol->setButtonText (TRANS("Vel2Vol"));
    Velvol->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Velvol->setBounds (637, 308, 66, 30);

    legatomode.reset (new juce::ComboBox ("legatomode"));
    addAndMakeVisible (legatomode.get());
    legatomode->setTooltip (TRANS("play mode"));
    legatomode->setEditableText (false);
    legatomode->setJustificationType (juce::Justification::centredLeft);
    legatomode->setTextWhenNothingSelected (juce::String());
    legatomode->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    legatomode->addItem (TRANS("Retrigger"), 1);
    legatomode->addItem (TRANS("Legato"), 2);
    legatomode->addItem (TRANS("Last Step"), 3);
    legatomode->addListener (this);

    legatomode->setBounds (401, 360, 150, 24);

    noteprioritymode.reset (new juce::ComboBox ("noteprioritymode"));
    addAndMakeVisible (noteprioritymode.get());
    noteprioritymode->setTooltip (TRANS("note priority"));
    noteprioritymode->setEditableText (false);
    noteprioritymode->setJustificationType (juce::Justification::centredLeft);
    noteprioritymode->setTextWhenNothingSelected (juce::String());
    noteprioritymode->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    noteprioritymode->addItem (TRANS("Last Note"), 1);
    noteprioritymode->addItem (TRANS("High Note"), 2);
    noteprioritymode->addItem (TRANS("Low Note"), 3);
    noteprioritymode->addListener (this);

    noteprioritymode->setBounds (401, 400, 150, 24);

    hyperlinkButton.reset (new juce::HyperlinkButton (TRANS("crazy-midi.de"),
                                                      URL ("http://www.crazy-midi.de")));
    addAndMakeVisible (hyperlinkButton.get());
    hyperlinkButton->setTooltip (TRANS("http://www.crazy-midi.de"));
    hyperlinkButton->setButtonText (TRANS("crazy-midi.de"));
    hyperlinkButton->setColour (juce::HyperlinkButton::textColourId, juce::Colours::green);

    hyperlinkButton->setBounds (893, 506, 150, 24);

    Filter1.reset (new juce::ToggleButton ("Filer1 toggle button"));
    addAndMakeVisible (Filter1.get());
    Filter1->setTooltip (TRANS("Voice 1 to Filter"));
    Filter1->setButtonText (TRANS("1"));
    Filter1->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Filter1->setBounds (204, 331, 66, 30);

    Filter2.reset (new juce::ToggleButton ("Filter2 toggle button"));
    addAndMakeVisible (Filter2.get());
    Filter2->setTooltip (TRANS("Voice 2 to Filter"));
    Filter2->setButtonText (TRANS("2"));
    Filter2->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Filter2->setBounds (148, 331, 66, 30);

    Filter3off.reset (new juce::ToggleButton ("3off toggle button"));
    addAndMakeVisible (Filter3off.get());
    Filter3off->setTooltip (TRANS("Mute Voice 3"));
    Filter3off->setButtonText (TRANS("3off"));
    Filter3off->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Filter3off->setBounds (16, 381, 66, 30);

    Filter3.reset (new juce::ToggleButton ("Filter3 toggle button"));
    addAndMakeVisible (Filter3.get());
    Filter3->setTooltip (TRANS("Voice 3 to Filter"));
    Filter3->setButtonText (TRANS("3"));
    Filter3->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Filter3->setBounds (82, 331, 66, 30);

    Filterin.reset (new juce::ToggleButton ("FilterIn toggle button"));
    addAndMakeVisible (Filterin.get());
    Filterin->setTooltip (TRANS("extern In"));
    Filterin->setButtonText (TRANS("in"));
    Filterin->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Filterin->setBounds (16, 331, 66, 30);

    Filterlp.reset (new juce::ToggleButton ("lowpass toggle button"));
    addAndMakeVisible (Filterlp.get());
    Filterlp->setTooltip (TRANS("Low Pass"));
    Filterlp->setButtonText (TRANS("LP"));
    Filterlp->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Filterlp->setBounds (204, 381, 66, 30);

    Filterhp.reset (new juce::ToggleButton ("high pass toggle button"));
    addAndMakeVisible (Filterhp.get());
    Filterhp->setTooltip (TRANS("High Pass"));
    Filterhp->setButtonText (TRANS("HP"));
    Filterhp->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Filterhp->setBounds (82, 381, 66, 30);

    Filterbp.reset (new juce::ToggleButton ("band pass toggle button"));
    addAndMakeVisible (Filterbp.get());
    Filterbp->setTooltip (TRANS("Band Pass"));
    Filterbp->setButtonText (TRANS("BP"));
    Filterbp->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Filterbp->setBounds (148, 381, 66, 30);

    Filterscale.reset (new juce::ToggleButton ("scale toggle button"));
    addAndMakeVisible (Filterscale.get());
    Filterscale->setTooltip (TRANS("scales filterfreq. to 0-71"));
    Filterscale->setButtonText (TRANS("scale"));
    Filterscale->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Filterscale->setBounds (310, 381, 70, 30);

    CutOff.reset (new juce::Slider ("cutoff slider"));
    addAndMakeVisible (CutOff.get());
    CutOff->setTooltip (TRANS("Cutoff (CC74)"));
    CutOff->setRange (0, 2047, 1);
    CutOff->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    CutOff->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    CutOff->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    CutOff->setBounds (250, 372, 66, 66);

    Resonace.reset (new juce::Slider ("resonance slider"));
    addAndMakeVisible (Resonace.get());
    Resonace->setTooltip (TRANS("Resonance (CC71)\n"));
    Resonace->setRange (0, 15, 1);
    Resonace->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Resonace->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Resonace->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Resonace->setBounds (250, 300, 66, 66);

    Noise1.reset (new juce::ToggleButton ("noise1 toggle button"));
    addAndMakeVisible (Noise1.get());
    Noise1->setButtonText (TRANS("Noise"));
    Noise1->setConnectedEdges (juce::Button::ConnectedOnBottom);
    Noise1->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Noise1->setBounds (585, 102, 66, 30);

    Noise2.reset (new juce::ToggleButton ("noise2 toggle button"));
    addAndMakeVisible (Noise2.get());
    Noise2->setButtonText (TRANS("Noise"));
    Noise2->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Noise2->setBounds (585, 164, 66, 30);

    Noise3.reset (new juce::ToggleButton ("noise3 toggle button"));
    addAndMakeVisible (Noise3.get());
    Noise3->setButtonText (TRANS("Noise"));
    Noise3->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Noise3->setBounds (585, 224, 66, 30);

    Pulse1.reset (new juce::ToggleButton ("pulse1 toggle button"));
    addAndMakeVisible (Pulse1.get());
    Pulse1->setButtonText (TRANS("Pulse"));
    Pulse1->setConnectedEdges (juce::Button::ConnectedOnBottom);
    Pulse1->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Pulse1->setBounds (655, 102, 66, 30);

    Pulse2.reset (new juce::ToggleButton ("pulse2 toggle button"));
    addAndMakeVisible (Pulse2.get());
    Pulse2->setButtonText (TRANS("Pulse"));
    Pulse2->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Pulse2->setBounds (655, 164, 66, 30);

    Pulse3.reset (new juce::ToggleButton ("pulse3 toggle button"));
    addAndMakeVisible (Pulse3.get());
    Pulse3->setButtonText (TRANS("Pulse"));
    Pulse3->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Pulse3->setBounds (655, 224, 66, 30);

    Saw1.reset (new juce::ToggleButton ("saw1 toggle button"));
    addAndMakeVisible (Saw1.get());
    Saw1->setButtonText (TRANS("Saw"));
    Saw1->setConnectedEdges (juce::Button::ConnectedOnBottom);
    Saw1->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Saw1->setBounds (725, 102, 66, 30);

    Saw2.reset (new juce::ToggleButton ("saw2 toggle button"));
    addAndMakeVisible (Saw2.get());
    Saw2->setButtonText (TRANS("Saw"));
    Saw2->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Saw2->setBounds (725, 164, 66, 30);

    Saw3.reset (new juce::ToggleButton ("saw3 toggle button"));
    addAndMakeVisible (Saw3.get());
    Saw3->setButtonText (TRANS("Saw"));
    Saw3->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Saw3->setBounds (725, 224, 66, 30);

    Tria1.reset (new juce::ToggleButton ("tria1 toggle button"));
    addAndMakeVisible (Tria1.get());
    Tria1->setButtonText (TRANS("Tria"));
    Tria1->setConnectedEdges (juce::Button::ConnectedOnBottom);
    Tria1->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Tria1->setBounds (785, 102, 66, 30);

    Tria2.reset (new juce::ToggleButton ("tria2 toggle button"));
    addAndMakeVisible (Tria2.get());
    Tria2->setButtonText (TRANS("Tria"));
    Tria2->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Tria2->setBounds (785, 164, 66, 30);

    Tria3.reset (new juce::ToggleButton ("tria3 toggle button"));
    addAndMakeVisible (Tria3.get());
    Tria3->setButtonText (TRANS("Tria"));
    Tria3->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Tria3->setBounds (785, 224, 66, 30);

    Ringmod1.reset (new juce::ToggleButton ("ringmod1 toggle button"));
    addAndMakeVisible (Ringmod1.get());
    Ringmod1->setButtonText (TRANS("Ring."));
    Ringmod1->setConnectedEdges (juce::Button::ConnectedOnBottom);
    Ringmod1->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Ringmod1->setBounds (845, 102, 66, 30);

    Ringmod2.reset (new juce::ToggleButton ("ringmod2 toggle button"));
    addAndMakeVisible (Ringmod2.get());
    Ringmod2->setButtonText (TRANS("Ring."));
    Ringmod2->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Ringmod2->setBounds (845, 164, 66, 30);

    Ringmod3.reset (new juce::ToggleButton ("ringmod3 toggle button"));
    addAndMakeVisible (Ringmod3.get());
    Ringmod3->setButtonText (TRANS("Ring."));
    Ringmod3->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Ringmod3->setBounds (845, 224, 66, 30);

    Sync1.reset (new juce::ToggleButton ("syn1 toggle button"));
    addAndMakeVisible (Sync1.get());
    Sync1->setButtonText (TRANS("Sync."));
    Sync1->setConnectedEdges (juce::Button::ConnectedOnBottom);
    Sync1->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Sync1->setBounds (905, 102, 66, 30);

    Sync2.reset (new juce::ToggleButton ("sync2 toggle button"));
    addAndMakeVisible (Sync2.get());
    Sync2->setButtonText (TRANS("Sync."));
    Sync2->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Sync2->setBounds (905, 164, 66, 30);

    Sync3.reset (new juce::ToggleButton ("sync3 toggle button"));
    addAndMakeVisible (Sync3.get());
    Sync3->setButtonText (TRANS("Sync."));
    Sync3->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Sync3->setBounds (905, 224, 66, 30);

    Voice2.reset (new juce::ToggleButton ("voice2 toggle button"));
    addAndMakeVisible (Voice2.get());
    Voice2->setTooltip (TRANS("Voice 2 On/Off"));
    Voice2->setButtonText (TRANS("2"));
    Voice2->setToggleState (true, juce::dontSendNotification);
    Voice2->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Voice2->setBounds (26, 164, 33, 30);

    Voice3.reset (new juce::ToggleButton ("voice3 toggle button"));
    addAndMakeVisible (Voice3.get());
    Voice3->setTooltip (TRANS("Voice 3 On/Off"));
    Voice3->setButtonText (TRANS("3"));
    Voice3->setToggleState (true, juce::dontSendNotification);
    Voice3->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Voice3->setBounds (26, 224, 33, 30);

    Led.reset (new juce::ImageButton ("Power_LED"));
    addAndMakeVisible (Led.get());
    Led->setTooltip (TRANS("midi-activity and  blinks when error-status"));
    Led->setButtonText (juce::String());

    Led->setImages (false, true, true,
                    juce::ImageCache::getFromMemory (redledoff_png, redledoff_pngSize), 1.000f, juce::Colour (0x00ffffff),
                    juce::ImageCache::getFromMemory (redledoff_png, redledoff_pngSize), 1.000f, juce::Colour (0x00ffffff),
                    juce::ImageCache::getFromMemory (redledon_png, redledon_pngSize), 1.000f, juce::Colour (0x00ffffff));
    Led->setBounds (962, 30, 40, 40);

    midichannel.reset (new juce::ComboBox ("midichannel"));
    addAndMakeVisible (midichannel.get());
    midichannel->setTooltip (TRANS("MIDI channel"));
    midichannel->setEditableText (false);
    midichannel->setJustificationType (juce::Justification::centredLeft);
    midichannel->setTextWhenNothingSelected (juce::String());
    midichannel->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midichannel->addItem (TRANS("all"), 1);
    midichannel->addItem (TRANS("1"), 2);
    midichannel->addItem (TRANS("2"), 3);
    midichannel->addItem (TRANS("3"), 4);
    midichannel->addItem (TRANS("4"), 5);
    midichannel->addItem (TRANS("5"), 6);
    midichannel->addItem (TRANS("6"), 7);
    midichannel->addItem (TRANS("7"), 8);
    midichannel->addItem (TRANS("8"), 9);
    midichannel->addItem (TRANS("9"), 10);
    midichannel->addItem (TRANS("10"), 11);
    midichannel->addItem (TRANS("11"), 12);
    midichannel->addItem (TRANS("12"), 13);
    midichannel->addItem (TRANS("13"), 14);
    midichannel->addItem (TRANS("14"), 15);
    midichannel->addItem (TRANS("15"), 16);
    midichannel->addItem (TRANS("16"), 17);
    midichannel->addListener (this);

    midichannel->setBounds (401, 320, 150, 24);

    link_button.reset (new juce::ToggleButton ("link button"));
    addAndMakeVisible (link_button.get());
    link_button->setTooltip (TRANS("link gui elements"));
    link_button->setButtonText (TRANS("link"));
    link_button->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    link_button->setBounds (918, 397, 66, 30);

    Voice1.reset (new juce::ToggleButton ("voice1 toggle button"));
    addAndMakeVisible (Voice1.get());
    Voice1->setTooltip (TRANS("Voice 1 On/Off"));
    Voice1->setButtonText (TRANS("1"));
    Voice1->setToggleState (true, juce::dontSendNotification);
    Voice1->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Voice1->setBounds (26, 102, 33, 30);

    reset_button.reset (new juce::ImageButton ("reset button"));
    addAndMakeVisible (reset_button.get());
    reset_button->setTooltip (TRANS("SID reset"));

    reset_button->setImages (false, true, true,
                             juce::ImageCache::getFromMemory (reset_png, reset_pngSize), 1.000f, juce::Colour (0x00000000),
                             juce::ImageCache::getFromMemory (reset_png, reset_pngSize), 1.000f, juce::Colour (0x00000000),
                             juce::ImageCache::getFromMemory (reset_png, reset_pngSize), 1.000f, juce::Colour (0x00000000));
    reset_button->setBounds (916, 320, 70, 25);

    keyboard_group.reset (new juce::GroupComponent ("keyboard group",
                                                    TRANS("Keyboard")));
    addAndMakeVisible (keyboard_group.get());
    keyboard_group->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    keyboard_group->setColour (juce::GroupComponent::textColourId, juce::Colours::yellow);

    keyboard_group->setBounds (8, 440, 1004, 68);

    Pitchbend.reset (new juce::Slider ("pitchbend slider"));
    addAndMakeVisible (Pitchbend.get());
    Pitchbend->setTooltip (TRANS("Pitchbend"));
    Pitchbend->setRange (-8191, 8191, 1);
    Pitchbend->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Pitchbend->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 12);
    Pitchbend->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00ffffff));

    Pitchbend->setBounds (574, 372, 66, 66);

    init_button.reset (new juce::ImageButton ("init button"));
    addAndMakeVisible (init_button.get());
    init_button->setTooltip (TRANS("Init +reset"));
    init_button->setButtonText (TRANS("reset button"));

    init_button->setImages (false, true, true,
                            juce::ImageCache::getFromMemory (init_png, init_pngSize), 1.000f, juce::Colour (0x00000000),
                            juce::ImageCache::getFromMemory (init_png, init_pngSize), 1.000f, juce::Colour (0x00000000),
                            juce::ImageCache::getFromMemory (init_png, init_pngSize), 1.000f, juce::Colour (0x00000000));
    init_button->setBounds (916, 360, 70, 25);

    Bend1.reset (new juce::ToggleButton ("bend1 toggle button"));
    addAndMakeVisible (Bend1.get());
    Bend1->setTooltip (TRANS("Assign Voice1 to Pitchbend"));
    Bend1->setButtonText (TRANS("Bend1"));
    Bend1->setConnectedEdges (juce::Button::ConnectedOnBottom);
    Bend1->setToggleState (true, juce::dontSendNotification);
    Bend1->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Bend1->setBounds (636, 340, 66, 30);

    Bend2.reset (new juce::ToggleButton ("bend2 toggle button"));
    addAndMakeVisible (Bend2.get());
    Bend2->setTooltip (TRANS("Assign Voice2 to Pitchbend"));
    Bend2->setButtonText (TRANS("Bend2"));
    Bend2->setToggleState (true, juce::dontSendNotification);
    Bend2->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Bend2->setBounds (636, 372, 66, 30);

    Bend3.reset (new juce::ToggleButton ("bend3 toggle button"));
    addAndMakeVisible (Bend3.get());
    Bend3->setTooltip (TRANS("Assign Voice3 to Pitchbend"));
    Bend3->setButtonText (TRANS("Bend3"));
    Bend3->setToggleState (true, juce::dontSendNotification);
    Bend3->setColour (juce::ToggleButton::textColourId, juce::Colours::brown);

    Bend3->setBounds (636, 404, 66, 30);

    mode__imageButton.reset (new juce::ImageButton ("mode button"));
    addAndMakeVisible (mode__imageButton.get());

    mode__imageButton->setImages (false, true, true,
                                  juce::ImageCache::getFromMemory (kippschalter_off_c_png, kippschalter_off_c_pngSize), 1.000f, juce::Colour (0x00000000),
                                  juce::Image(), 1.000f, juce::Colour (0x00000000),
                                  juce::ImageCache::getFromMemory (kippschalter_on_c_png, kippschalter_on_c_pngSize), 1.000f, juce::Colour (0x00000000));
    mode__imageButton->setBounds (416, 4, 70, 70);

    mono__label.reset (new juce::Label ("mono label",
                                        TRANS("Mono Mode")));
    addAndMakeVisible (mono__label.get());
    mono__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    mono__label->setJustificationType (juce::Justification::centredLeft);
    mono__label->setEditable (false, false, false);
    mono__label->setColour (juce::Label::textColourId, juce::Colours::blue);
    mono__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    mono__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    mono__label->setBounds (484, 28, 80, 24);

    poly__label2.reset (new juce::Label ("poly label",
                                         TRANS("Poly Mode\n")));
    addAndMakeVisible (poly__label2.get());
    poly__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    poly__label2->setJustificationType (juce::Justification::centredLeft);
    poly__label2->setEditable (false, false, false);
    poly__label2->setColour (juce::Label::textColourId, juce::Colours::brown);
    poly__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    poly__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    poly__label2->setBounds (484, 49, 80, 24);

    cachedImage_aiasshintergrund_png_1 = juce::ImageCache::getFromMemory (aiasshintergrund_png, aiasshintergrund_pngSize);
    cachedImage_typenschild_a_png_2 = juce::ImageCache::getFromMemory (typenschild_a_png, typenschild_a_pngSize);
    cachedImage_sidblaster02_png_3 = juce::ImageCache::getFromMemory (sidblaster02_png, sidblaster02_pngSize);

    //[UserPreSize]
	legatomode->setSelectedItemIndex(0);
	noteprioritymode->setSelectedItemIndex(0);
    midichannel->setSelectedItemIndex(0);
    reset_button->setClickingTogglesState(true);
    init_button->setClickingTogglesState(true);
    mode__imageButton->setClickingTogglesState(true);

    #define HakenFarbe juce::Colour (0xff239a0f)
    #define BoxFarbe   juce::Colours::blue

    Voice1->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Voice1->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Voice2->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Voice2->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Voice3->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Voice3->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Noise1->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Noise1->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Noise2->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Noise2->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Noise3->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Noise3->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Pulse1->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Pulse1->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Pulse2->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Pulse2->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Pulse3->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Pulse3->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Saw1->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Saw1->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Saw2->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Saw2->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Saw3->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Saw3->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Tria1->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Tria1->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Tria2->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Tria2->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Tria3->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Tria3->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Ringmod1->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Ringmod1->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Ringmod2->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Ringmod2->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Ringmod3->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Ringmod3->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Sync1->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Sync1->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Sync2->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Sync2->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Sync3->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Sync3->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Filterin->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Filterin->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Filter3->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Filter3->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Filter2->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Filter2->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Filter1->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Filter1->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Filter3off->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Filter3off->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Filterhp->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Filterhp->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Filterbp->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Filterbp->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Filterlp->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Filterlp->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Filterscale->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Filterscale->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Velvol->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Velvol->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    link_button->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    link_button->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Bend1->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Bend1->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Bend2->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Bend2->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);
    Bend3->setColour(juce::ToggleButton::tickColourId, HakenFarbe);
    Bend3->setColour(juce::ToggleButton::tickDisabledColourId, BoxFarbe);

    #define GroupFarbe   juce::Colours::black
    tonegroup->setColour(juce::GroupComponent::outlineColourId, GroupFarbe);
    soundgroup->setColour(juce::GroupComponent::outlineColourId, GroupFarbe);
    pulsewidhgroup->setColour(juce::GroupComponent::outlineColourId, GroupFarbe);
    waveformgroup->setColour(juce::GroupComponent::outlineColourId, GroupFarbe);

    filtergroup->setColour(juce::GroupComponent::outlineColourId, GroupFarbe);
    controlgroup->setColour(juce::GroupComponent::outlineColourId, GroupFarbe);
    keyboard_group->setColour(juce::GroupComponent::outlineColourId, GroupFarbe);

    #define SliderFarbe juce::Colours::blue
    Octave1->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Octave2->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Octave3->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Semi1->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Semi2->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Semi3->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Cent1->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Cent2->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Cent3->setColour(juce::Slider::thumbColourId, SliderFarbe);

    Attack1->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Attack2->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Attack3->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Decay1->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Decay2->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Decay3->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Sustain1->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Sustain2->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Sustain3->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Release1->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Release2->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Release3->setColour(juce::Slider::thumbColourId, SliderFarbe);

    Pulsew1->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Pulsew2->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Pulsew3->setColour(juce::Slider::thumbColourId, SliderFarbe);

    CutOff->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Resonace->setColour(juce::Slider::thumbColourId, SliderFarbe);
    sidvolume->setColour(juce::Slider::thumbColourId, SliderFarbe);
    Pitchbend->setColour(juce::Slider::thumbColourId, SliderFarbe);

    addAndMakeVisible(keyboardComponent);
    //keyboardState.addListener (this);
    keyboardComponent.setTopLeftPosition(15,452);
    keyboardComponent.setSize(991,50);
    keyboardComponent.setLowestVisibleKey(11);
    keyboardComponent.setEnabled(false);
    keyboardComponent.setVelocity(1.0,true);

	SidVolAttachment = std::make_unique<SliderAttachment>(valueTreeState, "SidVol", *sidvolume);
	VelvolAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "VelVol", *Velvol);
	Attack1Attachment = std::make_unique<SliderAttachment>(valueTreeState, "AttAck1", *Attack1);
	Attack2Attachment = std::make_unique<SliderAttachment>(valueTreeState, "AttAck2", *Attack2);
	Attack3Attachment = std::make_unique<SliderAttachment>(valueTreeState, "AttAck3", *Attack3);
	Decay1Attachment = std::make_unique<SliderAttachment>(valueTreeState, "DeCay1", *Decay1);
	Decay2Attachment = std::make_unique<SliderAttachment>(valueTreeState, "DeCay2", *Decay2);
	Decay3Attachment = std::make_unique<SliderAttachment>(valueTreeState, "DeCay3", *Decay3);
	Sustain1Attachment = std::make_unique<SliderAttachment>(valueTreeState, "SuStain1", *Sustain1);
	Sustain2Attachment = std::make_unique<SliderAttachment>(valueTreeState, "SuStain2", *Sustain2);
	Sustain3Attachment = std::make_unique<SliderAttachment>(valueTreeState, "SuStain3", *Sustain3);
	Release1Attachment = std::make_unique<SliderAttachment>(valueTreeState, "ReLease1", *Release1);
	Release2Attachment = std::make_unique<SliderAttachment>(valueTreeState, "ReLease2", *Release2);
	Release3Attachment = std::make_unique<SliderAttachment>(valueTreeState, "ReLease3", *Release3);
	Pulsw1Attachment = std::make_unique<SliderAttachment>(valueTreeState, "PulsW1", *Pulsew1);
	Pulsw2Attachment = std::make_unique<SliderAttachment>(valueTreeState, "PulsW2", *Pulsew2);
	Pulsw3Attachment = std::make_unique<SliderAttachment>(valueTreeState, "PulsW3", *Pulsew3);

	Voice1Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "VoiCe1", *Voice1);
	Voice2Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "VoiCe2", *Voice2);
	Voice3Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "VoiCe3", *Voice3);

	Octave1Attachment = std::make_unique<SliderAttachment>(valueTreeState, "OcTave1", *Octave1);
	Octave2Attachment = std::make_unique<SliderAttachment>(valueTreeState, "OcTave2", *Octave2);
	Octave3Attachment = std::make_unique<SliderAttachment>(valueTreeState, "OcTave3", *Octave3);
	Semi1Attachment = std::make_unique<SliderAttachment>(valueTreeState, "SeMi1", *Semi1);
	Semi2Attachment = std::make_unique<SliderAttachment>(valueTreeState, "SeMi2", *Semi2);
	Semi3Attachment = std::make_unique<SliderAttachment>(valueTreeState, "SeMi3", *Semi3);
	Cent1Attachment = std::make_unique<SliderAttachment>(valueTreeState, "CenT1", *Cent1);
	Cent2Attachment = std::make_unique<SliderAttachment>(valueTreeState, "CenT2", *Cent2);
	Cent3Attachment = std::make_unique<SliderAttachment>(valueTreeState, "CenT3", *Cent3);

	Noise1Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "NoiSe1", *Noise1);
	Noise2Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "NoiSe2", *Noise2);
	Noise3Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "NoiSe3", *Noise3);

	Pulse1Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "PulSe1", *Pulse1);
	Pulse2Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "PulSe2", *Pulse2);
	Pulse3Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "PulSe3", *Pulse3);

	Saw1Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "SaW1", *Saw1);
	Saw2Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "SaW2", *Saw2);
	Saw3Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "SaW3", *Saw3);

	Tria1Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "TriA1", *Tria1);
	Tria2Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "TriA2", *Tria2);
	Tria3Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "TriA3", *Tria3);

	Ringmod1Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "RingMod1", *Ringmod1);
	Ringmod2Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "RingMod2", *Ringmod2);
	Ringmod3Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "RingMod3", *Ringmod3);

	Sync1Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "SynC1", *Sync1);
	Sync2Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "SynC2", *Sync2);
	Sync3Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "SynC3", *Sync3);

	FilterfreqAttachment = std::make_unique<SliderAttachment>(valueTreeState, "FilterFreq", *CutOff);
	ResonanceAttachment = std::make_unique<SliderAttachment>(valueTreeState, "ResoNance", *Resonace);
	FilterscaleAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "FilterScale", *Filterscale);

	Filter1Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "FilTer1", *Filter1);
	Filter2Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "FilTer2", *Filter2);
	Filter3Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "FilTer3", *Filter3);
	FilterinAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "FilTerIn", *Filterin);

	FilterLPAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "FilTerLP", *Filterlp);
	FilterBPAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "FilTerBP", *Filterbp);
	FilterHPAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "FilTerHP", *Filterhp);
	Filter3OFFAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "FilTer3OFF", *Filter3off);

	LegatoModeAttachment = std::make_unique<ComboBoxAttachment>(valueTreeState, "LegatoMode", *legatomode);
	NotePriorityModeAttachment = std::make_unique<ComboBoxAttachment>(valueTreeState, "NotePriorityMode", *noteprioritymode);
    MidiChannelAttachment = std::make_unique<ComboBoxAttachment>(valueTreeState, "MidiChannel", *midichannel);
    ResetAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "ResetButton", *reset_button);
    InitAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "InitButton", *init_button);
    LinkAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "LinkButton", *link_button);
    PitchbendAttachment = std::make_unique<SliderAttachment>(valueTreeState, "PitchBend", *Pitchbend);
    Bend1Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "BeNd1", *Bend1);
    Bend2Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "BeNd2", *Bend2);
    Bend3Attachment = std::make_unique<ButtonAttachment>(valueTreeState, "BeNd3", *Bend3);
    ModeAttachment = std::make_unique<ButtonAttachment>(valueTreeState, "ModeButton", *mode__imageButton);
    //[/UserPreSize]

    setSize (1024, 530);


    //[Constructor] You can add your own custom stuff here..
	// start a timer which will keep our timecode display updated
	startTimerHz(30);

    //[/Constructor]
}

AiassAudioProcessorEditor::~AiassAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

	SidVolAttachment = nullptr;
	VelvolAttachment = nullptr;
	Attack1Attachment = nullptr;
	Attack2Attachment = nullptr;
	Attack3Attachment = nullptr;
	Decay1Attachment = nullptr;
	Decay2Attachment = nullptr;
	Decay3Attachment = nullptr;
	Sustain1Attachment = nullptr;
	Sustain2Attachment = nullptr;
	Sustain3Attachment = nullptr;
	Release1Attachment = nullptr;
	Release2Attachment = nullptr;
	Release3Attachment = nullptr;
	Pulsw1Attachment = nullptr;
	Pulsw2Attachment = nullptr;
	Pulsw3Attachment = nullptr;
	Voice1Attachment = nullptr;
	Voice2Attachment = nullptr;
	Voice3Attachment = nullptr;
	Octave1Attachment = nullptr;
	Octave2Attachment = nullptr;
	Octave3Attachment = nullptr;
	Semi1Attachment = nullptr;
	Semi2Attachment = nullptr;
	Semi3Attachment = nullptr;
	Cent1Attachment = nullptr;
	Cent2Attachment = nullptr;
	Cent3Attachment = nullptr;
	Noise1Attachment = nullptr;
	Noise2Attachment = nullptr;
	Noise3Attachment = nullptr;
	Pulse1Attachment = nullptr;
	Pulse2Attachment = nullptr;
	Pulse3Attachment = nullptr;
	Saw1Attachment = nullptr;
	Saw2Attachment = nullptr;
	Saw3Attachment = nullptr;
	Tria1Attachment = nullptr;
	Tria2Attachment = nullptr;
	Tria3Attachment = nullptr;
	Ringmod1Attachment = nullptr;
	Ringmod2Attachment = nullptr;
	Ringmod3Attachment = nullptr;
	Sync1Attachment = nullptr;
	Sync2Attachment = nullptr;
	Sync3Attachment = nullptr;
	FilterfreqAttachment = nullptr;
	ResonanceAttachment = nullptr;
	FilterscaleAttachment = nullptr;
	Filter1Attachment = nullptr;
	Filter2Attachment = nullptr;
	Filter3Attachment = nullptr;
	FilterinAttachment = nullptr;
	FilterLPAttachment = nullptr;
	FilterBPAttachment = nullptr;
	FilterHPAttachment = nullptr;
	Filter3OFFAttachment = nullptr;
	LegatoModeAttachment = nullptr;
	NotePriorityModeAttachment = nullptr;
    MidiChannelAttachment = nullptr;
    ResetAttachment = nullptr;
    InitAttachment = nullptr;
    LinkAttachment = nullptr;
    PitchbendAttachment = nullptr;
    Bend1Attachment = nullptr;
    Bend2Attachment = nullptr;
    Bend3Attachment = nullptr;
    ModeAttachment = nullptr;

    //[/Destructor_pre]

    tonegroup = nullptr;
    semigroup = nullptr;
    octavegroup = nullptr;
    Semi1 = nullptr;
    Cent1 = nullptr;
    Attack1 = nullptr;
    Decay1 = nullptr;
    Sustain1 = nullptr;
    soundgroup = nullptr;
    Release1 = nullptr;
    Octave1 = nullptr;
    releasegroup = nullptr;
    sustaingroup = nullptr;
    decaygroup = nullptr;
    attackgroup = nullptr;
    centgroup = nullptr;
    Decay2 = nullptr;
    pulsewidhgroup = nullptr;
    Pulsew1 = nullptr;
    controlgroup = nullptr;
    waveformgroup = nullptr;
    filtergroup = nullptr;
    sidvolume = nullptr;
    Octave2 = nullptr;
    Octave3 = nullptr;
    Semi2 = nullptr;
    Semi3 = nullptr;
    Cent2 = nullptr;
    Cent3 = nullptr;
    Attack2 = nullptr;
    Attack3 = nullptr;
    Decay3 = nullptr;
    Sustain2 = nullptr;
    Sustain3 = nullptr;
    Release2 = nullptr;
    Release3 = nullptr;
    Pulsew2 = nullptr;
    Pulsew3 = nullptr;
    Velvol = nullptr;
    legatomode = nullptr;
    noteprioritymode = nullptr;
    hyperlinkButton = nullptr;
    Filter1 = nullptr;
    Filter2 = nullptr;
    Filter3off = nullptr;
    Filter3 = nullptr;
    Filterin = nullptr;
    Filterlp = nullptr;
    Filterhp = nullptr;
    Filterbp = nullptr;
    Filterscale = nullptr;
    CutOff = nullptr;
    Resonace = nullptr;
    Noise1 = nullptr;
    Noise2 = nullptr;
    Noise3 = nullptr;
    Pulse1 = nullptr;
    Pulse2 = nullptr;
    Pulse3 = nullptr;
    Saw1 = nullptr;
    Saw2 = nullptr;
    Saw3 = nullptr;
    Tria1 = nullptr;
    Tria2 = nullptr;
    Tria3 = nullptr;
    Ringmod1 = nullptr;
    Ringmod2 = nullptr;
    Ringmod3 = nullptr;
    Sync1 = nullptr;
    Sync2 = nullptr;
    Sync3 = nullptr;
    Voice2 = nullptr;
    Voice3 = nullptr;
    Led = nullptr;
    midichannel = nullptr;
    link_button = nullptr;
    Voice1 = nullptr;
    reset_button = nullptr;
    keyboard_group = nullptr;
    Pitchbend = nullptr;
    init_button = nullptr;
    Bend1 = nullptr;
    Bend2 = nullptr;
    Bend3 = nullptr;
    mode__imageButton = nullptr;
    mono__label = nullptr;
    poly__label2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    //keyboardState.removeListener(this);

    //[/Destructor]
}

//==============================================================================
void AiassAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = 0, y = 0, width = 1024, height = 530;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_aiasshintergrund_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_aiasshintergrund_png_1.getWidth(), cachedImage_aiasshintergrund_png_1.getHeight());
    }

    {
        int x = 14, y = 28, width = 315, height = 41;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_typenschild_a_png_2,
                     x, y, width, height,
                     0, 0, cachedImage_typenschild_a_png_2.getWidth(), cachedImage_typenschild_a_png_2.getHeight());
    }

    {
        int x = 336, y = 49, width = 50, height = 20;
        juce::String text (TRANS("v. 0.1"));
        juce::Colour fillColour = juce::Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 728, y = 312, width = 159, height = 125;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_sidblaster02_png_3,
                     x, y, width, height,
                     0, 0, cachedImage_sidblaster02_png_3.getWidth(), cachedImage_sidblaster02_png_3.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AiassAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AiassAudioProcessorEditor::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == legatomode.get())
    {
        //[UserComboBoxCode_legatomode] -- add your combo box handling code here..
        //[/UserComboBoxCode_legatomode]
    }
    else if (comboBoxThatHasChanged == noteprioritymode.get())
    {
        //[UserComboBoxCode_noteprioritymode] -- add your combo box handling code here..
        //[/UserComboBoxCode_noteprioritymode]
    }
    else if (comboBoxThatHasChanged == midichannel.get())
    {
        //[UserComboBoxCode_midichannel] -- add your combo box handling code here..
        //[/UserComboBoxCode_midichannel]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//==============================================================================

void AiassAudioProcessorEditor::timerCallback()
{
	int Error_State = (m_sid->error_state);
    if (Mode_State != (getProcessor().MODE)) {
        Mode_State = (getProcessor().MODE);
        if (getProcessor().MODE) {
            legatomode->setEnabled(false);
            noteprioritymode->setEnabled(false);

            Voice1->setToggleState(true,true);
            Voice2->setToggleState(true,true);
            Voice3->setToggleState(true,true);
            Voice1->setEnabled(false);
            Voice2->setEnabled(false);
            Voice3->setEnabled(false);
        }
        else {
            legatomode->setEnabled(true);
            noteprioritymode->setEnabled(true);
            Voice1->setEnabled(true);
            Voice2->setEnabled(true);
            Voice3->setEnabled(true);


        }
    }

    if (Link_State != (getProcessor().LINK)) {
        Link_State = (getProcessor().LINK);
        if (Link_State) {
            Attack2->setEnabled(false);
            Attack3->setEnabled(false);
            Decay2->setEnabled(false);
            Decay3->setEnabled(false);
            Sustain2->setEnabled(false);
            Sustain3->setEnabled(false);
            Release2->setEnabled(false);
            Release3->setEnabled(false);
            Pulsew2->setEnabled(false);
            Pulsew3->setEnabled(false);
            Octave2->setEnabled(false);
            Octave3->setEnabled(false);
            Semi2->setEnabled(false);
            Semi3->setEnabled(false);
            Cent2->setEnabled(false);
            Cent3->setEnabled(false);
        }
        else {
            Attack2->setEnabled(true);
            Attack3->setEnabled(true);
            Decay2->setEnabled(true);
            Decay3->setEnabled(true);
            Sustain2->setEnabled(true);
            Sustain3->setEnabled(true);
            Release2->setEnabled(true);
            Release3->setEnabled(true);
            Pulsew2->setEnabled(true);
            Pulsew3->setEnabled(true);
            Octave2->setEnabled(true);
            Octave3->setEnabled(true);
            Semi2->setEnabled(true);
            Semi3->setEnabled(true);
            Cent2->setEnabled(true);
            Cent3->setEnabled(true);
        }
    }

    Attack1->onValueChange = [this] { if (Link_State) {
        Attack2->setValue(Attack1->getValue());
        Attack3->setValue(Attack1->getValue());
    }};
    Decay1->onValueChange = [this] { if (Link_State) {
        Decay2->setValue(Decay1->getValue());
        Decay3->setValue(Decay1->getValue());
    }};
    Sustain1->onValueChange = [this] { if (Link_State) {
        Sustain2->setValue(Sustain1->getValue());
        Sustain3->setValue(Sustain1->getValue());
    }};
    Release1->onValueChange = [this] { if (Link_State) {
        Release2->setValue(Release1->getValue());
        Release3->setValue(Release1->getValue());
    }};
    Pulsew1->onValueChange = [this] { if (Link_State) {
        Pulsew2->setValue(Pulsew1->getValue());
        Pulsew3->setValue(Pulsew1->getValue());
    }};
    Octave1->onValueChange = [this] { if (Link_State) {
        Octave2->setValue(Octave1->getValue());
        Octave3->setValue(Octave1->getValue());
    }};
    Semi1->onValueChange = [this] { if (Link_State) {
        Semi2->setValue(Semi1->getValue());
        Semi3->setValue(Semi1->getValue());
    }};
    Cent1->onValueChange = [this] { if (Link_State) {
        Cent2->setValue(Cent1->getValue());
        Cent3->setValue(Cent1->getValue());
    }};

	if (Error_State)
	{
		if (hz1>=0 && hz1<=(4+Error_State*4)) set_LED_Off();
		else set_LED_On();
		hz1++;
		if (hz1 == (10+Error_State*4)) hz1 = 0;
	}
	else
	{
		bool led = (getProcessor().LED);
		if (led) set_LED_On();
		else set_LED_Off();
	}

    if ((!Pitchbend->isMouseButtonDownAnywhere()) && (Pitchbend->getValue() != 0))
    {
        if (!(getProcessor().MIDIBENDACTIVE))
        {
            if ((Pitchbend->getValue() < 300) && (Pitchbend->getValue() > -300)) Pitchbend->setValue(0);
            if (Pitchbend->getValue() < 0) Pitchbend->setValue(Pitchbend->getValue() + 400);
            if (Pitchbend->getValue() > 0) Pitchbend->setValue(Pitchbend->getValue() - 400);
            if ((Pitchbend->getValue() < 300) && (Pitchbend->getValue() > -400)) Pitchbend->setValue(0);
        }
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AiassAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, private Timer"
                 constructorParams="AiassAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor (&amp;p)&#10;valueTreeState (vts)&#10;m_sid(p.getSid())&#10;keyboardComponent (p.keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)&#10;"
                 snapPixels="10" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1024" initialHeight="530">
  <BACKGROUND backgroundColour="ffffff">
    <IMAGE pos="0 0 1024 530" resource="aiasshintergrund_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="14 28 315 41" resource="typenschild_a_png" opacity="1.0"
           mode="0"/>
    <TEXT pos="336 49 50 20" fill="solid: ff000000" hasStroke="0" text="v. 0.1"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <IMAGE pos="728 312 159 125" resource="sidblaster02_png" opacity="1.0"
           mode="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="tone group" id="6d64fe01c88e0968" memberName="tonegroup"
                  virtualName="" explicitFocusOrder="0" pos="8 72 230 218" outlinecol="ff0000ff"
                  textcol="ffffff00" title="Tone"/>
  <GROUPCOMPONENT name="semi group" id="ebe4a4d581cc8ba7" memberName="semigroup"
                  virtualName="" explicitFocusOrder="0" pos="118 82 52 204" outlinecol="ffa52a2a"
                  textcol="ff239a0f" title="Sem" textpos="33"/>
  <GROUPCOMPONENT name="octave group" id="c581754f216617ea" memberName="octavegroup"
                  virtualName="" explicitFocusOrder="0" pos="60 82 52 204" outlinecol="ffa52a2a"
                  textcol="ff239a0f" title="Oct" textpos="33"/>
  <SLIDER name="semi1 slider" id="4297018af851022d" memberName="Semi1"
          virtualName="" explicitFocusOrder="0" pos="112 90 66 66" tooltip="Semitone1 Up/Down (CC79)&#10;"
          textboxoutline="ffffff" min="-12.0" max="12.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="cent1 slider" id="b0bba6848acec451" memberName="Cent1"
          virtualName="" explicitFocusOrder="0" pos="170 90 66 66" tooltip="Cent1 Up/Down (CC70)&#10;"
          textboxoutline="ffffff" min="-100.0" max="100.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="attack1 slider" id="53619e38d7835c9d" memberName="Attack1"
          virtualName="" explicitFocusOrder="0" pos="240 90 66 66" tooltip="Attack 1 (CC73)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="decay1 slider" id="49642dbf385beee8" memberName="Decay1"
          virtualName="" explicitFocusOrder="0" pos="300 90 66 66" tooltip="Decay 1 (CC75)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="sustain1 slider" id="2793e34c7a6a6286" memberName="Sustain1"
          virtualName="" explicitFocusOrder="0" pos="360 90 66 66" tooltip="Sustain 1 (CC76)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <GROUPCOMPONENT name="sound group" id="9c52dd13730dcbb" memberName="soundgroup"
                  virtualName="" explicitFocusOrder="0" pos="238 72 252 218" outlinecol="ff0000ff"
                  textcol="ffffff00" title="Sound" textpos="33"/>
  <SLIDER name="release1 slider" id="26b01f2c9f0fcbd4" memberName="Release1"
          virtualName="" explicitFocusOrder="0" pos="420 90 66 66" tooltip="Release 1 (CC72)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="octave1 slider" id="26c4155703d3dafe" memberName="Octave1"
          virtualName="" explicitFocusOrder="0" pos="54 90 66 66" tooltip="Octave1 Up/Down (CC78)&#10;"
          textboxtext="ffffffff" textboxoutline="ffffff" min="-4.0" max="4.0"
          int="1.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="12" skewFactor="1.0"
          needsCallback="0"/>
  <GROUPCOMPONENT name="release group" id="95044d948c239887" memberName="releasegroup"
                  virtualName="" explicitFocusOrder="0" pos="427 82 52 204" outlinecol="ffa52a2a"
                  textcol="ff239a0f" title="R" textpos="36"/>
  <GROUPCOMPONENT name="sustain group" id="5acc206370d9e6ff" memberName="sustaingroup"
                  virtualName="" explicitFocusOrder="0" pos="367 82 52 204" outlinecol="ffa52a2a"
                  textcol="ff239a0f" title="S" textpos="36"/>
  <GROUPCOMPONENT name="decay group" id="5436311d81346b70" memberName="decaygroup"
                  virtualName="" explicitFocusOrder="0" pos="307 82 52 204" outlinecol="ffa52a2a"
                  textcol="ff239a0f" title="D" textpos="36"/>
  <GROUPCOMPONENT name="attack group" id="3207ac8f3cb41ebd" memberName="attackgroup"
                  virtualName="" explicitFocusOrder="0" pos="247 82 52 204" outlinecol="ffa52a2a"
                  textcol="ff239a0f" title="A" textpos="36"/>
  <GROUPCOMPONENT name="cent group" id="9397004b3a3ac548" memberName="centgroup"
                  virtualName="" explicitFocusOrder="0" pos="176 82 52 204" outlinecol="ffa52a2a"
                  textcol="ff239a0f" title="Cen" textpos="33"/>
  <SLIDER name="decay2 slider" id="379b886c43a29254" memberName="Decay2"
          virtualName="" explicitFocusOrder="0" pos="300 152 66 66" tooltip="Decay 2 (CC21)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <GROUPCOMPONENT name="pulsewidh group" id="ee61762cce42c0fc" memberName="pulsewidhgroup"
                  virtualName="" explicitFocusOrder="0" pos="490 72 60 218" outlinecol="ff0000ff"
                  textcol="ffffff00" title="Pulse"/>
  <SLIDER name="pulsew1 slider" id="a63bd08caa77c655" memberName="Pulsew1"
          virtualName="" explicitFocusOrder="0" pos="487 90 66 66" tooltip="Pulse width 1 (CC77)"
          textboxoutline="ffffff" min="1.0" max="4094.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <GROUPCOMPONENT name="control group" id="f28a7389bff6ea97" memberName="controlgroup"
                  virtualName="" explicitFocusOrder="0" pos="380 296 631 148" outlinecol="ff0000ff"
                  textcol="ffffff00" title="Control"/>
  <GROUPCOMPONENT name="waveform group" id="52ab711584b2835a" memberName="waveformgroup"
                  virtualName="" explicitFocusOrder="0" pos="550 72 460 218" outlinecol="ff0000ff"
                  textcol="ffffff00" title="Waveform"/>
  <GROUPCOMPONENT name="filter group" id="5844d35c6980f98d" memberName="filtergroup"
                  virtualName="" explicitFocusOrder="0" pos="8 296 372 148" outlinecol="ff0000ff"
                  textcol="ffffff00" title="Filter"/>
  <SLIDER name="sidvolume slider" id="d351edf4789a40e0" memberName="sidvolume"
          virtualName="" explicitFocusOrder="0" pos="574 300 66 66" tooltip="SID-Volume (CC7)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="octave2 slider" id="7808b9c1fb74ccc8" memberName="Octave2"
          virtualName="" explicitFocusOrder="0" pos="54 152 66 66" tooltip="Octave2 Up/Down (CC85)&#10;"
          textboxoutline="ffffff" min="-4.0" max="4.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="octave3 slider" id="d3e4a1e141ca77b6" memberName="Octave3"
          virtualName="" explicitFocusOrder="0" pos="54 212 66 66" tooltip="Octave3 Up/Down (CC88)&#10;"
          textboxoutline="ffffff" min="-4.0" max="4.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="semi2 slider" id="4e87cf183b0e0e77" memberName="Semi2"
          virtualName="" explicitFocusOrder="0" pos="112 152 66 66" tooltip="Semitone2 Up/Down (CC86)&#10;"
          textboxoutline="ffffff" min="-12.0" max="12.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="semi3 slider" id="f03b15fac2d0a403" memberName="Semi3"
          virtualName="" explicitFocusOrder="0" pos="112 212 66 66" tooltip="Semitone3 Up/Down (CC89)&#10;"
          textboxoutline="ffffff" min="-12.0" max="12.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="cent2 slider" id="873ffcdb55231a19" memberName="Cent2"
          virtualName="" explicitFocusOrder="0" pos="170 152 66 66" tooltip="Cent2 Up/Down (CC87)&#10;"
          textboxoutline="ffffff" min="-100.0" max="100.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="cent3 slider" id="77eb6b6e2092a08c" memberName="Cent3"
          virtualName="" explicitFocusOrder="0" pos="170 212 66 66" tooltip="Cent3 Up/Down (CC90)&#10;"
          textboxoutline="ffffff" min="-100.0" max="100.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="attack2 slider" id="40a979315f74e3a" memberName="Attack2"
          virtualName="" explicitFocusOrder="0" pos="240 152 66 66" tooltip="Attack 2 (CC20)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="attack3 slider" id="7e38002dde33164c" memberName="Attack3"
          virtualName="" explicitFocusOrder="0" pos="240 212 66 66" tooltip="Attack 3 (CC25)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="decay3 slider" id="ff55788389bcec83" memberName="Decay3"
          virtualName="" explicitFocusOrder="0" pos="300 212 66 66" tooltip="Decay 3 (CC26)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="sustain2 slider" id="25e905e8830bd418" memberName="Sustain2"
          virtualName="" explicitFocusOrder="0" pos="360 152 66 66" tooltip="Sustain 2 (CC22)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="sustain3 slider" id="740735c3d8776e72" memberName="Sustain3"
          virtualName="" explicitFocusOrder="0" pos="360 212 66 66" tooltip="Sustain 3 (CC27)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="release2 slider" id="cede2f433ff54882" memberName="Release2"
          virtualName="" explicitFocusOrder="0" pos="420 152 66 66" tooltip="Release 2 (CC23)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="release3 slider" id="a6cb93496f682a4d" memberName="Release3"
          virtualName="" explicitFocusOrder="0" pos="420 212 66 66" tooltip="Release 3 (CC28)"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="pulsew2 slider" id="c761eb76e90133c8" memberName="Pulsew2"
          virtualName="" explicitFocusOrder="0" pos="487 152 66 66" tooltip="Pulse width 2 (CC24)"
          textboxoutline="ffffff" min="1.0" max="4094.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="pulsew3 slider" id="c9edf691a324176f" memberName="Pulsew3"
          virtualName="" explicitFocusOrder="0" pos="487 212 66 66" tooltip="Pulse width 3 (CC29)"
          textboxoutline="ffffff" min="1.0" max="4094.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <TOGGLEBUTTON name="Vel2Vol button" id="498d1ccffc218a3e" memberName="Velvol"
                virtualName="" explicitFocusOrder="0" pos="637 308 66 30" tooltip="maps Velocity to Volume"
                txtcol="ffa52a2a" buttonText="Vel2Vol" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <COMBOBOX name="legatomode" id="185cc42c904fe921" memberName="legatomode"
            virtualName="" explicitFocusOrder="0" pos="401 360 150 24" tooltip="play mode"
            editable="0" layout="33" items="Retrigger&#10;Legato&#10;Last Step"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="noteprioritymode" id="c728000aa37b04a3" memberName="noteprioritymode"
            virtualName="" explicitFocusOrder="0" pos="401 400 150 24" tooltip="note priority"
            editable="0" layout="33" items="Last Note&#10;High Note&#10;Low Note"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <HYPERLINKBUTTON name="new hyperlink" id="27b1f728dfa971d5" memberName="hyperlinkButton"
                   virtualName="" explicitFocusOrder="0" pos="893 506 150 24" tooltip="http://www.crazy-midi.de"
                   textCol="ff008000" buttonText="crazy-midi.de" connectedEdges="0"
                   needsCallback="0" radioGroupId="0" url="http://www.crazy-midi.de"/>
  <TOGGLEBUTTON name="Filer1 toggle button" id="f988e7a5126e5bac" memberName="Filter1"
                virtualName="" explicitFocusOrder="0" pos="204 331 66 30" tooltip="Voice 1 to Filter"
                txtcol="ffa52a2a" buttonText="1" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Filter2 toggle button" id="e8384ca904cc9cee" memberName="Filter2"
                virtualName="" explicitFocusOrder="0" pos="148 331 66 30" tooltip="Voice 2 to Filter"
                txtcol="ffa52a2a" buttonText="2" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="3off toggle button" id="46436fd7c74f713f" memberName="Filter3off"
                virtualName="" explicitFocusOrder="0" pos="16 381 66 30" tooltip="Mute Voice 3"
                txtcol="ffa52a2a" buttonText="3off" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Filter3 toggle button" id="15351388c9102c09" memberName="Filter3"
                virtualName="" explicitFocusOrder="0" pos="82 331 66 30" tooltip="Voice 3 to Filter"
                txtcol="ffa52a2a" buttonText="3" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="FilterIn toggle button" id="1a8bcabfd8647671" memberName="Filterin"
                virtualName="" explicitFocusOrder="0" pos="16 331 66 30" tooltip="extern In"
                txtcol="ffa52a2a" buttonText="in" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="lowpass toggle button" id="fe8269d4b1a9c6e6" memberName="Filterlp"
                virtualName="" explicitFocusOrder="0" pos="204 381 66 30" tooltip="Low Pass"
                txtcol="ffa52a2a" buttonText="LP" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="high pass toggle button" id="17b0fa917ff0851e" memberName="Filterhp"
                virtualName="" explicitFocusOrder="0" pos="82 381 66 30" tooltip="High Pass"
                txtcol="ffa52a2a" buttonText="HP" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="band pass toggle button" id="2bd008bd14ea7c51" memberName="Filterbp"
                virtualName="" explicitFocusOrder="0" pos="148 381 66 30" tooltip="Band Pass"
                txtcol="ffa52a2a" buttonText="BP" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="scale toggle button" id="1f267441a830f9ff" memberName="Filterscale"
                virtualName="" explicitFocusOrder="0" pos="310 381 70 30" tooltip="scales filterfreq. to 0-71"
                txtcol="ffa52a2a" buttonText="scale" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <SLIDER name="cutoff slider" id="b104465dc77b15ae" memberName="CutOff"
          virtualName="" explicitFocusOrder="0" pos="250 372 66 66" tooltip="Cutoff (CC74)"
          textboxoutline="ffffff" min="0.0" max="2047.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="resonance slider" id="b18e0fc28c589ec5" memberName="Resonace"
          virtualName="" explicitFocusOrder="0" pos="250 300 66 66" tooltip="Resonance (CC71)&#10;"
          textboxoutline="ffffff" min="0.0" max="15.0" int="1.0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <TOGGLEBUTTON name="noise1 toggle button" id="53248eb179f92afc" memberName="Noise1"
                virtualName="" explicitFocusOrder="0" pos="585 102 66 30" txtcol="ffa52a2a"
                buttonText="Noise" connectedEdges="8" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="noise2 toggle button" id="d83f77113f37d2ea" memberName="Noise2"
                virtualName="" explicitFocusOrder="0" pos="585 164 66 30" txtcol="ffa52a2a"
                buttonText="Noise" connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="noise3 toggle button" id="1da77acd9957a585" memberName="Noise3"
                virtualName="" explicitFocusOrder="0" pos="585 224 66 30" txtcol="ffa52a2a"
                buttonText="Noise" connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="pulse1 toggle button" id="3bbfb8f7a8ca0db0" memberName="Pulse1"
                virtualName="" explicitFocusOrder="0" pos="655 102 66 30" txtcol="ffa52a2a"
                buttonText="Pulse" connectedEdges="8" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="pulse2 toggle button" id="520ab3980bfa9711" memberName="Pulse2"
                virtualName="" explicitFocusOrder="0" pos="655 164 66 30" txtcol="ffa52a2a"
                buttonText="Pulse" connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="pulse3 toggle button" id="1dd05bea0d3cdf7d" memberName="Pulse3"
                virtualName="" explicitFocusOrder="0" pos="655 224 66 30" txtcol="ffa52a2a"
                buttonText="Pulse" connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="saw1 toggle button" id="a48dd1aa6574a3e4" memberName="Saw1"
                virtualName="" explicitFocusOrder="0" pos="725 102 66 30" txtcol="ffa52a2a"
                buttonText="Saw" connectedEdges="8" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="saw2 toggle button" id="ae3029edeecd4b14" memberName="Saw2"
                virtualName="" explicitFocusOrder="0" pos="725 164 66 30" txtcol="ffa52a2a"
                buttonText="Saw" connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="saw3 toggle button" id="656ce7e680e8573a" memberName="Saw3"
                virtualName="" explicitFocusOrder="0" pos="725 224 66 30" txtcol="ffa52a2a"
                buttonText="Saw" connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="tria1 toggle button" id="5747f6f8bb660f63" memberName="Tria1"
                virtualName="" explicitFocusOrder="0" pos="785 102 66 30" txtcol="ffa52a2a"
                buttonText="Tria" connectedEdges="8" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="tria2 toggle button" id="cc78b8161478c5a4" memberName="Tria2"
                virtualName="" explicitFocusOrder="0" pos="785 164 66 30" txtcol="ffa52a2a"
                buttonText="Tria" connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="tria3 toggle button" id="d9035b35478c1c9b" memberName="Tria3"
                virtualName="" explicitFocusOrder="0" pos="785 224 66 30" txtcol="ffa52a2a"
                buttonText="Tria" connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="ringmod1 toggle button" id="11efaf86d1acf272" memberName="Ringmod1"
                virtualName="" explicitFocusOrder="0" pos="845 102 66 30" txtcol="ffa52a2a"
                buttonText="Ring." connectedEdges="8" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="ringmod2 toggle button" id="9d63104088c0485a" memberName="Ringmod2"
                virtualName="" explicitFocusOrder="0" pos="845 164 66 30" txtcol="ffa52a2a"
                buttonText="Ring." connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="ringmod3 toggle button" id="a97c9d37cd1a1d18" memberName="Ringmod3"
                virtualName="" explicitFocusOrder="0" pos="845 224 66 30" txtcol="ffa52a2a"
                buttonText="Ring." connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="syn1 toggle button" id="fb4637c0f86bc855" memberName="Sync1"
                virtualName="" explicitFocusOrder="0" pos="905 102 66 30" txtcol="ffa52a2a"
                buttonText="Sync." connectedEdges="8" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="sync2 toggle button" id="99a8550e2ad2c6da" memberName="Sync2"
                virtualName="" explicitFocusOrder="0" pos="905 164 66 30" txtcol="ffa52a2a"
                buttonText="Sync." connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="sync3 toggle button" id="880c3fcf4ab4a1f6" memberName="Sync3"
                virtualName="" explicitFocusOrder="0" pos="905 224 66 30" txtcol="ffa52a2a"
                buttonText="Sync." connectedEdges="0" needsCallback="0" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="voice2 toggle button" id="3b39ff7f634b369" memberName="Voice2"
                virtualName="" explicitFocusOrder="0" pos="26 164 33 30" tooltip="Voice 2 On/Off"
                txtcol="ffa52a2a" buttonText="2" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="voice3 toggle button" id="62c330b01d3c339c" memberName="Voice3"
                virtualName="" explicitFocusOrder="0" pos="26 224 33 30" tooltip="Voice 3 On/Off"
                txtcol="ffa52a2a" buttonText="3" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="1"/>
  <IMAGEBUTTON name="Power_LED" id="77dead3478e9a659" memberName="Led" virtualName=""
               explicitFocusOrder="0" pos="962 30 40 40" tooltip="midi-activity and  blinks when error-status"
               buttonText="" connectedEdges="0" needsCallback="0" radioGroupId="0"
               keepProportions="1" resourceNormal="redledoff_png" opacityNormal="1.0"
               colourNormal="ffffff" resourceOver="redledoff_png" opacityOver="1.0"
               colourOver="ffffff" resourceDown="redledon_png" opacityDown="1.0"
               colourDown="ffffff"/>
  <COMBOBOX name="midichannel" id="62ff9b6ec5b8843e" memberName="midichannel"
            virtualName="" explicitFocusOrder="0" pos="401 320 150 24" tooltip="MIDI channel"
            editable="0" layout="33" items="all&#10;1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8&#10;9&#10;10&#10;11&#10;12&#10;13&#10;14&#10;15&#10;16"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="link button" id="8ffae76151409f08" memberName="link_button"
                virtualName="" explicitFocusOrder="0" pos="918 397 66 30" tooltip="link gui elements"
                txtcol="ffa52a2a" buttonText="link" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="voice1 toggle button" id="883f3d3793f0f11b" memberName="Voice1"
                virtualName="" explicitFocusOrder="0" pos="26 102 33 30" tooltip="Voice 1 On/Off"
                txtcol="ffa52a2a" buttonText="1" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="1"/>
  <IMAGEBUTTON name="reset button" id="99243fa27f37fff" memberName="reset_button"
               virtualName="" explicitFocusOrder="0" pos="916 320 70 25" tooltip="SID reset"
               buttonText="reset button" connectedEdges="0" needsCallback="0"
               radioGroupId="0" keepProportions="1" resourceNormal="reset_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="reset_png"
               opacityOver="1.0" colourOver="0" resourceDown="reset_png" opacityDown="1.0"
               colourDown="0"/>
  <GROUPCOMPONENT name="keyboard group" id="2120190faebacf62" memberName="keyboard_group"
                  virtualName="" explicitFocusOrder="0" pos="8 440 1004 68" outlinecol="ff0000ff"
                  textcol="ffffff00" title="Keyboard"/>
  <SLIDER name="pitchbend slider" id="ef7010e0cf15adf0" memberName="Pitchbend"
          virtualName="" explicitFocusOrder="0" pos="574 372 66 66" tooltip="Pitchbend"
          textboxoutline="ffffff" min="-8191.0" max="8191.0" int="1.0"
          style="RotaryVerticalDrag" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="12" skewFactor="1.0" needsCallback="0"/>
  <IMAGEBUTTON name="init button" id="719fda4fb1f8aa48" memberName="init_button"
               virtualName="" explicitFocusOrder="0" pos="916 360 70 25" tooltip="Init +reset"
               buttonText="reset button" connectedEdges="0" needsCallback="0"
               radioGroupId="0" keepProportions="1" resourceNormal="init_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="init_png"
               opacityOver="1.0" colourOver="0" resourceDown="init_png" opacityDown="1.0"
               colourDown="0"/>
  <TOGGLEBUTTON name="bend1 toggle button" id="22bc010c05d9b9f0" memberName="Bend1"
                virtualName="" explicitFocusOrder="0" pos="636 340 66 30" tooltip="Assign Voice1 to Pitchbend"
                txtcol="ffa52a2a" buttonText="Bend1" connectedEdges="8" needsCallback="0"
                radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="bend2 toggle button" id="5709fa6a03acabf9" memberName="Bend2"
                virtualName="" explicitFocusOrder="0" pos="636 372 66 30" tooltip="Assign Voice2 to Pitchbend"
                txtcol="ffa52a2a" buttonText="Bend2" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="bend3 toggle button" id="9269ed30a4a13a07" memberName="Bend3"
                virtualName="" explicitFocusOrder="0" pos="636 404 66 30" tooltip="Assign Voice3 to Pitchbend"
                txtcol="ffa52a2a" buttonText="Bend3" connectedEdges="0" needsCallback="0"
                radioGroupId="0" state="1"/>
  <IMAGEBUTTON name="mode button" id="5712bd502d0b9b7e" memberName="mode__imageButton"
               virtualName="" explicitFocusOrder="0" pos="416 4 70 70" buttonText="mode button"
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="kippschalter_off_c_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="" opacityOver="1.0" colourOver="0" resourceDown="kippschalter_on_c_png"
               opacityDown="1.0" colourDown="0"/>
  <LABEL name="mono label" id="45567f8d89f80845" memberName="mono__label"
         virtualName="" explicitFocusOrder="0" pos="484 28 80 24" textCol="ff0000ff"
         edTextCol="ff000000" edBkgCol="0" labelText="Mono Mode" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="poly label" id="e9c32c0f74123e87" memberName="poly__label2"
         virtualName="" explicitFocusOrder="0" pos="484 49 80 24" textCol="ffa52a2a"
         edTextCol="ff000000" edBkgCol="0" labelText="Poly Mode&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: redledoff_png, 2598, "../images/red-led-off.png"
static const unsigned char resource_AiassAudioProcessorEditor_redledoff_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,40,0,0,0,40,8,6,0,0,0,140,254,184,109,0,0,0,1,115,82,71,66,0,174,206,
28,233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,21,56,0,0,21,56,1,58,216,253,109,0,0,9,187,73,68,65,84,88,71,173,152,91,108,84,213,26,199,191,153,78,219,41,229,210,150,182,
244,174,66,41,1,34,130,105,212,28,83,136,137,1,68,114,18,121,57,57,137,132,192,155,18,125,4,125,16,53,33,154,96,159,76,120,210,135,62,25,77,12,209,7,195,139,49,177,77,142,39,146,131,88,129,182,132,150,
82,33,165,165,45,45,189,205,116,46,251,252,127,171,123,207,105,237,116,218,146,243,37,107,214,204,222,107,175,239,183,190,219,90,123,66,246,132,114,224,192,1,111,219,182,109,86,93,93,109,27,54,108,176,
130,130,2,11,135,195,238,94,58,157,182,185,185,57,123,252,248,177,13,14,14,90,111,111,175,181,183,183,63,145,174,53,63,116,236,216,49,175,165,165,197,170,170,170,44,30,143,219,204,204,140,37,147,73,7,
229,121,158,27,19,10,133,28,108,36,18,177,117,235,214,89,97,97,161,61,120,240,192,58,58,58,236,210,165,75,107,210,185,234,193,39,78,156,240,142,30,61,106,177,88,204,38,39,39,29,28,80,171,17,96,129,12,
44,125,249,242,101,107,107,107,91,149,238,21,7,237,218,181,203,59,125,250,180,179,196,196,196,132,115,29,150,114,77,138,61,89,41,45,165,174,201,114,92,15,11,60,63,149,114,45,36,235,106,37,153,103,0,44,
41,41,177,169,169,41,187,120,241,162,117,117,117,229,100,200,121,243,236,217,179,222,238,221,187,109,108,108,204,102,103,103,157,197,82,186,30,46,46,54,43,45,181,196,250,245,150,63,58,106,27,110,221,178,
226,190,62,43,24,31,183,148,32,102,116,127,180,166,198,70,234,234,44,182,105,147,21,11,114,179,22,3,176,7,176,164,168,168,72,83,148,218,245,235,215,237,194,133,11,203,114,44,123,163,181,181,213,195,106,
4,122,50,145,112,138,195,114,81,164,178,210,10,101,201,218,111,191,181,134,159,126,178,18,141,37,242,80,75,143,211,23,78,58,162,118,243,229,151,237,198,139,47,90,168,188,220,170,100,241,168,230,74,11,
22,215,111,220,184,209,89,243,204,153,51,89,89,178,94,60,119,238,156,87,81,81,49,15,167,21,39,53,97,177,44,82,32,203,52,181,182,90,227,111,191,89,177,146,36,161,5,196,30,61,178,105,89,46,166,49,78,228,
102,172,44,127,58,224,60,181,124,181,184,218,13,121,227,223,175,191,110,229,122,174,34,26,181,180,230,38,161,128,28,26,26,178,243,231,207,47,225,225,249,69,66,150,226,214,71,82,76,188,37,164,104,125,67,
131,173,215,138,159,125,255,125,123,86,147,23,189,250,170,37,229,158,36,46,211,234,35,26,7,20,99,137,67,36,69,60,170,37,104,250,13,108,237,195,135,86,162,80,184,185,117,171,37,5,88,148,151,231,32,73,188,
114,89,87,137,244,81,119,119,247,199,110,2,95,230,11,151,47,59,118,236,240,14,29,58,100,227,178,8,112,115,82,88,214,216,104,21,3,3,118,240,237,183,173,249,205,55,173,224,181,215,44,161,88,76,42,147,83,
211,211,150,34,54,5,186,78,202,128,36,17,156,5,37,65,159,244,33,167,212,26,84,23,255,249,249,231,54,115,227,134,221,211,243,170,69,150,210,243,232,68,119,83,83,147,239,138,121,89,4,120,252,248,113,27,
25,25,113,9,17,211,202,54,62,243,140,109,190,115,199,254,246,201,39,86,167,140,155,219,178,197,226,154,40,173,21,19,236,46,224,53,57,110,117,69,90,125,80,120,254,10,137,69,105,64,162,244,239,95,127,109,
241,219,183,109,80,134,48,45,14,131,224,53,24,22,74,6,240,212,169,83,94,126,126,190,11,216,152,106,92,153,118,137,58,185,100,255,135,31,218,86,37,68,92,0,73,101,172,39,120,79,247,51,13,5,82,28,146,85,
211,126,220,45,129,11,122,255,254,172,26,138,255,241,205,55,54,121,243,166,13,49,167,126,163,155,50,116,242,228,201,140,21,29,160,46,122,251,246,237,115,102,166,0,135,85,62,170,20,19,77,239,189,103,245,
223,125,103,115,178,84,82,165,6,24,79,25,157,246,27,191,129,194,122,132,3,32,153,24,116,159,75,251,52,11,85,155,213,56,50,255,144,230,191,55,60,108,90,102,198,213,123,247,238,117,76,140,119,128,71,142,
28,201,196,93,66,138,107,118,238,180,242,47,191,180,134,230,102,243,20,208,9,193,57,40,129,210,112,173,43,192,244,178,28,147,60,166,24,51,153,36,43,156,191,128,12,168,0,201,236,82,205,187,253,234,85,187,
175,152,198,19,232,167,122,28,62,124,216,141,115,128,219,183,111,183,105,5,44,37,69,232,86,84,91,107,21,63,252,96,155,222,125,215,230,180,58,87,14,180,58,160,130,230,98,80,147,185,216,147,242,25,1,98,
187,229,224,128,199,122,72,112,143,12,7,242,185,223,127,183,135,120,67,191,73,50,246,119,152,144,112,125,125,189,199,214,67,170,227,222,205,79,61,101,229,237,237,182,73,55,163,251,247,91,90,150,13,145,
20,52,1,5,45,77,236,1,168,73,135,5,239,0,244,29,201,6,135,91,145,69,247,124,192,50,45,174,188,171,203,70,253,221,138,36,45,43,43,179,186,186,58,47,188,133,204,20,24,254,143,75,233,102,145,151,126,245,
149,133,180,69,97,77,151,177,0,4,13,203,169,199,162,17,181,105,223,122,89,221,155,11,206,239,177,106,76,253,206,238,110,27,21,7,208,142,69,223,97,11,215,104,135,192,189,248,222,83,186,151,169,16,151,168,
70,37,4,135,133,130,196,112,205,47,47,33,93,195,205,163,186,22,88,143,29,33,163,88,96,192,81,114,114,193,5,61,9,82,175,250,56,169,45,148,103,9,53,152,106,21,106,97,182,25,104,185,88,164,239,249,170,131,
76,57,161,18,19,83,213,207,19,176,179,26,96,122,56,15,133,2,28,84,108,142,235,55,78,93,4,231,247,88,38,165,6,228,74,141,34,94,164,86,192,105,9,111,104,94,152,96,11,83,119,130,236,45,16,76,158,246,68,148,
242,96,151,118,142,180,86,18,213,190,92,168,193,100,237,176,234,214,109,197,11,110,101,33,75,224,52,57,125,112,13,235,174,212,136,93,116,70,21,123,179,226,192,197,48,193,230,236,207,5,90,88,133,58,172,
65,8,15,76,222,191,111,157,111,189,101,61,159,126,106,61,95,124,97,61,42,216,35,247,238,101,238,187,120,113,191,254,7,231,20,174,194,173,11,251,192,146,17,193,185,253,157,69,170,71,116,182,212,14,224,
55,167,64,141,193,0,160,38,165,149,140,223,189,107,211,114,61,143,112,13,136,229,224,86,19,115,127,237,221,162,248,129,110,129,45,100,10,227,218,64,98,114,103,74,187,72,176,34,32,56,145,228,169,241,29,
119,186,82,162,182,72,145,15,183,86,203,5,61,186,120,62,78,98,6,198,146,224,230,48,85,155,11,152,244,17,91,142,50,135,45,8,89,81,129,192,22,194,113,125,197,103,178,244,36,31,102,154,214,121,147,243,31,
96,48,241,238,19,230,56,159,167,242,130,60,214,97,96,86,131,88,9,74,145,21,21,144,169,62,28,18,88,127,45,141,112,26,87,252,115,0,118,229,76,192,48,141,138,39,204,241,42,0,164,0,15,81,143,116,68,119,241,
231,174,46,211,251,150,251,127,180,136,218,0,39,118,94,192,84,41,176,30,76,176,133,123,122,122,92,66,66,29,209,197,193,158,30,155,210,70,237,162,73,215,114,193,97,61,36,184,135,53,220,117,247,107,229,
158,177,28,54,0,188,251,244,211,22,21,28,161,6,11,241,126,235,214,173,144,211,192,65,17,225,98,255,31,127,216,240,243,207,219,156,86,227,147,47,158,120,25,56,122,174,35,171,133,116,71,53,245,99,210,251,
64,177,207,91,31,27,6,28,88,15,113,90,68,58,95,20,165,52,174,67,227,159,122,41,26,126,231,29,83,78,101,148,186,137,115,192,5,125,48,30,201,118,31,9,198,132,53,95,161,250,255,188,240,130,21,11,142,253,
29,235,193,114,91,167,109,55,134,143,206,206,78,109,173,243,228,252,93,113,229,199,31,237,238,75,47,217,195,150,22,247,70,198,74,87,3,23,244,110,156,251,149,189,119,161,32,215,98,128,27,122,33,251,83,
175,22,249,254,118,139,80,250,96,226,251,188,54,201,149,43,87,28,28,144,121,26,248,175,239,191,183,126,157,7,227,58,213,16,35,46,227,20,163,192,6,217,151,171,5,144,89,239,249,113,55,162,172,189,42,35,
20,114,204,18,32,201,193,107,7,44,129,100,0,123,123,123,67,212,29,178,7,208,49,109,105,215,126,254,217,250,62,251,204,226,69,69,174,62,97,126,20,175,166,5,178,228,186,230,192,43,211,114,99,7,201,168,205,
65,135,81,55,55,33,198,201,30,22,134,34,25,64,228,170,142,222,81,189,175,50,176,64,43,185,211,217,105,253,58,213,220,251,224,3,7,152,167,21,82,84,93,129,150,228,114,99,54,48,50,182,80,61,86,188,114,240,
160,197,228,173,144,0,177,28,158,35,246,174,93,187,198,232,140,204,23,64,95,116,6,251,88,3,63,226,37,154,135,168,139,119,116,144,76,86,86,90,74,39,155,66,125,143,42,227,81,232,32,53,105,46,200,76,175,
185,176,4,9,49,164,185,58,222,120,195,70,136,55,121,140,5,59,131,8,142,100,237,239,239,207,88,15,89,244,35,144,230,230,102,143,211,44,175,1,108,59,113,5,109,141,78,218,207,233,21,160,226,215,95,173,178,
173,205,10,117,141,147,48,0,108,83,88,197,253,155,192,119,172,165,62,88,61,46,157,80,232,116,189,242,138,221,173,175,183,105,222,115,84,45,120,93,32,164,248,35,137,191,62,20,123,75,120,178,2,34,141,141,
141,158,154,59,56,2,57,39,32,64,170,154,154,172,81,117,178,66,22,40,22,236,166,95,126,177,168,142,101,4,61,147,1,12,44,239,26,19,58,71,62,216,179,199,6,53,15,85,141,227,91,66,49,150,239,91,141,88,231,
127,67,44,215,215,215,151,149,101,89,64,68,174,246,120,71,197,221,164,62,85,158,30,139,110,80,24,84,168,250,151,170,76,68,20,183,17,202,148,44,206,121,14,184,152,158,153,213,65,100,74,150,153,86,28,243,
110,19,17,20,96,52,178,149,158,152,83,81,94,150,35,39,32,162,216,240,246,200,10,252,59,138,37,131,173,8,104,234,150,11,112,172,65,161,151,187,152,144,51,93,10,96,125,39,248,3,40,4,151,18,111,84,12,213,
58,230,204,201,176,34,96,32,252,169,195,75,204,66,107,34,192,46,236,3,1,108,97,15,88,96,181,251,114,53,251,172,187,177,130,172,26,48,144,134,134,6,143,63,208,9,236,133,86,116,53,210,135,4,42,176,28,113,
70,207,187,46,127,164,15,12,12,172,73,231,154,1,23,74,117,117,181,87,172,243,35,129,30,88,7,9,172,76,130,241,250,56,56,56,248,132,122,204,254,11,201,151,183,196,65,63,117,141,0,0,0,0,73,69,78,68,174,66,
96,130,0,0};

const char* AiassAudioProcessorEditor::redledoff_png = (const char*) resource_AiassAudioProcessorEditor_redledoff_png;
const int AiassAudioProcessorEditor::redledoff_pngSize = 2598;

// JUCER_RESOURCE: redledon_png, 2874, "../images/red-led-on.png"
static const unsigned char resource_AiassAudioProcessorEditor_redledon_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,40,0,0,0,40,8,6,0,0,0,140,254,184,109,0,0,0,1,115,82,71,66,0,174,206,
28,233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,21,56,0,0,21,56,1,58,216,253,109,0,0,10,207,73,68,65,84,88,71,157,88,107,108,28,213,25,61,51,251,176,119,253,136,29,219,117,
108,199,206,195,177,3,4,210,132,128,138,0,55,69,170,74,20,82,168,162,34,170,34,64,137,218,170,82,90,254,65,254,180,20,84,104,165,20,245,7,82,90,248,209,226,31,173,40,18,138,160,18,65,21,81,17,9,149,104,
35,210,212,56,248,145,216,9,142,29,219,137,223,246,122,189,222,221,153,158,115,119,238,102,29,236,144,112,164,111,231,206,157,187,247,59,243,189,238,189,227,224,43,98,231,206,157,126,115,115,51,234,234,
234,80,86,86,134,104,52,10,215,117,205,51,207,243,176,184,184,136,153,153,25,12,15,15,163,175,175,15,199,143,31,255,74,186,110,250,79,123,247,238,245,219,218,218,176,102,205,26,164,82,41,204,207,207,35,
147,201,24,82,190,239,155,49,142,227,24,178,225,112,24,241,120,28,69,69,69,24,25,25,193,137,19,39,112,228,200,145,155,210,121,195,131,159,122,234,41,127,207,158,61,88,88,88,192,236,236,172,33,39,82,55,
2,145,21,73,107,233,247,222,123,15,237,237,237,55,164,251,75,7,221,118,219,109,254,129,3,7,140,37,166,167,167,141,235,100,41,35,142,139,108,40,140,76,40,138,76,152,194,233,212,31,242,61,20,33,139,34,63,
139,176,151,145,207,243,255,17,193,138,138,10,204,205,205,225,240,225,195,232,234,234,186,46,135,235,62,60,120,240,160,191,101,203,22,76,76,76,32,153,76,26,139,101,233,69,63,86,130,76,105,37,18,209,82,
148,37,198,81,63,218,139,53,87,250,81,58,63,133,44,7,204,68,74,112,190,172,30,189,149,107,49,83,188,10,21,164,94,87,228,162,216,203,2,89,18,38,98,177,24,42,43,43,209,217,217,137,67,135,14,173,200,99,197,
7,47,191,252,178,47,171,41,208,51,153,52,178,30,45,16,43,3,170,190,134,210,228,20,238,253,207,27,184,167,227,35,56,227,28,28,162,68,41,202,17,133,161,60,159,166,16,217,114,224,232,134,251,240,247,245,
223,64,106,85,53,214,197,194,40,225,32,159,100,229,250,242,242,114,99,205,103,159,125,118,89,46,203,118,62,247,220,115,126,77,77,77,64,46,131,12,201,21,213,52,32,82,18,199,67,71,95,194,150,158,207,128,
141,45,36,187,5,88,72,195,27,225,253,228,121,56,34,234,5,83,242,63,142,136,46,82,82,20,118,127,176,97,11,254,176,245,33,212,242,197,27,74,139,225,113,110,37,148,72,142,142,142,226,197,23,95,252,2,31,77,
185,4,202,82,185,117,114,114,210,196,219,34,21,69,235,154,176,202,73,225,7,127,249,41,154,43,86,3,143,254,10,216,244,109,250,169,154,68,74,224,132,27,224,39,198,104,181,105,56,38,145,165,39,16,18,112,
34,185,230,134,203,87,112,251,100,63,142,86,108,68,50,82,140,178,112,200,144,84,226,85,87,87,43,145,158,239,238,238,126,65,51,88,228,10,87,128,205,155,55,251,15,62,248,32,166,166,166,242,228,202,215,183,
96,211,84,63,158,126,253,0,234,127,244,123,224,39,175,3,113,146,156,24,1,166,174,0,115,36,182,48,67,119,221,146,115,173,8,74,24,110,70,20,179,100,231,75,83,49,147,238,210,48,222,124,247,21,68,250,206,
224,236,116,2,30,147,44,155,205,26,157,210,221,218,218,106,94,209,98,9,193,39,158,120,2,99,99,99,38,33,146,139,25,196,26,54,160,241,114,47,126,120,228,37,224,149,19,64,235,253,192,232,5,146,154,164,181,
232,55,5,60,45,128,12,219,105,178,243,100,42,194,146,180,48,109,146,164,53,69,82,56,252,209,223,16,189,120,14,253,243,172,10,161,144,49,136,188,38,14,133,200,19,220,191,127,191,31,137,68,76,192,38,89,
227,202,155,54,162,37,53,140,199,223,253,53,240,214,32,221,89,5,140,93,2,146,243,140,43,102,128,8,114,92,94,22,147,36,66,178,5,150,91,34,65,191,172,137,112,174,253,167,99,111,194,235,235,194,231,115,172,
16,236,146,110,149,161,125,251,246,153,87,18,12,65,118,250,219,183,111,55,102,86,1,118,98,165,168,171,169,194,163,175,254,2,104,239,226,8,134,234,196,48,73,44,80,24,245,105,17,44,20,18,91,156,227,184,
252,188,57,20,16,203,131,101,200,140,18,73,78,251,218,199,111,225,226,200,21,204,179,211,186,122,219,182,109,134,147,134,25,130,187,119,239,206,199,93,154,10,107,90,110,197,246,247,95,69,228,225,239,48,
91,25,91,19,163,57,34,114,39,39,201,185,213,10,239,249,8,184,124,213,90,215,138,160,171,41,162,185,54,107,54,192,136,40,153,245,240,104,223,41,244,79,207,154,132,146,126,85,143,93,187,118,233,95,57,130,
45,45,45,72,36,18,212,151,129,31,137,34,90,83,135,29,239,191,15,236,251,13,245,78,208,133,180,92,33,57,115,85,204,81,164,40,227,179,170,208,194,70,57,93,24,144,176,68,140,136,156,133,125,198,161,170,159,
251,207,159,194,96,50,141,52,9,106,181,209,250,46,78,130,219,216,216,232,107,233,81,170,203,189,171,26,214,225,150,238,15,233,102,62,189,117,7,51,149,149,216,184,145,174,149,123,243,18,184,54,77,45,201,
51,185,186,23,40,54,194,119,224,74,103,224,22,88,46,239,114,123,79,19,69,103,128,187,7,186,48,146,200,173,86,74,210,213,171,87,99,237,218,181,190,91,91,91,107,136,201,255,41,42,86,89,217,122,252,175,192,
29,27,249,111,34,197,224,151,27,37,178,156,21,77,206,21,23,243,67,240,146,76,30,89,67,63,129,98,227,66,194,144,179,8,158,229,161,113,129,21,31,27,248,12,3,228,161,76,55,92,216,22,55,183,190,190,222,184,
87,190,247,184,20,84,115,181,88,219,213,147,115,159,96,172,20,36,134,44,39,23,155,162,70,114,131,31,195,27,61,105,120,25,126,82,46,238,20,193,146,163,113,115,86,11,250,243,68,109,63,167,251,22,183,99,
41,230,65,134,111,166,80,19,167,134,134,6,184,90,102,196,86,157,69,101,229,40,83,225,101,213,64,39,235,221,197,33,160,156,171,133,102,16,95,151,175,26,93,69,171,205,195,251,164,29,222,96,167,121,164,242,
134,44,127,68,142,77,33,111,185,128,88,110,133,201,181,243,196,108,91,255,231,251,87,204,205,34,153,205,237,124,196,73,220,92,213,29,155,189,145,88,28,197,211,204,88,254,65,37,205,123,242,118,224,108,
7,80,202,149,35,78,98,227,151,224,125,240,26,188,163,92,81,166,38,225,144,175,227,106,176,36,167,75,63,133,49,103,172,103,161,182,200,4,207,150,128,4,107,22,18,152,103,108,203,197,226,36,110,242,149,233,
144,184,225,8,162,138,57,161,130,50,60,5,239,153,239,194,59,248,0,188,223,126,31,94,251,47,129,158,78,179,41,16,57,99,186,64,153,137,57,202,114,49,183,36,121,150,17,93,68,60,38,98,20,89,80,124,4,87,89,
99,69,37,84,15,115,255,224,127,226,20,22,84,103,130,155,128,217,100,142,152,178,91,86,51,102,230,133,243,220,80,182,174,212,111,239,21,66,212,237,113,27,86,200,201,149,107,45,82,243,9,164,226,165,230,
143,230,173,101,161,16,37,66,9,7,109,227,35,34,80,96,44,71,44,103,185,60,236,253,10,253,38,134,137,89,158,97,92,198,132,136,9,114,179,171,170,173,14,153,116,250,202,101,76,87,52,228,215,74,51,193,181,
111,108,133,125,215,102,235,146,241,132,137,191,130,241,182,127,201,189,218,140,119,97,144,75,108,132,29,34,38,78,58,251,184,218,206,135,184,155,16,102,39,198,49,21,229,126,183,138,1,166,76,182,19,88,
20,76,108,187,243,228,10,21,10,65,219,89,174,191,240,94,32,193,100,220,197,100,156,123,75,238,222,21,102,226,52,62,62,14,87,219,43,75,144,102,196,232,200,48,206,222,122,95,142,160,133,38,43,16,51,55,127,
150,196,156,233,12,192,182,217,88,47,211,191,172,48,202,142,213,174,69,140,60,124,150,59,89,79,156,196,205,237,233,233,49,17,32,214,97,238,112,199,250,122,208,189,141,11,53,119,85,206,181,4,116,27,92,
151,141,185,107,100,197,236,45,32,111,44,204,250,255,78,253,122,84,112,127,233,5,89,172,163,64,111,111,47,207,141,132,54,138,130,58,7,63,251,20,159,110,184,19,88,195,64,228,30,193,4,146,38,227,68,87,99,
142,63,129,130,37,46,43,148,107,251,11,239,11,251,233,41,175,212,193,135,181,141,40,33,57,45,24,226,33,235,9,134,32,153,230,138,34,79,89,233,196,28,70,206,252,23,199,30,249,57,192,45,158,163,36,231,68,
87,179,85,191,193,141,85,98,97,239,87,234,183,150,11,224,40,57,104,189,231,239,184,27,53,92,25,66,44,49,178,158,184,156,59,119,206,140,49,4,59,58,58,28,203,92,159,43,254,247,193,49,28,111,190,7,189,59,
219,0,238,52,156,116,110,214,28,57,66,183,214,34,130,37,16,244,235,248,107,80,56,78,237,96,121,87,219,188,120,2,248,71,203,58,188,221,184,17,229,218,176,144,131,160,210,39,78,106,27,130,194,201,147,39,
13,57,145,140,120,25,124,114,244,29,188,241,200,211,88,104,228,18,199,137,220,128,164,217,116,90,133,130,109,7,68,236,210,246,133,236,21,130,113,198,114,12,159,201,213,69,120,102,199,253,168,226,234,229,
46,230,62,165,232,216,33,46,22,121,130,125,125,125,142,234,142,178,71,68,103,46,13,226,204,71,31,226,143,63,254,29,210,149,60,233,104,5,180,241,104,161,246,50,217,122,189,165,205,156,149,25,119,137,178,
8,30,123,96,15,74,121,198,137,114,47,42,215,42,196,180,179,23,23,142,50,200,19,20,78,157,58,133,226,226,226,220,199,158,104,4,67,157,29,56,59,50,134,246,39,185,6,107,228,52,69,111,111,150,165,27,144,66,
242,20,99,57,86,7,245,255,236,155,187,48,205,121,98,243,115,240,105,57,121,78,177,119,250,244,105,14,184,138,160,0,230,192,61,216,11,28,248,188,14,209,50,183,62,79,124,222,219,141,201,202,90,244,60,252,
56,90,135,186,80,122,145,25,47,197,246,29,229,70,75,88,23,185,208,222,235,74,200,221,142,42,2,165,187,169,6,143,239,254,30,206,167,179,136,203,99,129,229,68,78,201,122,225,194,133,188,245,132,37,55,22,
119,221,117,151,175,221,172,142,1,90,118,22,24,180,213,205,173,216,124,111,27,218,122,254,141,189,239,252,153,123,69,106,215,25,87,203,98,240,229,192,112,100,183,153,84,73,32,81,193,215,131,82,23,135,
238,127,0,111,215,173,227,38,119,20,17,86,139,48,173,166,144,210,135,36,125,250,96,236,125,129,207,178,4,133,77,155,54,249,20,179,113,20,201,69,146,76,82,81,229,166,86,212,127,125,7,90,156,20,238,236,
56,137,182,211,255,66,245,192,136,73,164,124,150,10,220,245,12,213,86,227,104,203,86,252,115,99,51,186,179,46,50,195,67,136,50,198,98,100,44,171,41,214,245,221,80,150,235,239,239,95,150,203,138,4,5,186,
218,215,25,85,238,86,234,107,67,161,107,146,199,128,120,85,21,15,247,235,81,220,216,4,183,168,24,69,92,5,162,202,68,158,93,166,73,96,134,9,149,157,153,70,134,27,16,73,136,47,26,225,54,77,196,36,202,86,
93,21,115,44,202,43,242,184,46,65,129,177,225,111,221,186,213,124,29,149,37,69,82,25,39,210,170,157,186,58,84,20,98,12,193,13,49,216,21,135,220,211,241,153,242,74,193,111,73,9,114,169,226,77,21,131,181,
78,115,94,151,195,151,18,180,208,71,29,29,98,10,173,41,136,108,225,213,66,196,10,175,34,102,173,54,52,52,100,214,89,243,224,75,112,195,4,45,154,154,154,124,125,64,87,96,23,90,81,4,45,73,145,178,150,83,
156,233,170,179,174,62,164,15,12,12,220,148,206,155,38,88,136,186,186,58,191,164,164,196,4,186,181,142,96,173,172,4,211,241,113,120,120,248,43,234,1,254,15,127,166,111,32,74,38,84,125,0,0,0,0,73,69,78,
68,174,66,96,130,0,0};

const char* AiassAudioProcessorEditor::redledon_png = (const char*) resource_AiassAudioProcessorEditor_redledon_png;
const int AiassAudioProcessorEditor::redledon_pngSize = 2874;

// JUCER_RESOURCE: reset_png, 4767, "../images/reset.png"
static const unsigned char resource_AiassAudioProcessorEditor_reset_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,138,0,0,0,48,8,6,0,0,0,206,214,226,119,0,0,0,1,115,82,71,66,0,174,206,
28,233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,14,195,0,0,14,195,1,199,111,168,100,0,0,18,52,73,68,65,84,120,94,237,92,9,120,20,85,182,254,107,233,37,221,233,44,36,233,236,
11,9,73,16,144,85,65,222,176,40,40,62,23,28,28,29,183,225,205,155,209,153,199,12,31,136,136,35,50,15,5,117,192,231,6,184,224,2,46,32,227,8,168,163,207,25,71,36,160,12,178,171,64,64,20,2,132,108,157,181,
147,116,119,150,94,171,234,157,123,187,147,9,16,37,194,251,76,131,253,231,59,233,234,170,91,183,110,221,251,223,243,159,115,187,186,17,65,4,61,129,16,122,61,107,212,191,184,196,165,84,86,88,4,85,225,239,
61,91,139,224,175,169,162,173,115,174,58,130,179,130,10,93,106,54,162,198,78,224,239,52,73,15,185,176,208,158,248,159,211,146,248,142,179,196,89,141,102,221,139,75,29,90,121,105,108,219,182,77,80,108,
85,188,18,69,208,224,86,5,184,21,1,126,106,172,170,105,193,194,17,252,160,16,5,1,58,136,48,74,26,76,162,6,153,198,132,141,132,156,158,14,195,229,147,144,182,232,217,179,26,243,239,117,82,195,250,55,218,
28,207,60,110,10,16,57,32,40,112,4,4,84,5,2,176,169,42,92,126,21,94,94,29,145,132,94,132,179,227,96,4,231,8,141,254,36,141,145,67,64,20,77,222,24,89,66,134,36,34,67,214,33,86,84,136,48,57,48,141,189,2,
169,255,243,220,247,26,160,30,23,174,154,55,75,107,223,186,9,30,91,5,202,136,28,165,94,21,118,149,53,135,42,33,202,106,244,79,213,27,17,147,148,140,232,184,88,232,204,209,16,37,41,66,151,31,8,204,107,
168,138,130,64,123,27,90,29,78,184,26,234,32,120,221,52,105,5,144,99,129,168,2,137,178,128,66,189,132,52,157,12,61,121,24,211,184,171,144,241,88,207,60,204,25,11,53,188,177,194,99,127,121,153,65,169,170,
66,21,121,142,175,220,62,184,152,203,32,8,212,136,132,190,121,72,25,50,4,214,254,131,16,151,154,14,65,150,73,134,190,7,3,35,248,127,5,35,12,169,14,52,154,204,174,186,26,212,31,57,132,154,3,197,104,60,
118,20,42,141,31,131,149,198,109,144,73,135,68,38,77,25,89,232,191,253,235,51,14,215,119,22,168,125,97,169,226,88,243,146,216,82,93,133,131,30,13,149,196,88,141,36,71,150,140,72,31,49,18,57,99,198,193,
156,96,165,125,161,19,34,8,75,48,143,223,234,176,163,98,199,54,84,237,222,13,213,239,161,125,26,242,117,2,242,13,58,152,211,178,16,63,109,150,63,249,87,211,244,161,83,78,195,183,14,113,205,115,79,41,13,
107,87,138,206,74,27,246,182,43,112,105,42,191,96,98,255,1,232,119,213,36,24,99,226,200,173,73,20,54,5,179,157,8,194,24,52,110,124,172,52,146,166,214,54,148,124,178,17,117,95,21,115,239,147,40,2,195,163,
244,48,103,166,194,122,231,61,254,228,187,166,119,75,150,110,137,98,123,105,169,210,252,198,203,98,67,21,145,132,164,198,75,82,35,24,244,200,27,63,1,9,68,148,8,206,127,56,143,149,160,100,115,17,84,138,
99,98,73,138,134,154,100,196,100,100,34,105,250,125,222,148,169,191,49,134,138,117,226,52,162,212,172,91,227,174,91,246,168,209,89,85,131,253,68,146,118,114,35,146,209,132,126,19,39,33,42,49,145,78,136,
232,204,133,0,150,29,249,154,155,113,172,168,8,190,246,22,196,8,34,134,69,137,48,165,103,96,232,206,35,167,13,242,105,59,246,94,86,160,185,171,107,112,192,227,67,171,66,238,138,162,228,156,177,227,161,
143,235,19,161,200,5,6,38,61,254,22,39,78,124,182,5,154,219,139,4,138,130,11,141,58,24,211,50,49,124,215,55,39,13,247,73,111,74,254,120,183,102,255,243,107,40,245,107,168,165,168,153,33,121,200,112,152,
146,172,17,146,92,136,96,76,33,197,240,54,54,161,122,223,94,122,175,33,71,47,32,85,22,145,116,231,239,213,252,133,79,74,193,130,167,16,229,139,81,253,53,123,85,37,142,120,85,202,100,84,24,19,83,16,159,
155,71,245,69,4,231,194,134,6,103,121,5,220,181,54,176,69,151,193,122,25,166,204,12,140,218,121,184,115,216,59,55,14,207,155,169,213,146,55,41,243,41,112,104,34,68,98,90,92,191,124,8,146,46,84,34,130,
11,25,130,162,160,241,248,49,122,13,32,158,252,72,6,91,152,155,250,91,20,46,94,198,57,210,73,148,157,163,46,210,26,171,42,80,230,15,166,187,178,217,2,93,124,60,165,191,204,63,69,112,161,131,169,134,223,
225,128,191,213,197,73,209,207,32,32,38,45,27,163,119,7,189,10,255,119,104,193,92,165,246,213,231,197,26,63,200,155,4,137,98,48,69,65,208,25,73,194,212,83,4,42,130,11,14,228,11,52,202,122,16,240,194,211,
214,206,119,89,37,137,7,183,25,115,30,108,43,156,61,47,58,72,148,185,51,181,202,55,87,195,230,245,193,31,34,133,32,210,137,17,252,232,160,133,150,249,201,161,32,85,39,35,235,23,191,198,128,199,159,19,
56,45,254,57,114,144,230,180,157,64,45,201,142,22,220,197,87,97,67,156,137,224,71,2,22,100,116,124,28,35,64,225,68,177,164,101,225,242,61,135,5,161,108,237,154,154,175,238,155,150,226,9,8,104,102,203,
244,17,122,252,232,17,140,74,53,244,161,160,214,72,142,227,58,91,187,32,124,253,244,34,207,241,165,139,12,109,20,154,184,89,56,18,249,132,47,2,2,123,108,196,36,171,48,83,236,114,209,19,47,212,139,158,
230,38,131,166,8,96,202,36,10,42,52,202,163,35,22,49,182,60,162,146,107,81,232,159,167,169,81,47,130,242,103,133,197,173,26,37,72,228,102,116,36,61,225,96,114,55,251,186,218,153,142,71,236,220,140,113,
129,129,61,91,164,122,189,58,246,224,19,133,45,65,85,146,184,244,176,199,9,122,219,20,72,68,94,201,104,128,108,50,158,100,162,81,7,153,50,50,73,96,105,124,160,155,115,123,215,68,106,151,68,61,42,81,159,
178,53,168,238,202,156,15,38,49,119,194,238,64,149,16,240,121,204,194,231,15,204,210,202,222,88,129,64,152,197,38,166,126,185,24,253,232,82,200,150,232,208,30,230,244,52,40,237,94,180,86,149,163,122,75,
17,106,54,111,228,143,254,133,19,204,233,25,232,51,98,52,84,73,131,251,120,41,154,14,178,207,80,66,7,207,67,232,136,23,125,103,206,134,176,251,129,123,180,210,213,43,104,6,16,147,66,238,38,28,16,55,104,
24,46,95,255,55,72,177,125,120,63,51,150,119,128,17,70,245,120,80,186,230,53,20,63,182,0,154,223,123,206,43,200,29,181,159,105,245,232,76,229,210,38,223,132,81,203,86,242,190,60,241,230,235,216,251,208,
28,222,222,243,109,85,138,221,39,107,55,107,121,254,140,123,33,242,55,100,236,198,194,201,24,58,134,94,115,123,80,251,73,17,170,55,110,64,91,233,113,126,19,236,25,153,172,155,111,65,124,94,1,149,39,34,
157,114,62,55,146,40,110,221,29,235,106,84,134,61,8,46,246,160,44,43,195,31,26,239,166,44,253,131,40,83,61,100,208,201,208,72,63,123,116,253,48,54,206,13,246,183,107,238,61,218,241,85,43,161,167,104,133,
5,136,106,56,80,159,24,18,119,241,197,24,187,238,99,200,49,177,240,54,212,224,147,27,38,192,95,87,131,168,220,2,140,125,227,109,24,210,179,1,191,31,187,167,221,129,234,143,63,162,150,179,27,162,177,146,
13,136,27,50,12,41,151,79,132,41,43,135,162,118,5,109,7,15,162,114,227,135,112,87,151,145,230,82,25,86,142,58,64,151,156,140,244,43,175,69,236,208,97,208,69,199,243,103,50,218,171,202,224,60,84,140,154,
29,159,2,45,173,124,70,105,212,39,166,244,76,36,83,217,132,129,131,0,163,30,110,91,37,234,54,21,193,190,255,11,8,1,31,4,73,143,180,107,175,71,234,164,235,145,62,229,22,190,36,238,252,98,39,170,55,252,
157,119,182,235,155,131,176,111,221,18,140,7,131,243,32,172,193,22,92,3,212,86,47,17,226,162,89,247,65,216,65,68,57,186,106,5,204,52,9,24,81,120,33,254,191,119,97,25,124,49,198,172,221,240,47,162,92,51,
30,254,90,27,244,230,24,92,182,246,175,136,29,62,26,154,207,135,61,191,189,29,245,155,54,50,215,72,163,105,68,254,239,103,161,239,175,127,7,125,12,73,22,155,21,84,151,170,249,209,118,236,8,246,255,241,
94,52,239,222,197,247,233,147,172,184,244,185,149,136,27,61,134,2,80,29,95,55,232,152,65,129,246,86,236,186,117,50,154,247,127,73,251,68,196,95,49,17,67,22,44,134,57,59,159,123,20,6,18,106,40,174,38,148,
44,95,134,19,175,44,231,159,178,143,92,179,30,137,151,141,227,189,204,206,35,150,242,178,172,206,242,181,107,112,104,238,221,156,40,225,206,19,230,201,153,249,232,46,217,151,250,6,207,91,224,16,5,202,
44,184,30,81,235,217,58,10,203,159,133,48,48,114,216,156,213,29,205,54,152,204,208,91,44,48,13,30,66,1,99,14,4,85,37,15,83,75,82,116,52,216,110,202,253,51,174,255,25,10,126,119,15,244,241,9,240,80,192,
123,108,229,179,168,88,187,10,106,155,27,150,194,65,24,246,208,98,24,173,73,148,49,9,72,30,55,1,241,35,199,208,85,36,216,63,219,132,99,75,158,192,241,229,75,209,64,18,167,53,53,81,125,36,47,84,111,116,
118,54,134,47,124,2,209,185,133,148,38,182,163,250,221,245,188,92,219,137,18,34,113,60,46,186,123,14,82,198,95,73,253,167,34,80,81,14,31,145,153,145,129,145,195,231,112,16,65,143,82,80,123,12,129,250,
106,242,76,204,157,119,127,191,225,100,140,3,58,222,247,34,20,34,6,147,121,49,42,41,197,197,110,140,125,231,131,13,14,251,150,153,28,6,198,102,55,3,11,167,116,177,137,184,116,249,43,24,181,238,3,140,126,
97,53,100,107,50,124,77,13,56,254,226,18,4,202,203,105,6,139,148,58,155,145,117,219,237,16,76,209,80,90,91,80,60,127,54,74,23,207,199,145,249,115,80,181,254,45,146,28,13,81,3,134,194,58,126,2,159,209,
230,148,20,138,35,244,228,149,60,56,178,114,57,142,190,240,4,74,30,127,24,95,146,148,237,184,253,6,180,210,224,202,130,132,228,127,191,30,198,236,92,78,90,219,91,107,80,252,223,51,80,242,228,35,56,52,
255,126,40,158,118,8,230,88,100,222,54,21,178,162,208,53,231,224,240,147,127,130,236,231,189,140,186,13,239,97,219,79,199,99,235,13,227,112,236,185,167,33,83,31,119,119,175,225,104,172,255,249,247,128,
72,171,205,105,25,45,226,208,25,179,99,105,63,252,36,196,236,123,125,82,136,81,189,109,18,205,72,54,163,69,34,129,100,208,35,102,240,48,196,15,30,1,41,41,137,92,186,31,181,255,248,27,108,239,172,35,207,
18,128,158,110,38,42,49,25,150,236,66,162,21,201,130,215,141,196,81,63,65,223,233,179,145,61,109,58,116,105,86,126,227,146,78,135,196,161,35,137,0,128,183,182,142,199,56,162,222,132,17,139,150,98,196,
179,175,162,96,206,124,164,142,187,26,106,107,27,4,87,35,100,145,149,31,65,193,43,197,41,84,177,174,79,2,250,221,57,3,253,168,222,196,177,227,233,66,10,79,127,44,249,3,160,179,196,65,160,76,76,32,57,164,
70,83,79,82,251,253,1,128,210,119,129,76,100,153,25,187,175,83,238,51,156,205,75,125,105,201,204,66,191,201,55,102,113,193,141,74,207,130,91,83,120,103,134,141,177,134,209,43,251,178,59,147,142,154,183,
223,130,253,163,255,133,234,116,82,202,163,67,218,77,183,33,227,150,59,58,179,10,201,28,77,102,14,110,39,36,35,111,250,125,40,184,127,1,242,239,127,20,105,87,79,225,117,49,232,227,173,116,190,0,251,246,
79,224,220,185,149,194,136,0,12,20,244,38,95,51,5,121,51,231,96,240,75,175,99,228,234,181,176,12,26,14,145,125,245,210,146,192,207,19,232,156,212,159,222,66,245,61,68,245,62,132,220,105,179,33,71,199,
242,99,162,201,64,68,33,247,204,218,29,186,14,3,219,238,216,119,190,25,91,173,247,17,39,82,175,184,138,223,11,127,120,118,214,212,219,23,214,237,223,11,11,233,178,158,175,243,243,73,209,171,22,101,77,
69,218,205,191,128,104,136,130,223,97,199,129,153,191,65,205,95,223,130,226,243,162,15,5,140,162,209,72,113,67,30,26,55,125,4,205,233,130,20,23,131,244,155,166,66,32,61,13,52,213,195,246,151,215,208,180,
99,59,156,123,182,193,249,249,14,56,41,136,117,238,222,142,230,61,59,224,57,242,13,208,214,130,186,173,159,192,83,242,13,149,111,36,25,105,37,254,25,33,91,98,161,79,77,167,24,69,128,99,203,102,36,144,
244,152,242,242,41,5,80,81,255,225,123,176,23,125,4,199,231,59,169,206,109,112,236,217,78,182,11,174,221,84,255,151,148,253,120,219,96,41,24,128,164,107,38,51,53,132,171,184,24,77,159,110,36,201,97,234,
24,30,253,218,83,115,147,179,108,33,185,78,188,100,52,86,109,219,249,48,247,40,134,244,172,182,0,249,80,87,232,55,78,194,5,212,222,78,136,170,159,40,238,134,253,237,181,104,63,124,144,98,6,210,210,172,
44,164,220,112,51,29,36,53,106,172,167,64,178,58,88,150,102,68,253,251,239,162,252,169,5,56,241,228,163,40,123,234,79,56,177,116,17,106,215,173,129,147,210,94,129,234,146,163,162,33,180,182,162,254,189,
181,20,199,204,194,190,95,222,136,253,211,239,128,223,213,192,131,123,75,78,30,15,62,221,71,15,147,196,80,162,72,117,186,191,62,128,242,165,139,113,226,137,71,120,157,204,170,87,60,79,228,249,16,26,73,
21,255,60,36,160,208,43,19,64,137,188,76,44,151,59,214,243,108,150,158,79,96,92,136,202,236,139,241,143,45,225,13,231,30,229,149,13,69,139,111,43,204,93,216,226,112,34,65,71,129,33,233,19,187,177,174,
12,251,161,77,111,77,33,143,242,31,16,12,6,40,148,174,86,175,125,157,188,64,59,5,23,237,20,129,155,17,55,118,28,36,81,15,99,98,34,26,55,124,64,146,212,76,231,36,35,238,210,209,20,208,154,16,91,112,17,
20,175,15,250,62,73,136,165,56,35,99,234,93,232,123,207,60,184,14,21,195,87,89,6,235,213,215,34,111,238,67,144,19,18,161,143,142,129,41,57,29,49,63,25,143,248,209,99,73,114,244,104,249,106,63,26,255,254,
62,252,237,46,36,95,117,29,5,173,22,68,247,31,0,69,210,32,27,140,176,244,235,143,164,201,55,34,247,15,243,96,74,74,71,243,214,141,156,217,44,240,182,78,185,9,170,94,135,168,20,43,162,7,14,129,117,236,
68,34,178,29,190,186,234,110,239,53,156,140,101,132,236,231,75,106,40,212,202,191,241,231,88,189,99,207,195,140,35,220,163,48,100,94,55,69,245,81,64,107,247,243,100,153,127,35,94,238,69,99,68,165,151,
78,176,53,30,246,161,37,155,238,141,20,171,4,42,43,169,144,6,99,223,124,196,77,152,68,71,85,212,172,126,5,142,205,255,128,66,25,136,137,92,102,255,167,95,194,224,85,235,80,248,204,171,176,254,242,46,232,
82,40,53,166,217,78,42,0,24,163,16,63,102,34,242,30,92,140,1,175,190,133,129,175,189,131,188,25,115,73,234,76,80,154,155,209,244,254,59,20,192,122,224,41,222,139,242,151,151,65,105,105,132,68,1,115,254,
31,30,193,160,215,215,161,255,202,55,209,247,222,7,97,30,56,28,26,95,131,162,160,155,234,117,31,61,132,182,253,95,240,235,200,113,73,176,94,247,51,88,111,190,29,198,220,92,62,16,76,134,186,187,223,112,
48,214,126,22,181,55,248,84,24,178,51,145,52,98,148,135,245,61,3,247,40,12,171,183,110,127,228,230,194,156,133,205,205,14,244,145,101,24,200,181,179,116,185,183,76,142,50,194,152,156,10,79,69,25,124,71,
14,193,190,165,8,34,197,17,124,218,82,22,161,177,135,192,41,195,240,149,149,82,140,226,64,235,190,47,200,243,180,192,177,109,11,252,52,115,245,34,95,103,230,203,255,254,202,10,184,62,219,138,218,85,43,
224,216,177,149,178,29,242,76,30,31,101,37,36,103,94,15,68,146,11,182,120,231,39,249,114,237,218,142,170,103,30,67,243,167,27,248,130,25,27,112,215,87,251,224,57,88,76,228,37,50,80,28,39,122,252,80,236,
117,104,37,66,212,189,251,23,52,188,179,6,106,83,51,79,161,5,175,31,205,95,238,2,28,205,8,212,215,193,91,126,12,238,227,37,104,249,236,159,240,84,149,241,229,135,238,238,55,92,172,133,172,130,250,165,
224,198,91,241,111,115,30,232,252,174,14,245,250,191,240,229,170,149,158,207,159,121,202,32,217,202,49,208,72,29,205,24,214,75,96,193,160,38,235,248,243,16,92,243,3,62,150,112,146,55,32,189,167,227,10,
229,184,146,160,227,191,238,196,82,87,182,140,206,192,127,56,134,109,144,235,151,244,122,58,32,65,243,123,160,82,170,170,41,62,170,139,78,224,222,138,166,54,27,116,89,15,205,160,227,75,255,170,143,165,
183,126,42,203,156,111,135,179,13,118,2,91,80,19,37,61,151,66,86,86,243,83,123,88,157,236,186,236,75,252,140,148,188,28,107,101,48,112,13,80,251,249,10,45,3,121,106,65,99,143,69,176,214,135,39,88,132,
90,236,13,64,166,44,120,218,190,146,147,26,122,90,171,63,158,51,67,219,191,122,5,50,245,50,242,100,246,84,5,139,87,66,7,123,1,172,243,249,229,59,55,130,96,228,224,160,125,156,208,161,99,157,187,105,163,
99,187,227,24,223,215,81,158,192,94,58,170,228,187,216,27,218,232,216,119,242,193,224,185,193,13,50,218,238,122,93,142,80,57,6,126,157,208,54,3,39,115,215,29,225,4,106,27,11,214,15,81,76,103,167,236,110,
216,127,205,84,39,45,94,210,169,54,12,221,54,253,249,33,185,90,171,173,26,5,52,43,179,228,111,41,20,193,121,143,46,188,70,9,121,199,19,228,245,226,51,178,48,125,255,209,211,134,252,91,57,240,236,144,60,
173,217,86,137,193,148,222,229,80,38,196,92,106,4,23,14,216,104,178,193,103,227,122,196,163,161,212,167,32,54,51,27,51,139,79,150,156,14,124,167,179,96,100,113,84,217,208,151,136,50,192,64,122,78,165,
121,230,17,193,5,1,55,165,127,7,221,10,108,148,37,198,101,230,96,214,41,113,73,87,124,39,81,24,158,30,76,100,33,207,210,71,20,113,9,5,184,49,36,69,124,97,233,140,103,70,16,174,96,241,124,189,95,196,129,
118,31,156,20,132,199,101,100,226,222,3,199,191,115,68,123,52,220,31,80,128,123,116,211,70,184,42,75,145,67,153,196,64,242,46,38,30,204,119,200,17,171,166,235,54,67,68,170,122,7,167,246,127,215,247,2,
156,148,242,31,242,144,23,161,120,36,38,43,27,5,215,222,160,78,126,236,233,147,2,215,238,208,35,162,48,236,123,119,125,235,166,71,230,155,155,170,74,249,227,252,169,58,9,249,148,21,37,83,122,25,252,193,
191,208,66,86,40,173,100,191,30,25,193,15,15,129,173,254,133,192,151,22,40,221,242,81,138,94,231,11,224,104,64,225,95,27,102,207,216,244,159,48,9,83,150,44,239,241,248,247,184,96,7,62,90,180,176,221,99,
175,139,42,217,188,25,14,34,13,251,200,62,69,212,33,129,54,44,164,73,81,36,81,70,246,236,96,144,53,17,252,208,32,93,241,8,42,218,168,251,93,196,148,70,74,119,237,1,31,188,52,46,241,233,125,145,63,241,
74,100,95,54,166,253,146,91,239,48,135,206,232,17,190,55,81,186,226,29,146,36,145,2,161,35,155,139,208,100,171,224,129,46,211,63,134,72,146,212,59,232,88,235,233,120,141,207,200,64,225,196,171,1,89,135,
155,158,60,187,223,193,103,56,39,162,116,197,103,175,190,92,239,176,85,196,248,93,45,134,224,147,81,17,166,244,10,4,1,146,36,193,24,27,235,142,207,201,117,94,54,245,87,169,161,35,231,0,224,255,0,27,187,
71,175,237,76,220,236,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* AiassAudioProcessorEditor::reset_png = (const char*) resource_AiassAudioProcessorEditor_reset_png;
const int AiassAudioProcessorEditor::reset_pngSize = 4767;

// JUCER_RESOURCE: aiasshintergrund_png, 3258, "../images/AIASS-Hintergrund.png"
static const unsigned char resource_AiassAudioProcessorEditor_aiasshintergrund_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,4,0,0,0,2,18,8,3,0,0,0,101,13,77,27,0,0,0,1,115,82,71,66,0,174,
206,28,233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,2,205,80,76,84,69,117,117,119,112,105,87,157,146,116,153,142,114,154,143,115,102,102,104,120,111,85,182,167,123,201,183,135,205,186,137,202,
184,136,204,185,137,105,105,108,124,115,89,163,150,112,172,157,117,201,184,137,205,187,139,205,188,140,110,110,111,82,77,65,104,96,77,97,90,73,112,104,82,126,115,90,123,113,89,122,113,89,111,110,111,82,
77,64,102,95,75,99,93,74,96,90,72,118,109,86,123,113,88,121,111,87,121,112,89,104,104,106,131,121,93,178,164,120,168,155,115,171,157,117,170,157,117,195,178,133,213,195,143,211,192,142,211,193,143,212,
193,143,77,71,60,93,87,70,90,84,69,91,85,70,89,84,69,97,91,74,104,97,77,103,96,77,109,110,110,87,82,67,110,102,80,105,99,78,107,100,79,106,99,78,117,108,86,126,117,91,125,115,90,126,116,91,103,103,106,
131,122,93,178,164,121,168,155,116,168,156,116,190,175,130,208,191,140,205,188,138,206,189,140,108,108,110,95,88,70,121,112,87,116,107,84,117,109,84,116,108,84,129,119,92,139,128,98,137,127,97,138,128,
98,112,112,112,69,65,56,82,76,64,80,75,62,86,81,66,176,163,120,167,154,115,170,156,117,167,155,115,189,173,129,206,189,139,204,187,138,205,188,139,106,106,108,111,103,80,146,135,102,139,129,99,141,131,
100,139,130,99,156,144,109,168,154,116,169,155,117,113,112,112,67,63,54,78,73,61,75,71,60,76,72,61,86,80,66,85,80,65,112,103,81,147,136,102,140,129,99,142,131,100,140,130,99,157,145,110,171,156,117,169,
155,116,104,104,107,126,116,89,168,156,115,160,147,111,162,149,112,160,149,111,180,165,124,196,180,133,195,178,132,196,179,133,111,111,111,79,74,61,94,88,71,93,88,70,102,95,76,109,101,81,108,100,80,110,
110,110,85,79,65,101,95,76,103,96,76,101,96,76,112,105,82,119,111,87,120,111,87,136,125,95,184,170,124,174,161,120,177,163,121,174,162,120,198,181,134,215,198,145,213,196,144,214,197,145,109,109,110,92,
86,69,117,108,84,113,105,82,124,114,90,133,124,95,132,122,94,133,123,95,112,111,111,73,68,58,87,81,66,85,79,66,91,86,70,98,91,74,96,90,73,97,90,74,105,104,106,123,114,88,165,152,113,157,144,109,159,146,
110,157,145,109,177,162,121,193,177,131,191,176,131,105,105,107,120,111,86,161,149,110,153,141,106,155,143,107,153,142,106,172,158,118,187,172,128,185,170,127,186,171,128,119,110,86,159,147,109,151,139,
105,151,140,105,185,170,126,183,168,125,184,169,126,161,149,111,153,141,107,155,143,108,153,142,107,172,158,119,160,148,110,152,140,106,154,142,107,152,141,106,171,157,118,186,171,127,161,148,111,170,
156,118,187,172,127,105,106,108,160,148,111,184,168,125,181,167,124,182,168,125,161,148,110,151,139,106,139,129,97,136,126,96,137,127,95,137,127,96,160,148,109,153,140,106,136,127,95,130,121,91,130,122,
92,131,122,92,118,110,85,160,147,110,149,138,104,135,126,95,136,127,96,132,123,93,134,125,94,110,103,81,133,124,94,121,113,87,124,116,88,93,27,156,218,0,0,0,9,112,72,89,115,0,0,14,196,0,0,14,196,1,149,
43,14,27,0,0,9,118,73,68,65,84,120,94,237,214,251,247,216,3,29,199,241,79,150,91,137,150,203,104,115,173,49,33,182,18,202,165,137,41,125,163,11,185,204,165,175,91,69,247,146,138,66,46,185,79,55,148,138,
110,34,151,162,205,148,133,205,108,99,183,102,209,138,100,114,79,253,13,237,116,57,157,211,191,240,124,60,126,124,255,254,126,158,215,48,188,108,173,49,99,94,14,196,140,25,179,214,203,134,97,237,117,214,
93,111,253,87,188,18,72,121,197,250,235,173,187,206,218,195,6,175,218,112,163,87,143,29,251,26,32,100,236,216,87,111,180,225,171,54,24,54,222,100,211,205,198,109,190,197,107,129,144,45,54,31,183,217,166,
155,108,60,140,159,176,229,86,91,111,181,205,182,219,189,14,136,216,110,219,109,214,188,253,150,19,198,15,175,159,184,253,14,147,118,124,195,78,59,239,242,70,32,97,151,157,119,122,195,142,147,118,216,
126,226,235,135,241,187,238,54,121,202,155,222,188,251,91,118,7,34,222,178,251,155,223,52,101,242,110,187,142,31,246,216,115,175,183,190,109,239,125,246,221,239,237,64,196,126,251,238,179,247,219,222,
186,215,158,123,12,83,247,127,199,1,147,14,156,118,208,59,223,5,68,188,243,160,105,7,78,58,224,29,251,79,29,14,126,247,200,123,14,57,244,189,239,123,255,7,128,136,247,191,239,189,135,30,242,158,145,119,
31,60,28,118,248,7,143,56,226,136,35,167,76,158,2,68,76,158,114,228,154,183,255,224,225,135,13,83,39,30,117,244,244,99,142,61,238,248,15,1,17,199,31,119,236,49,211,143,62,106,226,212,97,244,132,19,79,
58,249,148,15,79,255,200,71,129,136,143,76,255,240,41,39,159,116,226,9,163,195,169,167,125,236,227,159,248,248,132,79,126,234,72,32,226,83,159,156,176,230,237,63,118,218,169,195,232,167,63,243,217,207,
157,254,249,51,190,48,29,136,248,194,25,159,63,253,115,159,253,204,167,71,135,47,126,233,204,179,190,252,149,179,207,57,247,171,64,196,185,231,156,253,149,47,159,117,230,151,190,56,156,119,254,214,187,
93,112,225,215,46,186,248,34,32,226,226,139,190,118,225,5,187,109,125,254,121,195,37,151,238,125,217,229,87,204,24,185,242,235,64,196,149,35,51,174,184,252,178,189,47,189,100,152,250,141,111,126,235,219,
87,93,125,205,119,190,11,68,124,231,154,171,175,250,246,183,190,249,141,169,195,181,223,251,254,184,31,204,184,238,250,31,254,8,136,248,225,245,215,205,248,193,184,239,127,239,218,225,199,63,249,233,13,
55,220,240,179,27,111,250,57,16,113,211,141,63,91,243,246,63,253,201,143,135,155,111,185,245,182,95,252,242,246,59,166,253,10,136,152,118,199,237,191,252,197,109,183,222,114,243,48,115,214,157,179,239,
250,245,111,238,158,243,91,32,98,206,221,191,249,245,93,179,239,156,53,115,24,189,231,222,251,102,207,157,62,239,254,249,64,196,253,243,166,207,157,125,223,189,247,140,14,51,71,30,88,176,112,209,131,22,
0,116,204,185,251,193,69,11,23,60,48,178,102,1,204,122,104,241,146,165,203,150,207,159,3,68,204,95,190,108,233,146,197,15,205,26,29,70,45,0,168,249,239,2,16,0,8,18,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,
8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,
0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,
19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,
8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,
0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,
19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,
8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,
0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,
19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,
8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,
0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,
19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,
8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,
0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,
19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,
8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,
0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,19,0,8,251,255,
0,44,91,62,127,14,16,49,127,249,178,255,5,96,246,194,165,22,0,132,172,89,0,75,23,206,254,119,0,126,183,96,201,162,21,243,238,159,15,68,220,63,111,197,162,37,11,126,247,175,0,220,185,120,225,210,101,15,
207,91,14,68,204,123,120,217,210,133,139,239,92,19,128,149,35,191,159,189,104,233,138,71,30,253,3,16,241,232,35,43,150,46,154,253,251,145,149,195,232,172,85,127,92,50,247,79,143,61,254,103,32,226,241,
199,254,52,119,201,31,87,205,26,29,102,142,60,241,151,185,79,174,126,234,175,64,198,83,171,159,156,251,151,39,70,102,14,43,159,126,230,217,231,86,255,231,10,68,172,126,238,217,103,158,94,57,204,188,101,
213,243,47,188,248,28,144,242,226,11,207,175,186,101,230,48,250,183,151,254,254,15,32,231,239,47,253,109,244,159,14,176,8,201,28,171,135,213,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* AiassAudioProcessorEditor::aiasshintergrund_png = (const char*) resource_AiassAudioProcessorEditor_aiasshintergrund_png;
const int AiassAudioProcessorEditor::aiasshintergrund_pngSize = 3258;

// JUCER_RESOURCE: init_png, 3610, "../images/init.png"
static const unsigned char resource_AiassAudioProcessorEditor_init_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,138,0,0,0,48,8,6,0,0,0,206,214,226,119,0,0,0,1,115,82,71,66,0,174,206,28,
233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,14,194,0,0,14,194,1,21,40,74,128,0,0,13,175,73,68,65,84,120,94,237,92,9,116,84,213,25,254,222,50,153,201,36,153,36,16,178,111,
24,98,0,1,17,45,96,169,136,20,81,123,68,173,93,92,78,247,234,161,165,90,186,91,79,181,182,181,155,93,212,42,93,172,61,88,212,99,235,210,106,109,75,171,177,88,78,81,90,219,82,20,168,73,128,36,102,33,43,
48,153,100,50,235,123,175,255,127,231,77,242,222,76,128,16,21,103,210,249,230,124,121,247,222,255,190,151,55,239,126,247,191,255,189,115,103,144,65,6,147,129,100,30,167,140,7,250,239,244,245,105,29,121,
154,164,137,252,11,193,70,244,70,186,232,194,175,251,210,25,76,1,26,116,84,59,106,176,52,123,181,200,59,141,44,84,171,13,131,87,21,173,159,37,10,166,136,41,181,230,150,190,187,188,93,70,107,254,14,255,
115,232,215,186,196,85,52,205,128,20,144,32,19,35,17,29,134,110,152,181,51,56,149,144,100,9,14,135,12,221,101,192,112,27,112,168,18,12,106,138,89,106,5,222,238,92,139,91,203,239,153,82,155,159,212,73,
79,14,60,232,223,236,189,195,221,31,237,66,152,180,43,121,37,248,187,162,8,116,235,208,124,58,16,146,132,162,117,74,202,82,198,163,188,21,208,73,21,170,66,254,220,160,231,159,77,66,241,40,112,85,202,200,
171,116,64,203,215,80,165,214,98,169,251,2,124,165,236,222,147,106,160,73,87,254,118,215,70,99,231,232,115,232,14,118,96,164,61,138,112,171,142,240,32,121,17,186,2,83,163,27,116,234,46,148,120,74,144,
151,155,143,28,71,46,20,89,57,73,41,102,48,101,144,215,208,116,13,163,81,63,134,71,134,208,231,235,67,80,10,144,114,200,203,203,212,113,137,106,145,4,119,131,130,236,114,21,179,178,42,176,194,125,33,110,
169,156,156,135,57,97,165,71,7,126,30,220,50,120,183,115,128,134,152,64,151,14,223,222,48,224,139,157,38,145,66,106,103,214,97,94,233,153,152,87,188,0,229,5,21,80,36,21,6,135,43,25,129,188,53,32,193,72,
212,63,53,35,138,94,95,15,94,237,223,135,87,123,94,70,219,225,253,228,233,201,213,19,156,197,18,114,22,56,32,23,25,40,85,171,177,117,238,127,79,216,90,199,173,176,165,247,46,237,17,239,207,228,67,195,
52,212,236,49,48,218,169,33,68,42,200,85,93,56,171,98,41,150,215,174,68,113,78,49,185,59,243,132,12,82,18,20,182,160,127,100,16,255,236,216,129,221,93,255,64,64,15,194,144,12,184,234,37,228,214,59,80,
153,83,141,15,22,110,140,92,85,178,62,203,60,37,9,199,20,202,3,61,63,208,30,30,184,95,30,24,234,70,96,23,9,132,98,16,30,98,78,47,154,143,149,115,214,34,223,85,0,85,87,16,145,99,179,157,12,82,23,220,200,
220,86,81,106,171,32,13,77,207,183,60,139,125,125,47,11,239,163,22,1,249,75,178,80,152,83,134,235,139,63,19,185,166,100,195,132,98,153,80,40,155,187,239,210,30,61,122,159,220,51,208,141,161,93,97,200,
20,164,42,82,22,206,171,91,141,250,153,243,205,90,25,164,51,218,134,90,176,189,165,145,188,75,0,142,124,26,138,22,171,40,243,84,225,186,89,95,8,189,191,244,58,151,89,109,12,73,66,121,170,231,161,192,189,
125,183,187,14,15,245,96,104,119,24,145,81,3,110,197,141,243,201,139,20,102,23,101,102,51,211,4,60,59,242,133,143,98,199,129,70,58,14,195,233,145,225,58,75,70,169,187,18,141,139,155,147,26,57,169,96,205,
174,211,141,193,0,137,228,149,48,28,35,10,12,154,185,44,175,61,31,133,89,51,142,51,80,101,144,150,160,161,199,23,25,194,139,109,127,69,212,8,65,154,105,32,183,193,129,114,87,21,254,180,228,85,91,107,219,
50,95,111,249,180,241,219,193,205,8,181,26,8,244,70,69,217,194,146,37,40,114,23,103,68,50,13,193,77,170,145,90,124,161,35,216,123,104,23,165,12,56,106,37,56,203,100,92,61,235,147,250,205,245,223,167,249,
83,12,182,230,191,232,95,115,141,238,193,78,132,154,117,68,12,29,37,174,82,212,20,214,65,230,197,155,140,80,166,45,116,18,72,207,80,7,122,3,221,136,82,218,179,72,69,49,15,65,203,154,198,90,125,44,113,
91,211,141,198,111,122,55,35,216,78,179,24,175,12,93,54,80,91,80,143,44,201,97,214,200,96,58,67,151,52,180,31,62,128,168,20,133,92,8,56,43,21,92,83,126,61,110,105,184,91,104,100,76,40,23,239,156,103,116,
30,238,64,128,133,66,200,85,243,224,113,20,82,140,146,89,36,249,127,0,47,249,15,71,188,68,159,80,133,99,142,132,26,79,13,158,61,55,230,85,196,159,239,237,187,73,123,176,119,147,172,247,0,65,111,76,40,
78,103,54,178,37,23,41,141,29,211,255,23,138,178,139,177,162,242,157,112,169,46,28,56,218,132,127,247,238,52,45,211,19,44,2,217,144,17,68,8,193,224,168,40,115,21,43,34,184,253,84,229,173,254,13,13,55,
231,10,161,124,109,223,141,198,83,157,91,224,239,14,67,143,136,122,52,13,150,99,137,20,197,199,23,109,68,93,65,3,36,186,207,221,125,47,225,209,166,205,166,229,245,227,209,203,183,225,172,146,101,102,14,
88,241,112,29,6,70,123,205,220,244,134,78,177,41,67,114,2,217,101,42,222,91,253,81,220,54,255,222,216,162,200,165,219,23,24,173,67,109,8,245,106,177,79,29,185,34,31,98,201,148,68,211,199,71,198,196,124,
208,219,140,75,158,56,75,164,223,8,188,120,109,27,205,244,74,204,28,112,249,111,151,227,213,35,175,152,57,64,145,20,204,157,185,72,164,247,13,254,71,28,167,5,104,232,224,45,9,140,8,197,44,44,148,170,188,
106,52,174,106,146,228,39,219,31,234,57,48,220,10,57,204,226,144,32,43,49,242,190,6,206,167,42,19,49,81,157,169,178,229,232,62,243,170,64,32,58,138,14,122,62,86,251,179,239,223,131,39,175,120,65,240,215,
235,182,217,108,105,77,106,115,209,254,188,167,133,58,131,30,54,208,229,239,16,207,65,218,244,223,111,5,55,29,252,150,19,126,82,83,128,123,75,10,187,17,11,246,124,200,55,230,81,90,135,154,177,238,169,
179,69,250,141,128,67,118,96,69,249,26,100,41,78,188,60,240,18,250,70,15,153,150,24,254,250,190,3,152,229,46,21,233,166,35,123,240,158,223,159,43,210,211,9,188,109,36,234,214,225,200,145,113,251,188,159,
244,203,222,224,17,167,74,195,13,15,77,81,89,71,148,43,164,1,173,48,38,176,31,143,146,164,78,88,30,103,64,11,227,185,206,173,216,218,254,36,186,253,221,73,246,108,71,142,249,159,105,28,87,221,73,246,233,
64,94,30,1,135,43,154,129,163,193,195,89,210,55,118,125,198,248,213,107,247,67,11,232,208,163,220,155,82,59,136,141,99,239,181,227,30,229,224,80,19,214,253,225,28,145,102,172,170,184,4,159,92,248,101,
228,168,185,216,53,176,19,95,253,199,13,88,90,178,18,239,173,251,48,150,149,174,194,172,236,18,113,206,182,174,63,226,174,221,183,153,103,141,227,19,11,110,194,154,170,117,194,163,116,13,183,99,195,246,
247,137,242,159,174,250,13,170,114,107,113,90,126,131,200,51,120,179,80,151,191,29,254,200,8,162,52,19,184,250,153,85,166,37,189,161,233,6,52,135,14,197,41,97,99,253,173,126,153,61,137,78,170,97,40,10,
47,188,144,96,210,128,137,176,218,10,92,51,176,112,230,217,162,65,153,235,23,124,17,191,92,179,21,151,206,190,74,136,132,81,151,63,23,215,159,241,121,220,179,242,17,219,185,204,202,188,90,204,159,177,
24,115,242,231,97,85,229,37,99,229,103,80,153,85,36,12,222,197,87,147,87,71,245,207,196,162,162,115,232,127,207,180,93,43,206,40,5,135,19,149,167,42,37,197,128,2,25,78,67,161,56,45,152,35,179,219,102,
114,48,67,93,52,125,152,8,171,205,18,103,45,46,90,134,141,103,38,123,141,56,214,84,93,134,183,149,156,103,63,63,17,102,121,88,167,136,255,4,240,69,189,246,107,153,148,197,126,196,228,242,84,38,253,21,
218,224,157,113,178,164,83,65,84,130,174,232,48,84,18,77,154,208,6,122,71,54,187,101,53,57,62,60,53,118,63,141,143,253,109,29,214,254,121,33,30,107,123,64,148,197,113,113,237,149,182,243,169,35,217,16,
47,191,234,249,11,112,201,51,139,105,216,30,223,172,213,229,127,13,151,53,46,19,124,215,51,75,16,81,34,182,107,165,43,57,70,209,200,179,68,34,244,60,248,145,88,61,74,58,49,17,199,179,63,223,179,21,55,
254,253,26,188,216,191,13,29,254,86,124,115,247,231,17,210,130,166,21,168,112,87,31,243,92,70,188,124,32,212,131,182,145,253,34,22,137,35,172,135,208,226,219,43,216,58,210,108,187,206,116,32,107,131,247,
32,145,67,164,57,179,193,127,99,49,138,72,164,1,73,222,148,176,32,177,142,5,155,247,255,200,102,11,27,33,180,143,28,16,54,70,69,78,141,205,46,104,69,130,45,98,25,130,68,58,193,62,17,233,89,67,85,249,225,
79,108,79,53,202,42,29,232,168,104,164,13,210,135,8,102,181,232,184,71,225,239,132,240,27,74,117,218,64,89,171,45,113,226,166,76,240,158,70,181,17,211,74,118,73,177,217,18,119,241,89,109,204,168,49,238,
81,56,157,104,159,136,10,145,23,179,38,186,151,148,35,47,186,209,51,32,103,34,38,58,46,217,237,149,29,146,83,172,161,112,33,175,163,240,216,164,75,169,207,68,88,109,230,167,16,99,160,119,101,179,51,173,
224,14,98,181,241,14,117,43,172,54,102,36,97,232,73,180,31,139,124,99,218,4,229,41,71,210,128,226,160,14,66,193,154,164,73,98,43,172,92,156,93,234,99,213,136,200,150,34,93,86,60,171,63,213,105,5,59,0,
171,45,209,163,136,158,108,177,51,19,156,70,130,205,110,180,218,152,86,143,66,79,46,201,126,44,26,170,46,122,236,68,182,84,163,232,60,164,9,126,149,229,84,14,203,215,45,254,108,62,127,47,71,137,200,66,
36,58,205,159,133,87,73,113,90,193,57,171,141,134,84,27,172,182,56,109,74,161,164,213,150,228,81,44,54,102,196,34,20,79,86,65,146,253,184,76,147,231,43,24,2,202,243,170,113,241,156,119,87,139,71,90,145,
93,141,80,64,19,42,74,23,38,98,178,182,73,213,17,17,221,56,108,54,98,79,176,211,180,0,115,114,231,99,190,103,177,40,119,200,89,73,117,211,149,154,70,195,106,88,195,121,101,23,138,247,41,132,114,94,21,
101,120,47,53,81,40,62,13,104,3,123,4,139,45,209,163,240,186,138,213,206,180,106,129,31,140,213,150,228,81,44,54,102,71,224,160,105,137,225,241,115,95,192,131,75,27,177,251,194,163,240,184,102,36,213,
79,71,146,219,132,76,241,137,170,199,190,15,22,243,40,206,106,191,28,149,17,244,141,47,36,77,119,80,191,49,83,39,143,199,187,237,11,118,140,37,5,177,79,144,105,34,41,142,233,142,16,105,161,58,123,54,110,
59,255,78,241,160,196,187,218,176,252,75,185,229,158,42,232,94,154,38,211,139,87,230,192,107,42,41,204,160,22,160,68,12,58,175,148,90,108,214,149,89,94,48,18,239,210,98,103,106,244,138,195,33,59,109,54,
254,172,35,14,111,228,176,205,198,220,59,186,11,183,183,124,22,254,232,48,87,25,195,33,26,146,188,122,114,253,56,57,168,158,168,60,149,40,115,32,27,161,128,214,39,99,101,117,108,216,97,140,117,171,219,
183,125,73,123,232,149,77,50,74,233,193,18,197,167,200,83,239,116,83,7,183,241,36,255,111,142,146,39,142,126,205,222,96,140,66,181,72,252,178,2,219,2,186,63,86,152,112,237,34,71,108,79,201,96,36,121,155,
163,83,118,9,138,207,110,142,1,133,94,179,221,13,40,117,86,146,72,94,67,107,160,217,180,28,3,252,113,9,137,120,92,198,41,6,190,49,234,35,145,14,3,69,193,42,124,225,220,175,6,175,92,248,129,108,54,217,
154,100,197,47,234,141,67,254,14,184,231,169,80,121,203,69,138,11,229,164,241,102,94,123,18,136,104,212,1,217,171,164,48,34,212,47,134,155,194,248,224,130,245,248,246,218,77,99,55,107,187,235,135,255,
125,127,240,190,127,254,192,217,163,188,134,156,51,84,10,242,76,195,41,4,143,20,111,214,255,125,51,175,61,25,240,174,177,84,222,65,200,35,248,240,203,81,148,171,213,216,177,190,197,118,163,182,200,235,
3,103,95,239,90,57,251,66,132,142,232,8,180,235,98,15,37,175,114,242,44,226,84,145,199,73,107,158,188,117,172,220,82,38,200,229,68,182,91,109,156,31,43,179,212,97,242,15,204,196,109,113,187,53,205,54,
91,153,201,120,62,126,157,120,93,107,29,107,189,120,93,171,141,207,225,24,197,86,150,34,20,247,76,2,246,53,71,16,26,209,176,122,246,165,73,27,126,248,237,38,225,109,155,78,51,6,70,14,193,115,186,3,36,
174,99,212,202,32,237,193,67,177,137,225,150,40,66,109,58,42,11,171,241,226,134,253,73,45,126,76,9,44,189,167,206,232,62,218,137,130,69,14,184,106,101,225,54,51,152,70,48,227,53,110,215,72,179,129,64,
171,134,170,252,26,236,184,209,62,228,196,113,92,95,193,98,233,247,118,195,57,91,134,123,62,207,157,104,100,224,105,84,6,211,2,225,0,9,100,143,134,209,110,13,213,5,181,216,185,113,98,145,48,142,43,20,
198,210,31,146,103,241,118,34,107,134,12,207,57,42,224,33,189,240,216,102,218,51,72,63,240,110,1,185,95,198,240,43,97,4,135,116,148,23,84,225,165,207,29,60,174,22,78,40,20,198,205,79,223,96,108,223,255,
44,218,124,173,200,171,205,162,25,17,185,21,55,139,37,38,23,177,72,103,73,51,82,120,181,96,90,35,241,249,91,243,156,142,146,48,70,247,105,8,119,235,168,240,212,224,162,211,47,211,191,190,238,135,39,28,
39,38,37,20,198,239,254,243,216,200,29,207,221,146,115,224,72,43,20,135,4,87,153,130,156,122,5,121,37,89,226,7,255,196,141,144,167,225,61,12,12,254,245,200,12,78,61,156,60,181,51,161,115,19,240,42,117,
88,70,168,47,138,145,253,154,248,218,112,121,110,13,86,207,93,139,239,94,241,227,73,183,255,164,43,198,241,253,63,125,109,180,63,216,151,253,66,203,95,112,208,219,202,202,128,167,212,1,101,166,4,61,79,
135,154,45,195,233,146,197,15,178,100,112,234,161,82,147,134,130,58,120,49,90,242,73,136,28,214,49,50,24,134,17,146,81,87,56,27,239,168,95,131,229,53,239,24,189,242,156,107,199,191,197,54,9,156,180,80,
172,184,233,137,27,12,131,188,201,246,230,70,116,28,233,16,129,46,143,127,140,20,94,87,154,214,136,79,78,227,191,253,91,86,88,137,213,13,23,193,65,175,239,188,103,106,191,131,207,120,195,154,115,203,223,
238,235,239,244,118,120,70,35,195,78,222,25,149,137,81,222,26,112,28,162,80,143,205,115,229,7,106,10,79,27,186,102,249,71,202,76,211,235,0,240,63,102,101,166,27,186,87,201,90,0,0,0,0,73,69,78,68,174,66,
96,130,0,0};

const char* AiassAudioProcessorEditor::init_png = (const char*) resource_AiassAudioProcessorEditor_init_png;
const int AiassAudioProcessorEditor::init_pngSize = 3610;

// JUCER_RESOURCE: sidblaster02_png, 32883, "../images/SIDBlaster-02.png"
static const unsigned char resource_AiassAudioProcessorEditor_sidblaster02_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,159,0,0,0,125,8,6,0,0,0,188,151,177,105,0,0,0,1,115,82,71,66,0,
174,206,28,233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,53,211,0,0,53,211,1,12,33,67,119,0,0,128,8,73,68,65,84,120,94,237,189,7,160,36,87,121,37,124,42,116,206,241,229,28,
38,71,105,70,89,8,17,5,34,59,39,204,154,197,96,108,48,32,1,194,94,255,187,235,127,13,14,191,215,228,108,27,140,1,27,147,115,20,18,202,210,72,154,28,222,188,156,58,231,84,221,213,93,255,249,234,205,16,
108,176,229,0,8,152,43,245,188,126,221,253,170,170,239,61,247,124,231,220,251,221,91,184,84,46,149,31,87,81,46,252,124,92,148,179,199,239,83,13,163,229,235,89,138,203,233,241,26,78,167,167,57,61,187,219,
188,240,246,165,242,83,86,30,55,224,91,158,63,161,149,242,217,177,78,199,120,137,101,41,55,232,46,247,3,186,195,249,105,151,211,245,168,219,231,43,143,142,109,187,4,194,159,178,242,184,0,223,153,19,247,
105,157,118,103,182,90,42,190,180,86,46,253,90,187,109,68,201,124,93,175,63,120,222,235,243,127,194,233,241,124,193,233,112,159,118,56,244,210,196,244,238,238,133,63,187,84,126,194,203,143,29,124,139,
115,143,234,229,98,126,91,189,90,251,239,141,90,245,151,218,70,59,217,235,117,121,93,22,84,85,133,203,235,109,122,124,193,51,110,183,247,211,14,167,227,43,46,143,119,222,31,12,23,134,134,167,46,49,225,
79,120,249,177,130,239,252,217,135,245,122,185,56,211,168,215,126,175,94,171,255,2,217,47,38,175,91,189,30,44,75,30,22,47,208,226,85,170,112,123,189,45,143,207,127,204,229,246,126,222,227,15,124,141,207,
207,186,220,190,226,224,224,88,207,62,216,165,242,19,87,126,108,224,59,127,230,33,71,41,151,221,222,106,53,94,100,52,91,191,104,154,221,1,27,107,23,138,0,79,64,40,224,235,9,24,249,154,166,105,61,50,95,
137,224,123,196,229,246,124,205,233,116,223,206,223,231,8,204,242,200,232,76,55,189,126,62,196,191,139,242,47,115,3,195,179,213,173,35,93,42,143,215,242,99,1,159,0,175,92,202,111,175,151,203,191,109,24,
198,207,17,92,73,5,10,175,69,181,223,87,248,84,0,71,4,162,39,32,228,67,158,19,141,242,38,52,221,97,17,116,101,183,199,243,128,211,237,253,170,219,235,187,147,218,240,148,203,161,77,243,239,174,228,135,
238,208,157,206,115,4,110,88,81,212,106,162,127,188,109,31,248,82,121,92,149,31,57,248,206,28,191,219,89,175,85,246,54,106,245,23,26,173,214,243,201,110,3,170,166,217,209,85,216,77,138,66,16,218,204,247,
93,15,1,223,197,139,21,64,74,209,117,221,116,184,220,25,135,219,243,128,219,227,189,61,16,8,170,14,93,31,37,120,63,74,115,50,215,49,140,103,105,154,227,78,135,195,189,210,55,54,117,41,60,63,206,202,143,
20,124,139,231,142,184,74,133,60,129,87,123,73,219,48,158,77,12,197,85,77,85,133,243,190,13,50,41,214,22,3,74,145,215,108,22,252,238,194,223,237,64,44,225,152,239,171,154,222,38,8,179,30,175,183,230,243,
249,51,100,197,191,240,186,221,167,234,149,202,109,186,238,124,143,211,229,125,104,120,118,231,37,151,252,56,43,223,105,229,31,114,57,123,234,62,39,67,237,94,163,213,248,239,221,174,249,108,77,211,19,
78,183,75,165,131,101,24,213,190,243,80,249,208,84,209,119,182,219,37,43,10,195,217,191,95,124,77,177,159,235,2,58,251,247,158,217,113,26,141,234,80,173,82,216,86,41,231,247,208,192,252,106,179,101,252,
34,65,59,67,120,6,123,60,204,133,203,184,84,30,71,229,71,194,124,11,103,143,56,42,149,226,65,163,89,255,221,142,209,126,26,79,27,39,104,40,199,136,137,11,172,199,127,46,252,148,191,144,203,98,36,182,127,
181,95,216,122,191,183,245,25,251,33,175,9,243,245,186,252,93,30,52,39,60,158,238,112,89,100,186,58,193,89,102,8,246,184,3,161,255,215,237,13,124,72,119,56,114,35,99,211,23,14,118,169,60,30,202,15,157,
17,54,87,79,145,170,172,9,226,226,215,187,166,121,51,217,40,65,36,9,228,248,46,117,28,99,174,205,112,10,89,13,26,127,231,115,155,253,248,32,19,218,239,241,161,145,253,84,249,253,226,131,236,40,172,40,
44,200,15,240,53,29,14,167,75,24,81,233,154,29,191,209,170,15,53,154,181,176,97,52,127,195,234,117,126,14,189,142,103,235,138,46,149,199,75,249,161,131,175,215,181,220,116,178,7,220,110,239,147,131,145,
72,200,235,247,10,86,104,26,182,216,138,255,216,62,87,81,249,41,33,66,121,46,196,199,231,36,199,111,135,91,121,124,119,248,149,135,20,179,99,242,16,252,156,195,77,128,58,109,16,110,1,83,5,77,135,170,43,
214,110,165,219,253,45,151,209,121,74,241,220,201,129,242,234,210,15,253,59,95,42,143,173,252,208,27,66,97,243,171,154,211,165,233,46,175,203,233,85,130,161,40,34,177,36,188,94,159,13,178,111,135,85,1,
220,69,16,94,0,160,205,120,23,128,246,61,207,5,165,12,185,165,98,30,169,204,38,58,221,174,253,186,132,93,155,73,9,64,183,219,3,143,199,3,197,104,233,70,106,115,183,181,120,254,207,148,165,243,111,234,
21,50,79,46,47,47,94,98,193,199,65,145,38,255,161,150,204,198,146,211,236,154,79,162,201,120,83,175,215,221,211,53,13,226,161,102,131,171,75,208,52,235,117,152,102,215,190,16,91,243,217,8,20,240,17,68,
2,178,11,253,67,126,183,223,167,238,235,116,58,200,164,55,176,188,188,128,80,36,129,209,209,113,184,220,46,27,160,18,182,29,46,23,220,78,39,172,74,25,213,165,69,40,237,54,198,28,94,203,215,44,55,21,127,
96,169,55,52,254,13,43,18,253,71,248,131,71,84,111,176,25,28,25,187,164,5,127,12,229,135,206,124,212,106,29,221,225,76,57,28,238,156,174,187,225,116,249,225,114,5,209,110,119,9,186,30,219,63,132,64,40,
68,163,224,176,129,35,32,187,248,16,86,148,240,76,205,72,224,241,39,205,69,207,50,65,215,140,213,213,37,120,188,1,12,13,13,243,152,46,126,94,216,81,39,8,61,100,61,23,122,229,2,106,103,78,160,181,60,143,
94,189,136,86,48,166,24,125,147,222,94,171,187,93,59,115,244,183,148,185,83,239,237,22,242,127,104,150,242,135,42,203,243,174,11,151,123,169,252,8,203,15,157,249,164,228,50,235,211,100,173,255,221,237,
118,126,145,102,64,85,168,209,76,211,68,181,90,68,173,90,176,89,43,16,140,192,104,54,208,168,87,200,136,91,227,119,2,64,187,144,151,100,170,77,74,143,108,89,46,151,97,144,205,36,116,123,61,190,11,102,
68,135,147,134,195,229,112,162,83,201,161,177,254,8,172,86,10,173,150,137,112,196,75,160,142,195,169,141,129,208,135,94,47,163,211,42,89,85,127,160,174,58,221,167,188,201,129,127,112,133,163,159,82,20,
107,37,178,125,239,165,132,133,31,81,249,209,128,47,187,49,204,31,175,39,160,94,98,118,12,71,183,35,179,93,114,106,133,12,216,70,38,179,138,86,179,130,112,56,14,159,47,0,163,213,96,56,174,194,36,208,236,
66,240,217,23,74,0,182,25,114,229,229,111,155,17,49,33,182,198,115,195,234,26,40,175,159,69,57,117,6,225,4,181,229,200,229,208,125,253,36,78,3,181,204,105,84,214,87,16,119,142,192,173,5,145,135,137,213,
141,53,184,121,216,169,241,9,51,26,75,158,119,232,250,223,43,46,207,39,85,175,111,81,247,250,154,254,241,75,67,51,63,204,242,163,2,95,152,44,246,18,130,239,127,90,189,174,199,36,248,204,182,177,197,102,
154,78,48,153,52,15,89,100,211,235,34,252,144,72,246,193,227,246,162,94,171,216,224,148,215,132,5,77,195,32,32,123,116,178,78,251,247,11,142,150,97,215,73,96,118,176,124,252,62,100,22,143,34,49,16,196,
232,254,103,194,159,216,1,205,41,240,178,96,52,170,56,113,223,23,81,90,88,195,174,129,73,180,141,54,42,100,89,247,216,24,38,102,183,195,95,200,90,174,244,70,73,137,245,63,210,27,24,249,39,203,233,250,
50,193,190,233,240,135,140,240,142,221,151,166,230,126,8,229,135,174,249,46,20,163,215,235,21,9,62,147,214,87,6,130,225,36,184,196,157,182,201,114,162,229,132,245,198,198,119,48,108,122,112,230,248,81,
204,207,157,230,213,105,240,81,19,122,124,62,187,155,152,228,33,85,119,124,123,40,101,235,161,161,69,96,61,124,207,215,113,215,87,191,140,141,181,53,98,213,128,210,107,16,220,45,178,30,205,140,213,163,
73,105,227,196,74,13,119,158,75,225,68,174,128,141,98,142,44,168,97,182,175,15,113,151,27,190,205,37,69,63,243,112,164,185,60,247,196,226,218,242,159,84,211,27,111,107,55,106,191,108,54,107,51,249,147,
143,120,243,115,39,126,36,29,245,103,169,252,168,192,39,131,113,53,251,39,139,61,36,66,198,211,93,30,232,4,83,219,104,162,195,135,211,233,64,95,34,137,137,225,49,212,10,5,156,122,240,62,164,22,22,161,
211,136,120,60,126,120,125,126,219,201,10,232,100,0,218,65,147,98,154,6,30,121,248,126,124,241,139,95,199,153,133,13,228,203,13,148,242,89,52,179,199,160,214,78,67,111,175,66,55,215,97,22,31,65,53,51,
71,7,92,131,153,207,193,138,68,224,36,227,81,116,162,245,149,79,195,120,248,65,52,188,12,199,225,152,178,144,73,133,87,87,150,158,94,43,151,254,184,211,168,253,47,171,92,188,89,41,20,199,138,199,142,120,
74,103,46,129,240,191,170,252,72,192,23,79,12,118,248,163,104,3,208,30,78,33,0,25,54,53,2,207,77,141,231,11,132,225,18,227,64,80,138,235,13,4,130,48,107,13,120,187,26,54,239,252,38,142,126,238,211,40,
45,46,192,195,207,203,123,2,66,23,217,170,215,237,224,248,163,71,240,249,207,127,21,167,231,214,0,186,233,186,225,192,201,83,25,172,47,205,161,83,62,77,176,29,69,135,192,67,245,52,250,213,44,226,173,26,
102,90,117,236,136,69,17,11,71,97,45,206,163,122,223,125,88,95,203,32,221,209,25,189,45,168,12,239,134,174,43,166,207,63,72,198,126,62,29,206,155,144,75,255,15,164,215,111,70,165,48,90,62,123,204,85,94,
62,127,9,132,255,201,242,3,43,240,222,251,238,212,72,56,206,66,177,224,158,159,159,15,181,90,237,96,60,150,172,13,15,14,167,162,177,120,243,178,131,151,253,171,98,252,147,159,249,132,242,188,103,63,255,
219,159,201,166,215,14,240,108,127,194,83,222,72,220,57,47,96,208,214,125,91,15,190,192,240,219,237,24,168,147,185,30,252,220,39,225,10,196,224,94,56,133,74,54,131,94,32,4,255,212,20,6,14,92,134,192,224,
32,93,108,19,39,143,61,140,79,127,226,83,120,244,248,28,36,53,102,223,228,40,66,30,13,229,74,26,253,81,21,219,39,34,8,134,124,40,25,64,41,85,69,126,181,6,143,150,192,179,246,237,64,52,17,3,3,63,58,39,
143,97,113,61,135,227,26,89,120,104,4,147,131,125,72,6,253,8,108,223,142,224,244,12,116,130,81,89,89,134,82,206,118,85,127,112,73,241,121,63,143,96,248,43,74,52,241,96,169,83,206,142,239,123,194,191,90,
15,151,202,15,46,255,2,124,127,251,129,119,107,169,76,46,94,46,87,119,25,70,103,103,177,88,140,150,138,197,81,186,201,145,190,100,223,70,52,22,253,250,192,192,192,3,179,51,211,171,35,227,35,173,201,209,
239,117,132,31,252,208,251,212,84,58,59,208,108,119,167,34,193,224,106,200,239,93,123,225,11,95,220,201,101,214,35,252,224,51,249,145,151,240,113,152,30,192,101,159,93,80,120,17,137,4,97,167,90,70,227,
204,9,164,190,252,89,84,219,212,107,100,169,142,152,19,95,16,21,134,102,117,96,0,222,237,219,208,224,103,191,241,141,59,112,215,61,15,161,222,236,192,195,144,61,211,23,133,199,1,84,232,156,253,142,30,
53,29,208,165,80,92,169,91,240,193,137,164,83,199,224,212,118,60,241,186,67,240,151,43,72,46,47,146,21,11,184,223,29,195,29,141,46,234,236,0,73,143,11,7,135,135,112,217,204,4,18,30,29,10,255,190,163,56,
96,121,188,80,169,61,123,245,116,29,17,239,57,35,22,253,92,181,93,191,39,28,112,173,57,3,3,203,170,211,87,139,143,28,188,4,196,127,71,249,30,240,253,245,223,190,75,91,94,89,29,205,100,242,191,80,44,86,
158,91,42,85,246,102,51,89,103,169,88,210,52,77,85,226,137,68,103,96,160,127,101,100,116,232,246,129,129,228,87,134,134,134,238,29,232,31,216,124,210,19,159,242,237,92,185,63,254,63,127,52,188,178,186,
249,91,109,179,247,180,160,215,115,247,232,200,240,187,111,189,245,245,231,229,189,108,118,35,222,235,246,94,214,235,154,175,34,219,69,100,136,196,214,127,124,79,134,148,187,141,58,154,39,31,69,235,142,
175,161,121,226,24,90,29,19,13,2,179,29,143,67,33,243,181,93,58,90,58,193,197,240,187,158,175,225,27,71,142,99,97,61,3,141,161,218,239,245,34,225,39,151,89,38,106,237,6,34,46,130,79,233,162,65,80,45,209,
211,244,19,84,99,126,39,70,166,182,225,202,3,179,8,55,58,232,75,167,96,134,35,152,27,221,134,71,83,41,172,164,114,168,85,234,216,227,15,224,169,126,13,163,181,77,168,193,48,140,109,251,209,158,216,134,
150,167,135,118,113,30,142,96,0,221,208,96,171,211,235,46,121,181,234,9,69,119,124,6,158,193,47,143,237,184,49,35,223,243,82,121,108,229,219,224,251,155,191,125,143,186,185,153,30,95,91,223,124,17,153,
235,55,82,169,244,80,38,157,211,132,117,100,26,76,138,228,207,121,60,110,36,147,177,234,64,127,223,194,224,224,192,87,71,70,134,190,49,50,54,250,200,196,248,120,238,31,62,242,33,239,102,186,120,107,190,
80,249,205,102,179,57,16,244,186,86,14,236,223,251,63,254,247,255,251,198,191,151,191,79,167,215,199,59,237,206,45,173,70,253,69,52,25,94,7,77,131,139,140,34,131,195,180,189,104,145,241,26,223,248,34,
67,225,73,24,4,157,65,29,104,25,13,24,137,4,20,183,27,221,100,12,86,208,141,26,245,224,169,163,231,241,197,35,167,145,106,181,17,38,56,189,254,144,237,106,205,78,11,117,186,95,119,183,137,126,133,62,167,
221,195,70,27,24,242,185,49,236,119,97,58,62,132,39,78,36,145,168,151,225,230,247,233,92,113,61,170,51,59,145,174,148,177,186,186,142,194,74,10,131,165,50,118,213,179,136,57,123,208,47,191,6,237,237,251,
80,237,149,80,108,173,192,219,63,11,119,100,140,122,149,14,220,234,192,106,109,116,138,233,249,211,186,30,253,199,145,224,196,23,21,151,103,65,13,132,43,193,137,153,75,195,51,255,70,177,83,67,254,242,
175,254,84,201,48,212,230,139,165,223,40,20,203,47,201,231,138,195,133,124,65,149,153,6,129,167,61,227,192,207,117,169,201,100,102,161,90,173,185,138,197,82,95,165,82,217,85,171,213,247,166,210,233,104,
179,217,208,214,86,215,15,204,205,45,221,214,104,180,6,204,182,161,182,155,117,45,26,141,108,188,235,189,239,251,250,187,223,245,46,235,150,91,110,73,116,187,230,19,8,232,61,141,90,205,81,103,136,53,234,
117,244,154,13,116,40,252,107,100,188,214,241,163,104,215,234,40,144,233,26,131,35,112,123,156,208,6,250,97,145,221,122,145,40,116,26,5,69,213,81,76,23,177,176,145,69,71,115,32,62,48,8,221,203,144,200,
107,76,36,34,24,24,76,210,148,48,208,202,24,97,211,176,95,31,13,56,225,99,104,142,155,26,246,104,22,2,52,30,142,228,16,180,153,221,112,240,179,1,159,23,81,134,229,100,169,128,196,230,10,60,102,11,189,
153,61,168,110,59,136,149,70,19,233,212,163,236,16,140,184,19,87,193,225,31,132,230,226,241,61,65,116,21,175,182,112,238,68,188,149,202,236,234,175,54,103,213,102,43,106,169,106,243,182,215,191,174,250,
166,183,188,77,140,214,165,242,3,138,205,124,175,123,221,45,142,122,163,249,244,124,177,252,167,149,74,109,219,230,70,74,109,181,90,91,99,104,20,246,130,60,25,236,21,240,217,11,122,168,183,196,141,72,
198,177,223,239,179,34,145,112,102,124,106,124,174,90,174,122,22,23,150,15,88,189,174,170,145,133,44,171,215,217,182,107,199,23,95,246,59,47,255,213,27,159,120,99,45,157,222,8,152,157,206,19,219,70,251,
37,70,163,126,109,163,90,10,180,139,5,213,149,102,120,91,91,67,253,204,41,24,235,171,100,43,3,185,104,4,237,93,251,17,15,121,97,160,13,205,224,121,9,60,132,130,112,40,22,230,31,57,137,79,127,229,14,164,
13,19,195,83,179,112,5,67,246,245,248,220,26,245,159,130,193,120,12,17,93,197,38,89,116,253,220,89,12,147,168,186,154,11,137,154,138,167,197,252,240,187,52,56,8,60,109,239,101,80,253,30,40,213,60,186,
169,53,24,243,11,232,82,15,42,147,219,209,154,221,139,249,158,130,179,235,43,208,235,167,48,62,225,193,246,43,110,130,51,180,29,166,22,134,206,227,167,54,87,113,228,246,79,194,159,205,227,233,186,171,
227,10,71,54,149,161,177,7,48,52,254,77,43,22,255,166,226,15,206,43,110,159,17,28,159,186,164,7,255,89,177,153,239,170,171,14,247,205,157,95,120,67,169,92,187,186,88,44,107,21,134,32,167,195,105,207,191,
74,72,220,74,115,82,236,124,58,89,79,33,217,35,2,64,97,196,78,167,171,116,204,158,159,110,117,136,44,216,71,198,211,84,171,11,134,93,52,218,29,213,225,114,84,174,56,124,232,246,15,255,253,71,114,175,125,
221,45,194,4,27,170,170,45,240,88,21,213,236,38,157,171,75,17,247,35,247,42,234,218,10,76,10,251,150,211,135,58,181,158,18,13,194,53,54,12,68,67,40,210,20,80,208,195,31,79,194,100,168,214,25,130,25,77,
49,79,160,84,200,74,225,8,93,45,193,23,35,51,90,61,21,235,75,43,52,18,37,36,251,147,216,123,237,181,24,24,27,69,182,210,64,217,114,193,175,187,49,194,46,167,211,92,116,101,170,174,204,99,103,211,112,46,
157,133,107,121,14,14,147,151,56,187,27,214,158,67,200,49,252,158,92,94,70,154,76,220,203,111,32,230,175,97,104,72,135,213,173,99,110,97,29,70,101,25,39,142,62,128,115,199,78,193,87,163,233,41,85,52,189,
81,11,58,202,249,73,165,84,216,167,52,27,179,188,32,137,207,245,63,188,237,117,181,63,121,243,219,190,173,141,47,21,202,184,223,249,157,151,104,27,155,169,203,83,169,204,181,197,66,81,207,231,115,160,
41,32,211,109,77,127,93,20,133,162,245,4,116,62,134,55,93,6,136,101,34,223,229,178,7,123,117,134,51,195,104,107,109,163,165,59,84,9,211,38,90,237,14,136,89,104,189,110,184,84,200,207,206,205,157,85,146,
137,1,107,96,96,184,234,112,56,31,88,90,94,252,226,131,247,220,189,126,238,254,251,96,44,206,193,149,89,67,160,184,137,0,117,154,99,116,20,218,174,29,208,18,33,192,203,115,240,60,93,161,95,234,185,86,
62,133,66,38,13,87,40,68,157,231,131,202,107,237,17,232,117,26,134,212,233,211,88,231,35,187,188,134,243,199,79,227,174,47,126,21,15,159,56,13,255,244,54,196,46,191,10,5,127,28,27,145,36,54,3,97,30,143,
165,92,132,181,120,30,157,51,212,152,107,235,48,233,174,213,225,113,184,168,3,29,131,67,176,20,214,67,175,133,78,163,130,102,174,134,197,99,235,56,121,223,163,88,58,113,63,50,103,238,196,230,233,59,145,
62,247,16,214,206,167,145,42,182,240,21,26,155,111,53,160,108,90,186,199,44,100,199,173,147,71,158,137,83,143,220,106,173,206,223,102,166,55,110,42,159,58,22,43,45,204,93,172,210,159,249,162,93,119,237,
213,129,83,167,206,188,188,92,174,95,219,106,54,213,70,131,181,199,144,106,16,60,178,152,71,216,79,128,38,147,252,14,167,204,169,18,177,124,95,6,121,45,62,23,109,229,245,120,200,136,100,43,58,205,46,153,
163,84,161,158,162,126,10,250,220,138,223,235,238,4,194,129,179,67,67,131,15,190,233,141,111,194,158,253,59,149,59,191,121,251,248,29,119,222,253,75,15,60,124,244,198,71,206,158,15,122,24,210,7,117,11,
46,163,73,48,171,20,249,135,16,184,130,218,42,18,67,219,236,18,236,160,110,83,208,161,73,104,146,169,132,85,45,94,91,126,109,3,221,92,133,161,63,96,39,28,212,50,89,84,242,121,24,205,22,255,192,100,135,
144,33,154,48,52,95,4,169,124,1,43,107,41,24,138,70,39,236,196,176,81,135,139,50,66,21,121,192,206,34,140,110,242,189,110,36,1,107,112,12,106,32,8,103,192,135,96,60,10,151,3,168,174,46,35,183,153,161,
41,41,224,200,177,13,156,56,181,142,245,249,13,94,67,1,165,82,143,17,194,141,69,118,132,60,84,132,38,167,16,161,35,118,116,186,14,171,127,60,2,119,96,90,201,108,30,86,11,169,89,165,211,238,221,246,251,
175,40,189,225,213,175,105,189,241,109,111,255,153,14,197,218,238,221,187,198,215,214,82,47,107,25,157,17,105,84,97,61,97,60,105,12,75,164,186,189,104,71,62,202,176,235,208,36,204,210,4,120,68,207,193,
65,80,122,188,30,123,156,78,166,200,20,242,73,151,96,105,17,76,201,120,132,207,233,54,41,23,251,7,251,231,159,250,212,167,55,117,85,189,170,215,237,38,238,186,231,254,103,173,173,109,252,74,106,125,99,
40,147,47,40,129,104,12,51,241,48,124,102,27,10,145,166,237,218,131,8,181,88,98,104,12,193,72,220,62,175,55,156,176,27,184,94,44,34,183,177,129,18,67,113,59,147,135,171,218,132,131,33,183,197,179,183,
107,53,154,102,26,12,134,125,141,172,165,232,10,60,81,130,137,161,150,70,138,46,184,9,183,67,71,127,187,137,201,118,3,46,126,7,161,33,113,201,10,129,40,3,221,61,106,221,110,62,139,94,165,100,39,37,248,
130,188,46,30,167,188,116,6,197,66,22,117,106,204,86,149,172,222,104,67,231,247,107,181,186,236,32,14,184,248,217,130,209,130,147,223,120,50,17,197,160,159,218,116,96,2,214,232,140,130,66,214,165,158,
124,48,166,110,44,205,162,213,220,207,30,60,194,47,83,189,237,214,91,115,111,124,235,219,127,102,77,137,54,58,49,182,179,217,106,255,166,217,233,134,202,21,10,109,154,12,1,158,52,138,252,148,39,2,40,9,
185,29,178,154,204,167,74,58,147,160,74,230,98,217,98,168,215,170,104,54,234,4,38,25,132,111,180,249,51,24,244,195,229,117,99,120,100,68,63,124,248,202,241,217,153,233,167,212,235,213,39,223,125,207,189,
215,61,244,240,209,235,5,120,165,92,78,107,145,157,162,52,10,7,92,64,88,229,65,67,17,232,211,59,161,4,217,120,100,52,127,56,6,75,140,13,65,24,31,158,178,193,181,122,250,148,61,220,210,206,149,9,52,94,
151,207,143,38,129,32,83,114,118,186,22,59,131,91,151,235,227,119,232,240,250,104,32,26,173,6,195,106,27,142,122,5,163,52,81,83,4,148,139,82,66,25,30,134,22,240,67,175,149,229,139,194,226,223,91,100,87,
43,181,142,94,102,19,22,59,164,202,255,10,107,231,169,1,115,232,208,236,196,248,181,167,189,10,194,46,226,202,160,41,235,58,225,230,57,123,4,247,44,193,189,127,104,16,209,104,146,146,128,199,107,214,160,
157,122,8,218,185,227,138,82,41,186,208,168,37,172,90,117,151,210,110,95,67,118,30,123,195,239,189,124,229,15,110,121,85,249,79,222,246,78,49,229,63,83,69,219,190,99,215,84,183,103,253,2,67,174,191,66,
16,73,168,21,198,146,248,218,21,246,35,30,236,140,98,1,162,52,170,100,13,19,124,118,138,251,5,224,213,201,56,45,130,162,193,112,87,169,214,237,116,165,120,50,142,231,60,247,57,184,233,166,155,180,125,
123,247,4,232,128,99,247,222,123,111,228,203,95,249,70,255,210,249,197,96,33,147,83,155,100,25,97,214,8,15,181,127,40,134,228,101,151,67,191,246,41,80,134,38,137,28,55,93,129,3,14,25,7,116,121,236,172,
101,23,65,38,43,215,52,134,205,145,237,123,24,50,73,171,12,149,85,118,14,49,73,93,2,185,71,185,32,215,238,32,96,197,153,119,187,10,90,149,42,8,116,178,95,1,30,2,98,219,224,48,38,199,70,160,251,188,80,
227,9,120,220,14,120,154,37,123,10,175,69,240,11,251,169,245,26,20,126,55,228,211,48,232,104,83,133,20,50,4,173,12,220,4,121,236,4,65,40,125,112,163,169,194,164,145,9,176,50,199,248,184,146,199,29,101,
216,117,23,214,161,22,51,52,52,69,40,75,231,100,45,9,186,147,187,208,221,121,88,181,250,198,220,212,4,9,37,183,185,159,189,105,103,151,194,249,15,94,251,186,244,27,223,246,14,73,190,248,153,41,234,232,
240,80,39,30,141,118,72,108,208,9,60,59,12,137,176,179,81,39,141,39,58,206,68,135,141,170,171,52,25,236,217,26,27,92,32,89,175,215,9,60,130,141,239,137,70,108,52,90,212,103,42,46,63,176,19,207,190,233,
73,184,226,208,65,140,209,105,106,154,166,60,248,208,195,234,39,63,243,5,117,110,110,94,203,102,179,74,131,13,220,35,240,28,60,85,149,64,94,155,221,1,220,252,92,120,175,186,6,206,193,62,130,168,141,141,
197,69,252,211,39,62,78,125,117,118,107,145,16,195,124,48,217,135,137,131,135,176,231,250,39,225,170,159,251,37,108,223,181,27,62,126,214,226,185,21,30,79,174,93,128,23,243,133,144,116,19,176,194,91,38,
157,185,209,177,87,186,73,22,181,78,54,213,175,123,58,180,253,87,65,73,167,160,174,46,162,199,208,95,187,226,106,172,93,113,45,22,167,182,35,79,166,53,121,44,133,140,216,205,101,208,110,242,28,252,157,
135,98,125,176,83,146,81,53,17,189,252,223,203,14,209,239,115,227,178,145,1,140,238,63,192,112,222,130,103,99,14,254,149,83,240,156,123,20,74,147,81,97,114,55,140,157,135,81,237,31,70,41,26,69,35,218,
167,118,101,128,241,204,241,39,169,143,220,255,103,214,185,227,127,93,189,255,246,231,86,31,190,55,90,60,113,228,71,146,240,241,227,46,218,127,127,201,127,163,151,232,236,94,93,93,223,86,111,180,84,73,
95,255,118,17,36,218,63,85,18,145,11,161,80,216,158,229,232,81,31,117,232,60,141,86,93,92,46,195,177,48,100,15,125,212,121,47,253,111,191,132,151,190,228,69,216,189,107,59,194,212,98,50,59,242,192,131,
15,225,99,159,252,52,206,156,62,143,108,58,109,107,47,57,143,48,135,67,192,226,118,98,250,240,1,236,32,243,249,194,97,232,212,148,75,103,143,225,195,31,251,28,190,118,247,253,184,231,155,223,68,200,173,
74,8,167,222,12,192,23,138,218,225,191,157,77,161,114,207,183,80,163,195,109,181,25,118,201,74,146,102,31,36,24,182,141,79,96,124,100,152,225,214,128,73,157,214,224,235,109,158,47,65,230,222,206,243,141,
120,156,80,83,107,192,250,50,58,30,31,140,61,135,80,28,155,198,122,211,64,137,78,90,221,190,3,46,2,210,89,173,218,206,125,157,6,166,74,39,222,98,245,24,205,30,117,159,68,7,29,249,174,142,4,25,121,239,
196,8,166,111,184,1,238,93,83,176,18,116,211,222,32,117,99,21,221,66,1,189,65,106,191,217,61,232,18,132,245,106,9,101,134,126,7,245,163,195,229,133,57,190,93,181,188,1,47,178,155,211,202,250,242,77,104,
53,14,178,190,91,111,248,189,151,21,95,247,138,87,52,223,244,142,119,125,87,131,252,116,21,117,120,120,56,221,215,215,247,78,106,186,5,231,5,61,183,181,10,108,43,180,74,24,246,179,131,70,34,116,125,108,
56,49,35,157,118,139,15,154,19,17,233,4,157,139,134,224,218,171,46,199,171,126,247,133,120,206,115,158,129,120,162,31,186,211,139,66,169,136,187,239,190,23,159,255,194,87,177,180,180,6,50,30,106,117,106,
47,154,26,147,199,49,201,84,45,62,106,173,14,10,169,28,202,27,235,108,212,10,10,185,13,124,225,190,135,113,122,109,19,197,76,26,233,165,21,28,39,8,51,103,79,162,74,45,214,102,56,204,47,47,32,115,156,172,
82,43,33,49,156,192,240,236,0,6,146,94,244,251,93,24,114,187,17,167,30,237,31,27,167,97,9,195,41,233,246,236,73,210,138,22,93,49,24,70,113,207,215,161,158,122,4,10,191,51,118,95,1,204,30,64,208,210,48,
74,118,28,99,39,75,238,220,141,192,129,203,225,29,28,132,159,118,215,239,80,225,115,82,39,210,141,231,219,42,22,155,148,37,60,148,214,165,6,36,168,135,201,102,189,120,8,134,222,70,173,87,71,142,122,178,
58,177,29,230,149,55,162,123,240,106,116,188,94,244,202,57,120,87,22,144,88,156,131,123,121,14,157,98,26,21,106,135,50,59,91,39,212,135,110,171,29,178,22,206,62,67,153,63,253,87,214,250,202,255,65,106,
245,154,242,151,63,21,41,223,119,135,179,116,238,228,69,42,248,169,41,218,135,62,244,97,43,158,72,20,8,184,233,70,163,121,128,205,163,18,15,54,233,201,0,179,207,239,163,120,142,216,76,35,243,188,53,134,
161,6,123,176,204,128,24,100,20,89,41,246,148,39,61,1,111,122,211,159,216,108,167,168,14,50,91,11,231,206,207,227,243,95,254,6,190,240,165,111,16,120,171,200,8,227,17,120,91,91,158,73,208,150,135,248,
99,121,128,6,37,136,56,77,71,126,97,14,159,187,253,46,220,115,228,20,65,152,69,137,204,97,17,172,17,151,27,179,3,253,104,150,50,40,176,1,87,238,189,7,149,51,115,240,144,41,125,59,167,208,183,189,15,195,
147,49,80,66,160,159,108,236,171,210,221,230,9,104,134,203,50,207,91,37,232,90,116,193,113,50,247,14,158,113,76,167,91,167,110,83,28,116,37,254,48,20,63,217,142,161,218,235,246,34,74,13,24,228,231,84,
130,93,157,59,141,158,65,176,51,148,182,117,202,16,94,107,161,214,37,155,90,72,208,212,148,44,29,195,145,0,38,99,126,164,180,30,170,100,90,117,109,29,158,138,1,247,196,78,232,251,175,128,73,38,45,178,
195,86,52,39,156,233,117,248,169,1,85,106,192,14,29,113,141,161,219,44,230,224,38,139,247,70,183,161,61,52,73,219,222,13,169,27,171,123,148,236,198,83,216,14,99,170,213,51,148,158,89,189,237,85,191,223,
126,227,59,223,243,83,99,76,236,25,142,23,188,224,57,61,58,87,74,162,206,110,69,81,125,124,226,164,6,86,100,73,163,140,227,93,156,102,171,178,65,37,25,192,71,23,43,14,216,69,134,217,191,127,23,158,120,
195,213,232,39,48,68,83,101,178,5,60,114,244,24,190,126,251,157,120,240,200,49,100,50,89,228,9,32,49,35,18,106,237,253,86,228,63,121,78,224,9,195,74,106,125,153,161,56,155,47,227,228,169,57,60,122,110,
197,30,228,46,145,57,69,107,74,104,78,146,29,14,141,79,66,227,223,119,168,53,145,205,193,79,38,245,153,212,153,52,14,189,174,1,79,36,137,40,217,38,198,14,147,200,166,225,72,103,80,165,214,43,17,16,2,62,
98,24,131,154,130,3,78,21,253,180,195,162,13,197,145,162,156,7,42,5,185,26,80,79,160,119,250,24,218,15,221,131,246,249,243,100,226,26,114,12,232,41,23,195,182,236,228,198,99,148,26,12,25,68,161,135,81,
34,3,39,116,134,231,254,153,105,68,119,237,65,52,28,69,168,82,71,192,29,130,70,199,171,208,52,89,4,154,73,215,219,51,154,112,151,242,140,10,58,76,154,30,25,222,241,145,253,124,27,139,80,114,105,84,227,
113,212,200,178,170,238,97,196,113,168,250,241,7,66,142,220,198,110,173,211,58,160,116,205,56,181,99,235,13,47,126,81,229,13,175,252,189,238,109,175,125,173,245,198,183,188,205,110,196,159,212,98,131,
239,155,223,188,179,247,162,223,250,149,84,44,30,89,112,186,156,86,207,236,245,57,116,135,207,237,246,40,34,242,155,205,6,138,4,80,50,17,23,160,226,73,55,92,131,68,52,140,241,177,33,108,223,62,67,128,
122,32,195,52,2,178,227,39,79,226,203,95,253,38,78,159,157,151,4,4,62,170,4,30,53,158,128,78,90,238,187,20,140,13,64,62,132,85,37,45,170,84,111,161,64,176,136,22,148,113,67,209,107,18,50,61,124,68,168,
217,174,113,244,16,109,85,161,7,162,240,176,51,184,55,87,160,4,34,88,247,68,112,118,45,135,158,234,198,244,236,118,196,27,53,104,167,78,193,34,240,77,186,111,155,245,36,60,178,177,247,50,204,237,246,208,
184,16,124,146,57,173,242,130,84,211,160,41,32,56,200,232,226,110,149,141,21,88,116,187,61,106,193,118,40,14,250,96,84,61,6,157,5,121,154,192,85,25,122,99,65,29,244,234,88,96,248,141,198,6,176,125,114,
6,201,96,0,193,70,29,254,77,50,31,59,148,204,204,72,81,216,241,40,88,224,15,138,158,245,162,222,55,136,82,98,136,192,212,17,58,127,18,46,1,62,141,92,147,122,182,193,14,236,244,71,224,140,36,224,168,21,
224,220,156,215,245,220,106,159,90,45,29,164,51,222,13,211,12,88,102,167,75,249,211,184,237,149,175,52,222,248,206,119,127,87,141,254,100,21,27,124,82,62,255,185,47,183,255,248,143,255,159,249,88,44,126,
102,96,160,63,73,71,55,147,78,103,92,178,59,64,181,92,65,139,0,122,234,83,158,140,223,248,245,95,197,101,151,93,134,237,219,102,192,143,217,122,175,71,246,104,18,40,140,143,120,232,200,163,116,167,231,
236,68,132,42,1,105,207,70,92,0,217,119,3,239,98,145,215,101,6,197,75,77,164,179,1,124,46,121,238,66,165,82,179,167,241,156,60,190,232,0,63,129,115,141,95,197,32,31,134,36,150,82,112,149,200,128,11,100,
158,187,10,117,220,191,184,138,82,174,128,137,98,22,241,83,199,232,96,87,161,117,24,250,120,109,10,245,165,252,220,201,191,217,174,18,192,212,99,78,26,14,167,78,174,163,150,35,177,218,131,130,86,60,201,
208,235,129,73,70,55,198,199,109,211,161,140,76,195,100,56,110,244,218,208,156,53,68,98,160,254,37,115,38,29,48,216,75,178,37,21,7,6,134,49,61,54,193,186,112,195,34,35,43,25,58,232,244,42,116,158,87,103,
88,215,215,23,236,48,139,254,81,32,218,135,22,79,88,173,148,161,148,24,73,26,13,52,135,198,96,210,93,251,74,5,248,189,126,56,7,70,161,147,189,89,45,208,155,235,188,198,166,162,180,27,78,165,82,30,82,26,
181,203,149,86,115,155,98,52,189,74,183,99,220,246,187,47,35,8,127,183,243,198,119,190,247,39,14,132,223,6,159,148,63,125,211,95,40,227,99,19,190,190,254,254,125,4,221,129,185,185,243,238,98,145,161,143,
0,244,49,252,94,115,229,229,152,157,25,135,135,64,9,49,188,36,250,250,232,128,131,108,244,44,78,159,62,131,60,195,230,145,71,79,218,192,105,212,234,104,82,251,217,51,37,212,53,82,51,210,198,118,152,181,
91,123,235,185,152,152,64,32,176,181,221,5,53,152,155,224,19,70,146,241,66,159,0,129,225,93,180,231,240,216,40,174,126,218,147,16,191,246,122,180,233,100,201,121,184,111,35,131,7,214,51,88,100,131,103,
115,12,142,108,244,61,169,21,76,86,243,240,83,157,249,201,82,33,2,44,204,179,39,248,24,96,99,250,232,116,211,161,8,114,212,91,42,205,136,100,70,107,4,27,109,190,29,222,21,106,200,202,240,32,90,35,52,77,
3,49,152,50,144,238,244,195,220,40,160,182,145,35,35,211,81,43,46,40,38,15,86,180,144,108,104,216,77,80,71,101,122,48,26,135,22,8,218,83,123,189,141,101,208,218,66,167,201,112,149,210,80,201,120,221,104,
63,26,186,11,89,178,106,173,85,177,205,91,141,191,87,146,35,168,19,224,178,224,93,214,180,184,83,75,212,134,12,197,189,28,145,190,9,107,38,128,86,146,122,215,114,43,206,108,218,163,167,215,70,213,102,
125,159,165,40,219,44,69,15,177,167,247,110,123,217,139,235,183,221,250,154,246,27,223,246,147,227,142,191,7,124,183,222,122,139,143,63,110,162,249,248,141,106,165,58,114,250,204,25,20,24,74,197,245,134,
195,17,28,186,252,32,70,135,89,9,12,107,178,176,91,50,95,186,108,180,175,125,253,14,124,139,110,116,51,83,160,195,173,162,68,192,214,235,194,120,162,141,191,3,52,113,209,23,157,180,60,100,161,119,36,18,
33,211,121,200,158,212,90,108,52,89,226,216,160,65,168,212,40,172,248,247,3,131,67,184,234,250,171,113,253,211,159,130,3,55,63,7,142,209,73,180,9,136,211,139,203,184,231,248,57,172,100,243,246,84,91,141,
225,221,71,118,188,210,163,98,155,151,161,154,32,150,249,101,1,178,147,231,242,83,171,186,169,167,86,66,49,220,77,246,57,235,11,163,20,77,160,61,50,14,7,59,145,155,58,214,213,221,26,203,99,36,165,163,
46,194,176,76,180,116,26,18,202,14,247,220,57,56,54,203,232,116,105,76,2,179,208,141,16,66,85,96,138,64,234,239,212,225,233,54,160,55,42,208,104,44,180,2,153,175,72,29,201,231,226,198,29,52,44,42,235,
172,93,44,99,153,29,179,40,251,118,5,58,208,146,33,44,215,233,250,91,38,116,118,50,95,124,0,238,252,38,252,167,239,165,168,236,161,25,161,121,115,47,161,27,115,32,231,140,32,109,176,51,117,106,112,230,
243,170,210,67,160,23,31,154,233,133,19,135,208,237,78,49,52,185,232,228,91,183,189,242,21,149,55,189,235,189,63,17,187,46,124,27,124,50,240,203,214,30,239,245,172,87,247,122,221,43,8,58,245,228,201,211,
200,147,81,236,136,73,32,140,13,143,96,247,238,93,246,124,110,139,13,146,207,100,240,173,111,221,133,47,126,249,118,234,51,147,29,208,68,142,38,64,146,19,182,134,97,228,239,182,66,235,197,5,222,178,19,
169,104,60,97,188,56,5,182,56,233,46,129,215,164,134,147,153,17,1,173,0,79,254,110,160,63,129,231,255,220,243,112,211,51,110,194,206,93,59,225,247,249,109,199,125,250,204,89,220,126,199,61,88,91,221,68,
147,160,51,168,179,44,106,66,23,117,214,206,100,12,163,65,63,20,106,39,217,11,166,43,170,142,157,164,199,115,174,120,130,184,39,58,136,37,127,0,117,130,42,207,190,145,163,161,169,145,89,77,25,195,228,
67,225,137,93,133,60,60,252,30,176,52,134,192,97,56,121,125,142,66,6,142,100,2,17,126,255,196,206,189,72,80,231,37,24,131,67,169,69,120,123,212,166,78,13,122,167,9,149,76,167,82,63,154,100,85,115,98,18,
72,80,231,161,67,6,44,162,181,185,129,19,169,44,10,62,55,60,33,178,39,207,123,102,101,43,139,200,23,242,65,225,119,112,159,59,1,31,245,180,49,189,31,5,198,221,205,245,121,70,150,12,150,54,170,52,100,5,
12,187,218,112,26,212,135,253,83,140,0,59,20,213,31,246,178,82,199,104,72,118,107,27,75,51,74,41,31,126,221,239,252,118,251,245,175,248,221,234,155,222,243,254,199,245,188,241,119,143,164,83,29,43,251,
248,115,63,31,186,128,35,200,112,120,49,135,207,160,102,57,119,238,44,54,54,54,9,62,63,98,137,1,6,50,21,143,30,61,9,163,179,149,227,39,44,41,83,109,18,78,108,244,240,19,23,245,30,251,186,173,225,188,12,
63,50,172,18,139,177,225,24,178,101,3,32,57,182,209,34,227,81,152,203,48,141,156,243,250,171,47,199,47,255,252,115,112,221,53,87,98,112,112,128,215,18,180,143,81,42,149,112,247,61,247,99,126,142,140,192,
14,160,82,18,184,120,110,89,64,164,178,83,52,182,239,133,177,109,15,122,110,47,44,97,89,63,129,200,215,87,169,19,239,10,247,97,193,27,128,73,7,42,83,119,140,160,200,49,188,159,229,119,186,119,51,139,123,
218,22,206,210,49,87,7,70,224,10,69,25,82,155,232,219,216,64,104,115,13,218,200,8,204,203,246,195,177,99,24,222,33,63,60,227,73,72,187,147,100,105,138,248,221,216,117,53,50,183,70,243,210,99,189,213,118,
236,68,121,223,30,24,87,93,129,230,101,135,209,238,31,64,215,108,35,191,178,130,7,239,122,8,247,222,119,30,95,187,243,4,86,25,45,220,67,4,125,82,71,201,175,225,148,59,140,244,212,101,40,91,14,52,10,6,
178,171,30,156,122,164,137,71,31,94,195,210,106,22,149,158,27,245,216,56,150,217,92,249,210,38,89,121,9,138,219,116,49,212,79,105,203,167,159,239,56,125,228,13,142,83,15,253,161,62,127,250,23,42,15,221,
53,94,57,123,236,123,162,219,227,169,124,55,248,228,57,5,139,72,31,106,49,134,196,112,36,100,179,148,76,177,9,147,45,175,44,225,145,35,15,97,115,109,21,29,54,188,105,131,133,61,145,204,146,163,238,18,
125,184,53,31,44,192,147,34,225,117,235,153,0,88,30,2,82,209,143,242,144,198,144,45,49,12,178,158,28,95,206,59,52,216,135,231,220,244,68,252,230,175,189,0,79,126,210,19,17,99,88,22,86,19,195,147,207,231,
113,23,129,119,223,253,15,161,196,231,29,134,60,23,69,191,151,29,197,235,162,129,144,221,169,8,58,41,10,29,169,66,33,223,189,242,6,108,14,77,226,222,64,28,139,193,40,58,116,206,2,98,57,151,206,80,44,211,
129,114,93,5,26,128,51,4,225,3,155,25,60,216,213,48,215,63,134,18,29,103,135,108,229,88,95,133,159,117,224,33,203,54,207,207,161,148,77,161,214,107,194,180,218,172,44,134,76,130,143,95,75,56,150,18,69,
129,131,12,42,41,250,237,78,23,197,90,19,25,130,62,55,189,27,109,74,134,142,170,99,141,230,232,206,175,223,131,111,124,233,14,164,55,82,140,24,45,52,218,77,172,49,98,60,234,246,97,35,22,70,86,53,81,205,
87,224,52,253,168,244,237,196,185,64,31,54,20,31,178,74,12,249,224,16,93,118,7,217,234,9,118,162,147,252,178,103,80,235,22,217,30,101,93,95,62,53,226,60,253,224,179,156,71,239,122,173,254,224,55,255,16,
167,143,254,92,249,158,111,244,151,142,63,64,145,250,248,42,223,238,21,175,125,237,107,69,160,137,86,152,36,120,182,183,90,77,101,125,109,29,75,75,203,40,211,149,73,169,177,177,75,165,60,218,12,43,138,
217,65,134,21,247,224,209,19,88,91,223,176,25,73,230,120,165,81,217,182,118,217,154,45,217,218,216,81,138,48,90,40,20,66,32,24,176,53,94,83,6,171,9,170,46,177,154,232,235,199,225,67,7,241,115,207,123,
38,158,116,195,213,152,153,153,133,135,108,85,173,54,216,227,87,121,29,75,184,239,190,7,24,226,191,70,214,91,228,53,149,208,52,12,134,213,173,13,131,100,252,81,230,166,39,25,250,102,107,57,120,233,94,
123,251,174,66,105,124,7,110,167,41,121,68,166,216,216,240,162,233,236,189,155,121,109,110,26,18,7,65,42,128,145,14,99,18,96,45,131,32,167,230,76,81,70,212,8,4,37,24,178,147,41,188,229,60,188,235,52,2,
85,50,123,255,48,66,19,219,224,92,95,129,243,236,41,200,146,1,25,207,147,239,235,160,59,119,146,57,213,49,58,229,158,116,92,86,43,217,84,13,210,38,151,43,40,75,78,96,169,142,116,185,106,15,69,201,104,
64,161,80,193,218,70,30,115,75,105,4,19,33,140,142,186,168,59,27,148,4,148,6,252,78,43,219,6,113,42,234,162,9,74,32,58,49,5,103,199,129,5,118,8,93,95,66,188,175,3,131,205,56,191,94,68,160,90,132,79,52,
122,189,162,195,52,226,106,62,61,171,150,114,251,217,187,217,11,123,206,91,94,127,75,233,214,255,241,7,245,63,255,203,55,219,237,241,227,46,223,6,223,159,255,249,159,91,183,222,122,171,220,181,167,69,
0,237,51,77,51,150,201,100,148,133,249,5,91,199,217,187,125,122,60,168,49,172,110,110,110,162,144,207,81,231,145,249,90,29,108,108,166,108,192,9,248,182,216,110,11,108,91,192,211,108,112,72,214,115,136,
78,82,12,134,73,198,19,240,52,234,116,196,45,3,65,186,207,107,174,190,18,191,242,75,191,128,235,174,187,134,159,97,24,82,28,200,23,74,56,118,242,36,206,159,63,135,99,143,30,199,183,238,186,223,158,166,
171,144,129,100,22,70,163,102,130,230,176,183,222,144,243,184,232,150,39,204,38,102,148,54,53,21,25,115,124,59,114,100,194,35,4,201,249,116,134,192,106,219,215,34,96,19,182,114,59,100,250,80,76,144,128,
15,182,121,146,100,135,54,77,79,190,82,71,170,210,64,129,216,105,179,19,56,9,66,123,172,142,70,75,139,245,193,197,206,167,206,157,128,182,182,182,149,15,40,29,128,95,219,69,64,43,148,37,166,63,10,45,28,
135,234,224,53,146,185,21,209,177,85,154,48,118,239,54,235,205,206,232,49,68,235,182,144,203,149,177,177,146,102,24,45,219,209,166,47,238,67,149,81,229,108,182,137,50,191,91,184,63,73,9,225,64,33,226,
67,107,114,0,21,186,232,229,165,5,214,55,157,116,175,128,141,84,1,139,4,223,160,214,70,160,66,237,173,187,209,220,117,80,113,102,214,156,90,41,71,11,238,216,102,185,253,123,148,90,121,80,173,214,26,183,
189,226,247,138,175,127,213,43,59,111,122,251,59,237,118,250,113,149,239,209,3,4,159,73,224,229,217,54,109,134,193,169,74,165,18,155,63,127,30,155,12,71,114,235,129,177,145,81,12,80,171,201,110,162,155,
153,60,42,212,103,146,108,89,40,20,237,70,51,169,191,100,104,100,139,233,182,24,73,158,59,201,66,2,186,88,60,102,135,152,106,185,140,128,207,99,103,200,72,163,239,222,181,3,135,14,29,192,232,200,144,205,
96,45,106,173,37,106,35,209,118,217,244,6,141,197,58,142,29,63,139,20,197,186,100,210,200,150,25,253,3,3,240,80,63,218,235,126,5,64,60,151,135,29,96,140,173,59,77,73,231,21,195,67,86,233,81,155,186,162,
62,56,41,232,101,90,176,194,115,219,59,161,218,172,188,69,209,50,16,36,191,203,144,144,209,238,162,65,150,52,218,61,118,46,1,33,59,27,117,97,177,75,109,231,245,33,100,39,205,242,239,206,159,70,155,86,
66,45,21,161,83,130,216,76,74,23,43,215,97,176,67,117,202,37,24,185,44,150,22,87,112,255,185,69,44,102,75,232,242,184,46,178,106,128,117,25,160,156,9,182,219,232,210,24,117,88,225,18,1,36,3,187,88,40,
99,117,189,128,83,115,41,148,27,29,76,79,12,98,216,163,33,212,213,81,168,26,216,208,122,88,99,231,90,243,0,133,137,33,228,27,61,106,66,118,200,66,11,211,177,17,4,98,83,88,226,119,88,73,244,99,112,150,
145,54,28,82,218,51,215,186,123,125,99,73,165,219,217,161,173,205,31,86,171,37,86,147,217,124,221,239,191,162,242,167,239,121,191,140,149,255,88,202,247,128,143,236,39,0,148,49,208,53,195,104,27,133,66,
126,100,121,113,49,178,182,186,166,74,182,72,216,207,202,39,56,188,108,36,141,160,233,41,26,252,212,55,37,86,180,61,111,203,207,72,106,149,20,97,63,1,158,56,220,32,67,109,36,26,181,93,173,48,222,190,189,
187,241,43,191,252,115,56,184,127,23,6,146,81,12,13,245,243,253,152,29,178,155,212,61,181,106,197,214,118,71,30,57,129,52,5,249,202,218,166,205,130,18,166,2,100,160,253,7,14,96,100,120,107,71,210,30,89,
199,214,147,188,30,17,53,146,103,39,137,162,1,153,183,109,213,209,11,81,51,73,86,51,63,147,140,71,225,143,134,168,29,115,246,88,36,17,39,87,106,171,93,129,97,143,241,223,160,78,235,208,64,137,20,216,10,
197,150,205,206,149,84,6,73,154,163,145,252,58,124,155,203,240,228,54,160,21,75,116,183,101,232,100,65,151,155,223,215,235,70,91,113,162,233,13,161,193,198,223,228,53,223,191,153,195,113,130,104,189,222,
66,186,82,165,137,40,32,88,175,96,34,224,67,95,31,59,6,65,232,100,232,239,200,32,61,207,221,150,144,207,142,157,74,209,5,243,59,244,245,199,225,117,59,81,46,214,81,207,54,48,237,10,99,202,27,33,187,233,
40,14,38,81,137,199,177,178,90,135,110,40,216,73,179,18,158,222,135,123,74,89,180,156,22,166,47,11,195,26,138,217,99,137,29,71,84,117,27,134,135,237,210,167,47,156,222,169,101,55,246,179,23,134,95,127,
203,107,114,183,221,122,107,249,77,111,123,135,200,174,31,105,249,23,78,104,43,252,190,182,86,46,151,230,207,157,59,223,90,95,93,221,149,218,216,8,53,24,54,52,50,68,151,189,85,38,73,221,150,202,74,113,
195,77,55,41,89,194,50,181,70,95,251,237,25,13,41,2,60,25,144,78,246,37,237,231,27,212,144,33,178,214,47,254,194,11,240,172,103,223,140,157,59,119,97,118,118,6,145,16,93,181,210,37,115,182,201,30,30,59,
11,250,111,63,240,81,212,155,91,14,184,200,112,84,100,67,11,88,102,183,109,195,174,93,187,169,17,233,54,3,126,155,93,101,16,220,168,49,20,243,33,235,54,250,93,14,244,121,93,208,217,192,174,27,110,128,
103,98,146,14,220,68,151,154,213,39,224,156,158,128,211,231,178,231,157,237,78,195,106,239,72,184,149,161,25,65,177,13,60,251,7,67,42,191,110,165,130,16,95,56,176,125,23,70,59,85,120,139,25,88,60,79,59,
150,128,38,215,97,20,161,121,8,60,221,139,166,147,70,74,119,162,97,105,56,82,172,225,65,98,170,70,166,107,177,99,86,89,111,89,118,200,172,72,17,154,172,144,81,35,8,253,24,98,199,11,83,138,248,26,117,246,
0,234,30,94,67,179,109,216,17,102,157,46,124,105,53,141,197,149,12,250,217,129,175,223,62,136,153,128,27,174,22,235,147,102,166,226,115,163,198,80,223,158,26,132,111,247,54,132,45,23,238,124,248,24,194,
142,6,250,34,155,232,233,22,230,87,40,145,230,151,209,199,80,173,26,77,85,91,59,235,86,179,171,3,90,122,237,128,90,204,31,86,42,197,192,109,47,125,113,241,214,91,94,93,123,237,235,95,219,251,179,191,122,
171,221,126,63,236,242,47,192,39,69,0,248,218,215,222,106,156,61,115,54,156,207,102,175,220,220,88,31,144,173,104,133,39,58,166,137,34,27,67,103,171,120,232,20,21,130,203,36,251,164,82,105,27,28,194,124,
2,62,121,200,216,94,144,230,66,194,90,145,238,84,244,98,95,34,134,237,51,99,136,82,219,200,38,144,201,190,65,62,143,82,43,209,49,167,83,12,241,41,130,49,108,143,227,181,101,67,62,82,82,142,225,75,194,
173,12,253,12,12,12,217,218,81,134,108,100,86,68,66,186,44,62,47,167,54,24,254,234,246,66,167,209,109,59,48,186,123,47,180,11,179,38,222,88,28,209,233,237,118,174,96,151,141,110,86,75,72,242,249,200,232,
160,189,222,36,159,167,121,33,208,229,250,25,56,249,184,24,142,9,60,234,43,55,229,197,225,233,25,236,118,80,243,173,206,19,228,53,152,242,93,103,247,0,35,19,112,228,51,116,106,148,11,161,4,154,59,246,
163,195,14,35,99,144,247,84,25,30,21,134,102,234,82,97,104,1,115,135,127,87,37,107,109,80,195,229,25,65,18,205,50,102,123,6,118,14,13,217,227,134,160,22,237,176,222,234,100,66,133,242,160,74,182,204,200,
216,96,177,12,159,223,131,120,212,111,15,101,109,172,146,117,11,6,174,12,143,96,194,29,65,198,165,32,53,26,65,133,97,249,204,217,21,120,58,69,212,243,103,209,200,173,226,129,211,117,132,219,42,134,252,
116,239,137,65,26,41,143,210,13,4,52,247,198,146,87,207,174,143,16,124,135,208,105,239,99,228,241,240,219,103,254,240,13,175,175,254,201,155,127,248,139,155,190,47,248,164,188,246,245,111,80,214,230,207,
39,51,27,27,87,102,86,87,198,173,114,73,241,241,75,203,112,130,204,219,38,168,174,39,146,33,212,249,138,193,158,154,162,160,151,240,39,115,180,146,3,120,161,253,24,234,18,232,239,75,16,120,85,59,12,79,
12,14,146,65,166,160,116,201,106,12,177,178,34,206,31,12,210,73,55,241,177,143,127,10,95,248,242,55,112,226,212,25,137,64,182,206,220,92,93,35,243,21,237,99,185,201,46,194,116,246,66,31,254,46,207,101,
128,121,99,113,30,21,2,215,197,198,210,41,5,118,238,221,143,209,193,97,184,39,183,163,147,94,135,121,230,36,124,170,133,240,208,40,34,12,215,246,22,186,108,92,173,81,197,216,112,63,194,177,160,157,224,
90,97,3,139,118,181,77,18,175,85,52,163,131,230,230,114,58,204,171,251,163,72,44,159,132,206,144,38,6,194,98,56,214,9,98,101,115,3,93,70,133,158,156,155,127,211,50,186,56,91,106,224,158,46,29,41,89,80,
6,183,69,78,108,69,3,86,10,159,75,22,79,155,159,45,210,33,47,211,28,148,201,184,201,122,17,195,172,182,72,114,0,38,229,68,135,0,239,201,186,20,126,94,50,167,133,209,11,249,34,214,214,242,56,125,158,157,
52,85,196,222,137,97,204,134,28,24,247,6,176,185,148,195,186,106,98,205,217,197,102,183,138,218,254,89,100,181,48,114,71,51,56,186,216,194,158,209,109,24,60,252,36,84,216,110,103,242,27,212,130,38,162,
1,202,145,114,89,213,10,57,31,195,240,132,82,200,94,67,186,221,205,8,98,222,246,223,126,61,247,250,223,250,245,214,155,62,240,145,31,26,8,127,32,248,94,255,139,55,59,98,205,210,184,183,86,185,54,90,175,
77,236,111,213,213,189,237,38,34,12,113,246,194,106,130,38,52,214,111,175,161,104,82,224,102,201,108,146,82,53,152,72,96,144,110,85,204,128,206,207,136,57,136,211,104,72,146,129,12,59,120,92,78,76,143,
142,96,219,182,25,123,199,81,113,205,203,11,243,248,196,39,62,133,207,127,249,246,173,140,228,30,27,136,64,22,38,148,227,74,250,150,125,63,54,54,90,135,239,11,11,54,216,56,149,34,27,99,238,12,210,139,
114,187,3,3,58,1,17,161,240,223,215,105,96,64,172,39,175,35,31,244,193,156,28,133,82,92,133,121,126,14,126,2,32,49,53,141,208,16,245,150,76,235,177,83,196,120,157,147,227,195,240,4,188,54,211,200,244,
30,41,30,46,2,242,192,200,56,174,155,26,197,208,198,121,184,170,57,94,3,241,35,255,16,56,138,143,172,78,182,85,25,210,93,212,194,77,213,133,71,43,109,124,169,231,192,162,232,44,2,204,54,68,2,184,11,15,
233,128,118,72,183,65,72,176,178,131,173,59,220,56,163,123,80,37,192,98,181,34,250,233,150,251,120,222,32,59,137,159,242,65,110,241,101,210,169,91,52,64,5,209,131,107,27,168,214,234,240,251,221,232,24,
116,228,212,150,171,231,210,24,168,42,216,206,112,236,81,60,40,36,131,48,118,77,162,197,48,188,126,114,19,135,18,97,134,247,8,22,55,31,197,137,165,83,152,28,245,34,176,59,76,109,196,206,86,108,65,169,
52,84,173,148,245,104,233,245,89,181,82,120,58,43,154,148,238,106,49,28,111,190,241,3,31,97,88,248,175,47,223,23,124,249,79,190,67,235,166,54,102,28,205,218,139,19,94,207,211,38,6,135,61,195,20,182,145,
46,123,11,245,93,68,116,17,93,175,70,199,41,58,73,86,171,229,232,120,101,117,155,215,229,65,148,141,153,12,135,46,108,228,232,37,16,61,40,81,183,53,216,152,140,58,136,81,227,141,82,43,197,201,138,94,106,
198,179,103,207,226,83,159,249,60,67,77,155,97,184,31,110,54,100,153,14,91,92,116,91,6,184,217,90,146,92,32,183,200,146,45,59,100,26,78,86,203,213,139,121,180,37,29,221,52,224,228,117,203,28,238,78,2,
232,50,183,134,32,89,169,193,16,182,64,32,170,116,134,142,129,36,12,119,16,202,153,211,240,166,214,237,197,72,129,193,33,4,36,185,64,46,138,96,238,15,5,49,60,194,239,68,16,148,54,211,216,22,79,226,250,
153,41,140,84,210,112,151,210,100,54,2,79,230,122,93,62,96,219,30,168,215,63,221,6,159,76,173,201,154,223,147,109,7,238,212,253,88,231,251,22,89,217,14,181,172,42,1,221,86,185,8,66,121,81,94,23,96,18,
140,236,48,108,122,172,59,61,88,37,104,27,116,207,222,6,37,10,245,224,96,56,130,8,143,163,73,221,241,8,29,254,35,198,174,211,52,108,185,80,44,27,152,91,204,176,94,117,60,241,178,89,28,24,14,96,44,208,
135,115,103,86,209,232,15,160,78,169,82,85,123,240,95,189,199,30,30,58,126,228,81,44,166,115,216,51,225,164,123,175,65,181,136,171,34,35,90,149,15,182,171,210,110,42,106,41,235,82,106,149,29,61,167,171,
207,114,58,238,126,205,171,126,175,120,217,13,215,233,127,252,191,255,72,127,251,59,222,43,249,180,255,37,229,95,128,175,116,246,110,181,151,90,29,70,62,247,219,74,79,123,137,226,139,248,181,98,1,78,246,
80,247,240,8,188,12,145,1,134,94,47,43,33,192,158,164,50,124,150,43,77,228,232,68,183,198,209,236,187,64,210,193,233,136,249,217,187,200,46,10,193,88,161,131,149,135,12,228,122,60,14,12,37,34,8,57,29,
208,88,145,217,92,1,103,22,86,236,140,14,153,170,106,231,40,144,9,6,1,158,201,214,147,49,52,49,34,162,33,183,104,195,180,195,182,202,94,239,150,121,85,134,84,146,8,130,116,227,87,94,113,24,59,227,97,184,
43,52,1,108,64,209,77,133,179,115,168,136,9,143,38,225,26,165,249,56,55,135,222,3,247,217,67,36,129,72,2,225,209,81,4,8,122,73,250,244,144,85,67,212,120,131,158,0,174,154,152,192,84,105,29,222,204,50,
156,102,203,206,251,83,101,105,38,207,165,62,237,249,80,146,253,80,39,182,81,247,77,35,167,186,241,241,133,77,156,162,231,238,18,8,194,242,54,232,228,33,223,193,6,157,212,240,86,8,150,165,4,178,254,69,
198,249,100,193,187,0,149,161,130,122,208,137,77,118,224,52,53,161,78,189,57,222,105,226,242,100,28,147,236,168,126,154,54,176,29,100,155,15,157,29,190,77,169,146,162,70,222,220,72,147,164,156,24,30,76,
176,45,138,172,103,106,206,147,27,216,199,150,218,102,122,96,144,0,150,6,131,88,141,184,176,150,101,72,78,81,87,123,42,104,231,151,161,53,21,104,38,141,147,225,100,93,181,121,117,188,14,49,96,190,144,
101,14,141,60,96,197,18,95,62,66,155,62,63,191,112,85,146,250,233,125,127,243,119,235,242,45,254,43,202,191,0,223,235,95,241,98,135,153,89,61,100,213,42,47,85,20,199,176,221,211,217,40,10,25,207,162,126,
210,93,116,184,163,99,8,176,181,61,4,137,43,151,71,182,209,70,138,26,170,70,161,45,3,184,162,9,107,12,179,26,133,155,139,149,162,17,128,162,169,100,250,77,222,147,36,2,233,253,146,121,226,230,207,22,195,
220,34,93,93,73,146,4,36,60,243,124,108,95,187,177,58,108,36,162,206,102,79,185,177,159,223,235,198,204,112,16,123,39,3,24,14,59,224,97,123,24,194,190,236,143,163,253,3,216,201,176,31,33,112,125,141,50,
60,109,134,38,2,62,204,70,34,97,34,190,123,31,162,162,247,30,61,2,149,225,222,162,94,83,51,41,94,135,11,94,178,156,151,108,238,226,185,147,12,189,179,100,250,190,70,1,158,244,18,148,112,16,93,62,36,17,
96,107,0,157,64,138,245,217,187,26,88,252,221,12,132,145,138,244,227,147,223,186,27,217,82,137,178,193,180,181,172,236,55,45,97,246,34,243,93,4,160,104,99,209,112,109,118,82,118,37,22,130,145,207,237,
193,111,106,68,249,190,134,12,165,240,124,117,190,230,109,213,144,100,135,75,146,197,34,212,212,94,254,189,116,218,30,143,45,46,93,194,114,147,157,63,151,175,160,76,195,252,232,201,69,4,9,184,167,95,182,
3,81,118,78,111,215,135,5,214,111,217,167,161,196,227,52,163,62,212,70,134,97,165,90,8,20,61,112,133,119,194,17,25,180,53,176,202,206,208,81,157,104,110,59,144,235,206,236,252,59,171,127,232,129,175,223,
126,191,114,226,200,145,63,232,27,72,230,255,241,83,159,63,249,185,143,127,68,121,209,111,252,138,235,143,254,232,13,218,91,223,246,174,255,48,19,254,11,240,189,225,53,175,80,90,237,106,212,180,90,151,
247,138,155,131,86,169,168,171,26,101,60,89,73,163,96,215,249,16,23,233,148,132,76,246,66,234,91,84,233,112,55,101,51,29,2,208,193,30,44,122,141,194,12,110,62,100,253,133,197,16,87,167,120,207,231,11,
118,175,151,212,248,28,129,40,174,185,213,49,208,144,5,68,53,130,147,161,185,156,205,218,51,6,50,231,42,140,33,6,64,182,198,16,253,24,141,70,113,96,255,110,252,194,115,174,195,115,111,186,2,87,30,28,199,
244,152,143,161,163,67,227,209,195,182,104,63,6,105,98,84,58,72,61,216,134,39,108,193,231,84,109,157,23,102,3,201,54,184,56,115,2,234,250,26,27,154,161,152,141,238,148,69,221,27,171,232,174,175,194,33,
204,87,200,193,55,127,150,108,183,6,103,49,109,179,93,109,168,31,233,193,49,56,119,28,132,238,15,216,59,226,43,169,53,84,55,214,144,214,220,104,209,36,84,211,105,228,132,137,25,246,151,22,22,80,102,180,
16,144,202,190,211,18,13,4,132,242,184,88,100,160,91,64,104,27,17,27,148,202,214,20,225,133,207,139,174,236,178,126,139,236,252,43,12,197,101,94,127,64,118,90,16,205,76,13,29,99,39,116,176,35,181,249,
186,197,14,173,201,40,4,235,119,241,252,18,210,12,171,50,12,21,97,135,89,93,91,71,131,33,181,77,163,178,91,243,161,95,243,162,25,143,162,62,58,128,100,215,131,161,44,29,188,39,6,55,1,167,21,115,182,140,
16,230,238,13,140,102,21,95,248,155,26,156,139,39,78,205,69,207,60,114,228,215,246,94,182,247,3,255,240,185,175,100,15,237,217,19,40,228,178,7,35,177,168,78,38,148,47,250,31,42,255,2,124,111,252,171,119,
245,94,253,210,23,54,204,142,81,235,116,218,65,179,221,12,89,149,162,87,213,53,69,11,132,160,198,226,208,36,245,104,115,29,74,189,102,143,161,121,8,12,34,10,73,54,94,188,205,222,68,240,72,202,122,130,
252,237,96,133,119,201,16,6,123,106,129,128,115,16,72,49,234,60,7,25,163,68,192,166,40,150,75,100,62,153,62,146,158,47,123,173,116,200,10,18,182,236,155,192,144,25,5,136,3,9,191,236,166,133,231,253,252,
47,226,178,171,158,136,96,255,46,248,146,219,16,239,235,67,194,223,132,71,178,128,139,38,252,60,142,107,220,139,224,142,42,124,219,156,112,244,135,37,82,209,153,210,180,100,50,80,43,37,123,237,134,131,
225,221,41,199,238,118,96,10,219,18,60,214,218,42,65,181,9,141,108,169,26,77,178,139,132,33,178,74,184,139,21,255,0,194,147,187,224,137,247,163,59,62,131,2,191,227,89,163,131,85,143,139,160,235,80,167,
117,48,202,112,31,137,133,177,176,180,98,187,95,73,150,144,1,115,209,172,146,209,35,179,31,23,65,104,63,151,206,192,34,191,203,144,145,60,196,193,11,16,47,206,137,139,30,108,241,181,28,89,176,192,168,
99,240,122,61,236,176,253,148,44,9,178,91,200,225,132,95,180,26,129,220,227,223,180,40,85,100,29,74,131,236,93,111,154,172,99,19,243,139,107,216,61,57,130,43,166,7,209,239,240,160,93,161,212,201,22,49,
201,247,102,107,22,162,254,8,220,41,126,247,244,154,237,228,41,156,24,181,218,94,181,221,30,81,81,119,84,186,165,81,163,84,62,248,180,95,126,254,59,163,222,120,39,151,73,79,241,241,155,129,64,96,233,159,
62,243,249,149,71,238,187,67,123,197,203,95,234,190,245,53,175,84,223,252,214,119,62,102,38,252,190,134,227,245,183,222,98,24,149,198,106,199,232,46,209,76,116,41,114,99,221,118,131,234,181,204,106,160,
190,146,97,10,126,78,214,215,106,70,29,190,174,129,1,246,180,177,48,29,149,174,160,159,61,49,201,208,19,102,229,233,252,139,58,217,66,132,178,204,93,10,192,162,94,31,34,172,104,194,205,118,183,181,102,
155,21,47,139,102,84,148,25,202,101,32,91,214,251,202,248,161,80,84,136,2,243,57,55,12,226,153,55,63,13,219,247,94,99,143,239,217,83,106,178,208,198,29,165,254,171,162,185,114,22,221,140,1,87,40,78,141,
67,19,16,202,33,48,18,129,107,106,4,86,160,1,35,67,0,180,53,59,91,89,134,139,84,97,29,130,67,22,196,203,144,134,228,241,169,108,88,209,116,180,10,208,8,76,226,19,10,27,188,17,115,35,107,5,144,116,251,
109,237,153,101,103,185,171,92,131,62,26,227,121,120,52,126,199,251,30,57,73,118,217,64,122,85,230,158,107,56,124,249,1,108,219,181,221,30,124,223,36,251,216,251,29,242,220,178,38,70,0,102,47,17,32,128,
100,185,170,140,113,202,79,113,243,91,161,249,226,99,11,152,50,245,167,81,239,245,200,118,5,214,121,154,230,166,195,58,138,48,84,79,145,105,39,66,91,201,15,146,145,45,243,198,26,129,175,82,79,110,210,
52,45,81,75,27,36,132,190,190,24,130,65,47,9,160,142,252,102,25,174,114,27,147,193,4,77,71,20,22,235,220,183,122,158,250,143,145,138,245,32,78,92,149,173,238,58,213,126,109,210,218,167,68,171,251,194,
62,213,189,239,230,177,219,71,199,198,219,95,251,212,157,83,181,82,241,154,98,42,245,201,23,60,229,230,74,185,144,235,47,231,243,151,91,172,200,63,253,139,63,47,255,249,255,247,127,183,128,244,111,148,
239,11,190,63,127,219,123,240,123,175,188,181,109,182,123,27,70,195,56,223,233,169,69,83,213,125,166,105,68,122,141,146,75,107,86,20,7,43,80,21,61,199,198,113,13,142,146,156,231,237,249,218,64,44,106,
79,149,249,45,234,61,134,90,169,240,154,195,133,42,123,121,65,102,33,216,75,37,247,77,146,61,29,100,55,23,27,65,194,135,139,128,148,74,46,49,236,74,197,118,36,228,18,124,22,63,155,164,80,126,193,83,134,
176,107,247,78,134,211,73,182,136,206,163,241,13,41,12,185,133,205,243,88,62,126,154,13,203,202,164,224,79,101,178,12,225,52,55,60,142,220,4,166,107,202,189,218,146,176,92,52,21,100,107,123,206,151,13,
39,107,78,4,116,118,106,21,65,97,63,136,56,77,26,91,186,25,133,127,46,185,11,231,189,113,108,22,85,68,138,53,56,215,23,177,76,144,125,254,204,2,66,241,0,195,163,36,189,14,227,204,252,42,66,100,61,15,67,
157,236,15,211,239,243,97,146,225,186,65,22,79,179,113,101,160,93,182,22,145,249,91,9,171,162,9,229,28,54,3,10,202,46,20,27,108,23,126,223,2,31,27,137,159,223,250,44,223,35,8,235,100,187,148,211,141,60,
79,222,35,176,100,153,192,48,59,100,146,231,12,144,33,221,98,96,248,154,12,104,183,218,6,69,113,27,149,178,48,97,15,75,43,25,148,75,53,236,153,30,65,34,238,39,131,203,50,230,12,218,212,219,114,108,233,
156,154,212,189,156,107,194,173,104,215,56,252,138,55,29,143,13,105,129,192,80,168,223,169,234,145,236,169,141,65,179,92,143,14,12,70,62,191,150,174,182,138,217,204,1,130,239,102,94,205,220,228,174,61,
169,91,94,123,139,122,203,173,175,214,249,192,95,252,197,95,110,201,218,239,83,190,47,248,164,188,229,189,239,199,219,63,250,241,238,111,255,226,47,21,187,150,50,215,211,156,203,12,92,53,74,100,87,183,
211,164,225,237,56,148,114,65,113,78,110,135,99,98,134,96,234,192,209,71,209,90,200,218,83,106,238,8,169,156,58,81,39,131,201,68,123,138,64,43,176,209,237,125,96,248,229,68,108,251,89,161,178,93,153,45,
206,61,94,169,101,20,217,80,178,239,139,96,139,24,160,81,232,217,189,122,207,108,2,147,195,110,26,158,32,223,112,109,1,167,43,64,58,143,234,234,67,40,156,94,162,70,163,137,113,122,65,175,141,114,190,75,
32,119,80,79,23,41,198,9,176,224,14,132,18,178,48,135,33,159,218,70,118,21,221,186,49,52,129,204,243,74,111,151,90,234,50,108,119,195,49,123,213,218,70,116,22,247,140,63,3,15,186,183,97,217,53,141,162,
127,28,142,90,9,245,110,11,159,59,189,134,141,114,7,110,205,129,64,79,214,5,247,176,239,192,24,194,49,126,15,167,207,102,156,74,42,109,167,155,197,195,33,60,225,250,107,16,165,214,218,88,93,69,145,157,
67,234,65,128,102,135,89,129,38,207,111,91,25,249,210,118,145,208,187,5,68,233,12,14,246,88,213,166,98,50,173,160,146,64,105,16,112,89,118,254,172,244,80,214,103,146,18,97,154,76,56,192,239,168,242,117,
198,13,180,233,220,157,236,240,6,37,206,234,242,42,214,86,214,108,2,8,133,252,252,190,22,50,100,194,205,38,35,229,224,0,244,169,73,212,25,77,228,220,218,228,20,176,219,1,199,12,127,243,50,162,132,29,186,
195,107,77,43,221,226,30,119,163,56,29,247,121,219,207,126,249,83,143,132,2,125,173,35,119,30,57,80,204,164,199,19,33,255,215,43,75,133,242,220,67,247,205,24,245,218,118,143,215,85,127,203,59,222,211,
176,191,206,247,41,63,16,124,23,203,187,63,249,89,235,189,159,255,74,227,21,175,187,109,165,93,111,157,48,59,189,197,174,238,210,58,138,21,181,172,142,87,233,52,84,37,183,9,199,240,4,156,227,19,80,86,
23,237,125,245,100,13,131,147,225,192,69,16,130,33,37,197,80,84,165,1,241,178,210,229,164,34,182,251,124,46,76,15,37,96,42,186,189,13,133,184,55,153,134,147,53,194,146,155,103,107,30,86,148,252,220,62,
158,196,196,32,197,155,89,67,179,94,134,98,230,168,75,86,41,250,31,198,230,201,227,48,230,74,240,108,86,237,221,75,195,51,59,224,13,37,9,124,86,228,122,5,138,39,14,127,116,24,161,232,160,173,141,20,217,
129,138,199,165,73,102,120,39,67,240,137,232,203,174,135,226,125,52,132,222,158,253,104,78,31,192,145,200,33,220,29,57,136,53,189,15,69,47,77,71,223,54,180,92,97,50,73,1,119,173,27,118,14,93,167,184,65,
214,41,99,165,172,98,100,132,122,152,96,114,248,194,200,84,235,136,15,15,48,36,235,212,100,192,158,100,2,137,80,16,75,12,193,50,23,45,99,137,21,58,99,49,100,178,185,166,24,42,123,188,241,187,138,48,158,
199,181,245,16,0,10,16,69,255,202,115,201,200,81,8,198,14,65,88,243,50,20,147,9,203,252,78,178,134,164,159,175,203,118,32,81,186,227,176,56,110,9,249,188,14,249,142,66,4,146,188,80,41,85,25,130,155,88,
94,207,217,251,16,142,110,31,129,123,80,166,233,130,88,107,169,168,196,146,168,116,105,184,20,146,9,251,187,211,190,67,124,135,167,174,135,28,168,246,13,205,134,3,225,97,95,204,165,185,194,185,51,155,
219,219,165,82,253,233,63,255,172,219,107,133,174,181,242,224,61,207,176,12,99,38,49,60,116,246,237,127,243,193,202,133,175,243,47,202,191,9,190,139,229,157,127,251,193,238,239,191,236,119,43,29,163,181,
72,1,50,223,85,180,117,130,134,186,180,25,233,181,202,46,130,80,81,23,78,49,164,178,34,199,38,160,245,15,66,103,216,212,42,69,120,168,249,100,48,57,200,16,48,68,33,31,166,40,150,225,2,153,225,24,219,54,
141,58,27,191,82,111,81,92,243,75,151,203,246,220,168,232,63,161,2,17,235,46,135,130,67,59,134,237,236,151,74,41,135,53,123,89,100,10,237,210,42,230,142,206,97,254,209,52,25,183,139,136,238,133,127,116,
28,254,145,49,196,182,109,67,63,177,42,44,16,112,241,245,190,49,54,12,77,192,201,71,208,43,151,236,176,43,131,181,182,227,20,144,71,61,80,182,169,112,237,35,19,79,147,67,194,1,28,73,41,120,36,235,130,
225,13,193,162,44,144,25,140,170,131,206,221,232,33,19,156,65,199,45,9,1,235,24,9,117,240,181,19,13,228,41,228,117,153,252,33,17,185,253,58,38,39,251,16,33,219,21,203,117,84,105,66,74,178,123,106,174,
128,253,123,119,227,240,213,87,218,99,158,203,243,11,246,22,110,194,126,178,101,155,61,53,201,98,147,27,159,250,220,52,35,252,254,146,238,213,150,27,210,240,61,1,158,212,143,189,232,93,64,40,117,197,8,
82,33,19,110,146,185,115,212,124,46,106,238,41,173,135,169,160,31,97,214,191,108,168,46,147,1,178,147,151,131,223,185,69,34,72,109,166,236,12,116,217,117,182,143,117,43,123,199,44,164,74,88,167,121,234,
121,93,100,120,39,86,151,202,114,199,110,24,169,28,220,178,92,132,17,74,115,43,138,59,234,8,104,142,246,180,213,202,239,113,183,26,99,35,99,125,107,135,95,112,248,216,241,47,31,245,214,230,206,223,136,
106,165,56,125,112,255,131,111,249,187,15,255,192,217,145,199,12,62,41,239,248,251,15,91,239,251,220,23,59,191,247,178,151,103,122,102,239,52,219,238,76,87,209,203,29,77,15,152,157,70,212,106,85,117,221,
108,219,107,85,29,59,247,218,153,30,14,86,136,131,90,39,210,110,98,40,145,192,16,53,97,130,159,73,208,177,121,146,73,196,182,111,67,129,33,33,79,141,38,99,92,114,171,83,67,180,162,13,62,9,49,64,148,64,
216,71,64,140,140,12,80,183,180,144,43,26,240,187,105,234,228,246,5,103,51,168,20,58,240,145,213,226,251,182,246,86,81,105,128,130,102,19,209,212,60,92,108,69,39,67,168,168,68,156,57,10,37,151,178,29,
29,97,205,87,182,196,53,168,81,205,233,113,24,209,26,148,64,25,142,32,141,140,194,70,152,63,131,135,30,78,35,91,144,198,162,9,210,93,208,189,78,118,22,70,253,184,128,124,27,217,155,149,88,92,192,3,235,
30,172,175,164,224,228,119,181,154,12,195,108,224,0,63,27,8,133,209,232,170,232,80,139,5,135,6,248,157,52,12,146,141,118,142,12,218,97,113,126,113,25,78,151,3,229,66,17,117,234,46,9,173,78,25,80,231,119,
151,42,144,108,107,41,45,134,117,246,67,155,245,68,30,136,54,149,53,211,34,31,12,83,6,173,201,134,212,174,117,178,103,154,157,36,197,115,212,120,13,14,2,124,156,173,60,232,167,30,103,103,247,8,59,242,
251,203,144,142,205,192,172,79,113,198,249,98,213,214,131,139,171,155,136,15,196,121,237,10,220,129,16,214,10,46,108,156,77,33,179,218,98,36,105,83,163,155,4,161,135,242,135,60,172,24,110,197,106,198,
188,190,78,116,116,95,60,238,244,35,174,214,186,3,189,116,101,214,107,89,199,119,223,124,243,209,55,190,243,61,255,126,205,247,175,149,119,125,228,163,189,247,126,230,11,205,223,254,245,95,79,89,170,126,
214,82,29,231,9,194,94,71,115,196,123,90,215,103,117,91,138,202,80,172,54,234,20,175,116,94,236,57,142,236,6,60,50,12,147,72,34,50,53,131,48,123,106,136,238,210,203,144,82,99,248,41,209,61,178,70,237,
124,190,22,193,104,107,27,134,176,254,254,1,28,156,158,226,231,187,24,29,139,82,43,182,81,109,245,16,11,57,209,147,84,174,245,2,53,29,245,19,25,73,247,208,144,247,154,104,251,28,112,235,236,0,233,77,116,
82,27,232,85,201,44,169,53,168,212,163,42,29,174,172,209,21,6,177,151,118,82,151,246,102,118,163,21,140,162,192,198,47,21,232,182,91,101,2,40,141,90,62,135,249,85,11,169,84,19,45,30,203,197,239,226,161,
140,80,217,40,10,207,213,113,6,201,86,97,52,59,46,148,226,7,236,77,136,250,149,42,106,141,54,30,152,207,50,196,117,17,224,137,66,1,55,6,39,98,24,155,140,218,27,94,230,115,21,94,75,129,192,91,130,108,142,
121,243,115,158,129,73,118,194,37,178,96,154,97,217,222,196,146,29,81,66,177,0,78,22,104,73,114,171,244,68,9,197,23,77,145,124,139,14,129,103,180,69,67,91,146,233,70,16,178,83,242,245,6,195,108,142,70,
111,83,145,244,46,217,173,161,141,109,78,2,95,230,221,125,126,123,163,166,46,67,176,74,54,148,89,160,50,217,119,149,78,189,70,32,134,105,154,146,73,74,39,2,116,97,163,140,98,199,139,232,196,1,116,212,
62,172,47,178,115,86,101,39,136,50,156,193,32,52,167,162,232,110,75,119,133,148,168,166,86,103,53,179,178,215,235,116,71,251,103,134,31,137,95,219,119,246,13,191,255,98,243,255,252,197,223,110,1,231,159,
149,255,16,248,46,150,247,126,226,211,221,87,188,226,149,85,154,130,37,75,209,30,53,123,214,163,166,238,138,144,180,163,93,179,225,214,202,89,69,95,91,132,158,75,67,103,184,85,89,169,174,225,113,248,118,
239,133,135,140,224,99,37,56,114,89,184,36,83,154,128,171,177,162,43,172,16,131,0,100,60,68,44,26,193,147,183,205,96,199,244,44,149,115,9,67,99,17,123,246,64,26,34,25,97,207,173,213,104,40,10,4,57,5,113,
181,13,117,126,13,217,205,13,84,71,119,161,49,48,139,124,180,143,13,68,77,85,204,64,47,21,160,241,152,182,81,177,155,141,255,178,114,49,48,10,236,191,210,30,162,40,204,167,176,177,88,163,238,52,80,206,
84,208,162,142,139,249,70,233,10,217,97,148,12,198,93,243,112,27,105,186,233,6,178,153,58,28,81,50,42,245,90,29,1,56,134,182,35,49,58,137,241,144,203,118,218,143,44,21,208,171,23,16,177,242,182,243,212,
24,254,61,46,86,183,195,139,149,2,175,155,224,129,207,3,111,187,99,239,102,58,53,50,140,52,117,241,198,234,6,93,187,130,44,205,138,189,65,57,175,81,161,169,145,43,150,197,89,246,253,134,89,247,98,76,182,
178,175,73,228,252,90,146,135,40,63,123,18,42,228,219,145,209,101,176,184,193,191,207,50,18,109,104,78,52,249,153,254,78,131,32,84,48,68,19,20,35,192,189,6,117,130,253,89,50,40,59,130,44,10,43,229,139,
200,178,131,204,45,108,48,202,212,176,125,215,12,235,192,139,72,223,8,206,167,8,232,51,75,200,174,240,251,211,224,248,188,61,184,130,116,238,206,46,175,198,240,168,104,70,188,137,94,36,186,47,50,108,213,
219,209,206,138,81,123,221,139,95,86,121,195,27,110,53,223,248,150,239,77,219,255,79,129,79,202,59,255,238,239,173,247,126,242,51,157,87,189,234,213,197,86,173,54,175,250,66,231,186,150,74,159,169,13,
118,117,37,98,185,84,85,151,233,38,106,44,93,86,244,143,77,218,155,242,168,100,25,135,207,203,11,15,195,205,202,209,104,80,54,233,204,100,29,173,228,216,201,134,218,207,25,31,194,118,50,150,155,154,199,
27,181,16,29,136,160,205,10,172,54,58,136,5,85,116,171,108,96,25,59,164,6,243,186,147,136,247,243,216,84,24,155,203,25,156,205,149,176,232,242,195,77,70,209,216,219,125,12,243,42,157,170,236,102,42,13,
35,49,77,241,81,73,239,60,8,36,134,161,122,217,139,221,33,152,21,11,141,146,197,48,88,135,233,142,34,234,142,96,215,104,18,87,236,204,227,9,59,22,177,175,111,13,145,218,105,204,29,35,107,185,134,17,232,
235,131,131,70,66,161,42,55,201,132,94,183,31,21,53,130,178,43,137,128,149,67,191,187,134,243,105,3,167,214,12,104,166,2,89,149,31,140,6,49,56,226,195,212,84,31,170,93,13,249,84,30,102,54,139,135,79,158,
70,60,17,195,47,191,232,133,232,241,18,207,158,58,101,135,99,153,210,147,17,4,25,150,177,141,18,77,146,108,47,39,192,147,97,26,113,194,2,56,123,140,206,254,126,91,38,77,254,142,120,132,201,231,53,2,49,
195,122,206,144,17,37,11,103,138,142,125,54,232,165,59,143,195,224,251,21,118,62,75,230,230,25,13,228,182,99,185,172,100,207,48,114,16,209,147,179,227,24,24,220,210,132,39,151,74,200,52,188,240,246,239,
71,165,226,68,113,113,21,238,22,219,83,244,189,223,67,26,236,41,148,222,14,135,175,215,103,173,230,246,90,71,211,123,144,175,187,209,108,110,252,225,239,191,188,254,39,239,251,32,175,112,171,252,167,193,
119,177,188,227,131,31,178,254,250,243,95,54,127,231,133,47,76,117,205,246,35,112,251,30,106,91,90,171,163,59,147,93,153,231,9,251,21,217,157,73,171,149,109,81,173,209,17,43,12,131,74,46,99,11,237,192,
196,12,150,233,132,151,8,38,157,58,241,230,203,14,98,47,67,247,16,65,233,47,101,161,13,208,180,208,77,122,253,10,226,49,134,84,171,141,22,43,200,164,107,179,232,206,60,125,179,24,60,120,21,6,166,166,105,
2,216,208,103,78,160,190,188,4,139,21,220,99,227,244,29,56,12,215,216,212,22,91,136,192,103,163,201,188,172,184,81,185,181,150,202,240,235,158,217,142,224,56,181,92,189,73,115,36,185,117,35,136,15,77,
34,64,221,21,116,156,66,44,214,68,114,98,31,182,13,155,152,113,159,198,131,247,173,97,109,211,68,187,75,173,202,14,32,236,214,236,116,81,119,69,225,159,220,131,161,254,48,188,173,52,206,174,84,112,108,
190,104,207,131,251,242,105,88,46,29,61,89,135,160,244,144,42,183,177,82,99,160,236,75,146,137,117,140,177,17,103,9,206,177,153,25,44,172,175,35,151,201,218,251,186,200,70,77,58,25,208,229,161,49,98,253,
9,203,9,48,196,173,75,145,48,44,78,216,206,196,150,206,37,96,180,31,91,0,149,206,38,225,184,204,80,188,234,36,251,202,194,38,202,160,201,118,21,83,33,63,6,130,33,36,120,60,141,157,223,228,113,58,12,197,
166,60,167,51,222,36,8,83,153,42,142,156,88,176,181,225,85,87,95,70,35,100,81,27,15,97,101,83,65,237,204,25,244,50,121,176,25,225,34,243,59,252,50,7,78,65,186,212,240,233,15,44,143,106,203,107,215,162,
144,63,216,43,23,213,55,188,240,215,242,127,248,59,47,173,255,201,7,62,108,253,151,129,239,98,121,247,63,126,188,247,190,207,125,165,245,242,23,189,104,163,107,41,15,155,150,58,79,22,140,154,46,103,194,
114,107,78,209,128,154,55,0,61,146,224,171,17,232,12,191,180,84,116,171,25,70,33,143,189,75,232,30,58,213,189,197,148,61,29,38,21,40,91,231,54,131,110,248,167,18,108,52,133,204,216,131,179,215,66,83,210,
224,201,80,141,170,133,128,22,64,52,222,111,3,201,193,254,30,167,241,72,80,83,182,143,29,135,118,238,180,189,92,211,189,115,55,28,35,83,232,158,63,77,5,207,158,46,97,184,90,66,59,147,166,46,162,228,140,
70,161,109,44,243,90,114,8,48,28,251,67,81,123,254,90,2,74,181,91,67,187,186,206,99,231,225,84,155,116,235,41,44,46,86,113,234,92,27,38,117,165,218,40,35,54,54,14,119,40,64,32,251,217,10,1,40,186,135,
0,247,162,236,158,68,133,172,55,170,203,226,161,46,238,103,72,174,208,73,150,42,109,44,173,101,49,59,61,136,3,187,250,177,125,207,78,156,217,200,163,75,103,156,63,115,22,199,168,255,14,95,113,8,87,62,
225,26,228,114,116,249,236,76,162,137,101,87,126,151,71,26,88,66,177,48,33,213,4,235,222,222,131,90,192,199,58,147,255,183,88,240,2,22,229,85,62,17,103,44,9,174,85,26,160,85,74,128,140,162,35,104,52,176,
83,183,48,221,23,135,139,157,144,6,210,94,153,168,208,172,184,120,60,201,188,201,208,169,47,241,186,228,24,19,83,99,91,99,176,150,3,197,116,21,94,182,157,183,78,205,78,162,176,42,121,106,0,10,175,70,8,
56,106,40,218,124,78,211,235,117,143,86,45,141,43,149,226,85,104,212,118,154,78,189,254,186,151,252,230,218,127,57,248,46,22,130,176,251,242,223,122,113,85,243,7,206,91,154,235,126,163,99,165,200,71,253,
29,175,59,96,89,45,93,51,26,138,67,166,212,214,22,160,173,83,23,86,74,136,180,106,216,61,57,101,47,125,244,46,45,144,221,186,84,21,22,74,252,194,171,110,5,193,190,32,24,60,145,45,181,225,215,12,84,214,
179,152,91,98,207,44,108,45,232,246,21,75,176,10,37,232,97,217,69,85,135,223,50,49,48,60,130,152,65,3,35,247,116,163,91,85,102,103,109,19,164,16,96,138,244,108,178,200,70,56,134,101,134,159,22,181,33,
50,107,208,219,13,56,70,167,224,220,115,8,170,203,5,147,175,111,158,219,196,194,92,21,197,84,6,181,108,10,213,92,135,166,102,27,66,131,179,148,20,69,244,91,231,224,33,203,229,74,38,101,1,213,143,37,141,
236,69,163,231,135,149,152,69,104,114,31,182,15,199,160,25,101,60,184,144,199,201,179,43,88,60,121,130,12,99,98,251,76,63,206,157,91,36,163,71,176,148,173,34,219,35,224,165,179,16,4,227,94,23,118,241,
154,99,67,163,246,244,164,108,152,153,207,200,66,115,131,46,153,238,91,178,142,136,52,97,66,217,30,68,0,39,191,11,16,109,18,148,95,47,34,145,69,66,115,151,166,75,222,51,121,252,2,219,224,188,203,135,52,
227,124,176,94,198,148,222,197,144,36,46,16,148,17,131,29,84,134,163,168,73,219,188,78,113,198,6,117,246,234,242,6,13,74,3,25,186,251,112,185,138,107,9,232,160,194,142,46,14,154,90,177,157,38,248,86,125,
208,210,108,223,74,147,32,38,253,88,61,77,107,214,3,90,57,191,221,202,231,158,98,57,29,169,31,26,248,164,188,251,163,255,136,247,124,236,147,157,215,253,207,255,149,109,84,234,143,116,58,214,17,179,71,
197,225,112,38,77,157,173,82,203,43,122,57,167,232,116,173,50,38,40,26,48,112,253,19,183,134,75,22,231,236,85,97,82,113,29,134,232,198,64,16,30,127,151,44,215,68,177,220,130,131,128,106,230,100,97,81,
203,222,123,143,129,152,224,171,65,167,43,85,104,46,72,19,80,55,151,161,183,234,240,238,220,3,15,29,179,52,148,177,186,140,138,203,141,54,67,172,89,46,81,175,52,237,237,54,220,4,175,94,109,64,221,177,
27,174,203,14,195,73,240,201,30,202,164,24,168,241,1,168,100,169,46,181,219,194,124,29,11,11,77,20,140,40,93,227,52,158,250,196,203,113,195,84,10,207,62,240,40,174,156,160,155,94,123,4,43,143,156,162,
110,34,163,244,15,193,77,197,161,122,253,212,151,49,132,200,86,18,162,179,142,1,212,203,57,180,114,75,168,147,49,234,85,3,253,3,35,152,95,206,162,88,169,225,41,79,191,6,123,15,206,96,112,124,20,75,236,
96,43,103,230,48,47,44,207,144,222,215,159,196,224,64,18,153,141,13,62,54,237,65,106,201,229,147,41,194,173,116,175,45,128,217,217,50,23,158,139,81,145,185,114,73,103,171,55,106,118,74,155,172,200,147,
65,103,89,243,220,102,56,79,59,220,4,33,155,132,52,58,220,40,96,111,44,136,201,254,62,198,115,217,135,144,157,137,159,151,59,116,59,121,190,6,101,64,107,61,13,127,171,141,93,59,102,177,127,100,8,225,76,
17,142,190,109,128,135,114,170,234,35,153,48,170,205,94,101,103,152,19,112,246,52,38,165,168,116,10,181,237,15,169,102,60,241,137,31,42,248,46,150,183,190,231,189,120,255,103,62,215,121,233,11,127,109,
163,211,233,30,233,90,218,70,167,167,4,187,46,71,176,23,244,57,53,167,174,218,224,219,190,135,66,198,64,239,244,81,232,201,33,94,56,133,151,73,23,203,134,105,198,2,136,12,80,166,16,116,57,178,67,167,86,
177,43,178,76,71,24,240,123,209,231,239,179,117,154,155,127,175,179,199,106,29,153,200,167,203,148,222,155,207,64,105,54,1,185,183,26,67,124,83,230,58,7,6,225,37,3,58,201,34,14,130,223,75,160,121,220,
236,173,190,16,218,43,52,19,100,183,138,85,69,181,83,128,226,244,33,68,189,26,97,109,169,4,138,89,230,57,244,0,182,93,126,29,162,126,55,172,245,59,16,140,181,24,118,119,97,199,184,3,253,218,60,86,206,
231,177,145,163,65,80,189,104,202,56,159,74,87,204,190,84,214,163,80,71,247,32,64,70,51,55,78,193,146,221,238,75,37,100,23,86,176,188,176,4,63,117,227,204,68,31,30,126,224,126,59,11,124,131,154,112,149,
186,182,42,192,169,86,48,24,13,225,198,107,174,180,147,17,214,87,86,81,35,16,106,213,178,29,78,101,127,67,49,37,98,135,5,122,34,43,228,167,220,20,71,166,243,36,3,92,72,80,62,99,103,80,139,236,224,39,236,
1,125,70,151,22,163,192,166,219,139,5,119,192,118,255,178,184,105,196,239,65,152,210,40,212,105,35,192,72,33,159,211,100,74,145,199,153,164,54,189,54,164,98,56,53,7,119,110,29,30,154,35,111,193,128,111,
179,12,15,235,91,103,27,137,156,82,217,38,194,192,61,158,211,112,249,173,230,158,3,143,116,103,119,188,251,71,2,190,139,229,125,159,248,116,239,182,63,254,227,154,226,243,159,234,244,212,135,249,93,154,
29,69,11,152,161,64,192,10,249,157,74,167,173,104,27,75,112,236,187,10,142,167,191,128,33,207,65,39,203,64,75,151,166,80,11,246,204,28,186,142,46,74,108,204,88,220,69,199,171,33,76,241,17,232,209,207,
116,125,246,174,160,178,163,148,61,253,196,74,18,93,194,31,91,217,42,245,138,61,212,35,155,249,248,205,22,162,12,243,174,245,85,59,81,86,98,144,84,142,30,12,194,201,198,215,214,22,209,124,232,126,108,
108,46,161,54,186,13,205,248,16,42,155,27,176,22,206,81,87,198,48,58,58,142,201,112,28,201,233,9,84,207,30,163,166,243,160,182,62,199,227,167,200,224,77,58,218,18,26,153,50,150,230,106,168,158,95,64,79,
244,108,56,68,199,30,130,234,247,193,233,118,34,152,63,15,229,252,3,112,52,43,136,211,96,169,100,156,26,245,156,143,215,66,156,208,148,248,177,156,46,97,105,53,133,124,185,12,217,165,65,244,150,189,136,
107,117,149,224,94,132,143,46,251,242,171,14,219,153,50,11,231,230,80,149,117,196,100,64,135,100,184,144,177,228,203,219,35,47,194,130,23,126,202,211,11,191,216,117,35,89,71,146,190,37,199,150,23,4,32,
50,60,179,76,215,62,79,205,170,50,114,236,232,54,112,96,164,31,131,1,58,122,30,208,227,245,217,122,250,218,160,3,151,121,85,56,91,85,158,143,245,76,162,144,37,161,146,152,32,217,79,146,73,174,241,53,57,
182,152,59,67,115,163,62,187,199,104,31,188,250,131,250,192,196,23,126,164,224,147,242,214,247,190,31,239,254,240,63,152,175,255,195,63,202,81,67,156,236,180,187,243,157,78,79,51,117,103,168,231,84,92,
112,57,116,205,23,84,52,106,54,9,87,26,123,191,189,43,126,163,133,90,174,137,122,69,114,253,84,132,201,106,230,102,11,157,180,6,159,197,158,73,135,234,22,39,45,245,106,15,196,178,98,249,165,101,137,167,
140,68,8,32,29,130,70,190,215,96,207,237,144,5,20,182,178,56,107,217,24,220,158,95,229,219,178,128,219,61,54,1,207,240,40,26,37,10,237,181,60,86,11,13,164,66,253,192,196,40,195,156,97,175,133,8,30,56,
100,207,119,106,185,13,52,200,196,229,149,60,42,133,50,170,169,77,52,242,60,110,151,161,40,50,14,175,199,64,210,177,198,78,82,180,89,72,174,221,65,81,30,157,187,7,195,75,15,179,177,170,182,166,146,85,
106,194,76,33,94,163,193,208,187,177,153,37,235,85,237,140,31,73,183,151,148,44,25,110,241,241,17,162,51,21,208,12,7,253,184,106,223,30,236,216,181,11,231,23,22,145,207,102,237,172,112,217,253,64,222,
23,0,74,38,140,12,187,200,189,83,100,128,218,158,138,179,203,86,242,170,108,242,180,5,190,173,207,217,166,228,2,8,107,4,225,42,163,65,138,172,173,144,197,38,180,14,70,67,62,68,216,73,103,213,30,246,154,
21,132,28,116,200,188,126,217,171,198,164,131,78,59,2,212,145,65,56,120,110,91,141,178,78,101,22,169,195,166,173,247,141,244,218,251,175,56,170,13,141,255,153,18,8,175,243,173,31,111,57,250,233,79,233,
205,92,102,172,83,72,223,164,53,75,79,113,105,157,195,30,179,25,247,84,203,186,171,111,18,10,93,158,121,226,97,54,76,15,205,196,40,74,12,9,85,147,0,100,175,82,41,128,131,108,140,32,27,208,193,240,41,21,
94,11,135,81,103,232,136,104,22,194,12,55,46,158,67,165,187,179,7,30,88,9,50,242,127,188,111,220,190,1,96,148,104,27,161,195,11,164,215,161,24,20,201,213,154,189,125,133,220,242,20,135,174,99,232,205,
34,251,173,59,177,76,151,183,65,231,27,56,184,27,1,203,192,204,248,36,146,227,51,112,228,82,246,248,86,235,129,7,144,33,27,109,148,150,81,106,242,53,154,151,112,120,107,237,112,55,180,204,254,116,26,29,
61,132,227,107,65,60,120,198,71,45,25,193,190,250,38,6,23,30,194,202,198,58,78,119,122,88,161,224,151,59,41,249,226,73,184,162,97,134,124,11,70,36,106,175,97,145,237,74,196,152,12,13,244,227,201,55,222,
128,39,221,120,61,53,99,25,203,15,63,10,101,101,25,85,74,134,207,62,124,20,137,225,33,68,7,135,112,142,108,43,235,168,101,12,79,238,194,238,35,99,9,59,110,177,157,152,147,11,115,218,194,132,118,232,101,
159,100,221,217,161,88,94,147,94,34,200,224,239,162,213,44,178,156,147,29,238,198,236,50,158,107,164,161,78,204,162,215,63,6,207,241,187,161,51,44,171,148,36,50,132,85,160,163,255,82,190,131,77,118,176,
103,38,93,216,238,218,154,194,148,197,85,213,80,191,85,191,252,250,140,186,125,207,27,212,112,228,195,3,187,47,107,253,200,153,239,159,151,119,125,244,163,189,91,95,255,250,74,79,85,79,27,173,206,201,
174,105,53,76,218,99,211,237,8,245,154,21,246,41,153,61,206,195,65,13,231,146,73,242,171,110,160,246,27,70,132,161,46,82,73,33,80,201,194,73,139,47,169,91,180,184,40,244,15,35,75,131,98,145,29,228,182,
165,46,186,68,107,96,212,110,188,14,217,163,205,70,110,82,92,119,232,28,173,88,2,174,221,251,209,11,197,209,166,134,106,85,75,48,107,117,244,52,23,44,246,98,217,226,214,75,129,47,161,54,32,119,33,90,92,
132,182,188,136,0,221,180,115,108,28,10,67,183,236,60,229,28,101,67,116,219,112,83,86,246,106,12,61,188,182,228,228,14,68,250,195,112,180,79,194,231,175,32,156,72,96,60,217,197,160,190,132,65,130,124,
23,37,194,16,141,195,144,236,88,208,105,162,159,29,170,159,157,69,108,107,158,12,100,132,66,208,24,222,100,5,223,6,1,218,224,231,101,155,145,23,253,230,11,177,123,223,94,244,13,14,32,60,48,96,47,218,207,
73,174,94,165,138,221,125,73,92,113,248,114,184,8,218,149,181,53,148,11,121,123,215,3,59,125,139,172,39,83,118,194,124,50,187,99,135,194,11,64,187,200,118,91,123,215,124,135,143,46,126,70,18,48,116,214,
93,156,215,176,203,99,193,59,193,142,103,214,224,168,229,237,156,78,217,142,142,31,22,51,129,78,215,132,91,233,97,196,171,35,196,215,45,2,175,229,244,163,58,187,143,127,188,255,51,90,178,255,239,244,96,
36,255,231,255,247,205,255,245,227,124,255,145,242,182,247,255,181,245,158,143,125,220,120,249,11,255,91,170,99,41,199,44,221,61,215,238,244,186,166,230,8,116,85,10,58,143,91,211,168,147,28,100,5,71,188,
207,206,255,115,202,157,194,13,186,100,2,79,147,148,119,86,174,208,191,164,162,123,25,118,28,58,57,79,12,76,162,31,173,112,12,85,52,209,102,229,170,50,128,92,46,34,68,109,226,150,100,76,170,243,70,62,
141,146,135,94,103,116,130,160,101,120,37,168,148,204,38,96,11,121,158,135,32,240,57,52,68,216,112,126,106,32,49,47,38,181,155,81,175,162,69,198,181,248,154,99,254,4,130,12,195,137,145,49,244,143,76,18,
176,113,52,233,188,87,211,12,159,12,199,105,58,244,92,133,194,159,140,157,160,97,17,131,228,157,221,9,207,212,148,189,65,249,144,195,194,120,131,178,129,141,255,176,55,136,42,195,173,236,208,111,208,45,
86,105,52,36,68,30,62,116,0,87,94,121,200,158,150,148,13,58,195,4,89,124,120,24,225,81,89,85,24,176,151,155,230,201,192,235,53,186,89,2,102,132,0,29,30,27,65,70,118,21,147,49,83,190,102,215,19,89,80,214,
136,16,47,23,128,247,157,112,43,175,217,133,64,18,135,44,107,166,101,52,34,154,47,96,156,145,98,122,122,146,14,62,0,125,225,24,143,197,250,100,39,181,115,16,249,144,28,8,185,197,196,164,207,129,48,235,
75,142,103,200,122,228,145,217,94,103,247,193,187,213,225,177,183,234,225,200,201,228,200,36,195,11,217,214,62,209,227,164,188,231,227,159,176,254,230,11,95,106,188,254,127,255,241,106,189,84,63,202,175,
93,162,43,118,181,221,158,104,207,235,113,105,189,182,162,150,50,212,105,30,232,35,211,208,8,68,165,221,128,34,206,214,162,209,96,133,58,217,243,124,12,19,94,63,153,47,218,7,227,232,35,40,110,46,163,152,
244,66,217,127,13,234,150,147,14,179,14,55,63,227,38,131,233,50,206,124,244,33,228,72,58,141,201,67,104,12,205,162,78,214,84,154,20,209,217,13,104,146,249,188,186,0,101,115,5,46,159,207,30,6,146,157,19,
100,199,121,1,94,49,26,179,19,94,181,213,69,232,117,130,150,33,185,183,227,0,20,178,112,51,159,197,169,205,58,238,95,239,225,84,198,137,51,27,26,230,54,116,58,232,16,226,4,152,73,144,167,154,6,140,161,
73,184,2,4,248,198,2,78,81,47,61,72,179,81,103,195,155,100,44,89,7,210,102,71,145,109,71,166,167,38,72,238,14,59,29,76,50,128,220,30,175,157,170,38,187,127,201,24,224,253,231,206,99,141,44,152,111,52,
237,189,100,118,244,37,240,68,130,85,166,215,230,206,156,69,181,84,180,51,134,36,67,92,146,22,228,86,178,226,116,133,241,108,189,199,159,2,24,41,146,116,33,123,40,202,136,67,168,80,192,48,13,207,129,177,
65,12,177,179,184,206,83,171,182,155,12,183,110,177,206,54,235,137,195,230,95,83,91,202,195,198,34,216,126,168,198,71,172,230,174,131,75,234,216,212,155,181,72,228,107,3,19,179,140,15,91,229,113,5,190,
139,229,173,239,123,127,247,213,183,188,166,172,58,61,243,166,217,59,215,161,193,101,48,211,187,186,35,108,41,93,135,222,170,42,178,239,177,146,223,132,74,86,83,7,6,89,73,4,96,135,149,101,87,32,43,148,
238,88,39,0,69,40,27,27,107,200,119,20,180,98,163,88,240,38,80,143,38,224,142,248,249,57,13,132,17,116,151,135,140,100,161,180,154,69,138,44,85,36,40,209,159,176,199,206,156,178,152,72,182,197,32,203,
89,114,191,12,178,128,82,100,168,79,175,194,39,44,216,215,79,135,11,180,83,171,232,196,221,176,38,251,41,212,123,104,83,239,52,200,102,167,55,243,56,91,115,34,223,245,35,95,211,144,171,107,200,43,62,228,
45,29,71,87,55,113,239,90,6,39,235,29,156,47,215,176,72,224,220,169,251,176,193,58,144,149,126,114,19,28,105,200,0,89,118,106,122,10,147,147,12,245,52,71,2,10,217,213,213,236,24,252,164,66,162,174,225,
19,159,248,52,206,206,47,216,219,112,8,192,28,4,175,155,78,126,80,118,52,40,150,177,145,205,97,207,238,157,240,211,117,203,253,239,42,12,231,162,247,4,196,182,222,99,199,221,2,161,128,143,186,144,157,
88,86,197,5,168,45,135,121,29,7,84,11,123,14,236,129,191,188,1,189,156,37,240,104,39,196,168,240,124,252,184,252,255,157,66,0,146,99,209,240,70,209,216,121,32,223,155,222,241,33,182,211,63,234,62,127,
254,47,254,234,45,23,62,244,56,5,159,148,119,124,224,131,120,247,63,126,172,249,154,91,95,183,78,61,126,220,104,153,243,84,127,166,169,235,190,46,172,136,82,205,168,90,57,189,213,203,168,205,236,144,209,
168,218,83,66,118,239,149,159,108,0,73,127,114,6,8,166,146,129,198,177,99,12,125,45,180,40,204,29,116,174,108,71,4,216,101,157,254,0,124,195,227,118,99,153,115,231,208,161,198,52,88,217,78,154,151,224,
0,63,75,32,203,13,91,32,83,72,246,144,13,245,103,175,3,31,95,210,233,46,13,26,143,146,191,7,231,213,123,225,218,185,31,154,36,42,132,252,144,44,130,142,82,35,232,90,40,84,36,27,71,58,135,6,131,161,236,
220,102,6,167,138,21,172,181,218,88,145,244,42,2,239,108,143,224,36,16,90,188,142,2,193,39,155,104,198,99,81,236,223,191,31,207,126,246,179,176,109,118,218,54,85,246,253,74,200,190,22,175,33,189,153,194,
55,190,126,39,238,188,251,94,80,169,216,227,115,109,94,167,132,105,83,213,169,205,76,108,166,50,240,144,201,110,58,116,16,219,232,142,27,116,207,103,78,157,70,157,108,105,111,205,70,0,57,232,86,183,128,
71,221,42,195,61,157,54,92,178,139,3,175,99,143,217,194,254,29,219,17,243,240,59,230,86,108,253,104,111,25,98,119,244,239,129,157,61,180,35,58,175,233,240,163,54,185,211,50,183,237,254,156,62,50,246,94,
71,44,54,63,48,50,201,248,242,157,242,184,5,223,197,242,246,15,124,160,247,242,223,122,113,189,219,233,174,48,86,156,237,41,250,114,219,210,172,142,238,8,90,78,135,87,177,58,170,12,98,170,12,125,194,114,
170,44,152,97,56,80,71,167,101,103,33,59,11,87,247,5,16,188,242,9,240,83,187,249,87,22,129,245,85,152,108,108,31,193,23,220,190,11,122,178,31,206,145,113,248,104,80,194,52,53,222,82,1,42,65,232,90,95,
134,211,235,129,67,110,187,21,142,243,88,155,246,186,86,89,87,108,47,187,100,253,203,188,103,37,65,25,112,120,22,177,195,207,130,59,185,3,174,16,141,78,176,143,161,52,198,70,237,33,155,218,192,90,170,
108,47,108,151,164,10,217,70,174,78,241,46,51,15,50,12,44,230,82,60,103,139,207,58,4,148,108,7,39,251,209,8,200,102,102,102,240,203,191,244,203,120,210,147,110,196,208,208,16,130,236,16,50,244,36,33,89,
176,178,186,178,142,111,124,243,46,58,94,217,31,145,231,162,182,51,101,86,129,215,230,100,168,30,223,187,11,195,219,166,17,96,39,116,208,28,5,24,194,215,9,198,74,147,172,200,78,40,155,53,149,243,57,251,
238,2,2,36,89,215,34,69,165,52,137,16,120,219,24,97,46,163,166,236,27,140,193,83,88,34,203,179,83,11,217,93,192,220,247,128,143,207,45,118,230,54,13,91,109,96,210,106,239,61,180,166,14,141,190,197,17,
138,126,107,96,108,170,125,225,83,223,46,143,123,240,73,121,247,135,63,130,191,254,236,231,204,87,189,234,53,133,158,234,88,232,88,234,57,58,226,124,27,186,215,84,181,16,165,133,83,165,30,148,165,127,
12,30,52,25,12,195,7,174,182,123,180,220,210,84,110,234,167,95,118,13,60,179,59,16,164,62,242,50,12,187,22,230,224,162,78,147,241,41,141,175,171,108,125,49,18,142,102,9,30,134,215,16,65,231,166,158,100,
107,210,21,39,161,244,211,136,180,170,246,186,95,217,143,90,134,88,100,237,111,51,57,132,212,120,2,145,29,179,8,143,93,67,70,184,176,91,170,198,227,178,247,119,186,26,82,107,75,216,72,165,209,177,100,
143,102,203,94,191,33,242,224,226,170,57,217,53,75,52,87,139,33,82,54,218,44,217,187,101,245,208,151,76,226,249,207,123,62,158,253,156,103,147,1,99,112,177,51,201,254,55,242,16,192,202,146,131,147,39,
207,97,105,109,195,6,114,33,151,71,154,224,179,67,38,255,27,26,29,166,73,153,69,155,206,52,60,216,143,185,117,130,140,128,74,111,166,237,61,171,7,198,199,225,34,235,203,124,109,94,110,204,72,112,202,102,
79,98,122,66,60,246,40,191,235,229,225,32,198,183,77,193,87,221,32,139,54,108,147,97,135,89,2,237,95,0,143,143,46,89,175,30,76,90,12,183,41,101,102,231,71,105,18,63,57,48,189,61,119,225,83,223,83,216,
58,63,57,101,207,83,158,218,245,143,140,150,125,163,19,143,168,177,129,15,154,254,248,155,106,206,240,223,22,225,59,91,114,249,141,198,208,160,101,210,225,41,83,219,160,72,126,79,189,204,158,124,97,193,
13,27,90,110,149,160,215,74,136,122,117,12,237,220,133,200,216,132,157,1,35,183,84,48,8,180,78,37,139,206,220,49,232,155,231,225,105,228,17,24,30,129,127,27,153,145,198,194,56,114,63,242,102,15,181,107,
111,68,155,46,213,34,184,164,21,100,207,24,151,87,182,5,233,218,70,224,98,163,200,127,50,140,97,152,178,157,173,100,226,200,252,104,27,5,25,254,16,221,72,230,148,123,146,248,104,24,100,74,77,64,88,171,
214,8,168,138,157,222,46,174,253,242,131,7,241,236,103,221,108,223,54,66,26,87,142,235,112,56,237,187,63,141,142,77,33,20,233,67,169,74,3,193,115,201,192,178,189,73,58,153,173,214,144,189,178,219,246,
141,20,11,229,6,3,134,31,109,198,195,178,211,133,206,248,24,6,46,223,7,255,208,0,170,252,140,79,211,17,167,230,149,237,142,251,146,9,52,168,239,74,11,139,8,20,11,216,73,67,50,190,125,6,190,102,6,142,182,
108,113,183,5,176,239,1,157,20,254,46,225,86,70,14,90,146,217,61,177,173,101,141,77,125,77,139,196,62,172,121,188,34,97,191,111,249,137,96,190,239,46,111,255,155,191,193,187,63,242,145,238,43,127,231,
229,53,75,211,215,44,221,113,146,62,119,193,176,84,25,154,137,246,60,78,81,90,170,34,67,48,145,36,224,241,219,147,239,106,255,48,172,197,211,176,238,249,42,148,10,223,19,230,26,158,96,5,144,35,78,61,10,
131,159,47,71,162,246,58,87,103,122,13,142,154,12,179,180,224,136,148,224,116,172,195,89,94,71,151,141,216,29,37,75,178,129,116,134,115,25,168,233,50,172,54,6,104,91,60,100,50,103,128,108,71,45,38,67,
56,100,34,89,157,182,120,246,24,142,18,184,103,230,215,145,202,136,137,144,29,86,25,178,169,221,100,231,45,15,89,79,88,44,79,103,44,55,220,105,210,169,74,137,81,235,253,242,47,255,60,174,189,238,58,2,
91,134,202,191,211,224,23,1,62,119,118,17,15,61,252,40,214,54,120,236,205,77,219,160,200,208,140,164,85,201,54,29,50,105,184,145,42,34,157,171,97,126,105,131,96,245,97,251,246,65,84,8,208,124,131,110,
154,215,72,101,202,239,90,195,76,60,138,27,158,120,61,154,100,190,86,42,133,107,120,141,135,118,238,64,220,209,129,187,145,101,7,150,4,85,57,175,92,128,112,22,235,205,126,206,135,116,52,190,97,232,94,
84,199,182,91,157,61,151,31,213,134,199,223,233,8,134,238,235,27,157,248,23,225,246,98,249,137,3,223,197,242,206,15,125,200,122,207,63,125,188,195,80,92,110,119,204,69,214,227,49,83,113,100,218,150,30,
50,123,237,40,172,150,163,215,110,208,39,80,179,109,219,79,145,204,10,186,251,43,246,58,14,89,72,46,131,185,168,22,109,77,168,202,54,183,12,49,114,75,87,139,122,207,71,198,148,61,89,180,237,110,184,103,
138,240,76,58,225,28,114,193,217,169,65,61,147,177,239,167,43,11,207,237,181,32,116,29,181,177,36,186,14,5,225,176,244,253,14,54,233,98,215,87,86,144,89,59,131,59,110,255,38,238,121,224,40,230,87,54,237,
117,18,194,106,162,251,228,70,56,146,18,37,75,67,171,181,42,242,116,163,114,135,78,25,12,151,48,124,205,181,87,227,166,103,60,3,201,62,106,71,106,216,239,102,27,25,248,205,208,176,124,245,43,95,195,253,
15,60,128,149,229,101,20,233,94,13,186,83,25,155,19,224,203,118,35,178,177,146,195,227,177,223,19,96,203,142,5,65,175,131,64,36,80,105,188,196,108,72,230,244,64,95,2,125,98,160,248,253,23,215,55,208,207,
142,247,164,209,81,140,13,68,225,169,203,124,181,12,82,243,252,246,255,242,207,69,224,201,243,45,224,153,61,21,245,216,136,213,220,119,197,186,50,62,243,65,71,52,250,217,254,241,233,31,184,108,82,138,
28,226,167,162,220,255,183,239,35,233,184,195,221,122,109,178,87,200,60,85,111,86,158,175,183,202,59,253,42,220,126,134,75,7,195,136,82,164,244,32,230,186,178,16,245,178,235,104,117,67,48,239,189,29,189,
82,222,30,157,151,53,15,68,131,125,147,62,101,108,28,214,80,21,206,196,162,157,157,171,105,30,186,218,13,148,191,206,42,219,36,19,81,187,185,148,46,223,247,32,247,164,253,112,81,144,171,237,13,212,233,
119,30,60,94,179,115,14,61,78,3,95,186,251,28,30,60,185,105,103,210,200,242,71,185,185,206,192,192,32,205,195,160,173,243,4,112,46,183,211,62,239,35,143,28,181,193,185,119,207,110,188,236,119,94,138,43,
175,186,18,163,35,163,182,19,21,64,201,123,210,96,181,106,29,95,252,226,87,241,137,79,126,18,199,79,158,32,107,230,190,11,116,93,27,168,91,139,209,249,21,195,33,251,92,178,29,7,29,9,34,161,160,189,217,
185,76,191,197,66,97,188,240,133,191,134,203,46,219,135,20,67,237,250,201,147,56,254,181,175,227,114,50,225,85,87,30,66,56,127,30,78,67,34,0,33,199,135,232,8,27,48,4,159,93,236,95,100,60,79,67,45,144,
68,117,255,213,69,107,255,85,31,114,38,250,222,172,184,157,139,253,195,227,226,163,126,96,249,137,101,190,127,94,222,247,169,207,88,175,126,205,107,90,138,47,152,233,41,218,241,142,234,56,223,236,170,
245,110,87,237,183,52,74,27,183,174,106,98,20,92,62,168,87,62,201,158,249,176,220,1,40,131,35,80,227,125,108,81,234,195,122,149,245,202,10,150,108,103,126,174,78,86,170,81,188,119,106,57,180,155,89,212,
9,224,118,111,140,134,35,4,139,110,84,226,101,199,239,70,123,122,16,110,186,80,25,226,72,165,42,88,220,168,209,113,54,233,114,51,56,113,62,67,32,26,4,6,195,22,245,85,50,217,135,17,186,71,7,53,158,204,
92,72,25,25,25,194,236,204,24,22,23,151,137,143,46,110,186,233,105,100,190,235,48,53,57,201,176,236,177,65,85,174,84,177,206,240,186,182,178,138,187,239,186,15,95,38,235,157,62,119,6,121,106,72,201,211,
187,88,46,2,79,6,158,221,94,175,189,26,109,203,192,72,242,132,147,151,44,107,163,171,118,102,244,85,4,247,111,190,232,55,49,56,50,130,104,255,0,162,188,142,126,126,143,233,201,25,196,202,43,112,85,211,
60,34,13,18,43,176,107,49,212,178,243,200,30,54,162,87,229,187,203,67,142,103,56,36,220,238,176,204,93,7,239,119,12,141,190,221,233,13,156,72,14,143,126,207,176,202,247,43,63,53,224,147,242,182,247,255,
53,222,249,193,15,246,94,117,203,171,91,116,177,243,142,88,223,189,116,95,95,49,160,53,187,186,179,175,27,141,248,45,151,75,211,2,113,126,154,53,103,212,161,237,186,140,110,56,178,85,153,108,52,187,119,
199,7,41,186,250,80,61,183,134,213,7,87,24,18,129,114,182,139,98,198,132,210,30,132,111,96,187,157,111,216,46,102,81,166,137,105,48,108,185,124,100,167,78,21,53,50,95,181,73,166,48,9,190,116,22,167,87,
203,104,182,123,60,180,106,135,193,104,52,134,4,129,33,91,239,202,48,77,44,22,33,19,198,236,105,172,185,185,5,59,164,222,240,132,39,224,134,27,158,96,111,148,46,69,134,93,54,82,155,88,94,93,193,55,239,
248,22,190,244,213,175,226,252,252,121,59,139,69,134,109,4,156,23,117,160,24,23,185,133,108,136,172,102,231,225,17,76,178,153,164,128,90,88,80,142,159,165,131,151,92,199,43,175,184,12,123,247,238,129,
215,235,231,195,199,247,35,136,79,78,192,213,79,22,167,46,86,25,41,178,77,11,159,233,4,113,71,219,133,37,4,144,12,5,224,239,176,227,49,132,8,15,118,84,23,195,237,168,101,92,118,109,86,155,156,253,7,71,
32,248,201,228,240,200,99,186,183,199,79,148,219,125,172,101,199,213,215,89,251,159,243,252,238,193,23,252,92,62,124,249,149,15,59,118,236,253,227,170,59,252,187,37,45,240,177,178,47,144,173,164,231,204,
206,220,195,100,187,26,144,163,6,76,175,110,13,157,236,191,26,218,238,131,176,200,24,90,172,31,193,157,151,163,127,226,32,92,214,56,74,115,46,100,10,125,40,143,237,134,33,55,114,238,31,2,216,104,93,134,
196,166,97,242,80,178,1,144,66,253,228,195,161,189,49,236,28,247,146,221,128,118,167,135,176,83,71,204,237,178,239,99,34,183,219,90,147,77,206,201,70,146,23,39,195,45,178,99,235,217,185,121,59,117,234,
70,130,238,185,207,126,54,1,154,176,193,36,172,150,203,231,145,229,117,202,221,160,142,30,61,142,52,13,129,236,101,45,89,208,178,169,164,128,79,138,104,200,40,93,171,76,197,201,88,159,36,20,72,100,140,
39,147,118,34,130,176,173,140,231,201,80,140,220,13,0,86,27,199,143,62,136,249,185,211,168,82,243,202,248,161,63,20,129,111,106,22,165,195,55,98,37,50,129,59,16,196,157,148,28,15,208,108,173,237,220,135,
230,216,172,173,241,196,116,244,100,19,73,111,20,205,153,93,53,107,98,234,203,14,127,224,19,138,83,23,100,62,166,242,83,9,190,239,46,179,135,15,247,246,63,251,121,69,223,204,238,175,98,100,250,127,52,
156,161,63,168,185,67,119,87,125,190,124,61,187,216,237,220,243,57,130,176,0,125,231,30,91,68,43,241,97,56,103,119,219,211,104,226,23,99,123,15,98,104,223,97,12,121,146,232,239,197,17,175,26,112,143,78,
161,189,186,12,75,166,222,28,116,173,110,113,183,166,144,166,61,250,239,161,132,83,186,6,193,33,139,112,24,86,85,7,118,17,164,147,52,25,99,131,131,136,144,129,236,149,102,237,206,214,102,222,43,27,88,
92,88,182,239,73,242,138,87,188,18,219,232,50,37,3,69,88,170,65,102,203,144,225,54,104,4,78,158,56,141,245,245,117,148,104,32,100,219,224,238,5,224,201,60,172,124,214,67,128,139,89,17,131,177,41,247,195,
147,13,42,249,157,100,75,57,185,75,128,48,160,204,128,196,163,97,134,249,105,132,35,17,59,79,48,159,75,97,121,105,14,169,141,21,59,123,70,118,191,63,126,114,17,159,61,190,132,47,21,234,40,24,29,68,19,
73,28,220,187,11,33,59,228,202,230,185,14,24,116,247,141,241,237,102,119,118,231,81,103,36,250,1,205,237,60,151,236,27,146,24,242,152,202,79,85,216,253,215,202,59,62,242,145,222,187,63,254,201,226,43,
126,247,247,79,182,186,120,168,45,169,91,138,18,235,170,189,128,213,106,232,86,177,160,40,185,52,52,217,215,164,82,6,242,91,247,147,211,7,6,236,4,83,25,148,141,64,135,155,162,93,165,49,105,159,57,106,
111,223,219,240,145,1,250,101,71,46,133,61,185,77,166,234,81,62,54,176,190,176,142,163,115,12,91,21,21,187,198,167,176,107,98,10,94,73,88,240,251,209,144,191,107,200,128,173,70,135,218,66,58,147,35,235,
104,120,245,171,95,137,235,174,191,150,108,232,176,89,79,180,128,24,146,147,39,79,227,209,163,199,112,222,206,211,219,180,151,81,202,64,181,12,44,219,122,129,31,181,1,200,223,91,60,174,220,248,90,198,
54,229,230,59,50,32,237,39,227,6,252,212,142,4,107,48,224,195,245,215,95,135,231,60,231,57,212,154,195,116,210,186,205,148,178,95,75,171,73,160,229,211,56,118,244,20,254,233,179,95,196,73,130,119,179,
105,216,9,173,215,210,125,239,72,70,145,56,247,40,156,12,201,29,205,141,90,223,132,213,58,116,77,90,159,152,254,144,39,26,253,120,188,111,72,38,155,31,115,249,169,103,190,127,94,118,63,251,57,134,111,
102,219,73,165,111,248,237,134,55,246,127,106,142,192,167,170,192,90,189,150,111,117,168,166,229,150,83,200,111,66,238,16,46,83,84,50,67,2,217,106,195,144,253,235,216,206,170,6,243,252,41,70,44,134,47,
190,109,40,45,56,20,170,74,130,64,110,118,157,78,215,113,234,100,26,231,230,242,12,167,146,219,70,38,148,140,98,58,104,73,205,18,80,201,61,234,236,164,85,178,149,44,204,145,187,32,77,17,156,215,92,125,
181,237,128,229,54,97,226,90,133,73,229,159,146,204,253,206,47,34,155,161,198,44,201,189,227,100,45,5,255,23,124,178,200,15,25,246,49,201,146,45,97,99,118,16,217,103,90,246,73,12,145,101,67,212,105,62,
239,214,220,237,204,244,12,158,77,224,61,225,134,27,112,224,192,97,76,76,109,39,91,187,120,237,146,21,164,144,49,87,241,153,207,124,10,27,4,161,202,191,77,210,41,239,222,179,11,83,83,227,246,118,39,114,
55,117,147,225,182,225,143,89,173,29,123,107,234,216,212,183,28,190,192,103,98,137,129,31,184,21,218,15,42,63,115,224,147,178,227,198,167,152,193,109,187,210,190,189,7,63,209,141,12,188,161,238,137,253,
101,213,19,186,171,98,181,115,181,165,19,61,51,179,8,164,151,237,20,121,71,60,14,215,213,55,194,253,228,155,237,53,37,72,45,67,49,88,207,4,70,215,31,132,33,247,249,160,43,180,24,186,171,100,188,133,165,
2,206,158,75,219,32,52,154,4,16,117,92,97,97,17,43,143,62,130,18,117,154,76,95,201,158,212,178,39,179,108,130,41,131,202,73,158,99,15,27,88,66,166,20,123,98,159,0,147,173,226,82,116,204,43,43,107,54,240,
210,153,180,109,82,28,78,55,252,52,21,18,74,101,135,83,25,123,179,1,200,139,146,221,245,66,68,37,109,21,193,166,145,217,24,190,187,109,219,252,200,240,230,181,215,92,135,61,187,247,218,107,127,253,100,
226,209,241,105,2,112,27,153,207,111,79,215,205,207,47,161,80,170,216,139,211,197,32,141,146,29,175,56,124,25,205,75,8,174,50,77,8,207,223,112,135,80,155,221,211,233,238,216,243,144,35,26,127,135,230,
246,157,181,47,252,223,89,126,38,193,39,101,234,138,43,173,237,79,122,106,199,61,62,181,170,14,140,124,200,240,69,255,172,238,8,252,125,205,19,60,89,139,37,171,70,44,210,51,155,37,200,106,58,69,230,98,
201,109,206,29,108,180,3,87,66,75,12,216,12,166,134,98,104,43,126,108,80,23,149,51,41,251,94,186,133,213,77,52,169,227,234,141,14,202,4,95,151,159,235,200,14,240,12,181,50,8,44,128,19,96,137,232,151,91,
246,75,62,221,51,158,254,116,188,240,55,127,205,14,127,82,100,115,204,245,181,13,186,223,243,184,239,129,7,201,162,115,200,16,120,114,35,29,89,121,22,142,69,49,50,54,134,161,225,17,4,233,104,237,245,187,
4,154,164,135,13,240,124,3,252,189,63,17,103,184,245,18,142,38,54,54,54,176,153,202,209,217,238,197,13,55,222,96,223,186,246,98,17,166,13,4,195,60,222,20,193,152,192,122,74,238,125,98,217,169,86,225,80,
16,59,182,203,62,45,49,134,108,19,78,118,30,121,175,62,52,209,51,183,239,94,117,68,162,31,81,157,250,3,137,190,228,191,57,172,242,253,202,207,44,248,46,150,93,79,191,169,231,29,29,207,187,198,167,239,
236,70,7,222,218,112,4,223,84,115,133,62,83,137,244,47,214,34,177,86,43,183,134,238,249,135,161,144,5,157,12,81,250,224,168,173,167,36,36,203,186,98,71,93,67,187,74,48,57,132,10,27,240,59,13,36,163,4,
166,71,69,171,167,34,202,134,14,75,134,181,132,74,134,173,54,141,140,204,44,244,58,109,244,8,190,32,223,223,189,125,7,198,70,199,160,93,88,0,46,154,238,155,223,184,3,31,251,199,79,224,246,219,239,192,
242,202,10,228,46,235,246,236,8,79,44,119,105,143,39,251,48,48,52,204,199,144,125,15,59,201,106,78,82,79,78,240,120,3,252,189,111,120,136,122,207,107,159,47,157,202,146,1,93,184,234,170,67,116,195,17,
158,67,226,249,119,138,61,68,227,112,177,131,128,122,212,130,195,229,177,207,49,57,49,134,17,30,71,174,169,71,198,211,105,100,234,129,184,101,236,185,172,172,143,76,124,81,247,248,62,211,223,63,244,31,
190,101,234,207,60,248,164,108,191,238,122,107,223,179,158,109,68,247,237,95,116,142,76,124,186,227,139,254,101,83,243,189,179,170,123,239,40,213,42,153,234,202,153,174,177,124,2,230,153,71,129,51,143,
64,205,51,28,83,27,202,218,146,68,207,129,184,193,208,87,106,194,231,113,96,108,216,143,209,62,15,250,124,14,76,51,52,30,36,32,118,178,150,199,104,123,221,108,64,25,136,54,24,106,69,243,41,221,30,124,
100,50,147,14,51,77,166,107,212,234,118,248,148,212,168,82,177,68,225,255,168,125,91,133,76,102,235,190,118,2,18,25,15,172,243,115,194,130,146,52,155,236,239,199,228,204,12,102,232,144,7,249,83,29,25,
129,103,124,12,145,100,156,70,73,97,184,46,216,59,91,237,218,189,131,64,29,252,158,1,233,139,69,156,114,185,92,197,153,179,115,168,53,27,118,42,151,12,1,201,221,63,5,236,102,167,11,39,217,95,182,216,173,
111,219,99,42,147,51,15,185,130,193,143,234,46,247,247,205,86,121,172,229,103,198,237,62,150,242,150,247,190,23,239,254,167,127,234,188,226,229,191,151,235,118,123,103,59,134,121,150,77,94,236,234,154,
207,52,155,225,94,37,235,80,242,41,69,182,158,21,81,175,118,154,208,8,40,85,245,163,85,52,209,40,48,180,150,186,48,242,22,148,134,27,3,170,23,83,61,19,9,134,62,49,15,25,186,228,28,65,84,166,193,16,211,
33,55,136,118,50,236,137,147,46,174,109,34,146,136,161,70,112,62,120,223,17,156,62,125,150,33,142,238,153,12,41,206,216,54,42,12,125,246,42,52,34,84,198,4,5,144,146,21,35,179,38,114,243,107,23,53,92,135,
204,231,137,134,16,137,248,168,243,114,88,90,94,199,56,25,236,153,207,122,6,77,195,52,98,177,184,157,25,35,131,206,6,165,64,135,178,66,194,252,241,99,39,113,223,253,15,218,51,38,146,93,83,38,248,121,74,
59,187,198,79,22,116,151,249,123,183,99,169,7,47,95,115,247,15,254,133,195,227,253,70,162,127,64,182,148,248,15,151,75,224,251,62,229,157,31,254,112,239,61,159,249,108,227,247,95,241,234,117,66,236,172,
105,41,233,54,163,81,167,215,141,179,198,60,10,41,133,158,20,186,104,182,122,9,14,178,137,218,36,56,74,68,88,133,128,106,234,8,155,12,185,205,58,220,124,200,92,64,145,90,105,185,7,123,203,218,42,27,93,
182,196,221,170,124,185,29,108,129,90,113,149,44,163,227,236,201,211,248,250,215,191,129,205,92,218,222,54,184,78,224,201,12,135,0,79,246,207,243,201,205,93,162,81,123,38,163,217,228,113,248,186,220,229,
73,110,250,34,73,10,188,48,186,91,47,162,4,95,58,83,180,239,87,252,212,167,61,25,87,92,121,5,198,168,19,237,92,64,246,4,1,121,42,181,78,119,187,134,147,39,207,224,158,251,30,192,218,198,154,61,180,35,
219,229,102,179,89,251,22,181,146,17,20,137,134,209,169,84,225,31,27,171,7,38,38,63,236,244,251,223,159,28,24,170,217,151,255,159,40,151,192,247,175,148,119,124,228,195,189,91,94,251,186,154,217,235,173,
48,116,157,233,118,122,75,109,69,143,119,28,142,176,229,113,58,21,135,106,111,21,43,195,15,174,118,29,94,62,247,147,73,2,157,22,124,205,42,92,173,186,189,16,93,66,105,137,141,184,72,0,166,9,84,217,17,
84,182,171,149,25,5,25,169,51,201,164,19,145,0,186,108,224,185,179,231,80,108,212,224,102,200,150,172,98,201,239,147,251,122,200,96,176,12,201,8,131,202,29,61,197,104,200,34,114,49,47,50,16,45,227,124,
194,166,62,143,142,88,68,238,23,226,162,118,11,34,18,142,224,202,43,14,97,215,174,93,246,172,137,56,96,49,58,149,114,129,0,75,225,161,35,143,226,206,187,239,199,42,77,137,220,112,48,77,119,157,73,167,
108,86,108,81,4,202,174,88,18,230,11,213,58,198,247,236,201,40,110,255,195,109,211,58,241,182,183,191,149,110,236,63,87,164,94,46,149,199,80,142,127,237,43,122,233,228,73,159,210,106,60,81,53,91,207,211,
219,181,167,185,58,181,164,183,81,86,92,178,243,170,220,154,181,206,48,214,150,85,103,4,148,105,217,105,243,180,8,246,70,59,171,158,16,190,42,247,226,77,103,16,36,147,73,22,95,69,119,160,68,87,41,235,
33,174,157,153,192,238,169,73,123,131,204,71,179,165,173,93,252,25,242,214,86,215,109,205,39,192,168,146,137,36,212,202,210,209,136,44,155,76,38,237,193,97,1,96,146,238,214,231,113,193,235,166,33,145,
41,22,134,248,112,116,144,166,97,10,7,15,238,197,248,248,56,1,233,177,63,91,46,21,81,169,228,177,176,184,136,47,126,241,27,56,123,126,209,206,1,20,134,149,169,187,134,157,52,33,249,123,170,189,39,140,
236,146,144,140,198,241,228,167,62,169,238,245,5,215,15,94,126,240,173,201,100,242,171,100,234,220,248,248,80,254,66,21,253,187,203,37,240,253,59,203,131,31,250,59,127,175,81,159,54,139,217,43,96,212,
127,222,97,84,175,240,182,171,62,79,173,164,184,228,70,130,20,238,100,72,80,82,193,36,173,145,223,236,172,144,170,63,138,149,196,8,86,249,126,111,254,44,204,66,14,101,134,224,44,133,85,206,235,67,98,219,
52,110,184,236,0,234,109,19,95,61,126,22,14,134,199,46,153,111,99,99,211,6,133,36,148,202,138,15,185,67,165,172,241,104,146,5,101,218,44,78,208,201,93,215,101,22,35,18,246,17,52,114,203,46,153,83,6,110,
188,241,105,120,222,243,158,67,55,156,176,181,155,148,74,181,140,205,205,85,178,89,25,15,62,120,20,119,124,235,126,228,139,116,177,60,135,220,107,216,104,53,109,87,45,131,220,194,204,18,162,101,223,27,
57,71,146,199,161,102,236,62,249,41,79,62,231,247,6,207,81,75,126,38,158,140,125,154,72,111,108,223,54,249,237,37,145,143,181,92,2,223,191,179,156,189,251,110,165,93,171,105,173,76,58,96,214,43,187,186,
165,252,11,212,102,229,102,151,217,152,240,25,21,205,67,97,174,151,203,116,191,101,27,132,91,233,165,42,140,142,133,150,195,135,86,124,24,29,175,31,149,181,21,20,23,232,46,107,85,84,233,88,29,79,185,81,
118,244,197,242,249,21,44,231,74,8,247,245,219,191,175,80,11,74,25,24,28,176,205,133,128,66,110,144,40,211,108,185,92,158,102,192,139,161,225,97,187,33,53,77,214,135,72,184,108,16,44,65,252,207,255,245,
71,184,234,234,171,236,121,98,113,15,162,9,51,153,77,156,62,117,12,171,100,212,135,30,62,137,37,254,20,157,39,186,83,110,7,38,159,147,16,47,107,64,100,11,53,147,157,65,198,34,229,248,178,54,69,134,96,
134,135,134,187,253,125,253,205,235,174,191,238,68,34,217,255,72,56,28,250,242,248,232,200,103,137,83,107,116,108,224,123,199,113,254,149,114,73,243,253,59,203,219,254,250,175,37,139,186,247,218,215,191,
206,80,188,222,116,175,107,157,180,156,174,149,118,79,53,59,138,62,218,243,122,156,138,223,163,200,226,105,157,186,78,146,48,101,253,136,164,237,107,205,26,244,82,206,222,122,194,63,62,133,208,182,237,
240,80,83,5,249,186,155,90,172,193,198,47,167,211,40,49,244,122,24,86,101,159,150,66,46,103,27,145,96,40,136,16,117,160,204,108,72,24,20,189,39,183,129,13,133,66,72,144,253,36,59,90,134,68,196,169,74,
198,204,190,125,123,241,171,191,250,11,112,51,20,219,227,122,60,63,47,9,178,35,215,38,141,197,253,15,62,130,69,58,97,185,99,121,153,157,69,58,193,214,126,46,10,52,199,214,194,38,201,134,182,147,82,249,
135,118,178,42,223,235,116,59,178,20,64,165,22,117,208,148,244,21,10,133,25,130,111,128,82,160,143,160,85,94,245,234,215,108,188,237,109,111,121,76,0,188,4,190,255,96,121,235,251,222,135,119,254,221,135,
186,191,247,210,223,174,168,78,215,156,162,59,31,108,119,213,21,163,171,134,58,138,150,232,249,125,14,138,47,123,56,69,39,136,108,240,17,92,26,13,137,38,11,155,114,41,184,100,75,218,131,135,237,173,104,
221,12,133,33,186,207,184,193,232,37,187,24,80,99,85,25,254,10,153,172,108,220,101,175,174,171,87,42,246,206,91,30,175,199,78,50,21,16,74,58,190,12,32,139,25,17,93,40,107,68,132,169,174,56,124,8,79,184,
225,122,123,188,78,138,160,65,64,36,198,100,125,125,3,247,63,116,204,14,183,146,1,147,163,179,181,247,238,99,145,45,71,182,116,228,86,70,180,132,107,25,150,145,231,114,155,48,73,211,146,80,220,110,27,
74,62,159,211,8,62,15,65,55,198,78,182,203,225,212,82,94,143,231,129,119,190,243,237,143,105,198,227,210,32,243,127,178,236,187,233,230,222,101,63,255,75,117,239,240,216,188,119,108,252,239,180,196,224,
109,45,79,244,111,74,106,112,189,28,136,247,234,35,35,232,12,36,161,249,220,112,202,205,173,93,26,200,141,240,90,77,120,54,207,66,203,46,193,125,96,23,34,207,120,22,98,163,83,136,209,185,14,163,11,54,
57,218,141,58,122,50,84,195,71,173,152,67,238,220,25,100,30,122,16,149,249,5,190,214,132,147,64,113,137,97,33,48,196,157,138,94,147,204,150,103,222,252,76,252,226,47,255,2,141,201,86,90,150,60,248,15,
217,171,67,160,101,112,250,244,156,61,168,108,144,129,101,145,147,56,90,1,149,108,27,39,64,147,129,104,97,58,25,194,145,128,43,25,216,110,2,94,18,19,236,205,220,101,96,156,239,203,60,115,173,94,83,50,
153,148,179,144,207,36,91,205,230,44,47,37,185,178,186,246,152,228,220,99,250,208,165,242,216,203,137,175,124,73,51,74,229,144,145,203,94,221,205,103,126,93,111,150,175,247,170,70,220,219,174,233,158,
76,10,14,134,81,82,148,68,63,24,137,65,164,103,246,161,232,144,91,183,186,225,37,144,180,76,30,217,163,71,113,164,171,224,60,25,73,54,130,148,251,237,22,4,0,100,182,0,221,106,219,233,129,53,50,6,23,29,
172,51,24,34,84,45,44,209,185,86,132,25,201,122,175,120,197,203,240,220,231,63,151,12,233,182,151,5,72,182,243,230,218,134,189,71,203,209,227,167,113,199,93,247,34,75,189,40,201,169,107,171,43,182,193,
144,48,43,115,196,182,177,225,181,201,186,18,97,61,73,132,144,231,50,68,35,227,126,2,62,1,166,36,71,8,248,67,225,32,157,119,4,65,26,164,169,169,233,230,254,253,7,190,52,49,49,254,166,190,190,196,67,19,
227,163,50,146,244,3,203,165,176,251,95,92,222,241,119,31,178,222,243,177,127,106,190,230,150,91,151,187,138,122,180,109,90,235,102,167,231,51,53,61,218,11,50,20,123,221,91,59,138,49,100,150,251,135,187,
243,165,118,39,189,153,53,235,165,82,183,107,52,148,158,215,165,120,135,135,149,4,153,168,63,189,137,49,163,110,175,44,179,111,25,70,240,4,37,20,242,97,18,36,22,245,158,236,99,221,38,24,100,245,155,196,
214,100,50,142,131,251,247,35,42,67,53,124,65,238,233,91,173,212,112,207,93,247,227,235,183,223,129,51,103,230,176,180,188,53,87,44,233,244,50,134,39,159,147,97,21,91,18,242,88,194,158,26,157,174,0,140,
180,106,79,183,109,205,43,107,4,168,195,94,97,39,89,209,178,236,83,222,147,25,146,74,173,33,224,118,68,34,97,61,18,14,159,14,135,195,103,222,242,230,191,178,119,163,250,65,229,18,248,126,72,229,237,31,
248,64,247,247,127,247,119,11,142,64,240,116,183,107,61,220,233,41,141,142,165,198,122,62,175,199,138,71,21,51,30,175,149,253,201,19,157,104,255,87,93,201,254,135,116,175,127,206,180,208,107,55,27,78,
162,208,233,140,71,212,190,137,9,196,104,42,194,86,27,17,2,80,110,82,234,178,67,159,138,186,108,106,78,214,115,19,128,178,7,140,44,141,20,166,26,26,30,194,142,237,179,118,122,151,176,152,204,120,164,201,
166,39,79,205,225,244,153,51,246,180,156,232,194,181,181,53,123,126,248,226,156,177,20,59,68,243,119,209,135,246,38,226,4,153,128,82,102,81,36,204,10,144,237,133,80,124,77,116,161,83,54,34,119,200,102,
228,14,123,56,38,24,244,161,127,160,127,35,30,79,124,61,30,143,159,121,243,155,255,239,191,170,253,46,129,239,135,88,222,241,193,15,90,239,250,232,63,24,175,253,195,63,162,107,240,156,38,248,150,205,174,
98,88,78,79,195,10,198,239,208,19,131,111,142,238,222,247,145,190,157,187,191,30,28,30,250,156,162,234,247,247,20,189,100,118,58,129,110,187,229,239,58,21,167,147,44,232,235,27,132,79,152,134,33,215,222,
115,154,240,48,186,20,253,178,129,17,193,39,51,32,114,203,42,209,120,50,144,44,0,171,209,128,140,77,140,216,247,206,248,196,63,125,14,15,29,57,74,51,33,6,194,101,167,118,137,201,16,198,178,141,196,5,240,
73,177,245,33,139,132,86,187,240,247,78,91,214,237,242,172,124,75,140,136,104,65,153,31,150,101,160,137,190,164,189,113,185,204,154,232,154,195,140,39,250,143,140,79,140,127,106,104,96,112,237,255,251,
139,63,219,58,198,15,40,151,192,247,35,40,111,123,255,251,123,183,220,242,218,154,195,31,152,183,92,238,71,20,143,239,91,122,108,224,14,231,192,200,57,197,31,44,111,59,124,184,254,174,15,124,160,253,218,
63,248,131,180,230,116,28,85,52,199,25,171,167,212,76,195,240,17,132,174,158,207,227,116,14,14,43,110,153,82,99,232,117,73,166,50,195,160,37,115,191,193,48,178,178,177,80,185,108,167,251,247,36,60,18,
92,1,234,180,98,169,138,51,115,115,56,191,48,79,224,152,212,104,46,59,140,202,130,37,1,159,0,236,226,80,138,176,217,119,151,239,6,161,176,163,176,173,132,91,97,56,9,181,162,1,101,13,8,181,157,157,5,45,
174,217,235,241,231,167,38,167,63,181,103,223,158,175,204,76,141,253,155,153,205,151,12,199,227,176,156,184,227,14,165,146,218,12,215,83,155,87,183,11,185,155,21,163,122,157,174,96,220,229,241,122,221,
140,223,214,242,50,26,75,75,56,167,56,112,44,20,195,220,234,58,42,185,44,116,58,82,185,153,225,158,145,1,60,227,233,79,99,104,246,224,204,252,34,22,54,210,48,104,28,28,4,141,56,0,9,185,98,80,36,156,10,
232,46,2,77,126,191,232,140,5,112,2,84,41,242,25,1,169,252,46,25,206,18,114,101,169,229,232,232,8,124,100,189,245,181,117,148,139,101,236,223,119,224,200,115,159,247,252,255,113,229,53,151,127,169,63,
30,219,58,232,191,82,46,49,223,227,176,188,227,111,255,22,175,121,213,171,12,221,229,94,33,24,142,91,170,182,74,35,96,152,70,203,105,106,240,43,209,152,238,140,197,21,97,31,179,92,129,63,151,70,172,90,
134,215,48,96,49,44,122,35,33,28,190,254,58,236,216,183,7,45,134,228,179,243,178,167,222,119,140,131,36,171,138,3,22,80,217,172,167,169,118,88,149,34,12,103,99,145,175,95,192,158,93,182,192,200,247,117,
205,78,221,23,119,44,59,155,202,236,72,54,155,179,252,94,127,126,251,142,157,159,189,226,138,67,159,218,62,51,249,175,110,147,113,177,92,26,231,123,156,150,157,215,92,99,93,254,236,103,183,18,59,118,46,
198,182,239,250,39,119,255,200,255,82,124,225,63,51,45,245,179,245,118,107,190,238,119,27,254,177,65,236,29,76,226,9,131,253,120,66,216,143,107,21,19,87,169,93,140,243,119,123,118,36,83,64,189,33,183,
144,173,219,105,240,194,106,146,88,32,3,205,94,155,189,60,182,137,184,184,59,169,76,195,73,210,130,204,116,136,126,188,8,78,121,216,224,35,250,236,231,12,197,178,240,73,22,51,229,115,5,73,112,53,252,193,
224,125,126,127,224,31,137,219,205,173,111,240,111,151,75,97,247,39,164,156,252,250,215,149,226,234,138,207,40,230,166,204,74,233,218,110,187,121,147,213,51,15,234,80,18,78,195,212,149,84,26,237,149,101,
52,169,253,188,79,125,42,98,79,184,30,243,103,230,241,173,187,31,196,217,116,22,158,112,8,129,248,86,178,234,198,218,42,90,141,166,205,94,237,110,207,190,125,234,197,144,107,239,1,45,89,214,116,213,50,
232,44,69,166,217,228,117,113,207,110,134,89,1,159,172,25,145,144,107,65,177,124,94,255,210,206,93,187,255,242,208,21,87,125,240,165,47,254,213,199,196,122,82,46,129,239,39,172,60,248,241,143,169,245,
108,38,104,214,107,187,218,149,226,19,123,70,243,105,12,95,123,156,170,26,116,54,13,69,219,76,193,161,48,140,14,244,33,85,200,227,200,195,199,113,188,102,160,211,215,143,224,228,132,13,190,236,242,18,
244,78,27,30,1,18,93,171,97,209,132,52,90,52,20,100,52,186,86,1,155,68,94,89,27,44,225,88,146,88,201,121,118,230,140,132,110,113,211,78,167,110,79,235,249,3,193,246,228,196,244,23,46,63,116,248,245,79,
123,234,19,206,239,216,190,237,49,77,173,73,185,4,190,159,208,114,242,91,119,232,233,99,199,98,173,66,230,114,162,228,153,61,179,253,52,93,85,70,221,22,116,55,67,173,220,60,167,177,112,222,190,85,233,
92,179,139,181,129,33,52,183,239,176,103,65,218,233,20,194,58,245,155,215,11,133,6,162,77,22,171,180,218,246,77,158,139,229,154,157,182,37,14,86,82,248,37,28,75,178,170,0,45,34,251,190,116,77,251,125,
123,234,77,81,173,177,177,241,213,131,7,47,251,211,159,127,193,243,222,23,79,132,205,68,162,239,95,157,213,248,238,114,9,124,63,193,229,222,79,126,76,105,108,108,184,44,195,24,50,27,213,171,173,78,251,
185,86,167,117,149,3,74,159,155,118,196,65,7,218,158,159,71,126,117,13,115,116,197,103,39,167,80,161,78,115,55,104,82,8,30,184,221,80,9,62,139,90,143,129,214,146,155,71,23,202,85,217,206,77,201,243,111,
133,225,100,168,165,78,240,73,246,76,40,16,228,107,178,102,69,149,132,5,254,153,43,187,103,207,238,143,94,117,245,149,239,124,202,147,110,20,173,215,78,36,18,143,57,175,239,18,248,126,74,202,157,31,252,
27,111,183,86,217,209,46,230,159,220,109,84,159,166,90,221,43,221,14,167,199,217,165,142,219,204,224,76,169,134,7,157,30,116,141,166,21,84,122,61,213,233,48,123,14,71,89,113,57,215,73,111,105,75,209,114,
61,203,106,181,140,118,196,232,118,103,11,165,234,116,203,48,220,149,106,93,169,84,106,54,235,201,160,50,1,105,5,131,129,188,219,237,60,29,14,71,78,29,56,176,255,175,159,249,204,155,206,4,252,254,24,47,
163,66,240,61,230,204,230,75,224,251,41,42,143,126,249,11,122,121,121,49,210,109,52,118,152,181,210,13,104,55,127,81,83,49,225,32,8,235,109,88,231,11,149,98,182,94,255,178,98,245,190,214,213,212,26,193,
215,86,93,206,138,165,168,21,122,142,74,183,103,181,205,174,233,230,63,137,122,211,216,73,48,206,54,26,173,167,87,106,181,33,167,211,237,119,185,93,117,211,236,85,8,190,143,15,15,15,220,62,62,54,86,28,
24,28,120,240,202,43,174,148,85,108,178,221,66,135,224,123,204,251,181,92,2,223,79,89,57,74,87,220,109,212,28,181,245,229,160,89,43,31,176,218,198,115,172,158,241,44,69,87,147,70,79,123,40,103,224,47,
76,183,247,17,67,83,234,138,174,59,20,25,184,83,148,22,13,70,139,63,59,197,66,222,204,100,243,74,183,215,115,91,138,18,34,19,30,164,254,219,161,104,142,157,4,223,130,213,195,218,224,224,192,189,215,93,
123,101,135,76,152,187,246,154,235,203,114,222,108,54,171,16,120,255,230,192,242,119,151,75,224,251,41,46,119,125,224,189,78,171,81,239,235,182,27,87,160,215,29,99,220,60,231,24,219,118,204,17,137,186,
45,77,53,59,70,187,212,168,215,90,38,233,46,159,203,116,154,141,134,245,146,151,191,210,6,208,123,223,241,22,157,0,140,180,90,45,79,189,209,212,107,173,142,199,233,116,228,251,146,125,230,229,151,31,136,
107,154,94,82,20,100,14,30,60,244,152,13,198,63,47,151,192,247,83,94,30,252,216,71,148,86,49,231,232,181,155,186,226,246,152,161,189,135,186,221,173,9,93,159,101,89,97,34,64,54,110,49,97,161,198,223,43,
138,162,52,46,187,236,80,143,224,83,248,187,61,9,33,59,30,52,12,19,215,95,127,181,207,225,112,140,240,51,213,158,165,172,29,60,120,249,127,24,120,82,46,129,239,103,180,60,252,240,67,2,46,25,190,147,205,
173,188,4,84,192,178,122,9,190,21,177,44,200,54,24,243,151,95,126,216,78,14,120,232,200,125,94,58,220,203,248,84,246,164,63,197,63,202,237,63,240,31,103,188,173,2,252,255,111,148,206,97,161,49,57,133,
0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* AiassAudioProcessorEditor::sidblaster02_png = (const char*) resource_AiassAudioProcessorEditor_sidblaster02_png;
const int AiassAudioProcessorEditor::sidblaster02_pngSize = 32883;

// JUCER_RESOURCE: kippschalter_off_c_png, 6930, "../images/Kippschalter_off_C.png"
static const unsigned char resource_AiassAudioProcessorEditor_kippschalter_off_c_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,70,0,0,0,105,8,6,0,0,0,135,212,85,103,0,0,0,1,115,82,71,66,
0,174,206,28,233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,14,193,0,0,14,193,1,184,145,107,237,0,0,26,167,73,68,65,84,120,94,237,220,123,176,213,213,117,7,240,195,75,16,80,
20,84,20,37,42,248,0,20,35,74,193,71,124,96,84,162,245,153,113,162,177,157,140,82,147,25,77,7,157,206,56,201,116,198,180,117,76,31,90,51,73,219,84,99,242,71,67,83,71,199,88,211,9,204,88,173,198,24,173,
209,128,138,143,120,131,138,79,124,162,40,224,3,80,232,250,108,207,186,110,14,231,194,229,222,219,114,39,211,239,204,118,255,126,251,185,214,119,175,181,246,222,191,123,176,241,255,104,143,1,205,188,79,
241,252,243,207,239,118,247,221,119,239,242,248,227,143,55,70,140,24,209,56,250,232,163,55,28,115,204,49,207,142,28,57,114,109,179,73,191,71,159,17,115,231,157,119,142,121,228,145,71,206,12,50,102,47,
89,178,100,234,118,219,109,55,225,131,15,62,104,12,24,48,160,17,132,172,127,251,237,183,239,61,233,164,147,222,157,52,105,210,95,207,156,57,243,137,169,83,167,126,220,236,218,47,209,39,196,124,235,91,
223,58,252,158,123,238,249,187,55,222,120,227,243,200,216,126,251,237,155,53,159,0,57,235,215,175,47,105,191,253,246,251,96,226,196,137,223,140,54,255,116,205,53,215,172,111,54,233,119,24,212,204,123,
140,107,175,189,246,172,219,110,187,237,103,111,190,249,230,228,65,131,6,53,6,15,30,92,136,24,56,112,96,169,151,231,123,88,81,99,221,186,117,67,150,47,95,62,235,195,15,63,92,51,119,238,220,7,23,44,88,
176,161,52,236,103,248,68,250,30,226,171,95,253,234,206,243,230,205,251,198,202,149,43,119,164,52,229,147,8,144,111,216,176,161,147,24,9,134,14,29,58,108,237,218,181,87,189,245,214,91,23,207,159,63,255,
127,37,206,245,22,189,34,38,130,236,153,171,86,173,154,206,82,40,207,85,62,254,248,227,146,194,50,74,250,232,163,143,74,66,16,104,39,5,57,219,117,116,116,92,182,120,241,226,61,74,69,63,67,143,137,185,
245,214,91,199,172,89,179,230,146,112,157,193,136,129,36,6,17,114,239,8,105,37,69,226,114,97,65,19,151,45,91,118,126,169,236,103,232,49,49,177,11,237,24,46,116,192,144,33,67,10,1,200,168,45,164,78,234,
33,221,41,45,76,144,14,23,252,218,253,247,223,63,190,52,232,71,232,49,49,211,167,79,63,117,245,234,213,195,211,117,106,34,90,203,106,183,74,98,192,115,144,54,254,230,155,111,222,177,20,244,35,244,152,
152,80,252,163,116,17,57,34,18,117,121,214,33,38,2,110,33,71,25,43,98,49,195,134,13,107,68,16,238,119,59,83,143,137,185,253,246,219,239,140,0,250,190,231,214,88,82,163,149,28,231,28,57,171,65,74,96,232,
41,167,156,114,97,105,220,143,208,99,98,142,63,254,248,198,152,49,99,58,227,135,152,1,72,240,156,46,35,87,166,29,139,73,151,2,101,209,118,64,28,12,119,42,5,253,8,61,38,230,228,147,79,126,59,238,65,143,
37,17,72,176,211,36,25,146,242,36,41,159,37,132,100,210,254,253,247,139,225,245,43,244,152,152,201,147,39,191,51,122,244,232,142,92,253,36,35,73,128,154,140,76,233,90,105,69,200,124,247,221,119,75,251,
254,132,30,19,3,195,135,15,159,31,202,173,165,48,100,94,163,157,181,36,41,226,142,250,223,171,224,11,97,45,79,143,26,53,106,61,229,18,105,53,80,19,86,19,195,202,36,241,6,198,141,27,119,124,156,130,199,
149,151,126,130,94,17,115,209,69,23,13,216,99,143,61,138,5,164,226,137,250,185,6,43,145,244,201,60,220,105,236,11,47,188,80,182,168,254,130,94,17,115,192,1,7,60,29,183,228,219,237,54,73,68,18,212,142,
24,36,164,27,37,49,16,99,52,126,251,219,223,150,231,254,130,94,17,179,219,110,187,173,155,49,99,198,138,84,176,70,146,208,250,140,176,218,157,148,35,230,137,39,158,40,245,253,5,189,34,6,22,45,90,244,3,
59,75,42,158,104,13,186,82,18,148,238,36,33,73,234,111,59,83,175,137,57,239,188,243,214,237,190,251,238,157,1,23,144,208,46,79,212,174,228,57,136,29,118,246,217,103,207,106,86,247,11,244,154,152,131,15,
62,120,105,184,194,66,110,81,163,149,140,124,71,72,90,73,18,19,164,110,23,87,133,3,74,131,126,130,94,19,19,55,227,149,177,51,189,213,124,237,116,161,118,200,114,132,32,82,158,91,246,75,47,189,84,242,254,
130,94,19,19,23,192,13,19,38,76,120,50,20,109,123,72,171,99,79,62,167,197,164,213,136,81,107,214,172,41,117,253,5,189,38,230,11,95,248,194,134,21,43,86,220,30,55,229,13,93,89,74,43,57,233,78,114,196,232,
183,114,229,202,102,139,254,129,94,19,3,23,92,112,193,179,161,232,43,20,236,42,37,60,35,36,93,73,130,112,199,163,239,190,251,238,62,145,167,47,208,39,130,156,120,226,137,75,119,221,117,215,215,82,201,
118,164,164,213,164,181,104,139,28,169,25,151,142,88,186,116,233,239,23,49,48,125,250,244,129,148,236,46,16,148,174,4,245,119,154,254,128,62,35,38,174,5,55,229,89,38,149,206,84,35,45,40,221,72,98,65,190,
201,188,242,202,43,165,174,63,160,207,136,153,50,101,202,115,35,71,142,236,50,0,67,237,86,73,10,43,241,142,152,251,238,187,175,212,247,7,244,25,49,161,220,61,161,220,51,148,108,71,78,107,89,18,147,46,
100,187,126,238,185,231,154,181,219,30,125,70,204,136,17,35,86,31,118,216,97,107,51,78,32,66,226,94,18,194,50,65,6,96,185,52,100,200,144,1,243,230,205,251,131,82,217,15,208,103,196,4,41,31,197,65,237,
222,230,107,65,59,203,1,228,36,33,153,6,13,26,52,48,44,230,184,102,147,109,142,62,35,102,218,180,105,31,109,191,253,246,15,251,184,221,106,29,137,154,40,117,105,49,114,86,245,236,179,207,110,220,97,27,
162,207,136,129,157,119,222,249,254,80,242,181,230,185,164,148,37,57,249,94,151,167,181,112,63,215,130,55,223,124,179,212,245,7,244,41,49,29,29,29,203,118,216,97,135,247,107,50,106,43,105,5,75,65,138,
132,204,216,242,187,110,252,127,140,62,37,230,138,43,174,88,55,126,252,248,37,173,132,32,42,201,2,117,105,45,233,78,92,112,255,253,247,63,251,145,71,30,25,217,108,182,77,209,167,196,204,156,57,243,131,
216,126,239,246,169,50,201,105,37,41,129,40,150,146,174,164,77,92,36,119,121,233,165,151,122,253,43,175,190,64,159,18,3,231,156,115,206,170,32,167,211,60,218,145,131,20,239,172,37,221,9,65,62,170,191,
245,86,231,167,157,109,138,62,39,38,92,226,95,227,4,252,113,42,223,74,76,237,82,105,45,233,78,158,151,44,89,210,172,221,182,232,115,98,158,121,230,153,15,38,76,152,80,20,77,50,18,53,65,128,164,36,68,238,
244,251,194,11,47,52,107,183,45,250,156,152,243,207,63,127,195,123,239,189,119,171,103,138,215,22,146,168,173,7,33,82,243,106,176,253,236,217,179,199,150,202,109,140,62,39,230,224,131,15,222,48,105,210,
164,231,41,155,164,36,65,173,36,37,49,25,103,134,15,31,190,199,152,49,99,102,45,94,188,120,112,179,201,54,195,198,182,222,71,184,250,234,171,47,248,65,32,14,109,219,81,26,146,4,121,222,157,228,163,71,
143,110,248,243,203,158,123,238,89,126,72,244,217,207,126,246,202,184,94,44,138,231,143,194,178,202,47,58,147,208,184,79,189,19,23,213,151,131,192,209,241,250,104,60,191,102,33,74,101,31,163,79,137,121,
226,137,39,14,95,177,98,197,231,127,247,187,223,189,244,221,239,126,247,159,99,151,217,9,25,144,196,0,87,242,46,223,105,167,157,10,49,227,198,141,43,255,238,96,234,212,169,119,5,49,135,196,150,239,119,
121,67,179,125,51,95,23,253,214,68,62,56,210,59,171,86,173,154,23,239,101,27,67,114,16,183,60,230,152,119,252,241,199,247,250,139,87,159,17,19,7,179,105,111,191,253,246,252,56,139,140,139,157,105,221,
245,215,95,63,56,118,152,144,255,211,191,64,182,18,67,153,56,41,23,98,36,36,41,147,43,207,228,151,161,185,181,235,91,247,151,114,204,192,199,225,138,215,70,90,24,115,253,236,144,67,14,249,228,111,51,61,
64,159,28,166,30,125,244,209,225,65,202,223,174,94,189,250,40,239,33,244,160,215,95,127,125,64,236,80,157,138,212,200,119,185,59,82,108,239,226,75,177,24,64,128,109,123,209,162,69,37,61,255,252,243,133,
0,110,151,36,229,24,8,170,198,199,210,140,112,195,51,134,14,29,186,110,206,156,57,15,222,112,195,13,159,172,198,86,98,99,137,123,128,251,238,187,111,64,8,253,143,113,1,252,122,10,28,66,53,158,126,250,
233,198,119,190,243,157,242,239,7,18,234,89,77,42,66,89,113,133,181,140,29,59,182,177,203,46,187,248,161,64,227,136,35,142,40,87,4,109,29,248,146,36,127,223,62,240,192,3,125,95,110,140,26,53,170,236,100,
198,48,94,90,14,176,178,144,225,163,29,119,220,241,191,226,198,127,209,228,201,147,151,53,171,186,141,94,17,19,177,228,208,176,146,105,175,189,246,218,223,71,76,24,141,4,66,58,139,132,197,52,126,242,147,
159,20,139,176,170,64,209,124,78,87,208,7,41,146,223,218,32,36,2,106,57,5,107,131,100,174,197,154,220,190,239,191,255,126,243,250,204,209,152,49,99,70,105,103,142,36,72,242,206,178,244,9,183,90,20,115,
156,23,132,62,83,38,238,38,122,76,76,196,148,209,161,196,169,17,83,126,24,2,15,243,155,221,229,203,151,151,63,181,238,183,223,126,69,201,75,47,189,180,172,114,90,8,69,51,65,42,177,235,174,187,22,98,246,
218,107,175,242,147,144,88,233,210,47,201,161,160,250,207,124,230,51,37,72,71,128,111,204,159,63,191,252,52,246,148,83,78,41,228,33,6,169,73,142,62,22,194,47,75,195,5,175,141,113,191,113,232,161,135,110,
250,123,149,46,208,227,24,115,201,37,151,204,141,201,254,42,98,203,14,177,58,157,241,36,182,219,178,90,148,226,78,97,77,69,224,132,54,53,57,128,84,49,134,11,32,134,101,112,33,228,196,206,83,136,120,227,
141,55,138,21,170,71,36,119,115,246,185,243,206,59,27,251,238,187,111,25,23,17,136,6,110,75,14,238,22,238,58,49,136,187,227,186,235,174,123,189,84,118,3,61,58,224,61,254,248,227,71,189,243,206,59,203,
35,237,24,2,12,236,232,232,40,194,237,191,255,254,101,21,145,66,32,87,3,121,77,66,13,138,0,37,50,254,0,34,242,135,210,18,2,252,21,225,213,87,95,109,60,246,216,99,141,135,31,126,184,60,115,165,47,127,249,
203,141,59,238,184,163,92,39,144,166,29,24,207,188,198,9,57,199,198,243,15,99,147,24,82,42,187,129,173,38,38,44,99,84,100,103,134,18,215,69,124,25,42,158,240,119,230,28,87,129,162,68,42,186,247,222,123,
127,210,41,208,106,37,158,173,50,100,123,137,117,81,16,33,222,181,67,152,103,99,251,27,183,191,38,176,70,174,43,96,159,123,238,185,141,95,253,234,87,197,234,88,25,50,244,67,146,24,198,234,162,236,176,
24,251,47,163,93,183,194,199,86,17,243,155,223,252,198,22,115,125,172,206,220,112,161,33,204,59,252,182,88,136,68,129,84,158,34,132,38,108,150,37,17,53,212,37,41,20,71,140,178,76,217,38,115,115,32,142,
171,113,185,88,156,18,147,78,59,237,180,198,47,127,249,203,114,130,86,158,242,176,36,253,162,221,160,24,255,130,136,125,251,148,193,182,128,173,34,38,124,246,75,193,254,31,46,91,182,108,152,201,227,148,
90,86,167,94,89,121,42,130,20,193,47,223,91,145,241,38,137,145,90,201,107,237,155,237,41,110,110,137,242,206,56,51,103,206,44,191,229,179,253,35,78,91,237,4,102,214,28,228,140,11,114,190,25,109,62,57,
48,109,6,221,34,198,9,54,226,202,31,133,208,215,69,0,220,1,41,182,84,166,106,149,107,75,145,215,202,216,105,212,67,18,81,183,5,245,53,49,117,187,108,83,67,128,205,32,155,115,35,103,159,125,246,41,1,23,
148,33,67,78,206,36,39,146,127,208,241,249,210,104,51,232,22,49,49,184,224,245,141,112,159,145,72,17,104,91,45,37,5,148,18,202,180,69,30,168,163,52,33,51,65,146,162,93,77,12,120,134,236,139,16,135,66,
219,113,158,155,178,30,1,2,178,248,99,94,174,158,178,73,92,48,136,25,18,207,151,70,16,223,165,116,236,2,91,36,38,44,101,76,8,51,47,6,157,26,196,20,127,38,92,146,146,2,167,128,144,229,2,40,139,81,231,61,
235,106,168,171,137,81,159,113,33,21,242,172,29,34,5,121,87,8,9,65,173,71,1,99,56,71,217,217,200,202,74,140,97,33,181,21,188,227,121,86,140,57,183,217,173,45,182,72,76,8,188,111,12,126,44,82,76,234,200,
142,249,20,92,94,167,68,62,107,239,228,170,109,34,73,212,38,199,72,171,66,208,145,71,30,89,20,247,156,164,74,22,68,185,241,40,45,134,165,235,36,140,35,0,139,49,19,39,78,108,144,59,231,16,111,44,86,144,
51,32,242,203,23,47,94,188,67,179,219,38,216,44,49,97,45,7,6,203,215,199,224,67,109,131,148,100,174,181,66,208,46,79,34,228,159,251,220,231,74,46,81,52,137,73,16,22,94,126,249,229,114,96,123,232,161,135,
202,65,81,191,36,71,98,45,8,17,104,229,14,134,200,98,73,230,204,249,45,156,147,119,156,95,74,32,102,45,230,102,137,218,211,33,210,176,112,197,31,199,9,190,237,79,245,187,36,38,238,35,187,199,68,183,134,
73,30,238,28,96,101,36,43,66,88,66,164,130,173,138,130,50,109,249,249,9,39,156,208,248,202,87,190,82,4,98,254,117,95,91,186,184,16,39,233,206,211,173,107,197,47,126,241,139,178,218,167,159,126,122,105,
71,121,125,119,222,121,231,114,129,68,10,121,140,147,227,229,152,72,112,133,176,152,218,154,55,235,144,230,185,73,206,201,97,129,231,70,188,217,132,135,182,196,196,9,209,135,160,63,143,142,7,241,81,38,
104,133,12,218,74,74,43,8,165,94,238,140,225,244,187,116,233,210,198,143,126,244,163,114,32,115,82,189,246,218,107,27,151,95,126,121,99,206,156,57,141,139,47,190,184,113,214,89,103,21,5,196,0,115,136,
15,92,33,206,77,133,172,83,79,61,181,200,192,141,108,255,2,111,237,66,53,33,96,254,148,49,9,52,174,122,214,169,206,123,184,212,136,176,162,171,130,244,77,254,21,239,38,196,132,251,12,10,147,61,43,58,126,
201,234,25,28,25,252,57,77,30,12,222,14,218,19,192,196,204,152,123,248,252,128,20,125,124,91,81,111,229,147,8,150,101,117,221,149,244,49,6,55,240,11,171,123,239,189,183,4,83,167,104,110,160,77,29,116,
147,20,168,159,17,137,108,57,249,185,145,121,181,49,167,156,213,196,226,237,21,229,115,154,221,58,177,9,49,33,252,132,72,211,130,148,177,58,231,74,25,184,89,95,242,174,96,114,201,86,74,145,239,125,239,
123,133,20,160,156,93,129,37,81,206,74,18,154,146,142,1,20,57,228,144,67,74,108,17,35,44,132,79,12,44,231,140,51,206,40,109,89,0,183,34,91,230,144,57,144,81,98,93,8,134,140,51,22,65,158,100,241,136,40,
155,35,158,150,134,77,108,68,204,83,79,61,53,56,132,157,27,131,125,221,128,20,67,12,211,205,1,183,4,2,81,136,98,183,221,118,155,187,85,33,128,178,98,13,97,89,135,177,37,227,18,146,98,7,29,116,80,113,89,
187,137,251,151,173,94,93,184,118,25,143,213,230,39,134,154,136,26,185,112,100,53,47,89,140,41,78,122,214,79,27,122,89,60,139,20,164,237,21,229,223,142,64,220,201,199,70,196,4,131,167,71,163,139,195,90,
70,25,152,224,4,51,0,5,182,36,76,66,63,43,100,135,209,71,140,184,240,194,11,253,88,218,191,113,42,68,19,136,160,44,136,105,79,158,60,185,241,197,47,126,177,196,29,214,33,88,35,210,14,228,152,79,158,214,
83,116,202,83,231,249,156,50,201,141,33,102,209,33,145,228,200,89,77,200,59,61,172,120,74,179,250,83,98,58,58,58,118,139,149,184,42,174,243,131,76,206,188,51,175,7,172,209,74,8,88,77,174,23,214,87,2,167,
111,39,72,177,253,90,117,255,44,217,57,132,21,16,150,245,248,116,105,1,28,7,40,193,114,88,24,130,172,58,101,185,26,107,51,190,4,237,230,135,186,92,95,99,88,8,80,151,228,90,24,250,53,137,241,41,224,111,
98,135,42,255,243,155,78,98,98,213,142,8,75,89,153,177,196,228,6,48,40,161,219,33,87,40,87,9,172,190,0,73,89,132,250,234,150,95,244,36,99,218,162,149,115,11,49,195,206,101,140,240,243,178,138,200,84,39,
14,145,71,25,11,76,55,74,212,243,182,3,18,50,72,39,25,181,46,234,141,159,22,30,68,157,16,101,19,213,117,206,18,133,71,70,148,62,34,25,213,152,64,6,110,29,172,206,91,133,83,174,175,136,175,14,81,222,145,
69,97,110,132,52,59,158,21,67,158,157,234,231,63,255,121,41,19,160,245,75,162,8,174,29,43,52,14,121,218,17,98,222,76,245,123,182,69,168,177,232,150,227,75,222,181,67,76,184,245,176,48,132,115,74,123,255,
89,184,112,225,105,97,170,95,75,86,107,24,176,158,44,209,78,184,132,118,121,42,229,78,49,126,81,90,0,68,178,47,125,172,71,236,146,196,14,103,25,137,133,62,251,236,179,229,43,221,130,5,11,10,113,44,204,
246,142,100,196,212,10,131,247,90,198,172,151,180,55,134,103,11,221,78,199,180,154,112,169,129,177,8,123,197,130,12,24,20,91,225,78,193,212,63,4,99,147,117,206,129,53,204,9,8,91,199,153,156,52,161,29,
152,148,32,185,58,126,208,172,46,45,142,178,62,131,218,169,212,131,182,198,118,218,85,143,196,101,203,150,149,47,114,15,62,248,96,137,65,199,29,119,92,185,63,121,70,120,162,150,163,206,83,30,174,199,114,
201,100,219,71,112,30,19,204,91,247,215,71,187,176,204,61,163,238,150,129,81,49,58,10,15,85,89,179,153,131,119,21,95,218,193,36,132,17,84,237,62,130,172,119,223,105,157,126,185,19,161,4,66,171,175,142,
197,56,26,56,237,18,214,89,134,117,217,137,180,211,230,196,19,79,44,187,23,119,34,87,187,85,175,145,10,35,220,124,22,65,63,207,93,65,123,50,69,31,255,159,137,25,3,67,176,181,33,112,249,199,66,4,75,240,
235,100,60,217,77,178,186,130,118,132,214,215,153,99,214,172,89,101,133,172,52,75,16,75,236,44,135,31,126,120,57,225,38,49,200,16,91,212,57,12,106,231,212,139,152,51,207,60,179,49,126,252,248,66,54,197,
140,79,150,205,33,229,36,123,30,13,88,3,89,90,251,106,155,36,106,31,158,242,97,60,63,60,48,42,214,197,132,239,154,180,86,156,165,100,7,110,5,53,113,173,200,9,141,65,81,31,172,93,0,153,47,161,88,140,216,
193,141,92,14,185,4,242,140,45,167,176,63,181,176,22,164,32,200,182,237,91,174,119,227,164,18,137,90,94,207,153,0,233,100,247,158,247,189,36,166,30,3,232,101,238,102,185,255,108,24,24,4,140,136,52,190,
85,105,3,106,136,32,66,103,218,18,140,35,33,154,165,56,176,9,174,162,62,151,242,117,13,65,8,224,30,202,181,163,60,75,65,32,242,156,126,47,187,236,178,98,41,118,179,84,50,21,79,212,239,117,125,202,193,
61,88,2,55,204,197,134,212,69,27,110,140,56,174,30,239,111,196,66,126,56,40,174,251,67,226,229,204,48,55,159,47,59,99,138,142,105,186,57,137,65,181,105,101,188,181,204,187,73,28,202,88,134,191,36,24,87,
220,96,9,76,155,213,168,71,144,139,230,139,47,190,88,2,164,149,59,233,164,147,202,45,92,61,82,91,93,168,117,126,48,103,45,135,60,149,182,51,178,22,50,113,93,229,172,88,27,114,249,27,149,195,37,171,12,
2,111,141,251,218,141,101,148,216,158,126,96,187,38,176,248,64,8,137,153,103,112,244,85,12,251,181,128,4,129,214,178,44,39,0,165,141,155,95,213,126,250,211,159,150,115,140,62,73,184,103,66,185,31,29,123,
236,177,197,58,172,96,30,252,8,223,170,120,206,145,200,122,41,227,138,69,97,161,254,247,8,46,167,224,222,148,164,32,28,41,250,136,113,227,198,141,91,19,101,179,66,142,7,202,44,177,133,94,20,204,94,23,
228,12,38,100,238,247,58,216,89,152,185,142,25,221,65,158,66,182,35,198,123,42,206,85,184,137,103,110,33,71,178,121,8,151,11,192,138,144,226,84,44,78,33,36,93,40,199,206,121,18,117,93,194,120,218,113,
85,91,127,92,14,27,179,103,207,46,242,139,103,230,55,175,115,149,197,98,149,228,10,98,30,11,195,56,57,44,252,245,18,88,162,195,189,209,225,61,1,203,4,58,26,216,179,193,176,204,172,147,233,132,250,90,32,
80,159,125,17,70,57,38,204,157,108,225,132,230,243,98,139,58,227,35,72,31,113,197,202,138,7,105,185,57,95,142,219,250,12,41,131,156,140,250,73,121,12,160,180,57,204,157,186,169,167,147,5,160,31,25,131,
172,239,35,197,88,133,152,184,224,45,137,21,251,49,19,212,57,25,7,10,96,153,105,66,59,50,234,247,214,250,124,167,40,161,93,18,185,200,148,41,83,202,174,35,33,68,185,122,68,165,235,16,190,29,114,76,169,
6,165,205,67,118,132,24,139,165,90,16,229,244,210,71,142,20,86,227,136,64,239,48,138,39,99,190,127,111,14,245,233,93,41,112,93,4,168,21,76,90,103,147,72,76,217,4,233,82,132,7,109,8,46,175,87,207,115,166,
132,54,153,244,177,122,146,113,185,84,90,71,29,75,36,72,114,242,61,145,239,117,123,178,178,122,227,114,35,139,105,76,129,23,9,169,19,139,229,70,2,46,235,140,133,95,29,245,223,14,87,254,244,255,56,208,
204,153,221,146,96,242,191,5,172,28,128,114,57,144,114,19,59,19,40,111,39,104,166,118,168,201,210,134,194,117,170,251,215,169,29,148,215,253,0,185,148,71,132,88,229,253,215,191,254,117,249,124,97,17,44,
120,202,96,103,116,247,226,66,172,37,136,187,51,198,186,233,168,163,142,234,156,176,147,152,184,139,172,143,78,55,69,163,245,24,206,65,36,147,91,1,23,63,219,171,201,235,58,144,119,55,101,251,68,107,93,
142,157,200,186,86,50,192,51,119,167,184,69,20,87,210,133,196,13,22,193,117,212,177,118,27,1,249,185,46,82,162,205,59,81,247,247,17,219,62,29,52,80,187,146,206,183,132,101,60,156,86,99,160,20,18,235,172,
37,63,112,215,194,215,10,37,178,190,110,87,163,181,172,171,118,173,72,146,50,33,197,66,146,85,92,65,140,69,244,201,130,181,176,156,36,13,33,136,73,23,10,82,214,135,174,87,196,188,15,52,135,239,196,70,
196,76,157,58,213,149,119,110,116,120,29,57,4,53,96,146,196,47,1,57,110,195,38,170,145,194,214,207,117,89,162,181,206,60,173,101,93,165,180,24,137,146,228,228,66,8,73,107,113,51,247,3,70,241,134,220,82,
6,92,27,9,55,146,135,43,61,21,196,221,212,238,71,212,27,17,3,49,225,195,193,240,115,6,173,173,198,179,50,214,66,40,172,59,165,138,59,205,126,157,68,165,224,93,165,108,147,185,126,173,117,233,54,73,68,
237,66,230,116,254,224,14,20,118,178,69,138,64,238,147,41,23,241,213,16,88,11,29,4,98,86,111,23,66,102,180,89,31,229,23,69,147,182,255,14,104,19,98,194,215,214,196,100,215,4,163,107,176,10,53,57,38,117,
180,103,162,98,142,64,71,40,245,91,90,249,26,217,182,21,173,237,229,72,65,158,156,213,114,21,135,50,50,56,192,81,154,165,184,139,137,129,17,68,75,223,12,184,198,32,103,6,92,110,20,117,11,162,239,131,93,
253,228,126,19,98,32,152,191,35,8,120,136,239,90,17,72,197,89,141,63,127,222,117,215,93,101,165,8,72,0,150,36,6,33,175,86,12,242,93,74,43,72,11,144,82,248,186,174,78,64,113,74,91,24,159,33,40,234,103,
110,185,221,179,20,151,83,63,90,76,185,201,194,205,180,245,206,90,44,118,16,243,98,212,125,123,214,172,89,109,73,129,46,163,93,220,112,207,8,115,253,89,88,195,128,252,36,73,200,52,123,254,234,11,29,95,
118,72,67,152,50,66,56,77,90,149,36,179,38,0,50,135,36,36,219,37,60,231,241,128,242,206,81,92,199,51,66,148,91,16,132,249,131,156,185,125,229,243,115,87,86,193,93,88,58,247,177,128,238,106,238,99,177,
168,107,163,124,118,120,198,61,205,169,218,162,75,98,22,46,92,232,23,223,11,131,148,195,184,138,9,144,82,19,148,228,8,198,199,28,115,76,17,222,10,49,117,49,192,74,18,176,105,186,101,220,36,169,29,140,
169,143,254,8,64,54,101,108,187,8,224,54,230,68,162,58,193,215,252,44,195,223,165,200,161,189,133,81,198,74,220,218,17,197,237,17,27,233,230,152,231,207,130,152,205,254,31,54,54,187,63,46,94,188,248,188,
32,228,95,66,201,161,252,152,208,169,88,174,168,195,210,3,15,60,80,148,177,61,186,0,18,132,50,132,115,56,68,172,92,127,164,90,201,36,71,174,76,29,101,185,138,88,32,55,190,190,200,176,234,218,106,131,24,
110,19,242,21,183,50,39,242,17,163,175,69,48,183,190,44,75,27,132,133,43,173,141,133,154,113,224,129,7,46,46,147,111,6,91,34,102,167,96,253,63,66,249,99,77,98,213,40,33,65,90,143,243,3,33,157,29,220,131,
92,4,173,14,127,102,49,114,194,38,33,53,41,9,202,34,130,165,32,145,75,34,157,98,234,140,67,89,59,161,63,230,105,227,190,197,58,140,43,238,113,35,207,218,145,141,133,41,19,91,66,158,13,177,88,87,134,62,
87,77,154,52,169,253,95,16,43,108,150,24,232,232,232,56,39,132,184,49,132,28,130,156,84,12,33,153,131,56,148,171,200,141,92,12,253,131,8,214,195,189,50,24,18,92,130,236,207,90,28,212,88,29,242,189,107,
171,31,66,17,134,16,223,86,184,52,101,197,12,245,218,217,0,88,68,146,34,71,138,190,172,5,121,225,230,47,198,148,71,199,237,249,229,50,249,22,176,69,98,98,11,220,33,38,242,171,170,243,89,134,21,77,50,146,
28,201,170,82,202,42,83,64,210,62,253,155,34,158,9,173,189,21,149,40,13,250,75,160,28,81,172,198,78,100,28,253,50,134,136,101,218,114,55,99,115,91,80,166,29,43,179,56,72,241,201,33,220,235,131,112,193,
203,99,107,254,126,105,216,13,108,145,24,8,211,61,44,4,93,24,74,15,176,170,73,70,109,53,132,146,75,4,179,98,86,153,82,121,246,80,103,21,41,36,183,226,250,25,131,37,72,136,71,150,149,23,79,36,219,47,229,
197,17,46,149,113,72,98,137,144,164,202,29,29,184,114,6,220,32,242,202,24,247,202,176,150,110,255,45,168,91,196,60,249,228,147,254,55,251,243,99,23,152,101,21,41,64,25,160,44,36,89,249,172,28,33,130,38,
43,98,1,105,33,53,1,208,78,57,43,175,28,17,18,82,88,92,126,63,81,103,30,109,179,159,50,243,153,155,181,32,46,44,230,238,32,249,143,99,215,122,181,52,234,38,186,69,12,68,96,61,50,92,229,182,136,51,99,197,
154,86,66,146,140,20,210,59,40,19,51,236,106,250,177,28,36,229,14,133,156,236,15,250,103,108,65,0,50,144,34,78,164,133,213,100,232,199,186,188,35,219,14,38,6,185,178,132,165,172,143,190,39,7,41,119,149,
198,91,129,110,19,3,65,206,213,17,136,47,139,201,135,228,110,1,169,88,42,215,85,174,125,146,33,79,11,242,172,77,6,78,43,143,4,207,217,79,125,206,7,158,235,114,137,251,114,57,214,18,46,180,38,220,240,79,
194,125,254,173,217,101,171,208,246,74,208,21,66,129,43,99,5,23,153,220,138,82,140,82,169,88,62,183,150,201,37,237,229,169,120,198,142,230,174,81,172,131,149,136,43,72,170,199,204,231,26,202,146,20,11,
101,92,1,58,198,219,16,99,253,103,16,59,191,217,116,171,177,85,22,3,177,125,79,141,24,113,83,248,242,20,110,193,37,196,140,92,249,20,158,208,53,8,223,27,228,120,57,142,60,93,8,201,100,17,108,227,60,179,
42,118,174,5,225,86,127,26,231,169,30,255,31,52,122,36,109,184,212,132,32,227,134,152,124,114,184,213,56,91,163,184,1,93,17,147,216,90,130,218,17,44,41,79,215,99,105,205,152,178,58,172,102,206,180,105,
211,110,105,54,239,49,122,188,140,113,113,27,20,187,133,127,28,117,99,4,213,189,99,199,26,146,86,3,245,10,43,219,28,33,218,118,135,176,36,35,201,65,10,183,139,120,178,34,242,123,99,158,27,163,252,150,
56,17,183,95,149,173,64,143,137,73,196,65,110,207,240,239,67,67,160,185,33,216,17,77,114,134,69,202,127,87,188,214,115,119,20,239,14,130,24,31,152,86,35,40,172,195,255,73,237,142,24,251,47,162,234,153,
32,100,227,32,212,11,244,141,180,129,56,235,140,136,21,221,221,233,55,124,126,70,8,139,172,13,65,212,99,161,136,191,143,182,157,139,21,164,197,100,46,181,131,250,24,235,173,112,225,91,181,137,224,29,156,
175,127,57,78,180,61,254,23,249,237,209,104,252,15,105,87,197,81,29,255,36,132,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* AiassAudioProcessorEditor::kippschalter_off_c_png = (const char*) resource_AiassAudioProcessorEditor_kippschalter_off_c_png;
const int AiassAudioProcessorEditor::kippschalter_off_c_pngSize = 6930;

// JUCER_RESOURCE: kippschalter_on_c_png, 5809, "../images/Kippschalter_on_C.png"
static const unsigned char resource_AiassAudioProcessorEditor_kippschalter_on_c_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,70,0,0,0,105,8,6,0,0,0,135,212,85,103,0,0,0,1,115,82,71,66,
0,174,206,28,233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,14,192,0,0,14,192,1,106,214,137,9,0,0,22,70,73,68,65,84,120,94,237,155,9,176,151,213,121,198,63,46,171,200,190,41,
178,171,112,217,149,197,94,192,34,138,78,77,138,178,136,45,196,150,52,76,163,56,41,148,142,83,154,177,214,153,56,138,72,166,46,49,140,84,168,162,73,1,105,32,184,142,64,4,92,8,184,142,168,128,108,42,139,
226,5,17,81,118,20,232,243,59,252,159,235,225,187,255,187,17,218,154,204,247,204,188,115,206,119,214,247,125,206,251,158,115,190,239,127,111,146,33,67,134,12,25,50,100,200,144,33,67,134,12,25,50,100,200,
144,33,67,134,12,25,50,100,200,144,33,67,134,12,25,50,100,200,144,33,67,134,12,25,50,148,143,106,185,244,127,5,199,143,31,111,164,228,60,73,199,80,112,18,235,10,10,10,54,229,242,165,160,62,103,43,105,
39,137,251,108,82,159,117,185,124,134,63,9,104,165,11,115,30,242,127,6,205,87,148,203,126,55,32,133,250,230,178,223,57,252,191,232,166,73,107,72,10,36,213,115,69,223,57,88,55,165,53,67,193,105,162,32,
151,86,8,77,212,94,9,174,91,79,27,225,177,80,248,29,68,164,91,15,233,92,36,105,144,123,62,115,208,160,117,36,23,229,30,255,40,33,253,187,230,178,25,242,65,4,113,5,168,52,42,29,74,127,2,104,44,114,216,
14,42,133,51,122,193,219,180,105,211,104,77,222,64,146,43,73,206,169,86,173,218,223,157,56,113,34,247,248,45,226,50,181,41,121,38,111,28,59,118,236,113,201,78,234,106,215,174,61,72,117,92,9,102,212,168,
81,131,118,191,237,216,177,227,238,92,211,51,142,83,136,201,49,122,88,27,88,241,201,146,138,177,97,195,134,106,82,124,212,254,253,251,219,171,255,101,213,171,87,255,126,174,42,24,11,73,24,27,27,28,151,
171,125,40,35,175,121,67,74,125,90,220,223,237,36,95,125,243,205,55,15,169,232,75,145,151,52,104,208,96,81,97,97,225,234,208,232,12,224,15,242,152,141,27,55,142,148,82,147,247,237,219,87,184,107,215,174,
18,229,109,12,128,0,131,122,86,187,86,173,90,37,6,82,255,245,215,95,39,71,143,30,77,100,104,104,7,89,110,231,182,128,118,144,96,82,233,111,212,173,91,119,171,250,116,42,42,42,58,154,43,42,23,26,163,72,
253,95,203,61,150,66,53,53,104,172,6,95,228,158,43,141,245,235,215,143,56,114,228,200,79,15,31,62,92,244,229,151,95,6,165,81,22,66,76,134,9,194,128,179,206,58,43,164,16,64,251,175,190,250,42,180,87,136,
132,186,154,53,107,6,50,0,253,105,119,224,192,129,208,14,50,168,111,209,162,69,210,180,105,211,208,199,68,50,190,137,59,251,236,179,231,52,106,212,104,162,202,246,117,237,218,245,72,40,60,77,64,76,39,
41,188,49,247,92,33,180,143,180,144,66,131,212,111,237,39,159,124,50,89,125,135,139,156,80,103,34,44,49,33,123,247,238,13,134,106,101,147,198,141,27,39,245,234,213,43,233,3,17,164,49,232,131,231,216,99,
180,8,201,103,159,125,150,124,250,233,167,129,148,230,205,155,39,231,158,123,110,104,123,232,208,161,208,6,98,69,220,70,245,249,231,206,157,59,63,19,42,79,19,85,14,37,237,41,255,160,21,60,40,82,186,203,
75,110,161,204,134,217,72,148,172,83,167,78,88,101,8,193,155,154,52,105,194,138,134,122,60,32,38,194,43,14,210,121,11,128,40,188,133,49,32,104,219,182,109,236,45,73,251,246,237,195,152,144,199,188,34,
231,51,53,191,174,91,183,110,43,66,199,211,64,149,136,17,41,127,33,165,206,151,82,71,181,217,62,130,146,120,11,138,155,20,148,199,43,120,38,100,228,218,65,89,86,217,237,128,141,5,177,241,6,237,226,114,
60,8,240,76,30,210,241,38,188,232,253,247,223,79,218,180,105,19,66,13,239,97,126,121,228,30,233,114,77,151,46,93,86,133,142,149,128,244,239,166,177,215,146,175,52,49,10,161,54,90,149,241,82,100,142,66,
98,137,194,169,133,141,100,181,32,5,69,33,193,30,129,135,224,45,134,219,131,152,8,231,227,50,35,95,29,228,243,140,16,62,204,169,61,47,249,226,139,47,18,121,73,152,159,185,85,190,79,207,149,126,37,144,
13,245,69,204,62,242,149,190,224,137,136,31,169,227,124,173,200,165,242,146,22,40,7,25,40,129,160,160,61,197,202,226,37,180,161,204,82,30,220,22,56,165,12,196,99,196,243,66,60,123,87,167,78,157,146,238,
221,187,39,111,189,245,86,216,148,153,91,117,245,215,172,89,179,80,158,126,114,87,175,0,38,5,84,138,24,13,220,85,10,53,43,46,46,222,42,82,126,138,27,19,66,86,146,103,72,1,228,89,73,20,166,30,216,160,56,
239,103,192,24,38,5,113,190,162,52,206,19,66,132,246,229,151,95,30,188,71,87,136,80,39,12,87,58,49,76,84,5,84,72,140,38,169,165,129,127,32,34,126,169,21,90,174,124,91,43,195,138,1,188,131,211,7,47,242,
74,2,218,164,97,131,210,226,186,178,144,110,19,247,99,62,242,44,6,114,197,21,87,36,31,125,244,81,216,127,114,139,244,79,171,87,175,110,24,26,87,18,21,18,35,18,122,105,210,165,218,72,39,29,60,120,176,43,
30,97,111,64,240,20,226,25,80,110,37,203,66,188,87,120,12,231,157,158,142,176,88,204,141,14,58,24,146,129,3,7,38,59,118,236,72,184,120,106,193,90,107,222,185,90,228,198,97,146,74,160,92,98,116,179,237,
163,184,235,179,115,231,206,6,58,10,71,113,26,48,49,74,0,60,197,196,224,202,40,152,70,218,0,183,97,140,88,40,143,243,150,116,125,92,23,151,57,181,199,162,79,255,254,253,147,173,91,183,134,211,81,196,124,
95,109,230,232,16,169,212,231,215,114,137,209,4,183,75,214,72,254,86,161,212,208,19,91,9,78,33,110,162,190,249,82,14,98,175,72,131,126,136,225,103,247,117,30,241,92,78,13,242,233,49,156,186,63,27,48,228,
92,124,241,197,201,7,31,124,16,158,37,223,83,221,45,90,240,250,161,67,57,40,147,24,49,251,143,26,100,181,220,241,93,77,80,200,254,193,224,40,201,228,246,22,46,85,40,80,30,25,49,210,161,196,51,174,255,
249,231,159,39,187,119,239,14,251,130,46,143,97,143,248,240,195,15,75,110,186,204,235,249,77,12,105,156,247,152,46,103,177,208,187,101,203,150,201,199,31,127,28,238,63,58,193,122,74,231,238,161,113,57,
40,211,26,93,154,118,40,62,187,105,240,101,218,225,47,102,2,123,5,39,210,57,231,156,147,180,110,221,58,24,129,178,0,165,104,151,70,154,12,3,131,81,150,219,43,222,199,177,203,105,66,155,250,245,235,39,
13,27,54,12,115,110,217,178,37,120,37,115,178,199,33,244,99,92,82,64,222,226,50,174,13,8,99,105,243,77,206,59,239,188,240,58,34,172,214,124,131,117,196,151,249,142,152,151,24,109,82,67,101,236,5,34,102,
175,94,226,30,101,34,140,64,97,72,32,223,182,109,219,96,16,27,156,149,4,78,1,121,250,88,97,192,51,134,145,114,146,209,127,241,226,197,201,43,175,188,18,86,21,34,104,203,152,220,100,9,133,107,175,189,54,
233,221,187,119,178,121,243,230,224,157,220,166,33,146,54,94,136,88,7,242,128,58,242,28,227,204,135,23,118,232,208,33,204,175,186,135,245,162,121,115,104,152,7,165,136,81,252,245,151,241,255,178,103,207,
158,137,114,241,173,58,137,66,185,93,152,219,37,43,199,251,9,174,143,33,49,172,20,136,137,49,32,131,85,36,4,159,126,250,233,100,206,156,57,97,28,66,147,149,37,101,12,230,197,131,88,4,12,28,48,96,64,50,
97,194,132,64,10,123,70,179,102,205,130,129,140,101,34,1,121,11,101,244,69,88,68,250,49,63,99,208,79,132,141,40,44,44,124,50,116,76,161,20,49,242,150,31,138,128,13,58,137,198,234,5,112,28,147,199,151,
57,98,158,91,230,249,231,159,31,38,2,86,196,249,56,53,172,36,155,53,68,60,241,196,19,129,24,60,160,85,171,86,73,207,158,61,131,87,16,158,156,114,16,71,8,173,88,177,34,8,237,120,155,190,237,182,219,194,
13,151,213,135,72,188,129,177,173,67,156,71,152,147,20,66,72,183,111,223,30,116,192,227,100,219,106,205,219,43,167,226,41,56,69,123,221,112,249,185,225,114,145,178,89,171,53,79,155,93,117,54,60,72,193,
99,216,36,121,91,238,219,183,111,73,24,49,25,32,141,189,131,212,121,128,194,124,42,96,140,231,159,127,62,153,63,127,126,216,112,59,118,236,152,140,28,57,50,185,236,178,203,194,38,9,249,8,11,130,247,48,
255,171,175,190,154,220,126,251,237,28,8,193,83,166,78,157,26,60,150,253,13,18,105,91,22,57,228,17,60,4,79,129,80,250,96,143,158,143,169,239,10,201,15,165,199,182,156,170,1,37,59,165,38,109,174,198,83,
164,248,66,121,200,52,185,114,19,6,70,73,128,209,92,150,152,4,111,193,213,113,115,43,96,56,31,151,211,135,19,140,213,99,197,30,121,228,145,224,53,120,199,184,113,227,146,17,35,70,4,227,184,202,35,120,
10,70,19,182,120,68,159,62,125,146,33,67,134,36,175,191,254,122,240,210,117,235,214,37,215,92,115,77,73,120,51,15,115,196,115,199,41,160,30,97,30,22,135,188,108,42,16,97,237,165,215,241,105,211,166,45,
201,53,13,40,217,16,52,65,123,53,158,161,78,67,229,45,29,112,53,239,31,40,128,107,203,147,194,174,142,91,66,12,100,89,128,21,201,87,198,234,211,231,197,23,95,12,39,12,227,15,31,62,60,24,12,89,243,230,
205,75,22,46,92,152,44,90,180,40,200,115,207,61,151,60,245,212,83,33,228,150,44,89,18,246,181,153,51,103,134,20,114,40,103,35,37,196,236,101,128,249,44,49,168,167,45,225,135,23,50,63,95,7,177,81,122,181,
150,99,116,200,53,13,8,196,104,195,109,42,67,110,210,42,189,40,47,24,140,81,222,244,24,16,118,217,103,88,65,66,8,183,164,62,134,137,136,97,130,232,239,62,239,190,251,110,32,230,130,11,46,72,134,14,29,
154,188,253,246,219,201,227,143,63,30,188,97,237,218,181,232,18,66,6,207,161,142,183,229,103,158,121,38,153,53,107,86,8,163,73,147,38,5,157,32,142,113,8,15,22,142,121,40,119,234,188,197,207,216,4,208,
137,50,182,6,145,56,74,246,141,215,21,165,228,103,221,64,140,58,220,32,89,34,185,71,158,209,51,231,102,97,66,152,103,0,60,6,114,24,216,117,105,80,158,15,244,161,61,30,195,74,209,174,95,191,126,137,78,
190,100,249,242,229,193,181,9,83,86,242,146,75,46,73,198,140,25,147,140,31,63,62,185,225,134,27,194,93,134,187,13,247,144,5,11,22,36,87,95,125,117,184,143,16,106,132,20,251,18,171,238,185,73,45,105,114,
16,244,32,172,125,45,224,57,119,119,186,69,243,15,14,131,8,5,90,29,126,168,239,46,55,91,45,195,255,156,66,111,184,8,131,35,148,217,69,93,134,184,29,112,158,54,206,251,25,98,81,6,207,65,184,163,224,13,
144,6,65,140,63,118,236,216,164,115,231,206,193,83,102,204,152,17,66,7,15,123,239,189,247,56,24,146,85,171,86,133,112,214,253,35,140,5,49,236,65,241,220,105,120,126,235,68,63,190,55,67,136,189,7,221,16,
57,196,44,121,106,248,144,92,160,6,188,55,20,235,132,232,35,67,195,159,80,120,2,15,8,1,196,39,229,12,8,200,35,212,249,185,44,80,135,66,24,65,168,120,3,196,72,234,120,13,192,19,184,192,65,8,94,84,92,92,
28,60,12,65,105,78,64,142,109,142,120,188,4,114,217,35,72,61,71,62,29,76,136,235,208,31,61,76,140,203,241,26,45,78,75,101,111,226,89,36,21,252,181,42,239,215,228,215,17,66,177,183,24,148,17,70,144,224,
122,20,138,87,2,184,95,220,23,64,74,238,222,80,178,74,120,9,202,161,16,43,72,155,39,159,124,50,60,59,148,1,227,243,76,63,242,108,208,43,87,174,12,125,184,143,184,13,200,55,127,252,76,138,13,140,21,167,
22,136,86,155,191,212,94,83,167,64,153,70,138,215,134,154,124,40,70,231,3,157,168,195,16,12,64,56,101,60,33,72,231,211,2,41,144,203,125,133,148,61,133,113,24,151,13,253,165,151,94,42,181,161,231,3,186,
224,189,108,196,156,74,244,135,184,52,60,111,58,79,255,184,220,164,2,244,209,107,201,137,119,222,121,231,18,254,8,8,133,170,107,178,218,14,147,24,116,166,156,201,233,136,242,132,1,238,24,79,152,134,235,
220,159,112,32,29,60,120,112,24,139,61,3,163,32,24,239,227,200,142,149,76,231,99,175,176,46,140,201,107,131,137,137,251,228,131,251,162,7,109,177,61,13,141,219,79,201,58,60,38,20,176,138,136,159,61,137,
149,114,92,18,243,172,24,167,5,134,209,62,22,38,139,39,116,57,100,178,202,24,195,253,133,75,28,183,80,218,90,201,124,138,166,129,97,180,135,204,7,31,124,48,220,139,92,22,235,129,128,244,51,225,131,29,
244,103,145,93,110,104,28,126,139,218,95,96,163,1,87,116,86,34,31,124,61,199,64,140,51,108,80,172,0,226,114,11,202,80,206,117,156,15,214,23,93,116,81,248,61,136,251,11,97,5,208,165,60,164,235,49,242,161,
135,30,10,23,62,123,77,12,230,3,244,179,176,215,177,176,177,231,0,218,114,113,85,200,175,27,61,122,244,17,136,169,215,164,73,147,33,196,57,164,248,183,226,24,236,15,8,44,219,125,97,155,73,128,201,40,15,
140,201,198,202,107,0,23,51,238,40,236,17,156,62,188,152,86,21,204,7,225,24,56,125,250,244,112,162,161,163,245,72,167,6,100,18,25,180,101,161,13,198,97,60,219,4,49,179,101,112,67,121,196,118,126,70,229,
38,72,184,196,3,187,19,245,120,12,134,65,32,175,7,177,59,230,83,198,43,2,40,167,95,151,46,93,130,119,94,121,229,149,97,227,165,140,241,43,11,198,68,39,82,198,132,116,60,7,114,172,43,160,46,214,133,58,
218,178,184,56,1,207,6,81,131,109,42,123,95,87,138,46,16,179,83,164,236,82,250,35,12,199,157,48,220,251,7,128,93,148,224,254,192,234,226,49,24,67,57,64,17,132,246,78,157,79,11,138,177,98,188,18,176,58,
188,37,115,147,229,147,66,236,169,177,65,49,208,195,32,143,208,22,125,245,34,24,62,118,225,21,105,208,134,249,152,219,158,239,177,72,233,79,185,240,180,158,219,64,217,94,41,220,86,138,237,18,65,203,188,
65,98,120,12,24,133,56,86,26,47,225,30,2,195,108,194,24,100,50,172,172,225,114,139,87,108,233,210,165,225,171,29,159,29,240,32,238,36,172,96,220,182,44,164,235,76,4,70,223,123,239,189,37,123,22,136,141,
103,209,9,103,239,51,174,195,54,158,181,208,11,154,55,111,222,88,227,191,92,208,169,83,167,19,106,48,83,131,255,189,228,14,25,250,53,47,102,188,48,50,17,157,17,58,147,178,9,155,20,82,159,78,120,3,136,
13,43,75,32,22,69,216,95,158,125,246,217,224,129,120,76,97,97,97,137,167,50,23,169,199,52,92,103,196,121,143,125,247,221,119,7,253,121,118,123,239,63,216,228,114,64,29,186,227,45,202,79,209,226,212,164,
44,4,153,20,218,170,135,101,173,90,181,218,173,1,238,225,131,18,172,50,184,79,41,19,195,234,174,89,179,38,40,64,61,194,167,0,38,196,27,152,36,158,24,248,217,194,152,120,13,202,66,52,239,60,111,190,249,
102,32,154,57,16,35,61,78,140,184,29,176,199,161,203,148,41,83,130,119,224,77,180,227,197,145,253,19,187,226,104,192,139,88,24,149,175,83,223,45,42,234,46,47,62,92,178,251,104,208,141,170,24,35,230,254,
67,202,22,67,142,223,85,152,12,70,29,78,12,196,62,196,196,132,22,117,24,104,18,211,6,128,216,8,72,113,140,163,168,63,98,165,95,7,210,227,164,137,136,65,157,133,49,240,232,201,147,39,219,232,80,206,248,
140,233,141,151,57,115,222,178,95,114,151,188,182,153,234,231,51,94,9,49,10,169,13,116,214,91,111,47,13,244,111,245,235,215,15,33,5,203,24,1,184,131,48,16,159,6,184,127,224,33,16,195,203,32,27,51,237,
76,14,237,44,0,133,44,40,75,59,242,40,8,177,140,205,251,15,115,198,253,0,237,98,248,57,93,30,195,68,16,86,140,133,55,66,16,11,106,47,98,78,218,200,107,54,200,17,126,167,178,246,226,97,47,253,191,61,175,
4,41,249,95,234,52,94,204,253,183,86,241,85,142,99,38,167,51,36,48,48,158,65,232,48,48,55,87,66,138,205,14,185,240,194,11,3,81,40,66,63,27,72,222,70,240,140,23,210,143,49,44,0,130,60,71,140,184,127,58,
5,113,222,227,65,56,41,122,221,122,235,173,33,124,152,147,61,204,222,130,77,68,129,242,255,169,174,135,52,206,75,39,71,73,17,35,182,214,170,211,60,201,29,82,240,103,124,6,228,148,178,33,12,72,25,131,242,
123,15,123,13,46,75,61,31,142,32,133,111,37,124,34,0,40,140,114,38,8,65,49,218,163,148,141,0,78,129,61,147,254,22,224,212,136,251,0,27,140,56,207,62,198,21,227,190,251,238,11,223,153,33,159,113,176,3,
178,180,8,91,213,238,49,217,126,64,114,242,143,9,133,83,136,1,154,236,87,26,180,145,8,169,39,54,151,226,53,40,138,11,66,14,43,202,134,133,203,243,163,27,31,143,8,33,8,242,47,134,61,122,244,8,247,137,244,
102,140,80,6,49,148,27,38,8,193,32,140,97,37,221,39,31,98,82,232,83,158,64,6,11,199,231,81,198,99,124,116,22,41,156,200,119,233,170,208,104,211,166,77,167,252,213,120,41,98,180,35,31,215,96,255,46,25,
39,38,71,42,164,246,67,14,43,237,179,159,35,26,119,231,136,101,85,56,81,48,24,114,120,107,102,37,122,245,234,21,220,152,19,194,36,152,24,148,34,111,34,16,175,50,101,72,236,53,229,193,253,72,233,71,123,
247,113,57,2,57,252,229,195,236,217,179,195,216,236,115,34,127,219,192,129,3,9,163,118,178,155,19,169,4,165,136,1,106,196,255,45,254,70,27,210,32,121,200,253,184,29,228,224,13,24,10,227,156,78,92,231,
121,247,225,11,28,223,100,81,8,242,248,20,201,134,204,223,195,161,0,27,56,132,80,15,193,222,160,13,147,129,152,28,136,199,59,109,164,211,124,48,33,16,201,60,105,129,20,116,70,208,147,159,132,57,9,85,254,
51,121,202,213,26,34,108,184,49,242,18,3,116,183,121,76,76,247,16,1,191,82,232,252,154,208,65,89,54,98,66,10,214,185,173,66,14,47,131,108,196,124,171,5,212,243,173,150,50,194,13,99,9,51,66,40,31,98,98,
252,12,56,165,156,79,3,34,226,126,60,67,2,228,88,76,12,139,129,215,16,158,144,205,143,125,210,229,181,75,47,189,244,49,57,193,98,201,134,220,176,37,40,253,82,17,97,194,132,9,159,202,168,239,105,213,103,
42,29,173,201,235,113,161,99,5,152,128,137,28,98,236,59,252,221,45,27,48,127,90,138,162,220,108,9,43,222,133,188,90,120,16,4,179,17,18,82,54,28,242,98,80,78,59,194,147,177,92,22,11,198,186,159,73,112,
248,185,15,112,91,116,0,120,189,22,182,245,202,149,43,239,8,5,121,80,166,199,0,121,205,102,37,71,116,183,233,44,18,126,205,222,130,135,216,107,32,136,80,226,50,72,184,249,23,202,23,94,120,33,24,141,87,
17,102,124,163,37,12,9,45,60,7,111,194,149,25,143,49,80,28,163,108,140,83,140,230,101,19,242,41,163,93,92,231,103,234,45,38,8,137,203,17,0,217,44,34,159,82,245,22,93,230,63,155,150,75,12,16,211,11,36,
215,137,237,127,213,128,111,19,62,40,3,57,172,14,94,35,87,12,119,27,136,224,7,122,218,16,199,252,225,15,101,180,33,172,248,48,197,219,52,251,21,222,196,222,99,23,135,40,72,71,105,66,136,107,130,142,207,
240,105,130,49,104,103,114,16,192,51,4,176,103,177,80,105,34,76,144,235,17,8,69,56,165,116,140,247,15,3,229,65,133,196,72,185,61,74,166,203,216,201,90,221,49,82,250,115,72,128,24,159,56,172,2,239,80,220,
126,49,2,35,185,207,64,198,178,101,203,194,251,20,198,226,202,132,22,251,21,183,103,190,226,65,0,138,226,97,16,133,65,140,73,8,113,138,188,241,198,27,225,229,146,122,16,147,18,19,64,159,24,60,199,196,
208,159,144,183,167,83,175,133,59,249,233,50,15,202,221,99,140,137,19,39,114,140,12,148,209,187,52,248,55,82,238,207,152,4,129,20,12,195,104,60,133,212,87,126,8,194,27,248,128,196,254,195,170,35,132,27,
36,144,82,207,177,207,62,196,70,13,233,120,20,66,57,27,59,63,234,115,95,114,248,32,246,22,19,105,111,34,45,11,174,99,28,116,28,53,106,212,11,115,231,206,253,125,40,76,161,66,143,1,10,149,221,26,108,158,
38,158,32,34,166,201,224,141,236,43,40,133,113,94,45,140,102,227,197,16,66,138,125,135,77,26,79,162,61,225,195,239,211,92,254,236,113,164,220,76,113,109,238,61,140,9,193,16,66,216,17,94,180,227,166,109,
195,226,212,164,152,116,139,9,140,219,65,164,67,142,5,145,94,39,175,232,121,144,255,44,44,3,186,188,253,64,131,183,148,129,191,145,178,219,48,136,48,33,28,240,14,128,2,172,8,30,3,17,120,10,27,175,221,
24,101,77,40,6,163,44,174,141,224,109,40,28,111,200,132,128,55,123,94,4,237,53,24,203,56,8,249,184,28,144,198,121,234,1,164,161,43,158,185,124,249,242,50,237,175,148,199,24,138,245,185,154,224,144,92,
188,181,140,184,133,189,2,143,96,63,64,65,96,5,72,241,18,86,222,55,101,60,136,189,6,197,240,10,66,5,111,226,119,108,66,135,177,32,22,50,24,15,130,152,131,223,179,139,138,138,66,74,61,4,48,62,245,105,239,
200,7,19,70,74,123,22,73,58,61,154,171,206,139,42,121,12,88,191,126,125,93,77,50,81,222,240,11,121,197,107,186,143,116,231,165,145,155,48,70,163,48,74,216,109,185,215,176,9,35,108,188,177,87,32,228,33,
13,161,14,229,233,139,1,212,67,34,196,50,54,101,15,60,240,64,240,70,3,2,105,15,152,23,113,62,6,122,49,182,231,27,48,96,64,219,233,211,167,111,207,85,151,66,149,60,6,104,213,14,106,146,151,181,218,63,209,
10,255,149,86,250,24,138,99,52,68,120,69,17,242,24,97,119,199,0,54,61,66,130,251,13,132,114,242,176,57,115,148,243,158,69,57,100,112,39,226,212,226,116,107,215,174,93,8,87,200,31,54,108,88,9,49,204,97,
130,109,120,44,148,33,38,25,143,164,175,210,177,189,123,247,254,56,12,82,6,170,76,12,80,72,253,94,147,213,86,8,12,209,36,63,22,73,135,153,156,61,195,33,69,138,18,148,17,26,144,98,37,17,43,13,168,51,129,
24,100,15,162,29,128,96,218,32,108,236,131,6,13,10,121,123,133,199,138,201,176,120,46,136,97,124,133,228,203,119,222,121,231,111,111,188,241,198,83,93,42,133,42,135,146,161,151,47,254,43,229,126,41,247,
196,246,237,219,59,106,131,188,75,97,213,84,174,90,11,50,48,6,69,98,3,236,77,105,164,87,152,60,125,226,52,206,211,134,63,9,225,142,147,110,71,10,252,236,188,230,62,212,183,111,223,223,93,117,213,85,99,
69,10,119,179,114,113,218,196,24,218,115,250,107,210,107,181,1,175,82,88,116,16,41,247,42,92,106,216,115,98,69,211,136,13,193,88,136,139,225,58,27,24,3,15,224,13,158,79,172,220,176,237,109,140,3,188,32,
180,211,70,191,65,161,57,117,246,236,217,179,66,101,37,240,7,19,3,180,55,116,150,81,127,35,197,214,232,226,86,91,251,205,48,41,198,191,243,116,176,177,164,40,154,207,200,170,194,227,32,132,10,151,69,174,
5,220,133,56,218,41,151,71,47,214,254,116,64,164,77,189,249,230,155,183,92,127,253,245,223,254,216,84,9,156,17,98,12,189,148,13,19,1,63,145,112,207,217,40,130,118,152,16,32,35,38,106,101,127,17,30,78,
19,242,136,115,37,133,202,246,211,216,15,107,188,189,186,4,78,210,94,119,19,36,201,67,182,40,189,71,242,168,46,166,167,126,248,169,2,206,40,49,64,43,85,71,222,210,68,202,255,88,143,135,165,124,123,17,
51,74,249,119,180,146,139,66,163,28,76,88,85,144,199,227,248,183,190,186,154,231,231,26,239,97,234,69,206,81,189,227,237,63,89,125,58,72,146,255,1,124,207,83,163,141,22,86,223,0,0,0,0,73,69,78,68,174,
66,96,130,0,0};

const char* AiassAudioProcessorEditor::kippschalter_on_c_png = (const char*) resource_AiassAudioProcessorEditor_kippschalter_on_c_png;
const int AiassAudioProcessorEditor::kippschalter_on_c_pngSize = 5809;

// JUCER_RESOURCE: typenschild_a_png, 11020, "../images/Typenschild_A.png"
static const unsigned char resource_AiassAudioProcessorEditor_typenschild_a_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,64,0,0,0,41,8,6,0,0,0,68,28,240,140,0,0,0,4,103,65,77,65,0,0,177,
142,124,251,81,147,0,0,0,32,99,72,82,77,0,0,135,15,0,0,140,15,0,0,253,82,0,0,129,64,0,0,125,121,0,0,233,139,0,0,60,229,0,0,25,204,115,60,133,119,0,0,10,47,105,67,67,80,73,67,67,32,80,114,111,102,105,108,
101,0,0,72,199,157,150,119,84,84,215,22,135,207,189,119,122,161,205,48,210,25,122,147,46,48,128,244,46,32,29,4,81,24,102,6,24,202,0,195,12,77,108,136,168,64,68,17,17,1,69,144,160,128,1,163,161,72,172,
136,98,33,40,168,96,15,72,16,80,98,48,138,168,168,100,70,214,74,124,121,121,239,229,229,247,199,189,223,218,103,239,115,247,217,123,159,181,46,0,36,79,31,46,47,5,150,2,32,153,39,224,7,122,56,211,87,133,
71,208,177,253,0,6,120,128,1,166,0,48,89,233,169,190,65,238,193,64,36,47,55,23,122,186,200,9,252,139,222,12,1,72,252,190,101,232,233,79,167,131,255,79,210,172,84,190,0,0,200,95,196,230,108,78,58,75,196,
249,34,78,202,20,164,138,237,51,34,166,198,36,138,25,70,137,153,47,74,80,196,114,98,142,91,228,165,159,125,22,217,81,204,236,100,30,91,196,226,156,83,217,201,108,49,247,136,120,123,134,144,35,98,196,71,
196,5,25,92,78,166,136,111,139,88,51,73,152,204,21,241,91,113,108,50,135,153,14,0,138,36,182,11,56,172,120,17,155,136,152,196,15,14,116,17,241,114,0,112,164,184,47,56,230,11,22,112,178,4,226,67,185,164,
164,102,243,185,113,241,2,186,46,75,143,110,106,109,205,160,123,114,50,147,56,2,129,161,63,147,149,200,228,179,233,46,41,201,169,76,94,54,0,139,103,254,44,25,113,109,233,162,34,91,154,90,91,90,26,154,
25,153,126,81,168,255,186,248,55,37,238,237,34,189,10,248,220,51,136,214,247,135,237,175,252,82,234,0,96,204,138,106,179,235,15,91,204,126,0,58,182,2,32,119,255,15,155,230,33,0,36,69,125,107,191,241,197,
121,104,226,121,137,23,8,82,109,140,141,51,51,51,141,184,28,150,145,184,160,191,235,127,58,252,13,125,241,61,35,241,118,191,151,135,238,202,137,101,10,147,4,116,113,221,88,41,73,41,66,62,61,61,149,201,
226,208,13,255,60,196,255,56,240,175,243,88,26,200,137,229,240,57,60,81,68,168,104,202,184,188,56,81,187,121,108,174,128,155,194,163,115,121,255,169,137,255,48,236,79,90,156,107,145,40,245,159,0,53,202,
8,72,221,160,2,228,231,62,128,162,16,1,18,121,80,220,245,223,251,230,131,15,5,226,155,23,166,58,177,56,247,159,5,253,251,174,112,137,248,145,206,141,251,28,231,18,24,76,103,9,249,25,139,107,226,107,9,
208,128,0,36,1,21,200,3,21,160,1,116,129,33,48,3,86,192,22,56,2,55,176,2,248,129,96,16,14,214,2,22,136,7,201,128,15,50,65,46,216,12,10,64,17,216,5,246,130,74,80,3,234,65,35,104,1,39,64,7,56,13,46,128,
203,224,58,184,9,238,128,7,96,4,140,131,231,96,6,188,1,243,16,4,97,33,50,68,129,228,33,85,72,11,50,128,204,32,6,100,15,185,65,62,80,32,20,14,69,67,113,16,15,18,66,185,208,22,168,8,42,133,42,161,90,168,
17,250,22,58,5,93,128,174,66,3,208,61,104,20,154,130,126,133,222,195,8,76,130,169,176,50,172,13,27,195,12,216,9,246,134,131,225,53,112,28,156,6,231,192,249,240,78,184,2,174,131,143,193,237,240,5,248,58,
124,7,30,129,159,195,179,8,64,136,8,13,81,67,12,17,6,226,130,248,33,17,72,44,194,71,54,32,133,72,57,82,135,180,32,93,72,47,114,11,25,65,166,145,119,40,12,138,130,162,163,12,81,182,40,79,84,8,138,133,74,
67,109,64,21,163,42,81,71,81,237,168,30,212,45,212,40,106,6,245,9,77,70,43,161,13,208,54,104,47,244,42,116,28,58,19,93,128,46,71,55,160,219,208,151,208,119,208,227,232,55,24,12,134,134,209,193,88,97,60,
49,225,152,4,204,58,76,49,230,0,166,21,115,30,51,128,25,195,204,98,177,88,121,172,1,214,14,235,135,101,98,5,216,2,236,126,236,49,236,57,236,32,118,28,251,22,71,196,169,226,204,112,238,184,8,28,15,151,
135,43,199,53,225,206,226,6,113,19,184,121,188,20,94,11,111,131,247,195,179,241,217,248,18,124,61,190,11,127,3,63,142,159,39,72,19,116,8,118,132,96,66,2,97,51,161,130,208,66,184,68,120,72,120,69,36,18,
213,137,214,196,0,34,151,184,137,88,65,60,78,188,66,28,37,190,35,201,144,244,73,46,164,72,146,144,180,147,116,132,116,158,116,143,244,138,76,38,107,147,29,201,17,100,1,121,39,185,145,124,145,252,152,252,
86,130,34,97,36,225,37,193,150,216,40,81,37,209,46,49,40,241,66,18,47,169,37,233,36,185,86,50,71,178,92,242,164,228,13,201,105,41,188,148,182,148,139,20,83,106,131,84,149,212,41,169,97,169,89,105,138,
180,169,180,159,116,178,116,177,116,147,244,85,233,73,25,172,140,182,140,155,12,91,38,95,230,176,204,69,153,49,10,66,209,160,184,80,88,148,45,148,122,202,37,202,56,21,67,213,161,122,81,19,168,69,212,111,
168,253,212,25,89,25,217,101,178,161,178,89,178,85,178,103,100,71,104,8,77,155,230,69,75,162,149,208,78,208,134,104,239,151,40,47,113,90,194,89,178,99,73,203,146,193,37,115,114,138,114,142,114,28,185,
66,185,86,185,59,114,239,229,233,242,110,242,137,242,187,229,59,228,31,41,160,20,244,21,2,20,50,21,14,42,92,82,152,86,164,42,218,42,178,20,11,21,79,40,222,87,130,149,244,149,2,149,214,41,29,86,234,83,
154,85,86,81,246,80,78,85,222,175,124,81,121,90,133,166,226,168,146,160,82,166,114,86,101,74,149,162,106,175,202,85,45,83,61,167,250,140,46,75,119,162,39,209,43,232,61,244,25,53,37,53,79,53,161,90,173,
90,191,218,188,186,142,122,136,122,158,122,171,250,35,13,130,6,67,35,86,163,76,163,91,99,70,83,85,211,87,51,87,179,89,243,190,22,94,139,161,21,175,181,79,171,87,107,78,91,71,59,76,123,155,118,135,246,
164,142,156,142,151,78,142,78,179,206,67,93,178,174,131,110,154,110,157,238,109,61,140,30,67,47,81,239,128,222,77,125,88,223,66,63,94,191,74,255,134,1,108,96,105,192,53,56,96,48,176,20,189,212,122,41,
111,105,221,210,97,67,146,161,147,97,134,97,179,225,168,17,205,200,199,40,207,168,195,232,133,177,166,113,132,241,110,227,94,227,79,38,22,38,73,38,245,38,15,76,101,76,87,152,230,153,118,153,254,106,166,
111,198,50,171,50,187,109,78,54,119,55,223,104,222,105,254,114,153,193,50,206,178,131,203,238,90,80,44,124,45,182,89,116,91,124,180,180,178,228,91,182,88,78,89,105,90,69,91,85,91,13,51,168,12,127,70,49,
227,138,53,218,218,217,122,163,245,105,235,119,54,150,54,2,155,19,54,191,216,26,218,38,218,54,217,78,46,215,89,206,89,94,191,124,204,78,221,142,105,87,107,55,98,79,183,143,182,63,100,63,226,160,230,192,
116,168,115,120,226,168,225,200,118,108,112,156,112,210,115,74,112,58,230,244,194,217,196,153,239,220,230,60,231,98,227,178,222,229,188,43,226,234,225,90,232,218,239,38,227,22,226,86,233,246,216,93,221,
61,206,189,217,125,198,195,194,99,157,199,121,79,180,167,183,231,110,207,97,47,101,47,150,87,163,215,204,10,171,21,235,87,244,120,147,188,131,188,43,189,159,248,232,251,240,125,186,124,97,223,21,190,123,
124,31,174,212,90,201,91,217,225,7,252,188,252,246,248,61,242,215,241,79,243,255,62,0,19,224,31,80,21,240,52,208,52,48,55,176,55,136,18,20,21,212,20,244,38,216,57,184,36,248,65,136,110,136,48,164,59,84,
50,52,50,180,49,116,46,204,53,172,52,108,100,149,241,170,245,171,174,135,43,132,115,195,59,35,176,17,161,17,13,17,179,171,221,86,239,93,61,30,105,17,89,16,57,180,70,103,77,214,154,171,107,21,214,38,173,
61,19,37,25,197,140,58,25,141,142,14,139,110,138,254,192,244,99,214,49,103,99,188,98,170,99,102,88,46,172,125,172,231,108,71,118,25,123,138,99,199,41,229,76,196,218,197,150,198,78,198,217,197,237,137,
155,138,119,136,47,143,159,230,186,112,43,185,47,19,60,19,106,18,230,18,253,18,143,36,46,36,133,37,181,38,227,146,163,147,79,241,100,120,137,188,158,20,149,148,172,148,129,84,131,212,130,212,145,52,155,
180,189,105,51,124,111,126,67,58,148,190,38,189,83,64,21,253,76,245,9,117,133,91,133,163,25,246,25,85,25,111,51,67,51,79,102,73,103,241,178,250,178,245,179,119,100,79,228,184,231,124,189,14,181,142,181,
174,59,87,45,119,115,238,232,122,167,245,181,27,160,13,49,27,186,55,106,108,204,223,56,190,201,99,211,209,205,132,205,137,155,127,200,51,201,43,205,123,189,37,108,75,87,190,114,254,166,252,177,173,30,
91,155,11,36,10,248,5,195,219,108,183,213,108,71,109,231,110,239,223,97,190,99,255,142,79,133,236,194,107,69,38,69,229,69,31,138,89,197,215,190,50,253,170,226,171,133,157,177,59,251,75,44,75,14,238,194,
236,226,237,26,218,237,176,251,104,169,116,105,78,233,216,30,223,61,237,101,244,178,194,178,215,123,163,246,94,45,95,86,94,179,143,176,79,184,111,164,194,167,162,115,191,230,254,93,251,63,84,198,87,222,
169,114,174,106,173,86,170,222,81,61,119,128,125,96,240,160,227,193,150,26,229,154,162,154,247,135,184,135,238,214,122,212,182,215,105,215,149,31,198,28,206,56,252,180,62,180,190,247,107,198,215,141,13,
10,13,69,13,31,143,240,142,140,28,13,60,218,211,104,213,216,216,164,212,84,210,12,55,11,155,167,142,69,30,187,249,141,235,55,157,45,134,45,181,173,180,214,162,227,224,184,240,248,179,111,163,191,29,58,
225,125,162,251,36,227,100,203,119,90,223,85,183,81,218,10,219,161,246,236,246,153,142,248,142,145,206,240,206,129,83,43,78,117,119,217,118,181,125,111,244,253,145,211,106,167,171,206,200,158,41,57,75,
56,155,127,118,225,92,206,185,217,243,169,231,167,47,196,93,24,235,142,234,126,112,113,213,197,219,61,1,61,253,151,188,47,93,185,236,126,249,98,175,83,239,185,43,118,87,78,95,181,185,122,234,26,227,90,
199,117,203,235,237,125,22,125,109,63,88,252,208,214,111,217,223,126,195,234,70,231,77,235,155,93,3,203,7,206,14,58,12,94,184,229,122,235,242,109,175,219,215,239,172,188,51,48,20,50,116,119,56,114,120,
228,46,251,238,228,189,164,123,47,239,103,220,159,127,176,233,33,250,97,225,35,169,71,229,143,149,30,215,253,168,247,99,235,136,229,200,153,81,215,209,190,39,65,79,30,140,177,198,158,255,148,254,211,135,
241,252,167,228,167,229,19,170,19,141,147,102,147,167,167,220,167,110,62,91,253,108,252,121,234,243,249,233,130,159,165,127,174,126,161,251,226,187,95,28,127,233,155,89,53,51,254,146,255,114,225,215,226,
87,242,175,142,188,94,246,186,123,214,127,246,241,155,228,55,243,115,133,111,229,223,30,125,199,120,215,251,62,236,253,196,124,230,7,236,135,138,143,122,31,187,62,121,127,122,184,144,188,176,240,27,247,
132,243,251,55,4,41,30,0,0,0,9,112,72,89,115,0,0,46,34,0,0,46,34,1,170,226,221,146,0,0,32,71,73,68,65,84,120,94,237,157,7,116,20,85,219,199,159,244,2,164,64,8,37,144,16,18,74,0,65,16,66,175,34,130,168,
168,175,136,128,116,233,189,170,32,162,2,82,164,190,128,124,162,188,34,34,136,136,136,40,210,59,36,132,78,168,161,6,72,72,239,61,155,228,187,255,187,51,201,236,236,204,238,44,226,123,248,206,55,191,115,
6,118,102,55,179,179,179,247,62,247,255,148,123,215,142,158,156,202,246,246,246,157,124,43,87,108,233,233,89,33,196,213,197,185,134,131,131,131,167,157,157,157,35,123,238,239,156,87,71,71,71,71,137,18,
70,161,193,80,148,154,151,151,255,48,53,45,227,74,82,114,106,56,59,118,140,61,151,110,124,137,109,216,106,168,156,93,156,157,255,85,43,160,250,48,223,202,149,58,84,173,226,227,228,234,234,34,60,165,163,
163,163,243,223,131,25,62,202,201,205,163,184,184,196,220,248,132,228,125,209,15,99,191,97,198,113,15,123,170,200,248,10,235,104,53,128,142,238,238,110,253,235,6,7,204,169,29,88,51,176,156,187,155,112,
88,71,71,71,231,217,32,61,35,139,238,220,125,112,249,214,157,232,143,11,10,10,255,96,135,74,140,207,168,99,213,0,50,151,182,126,112,144,255,55,141,26,212,105,87,190,156,187,112,84,71,71,71,231,217,132,
185,198,37,145,87,163,126,143,126,16,59,134,237,198,26,143,42,99,209,0,186,187,187,246,105,218,56,100,29,83,125,30,194,33,29,29,29,157,103,158,226,226,18,186,17,117,247,241,229,43,55,251,21,22,26,142,
8,135,205,80,53,128,94,94,30,211,90,181,104,178,176,178,143,183,131,112,72,51,21,60,60,41,36,164,17,213,10,12,162,202,190,85,200,197,197,133,12,6,3,37,37,37,82,204,163,7,116,253,106,36,37,36,196,9,175,
214,209,209,209,249,103,120,20,19,159,119,250,236,229,33,57,57,185,63,9,135,76,80,52,128,94,158,21,166,183,107,243,194,34,111,47,15,173,49,66,78,72,131,231,232,149,158,111,80,163,198,77,201,193,193,129,
7,41,11,11,11,41,47,47,151,92,93,221,200,201,201,9,46,53,63,126,239,238,45,218,191,239,79,10,63,117,130,138,138,12,194,25,116,116,116,116,158,46,113,241,73,134,147,97,231,251,231,228,230,253,44,28,42,
197,204,192,185,187,187,245,233,216,182,249,102,31,31,111,123,225,144,85,42,85,170,76,3,135,140,160,166,205,66,41,43,43,147,34,194,79,208,133,243,103,152,145,187,77,153,153,25,220,224,193,240,149,175,
80,129,106,213,10,162,166,47,132,82,171,214,237,169,124,249,10,244,240,97,52,109,88,255,21,221,138,186,33,156,77,71,71,71,231,233,242,240,81,92,222,137,176,243,93,153,39,122,82,56,196,49,49,128,72,120,
180,105,213,52,162,118,173,26,21,132,67,86,169,31,210,144,198,79,250,144,156,157,157,233,143,223,183,211,222,191,118,113,197,39,226,232,228,66,117,235,53,164,187,119,162,40,47,55,75,56,74,92,17,118,237,
246,10,189,214,235,109,174,12,183,108,250,142,43,66,29,235,224,126,121,87,172,68,30,30,94,108,192,50,38,166,178,179,179,40,53,53,133,210,216,86,92,92,204,143,61,41,80,239,94,222,21,201,203,203,155,157,
191,28,217,219,219,83,78,78,14,165,167,165,82,114,74,18,21,25,180,43,118,39,118,45,205,227,147,133,61,29,83,236,40,162,74,37,42,178,183,201,209,210,121,66,174,94,187,253,232,252,165,107,205,216,195,68,
227,17,83,3,232,88,55,184,214,209,208,230,141,219,48,177,166,137,102,76,201,141,25,63,157,226,30,199,208,218,53,75,41,230,209,67,225,25,35,80,126,163,198,78,167,182,237,218,83,92,220,99,154,60,97,56,57,
57,154,134,20,125,171,84,163,177,227,167,81,96,237,32,218,190,109,11,237,220,177,85,120,198,118,6,15,29,77,254,1,181,132,189,50,142,31,61,68,135,15,237,21,246,172,211,167,239,32,170,87,191,129,176,103,
36,236,212,49,218,191,87,155,129,134,1,153,52,117,22,149,43,87,78,56,82,198,47,219,126,164,107,87,46,11,123,218,113,99,134,174,93,251,206,212,188,69,27,126,175,48,128,200,193,253,206,200,72,167,43,145,
23,233,232,225,125,116,243,198,53,126,76,11,142,142,78,212,162,101,27,106,221,166,3,5,215,169,199,174,189,60,87,237,82,112,174,156,156,108,126,222,19,199,14,209,249,115,17,204,216,90,46,185,114,51,20,
209,128,235,247,132,61,29,41,37,236,246,126,31,82,155,10,28,212,157,173,26,53,253,201,211,211,75,216,211,198,35,214,15,49,88,1,180,147,151,123,188,70,207,55,109,206,60,46,15,74,78,78,162,211,225,199,233,
216,145,131,127,59,244,20,88,59,152,218,180,237,200,196,143,11,133,135,29,167,235,215,34,133,103,212,65,94,160,125,199,23,201,215,183,42,111,171,151,47,158,99,94,99,134,240,172,54,10,10,10,41,55,215,56,
32,195,227,212,218,198,33,12,142,158,56,187,229,81,76,92,63,225,80,153,1,44,231,238,54,244,229,174,109,215,151,211,88,234,82,187,118,29,250,104,246,60,186,123,251,22,173,88,246,5,191,32,57,120,195,89,
115,22,83,72,72,8,123,62,151,134,12,236,77,206,78,230,57,21,87,55,55,154,58,125,54,83,138,13,104,221,218,21,116,242,132,106,210,70,21,36,91,22,47,93,203,141,143,156,120,102,124,103,76,29,195,110,148,54,
101,52,105,234,76,102,220,91,10,123,70,254,250,243,55,218,242,227,119,194,158,101,154,60,223,156,166,206,152,45,236,153,114,254,220,105,90,177,244,11,97,79,27,205,91,180,166,65,67,71,217,212,17,208,40,
206,159,61,77,235,191,93,67,89,153,150,27,88,80,112,93,26,62,106,34,85,175,94,67,56,162,141,59,183,163,232,235,175,150,179,193,205,98,165,129,206,19,226,201,20,248,194,197,171,169,92,249,242,194,17,235,
160,207,205,156,49,158,98,99,31,113,5,63,99,230,231,84,163,134,191,240,108,25,151,47,157,167,149,203,22,80,97,97,129,112,196,54,208,255,103,205,89,192,189,17,128,129,112,249,146,249,116,137,25,52,53,186,
191,210,139,222,237,55,136,121,20,54,231,85,21,41,42,42,98,94,79,50,93,185,124,145,78,157,60,162,105,192,79,74,78,45,222,127,232,20,115,133,139,14,99,95,188,18,215,70,13,234,108,171,225,87,85,83,15,115,
113,113,165,15,102,126,198,221,162,197,11,231,144,161,168,152,94,237,245,14,85,247,243,231,170,7,55,5,177,63,40,136,168,155,215,41,55,47,143,126,219,241,51,115,207,140,202,211,155,185,87,117,235,133,80,
227,166,161,212,185,75,15,138,141,137,97,10,109,15,181,96,234,6,10,228,236,153,48,214,105,51,249,107,181,210,189,71,47,106,208,240,57,97,207,20,196,26,111,69,93,215,156,121,110,213,166,61,85,147,25,131,
219,183,110,112,101,165,5,124,201,106,198,4,138,247,248,209,3,124,64,208,66,155,118,157,104,244,184,169,228,198,6,9,91,192,189,175,238,87,131,25,227,23,248,232,172,214,208,161,246,62,156,57,151,127,39,
182,82,145,185,225,45,91,183,167,11,231,35,108,254,190,116,172,51,112,208,8,10,174,91,95,216,211,70,244,253,187,244,251,206,109,252,241,136,209,147,168,126,72,35,254,88,78,149,170,213,120,216,228,246,
173,155,194,17,219,24,56,120,36,83,167,1,194,30,218,155,61,85,97,109,251,216,145,3,194,17,83,90,132,182,161,97,195,199,241,112,202,211,2,231,66,136,70,84,149,176,41,183,163,110,240,207,165,134,187,187,
155,93,94,94,126,157,164,228,52,174,102,248,213,184,186,56,247,14,10,148,124,26,43,188,250,250,91,228,227,227,75,95,175,93,206,223,172,231,107,111,83,151,23,187,145,95,13,230,126,218,185,48,105,155,69,
207,53,110,202,95,155,16,31,67,219,127,222,72,81,55,140,242,56,32,32,144,236,29,93,233,204,185,11,236,75,168,65,29,58,118,162,119,251,15,166,236,172,44,250,159,53,203,200,145,25,207,254,3,222,103,175,
212,232,135,51,160,250,112,3,44,209,169,75,55,225,209,63,11,12,9,20,160,26,184,214,14,29,187,10,123,150,241,240,240,164,65,67,70,154,53,26,140,182,48,198,136,185,254,252,211,70,218,177,125,11,157,98,170,
25,46,133,28,52,210,190,239,13,17,246,76,193,72,252,254,200,9,228,226,234,42,28,17,96,163,40,212,221,95,187,119,210,182,173,63,208,118,230,182,31,57,180,143,18,19,226,133,23,148,129,107,28,62,114,226,
83,109,216,58,68,117,234,134,80,219,246,157,133,61,237,96,176,3,78,78,206,204,237,109,193,31,171,209,180,153,229,231,213,192,119,222,152,13,172,114,224,18,163,4,78,14,92,228,247,6,190,111,22,82,121,218,
52,108,212,132,230,204,253,146,27,68,75,212,14,172,217,154,93,75,91,60,230,10,176,78,112,192,234,0,255,234,154,12,160,59,83,120,99,199,77,167,19,39,14,211,225,131,198,184,90,131,134,141,153,20,77,167,
174,93,187,178,81,160,42,149,176,211,70,71,223,39,111,47,79,147,78,137,27,81,201,167,50,121,120,251,210,248,241,147,169,97,195,134,116,240,224,65,30,87,138,188,116,150,7,241,161,42,144,33,190,18,121,129,
82,146,147,132,191,180,12,190,200,46,47,118,23,246,140,160,238,80,218,41,171,84,173,78,71,14,239,167,124,166,70,173,241,119,20,96,183,238,175,81,163,231,158,23,246,140,200,175,197,151,221,163,253,123,
255,176,42,215,59,118,238,70,47,52,55,117,197,51,210,211,104,254,220,89,180,251,143,29,116,245,202,37,174,176,111,92,191,194,84,115,56,29,216,183,155,39,163,130,235,152,170,6,196,145,142,31,59,100,22,
166,64,217,82,143,158,111,8,123,70,12,134,66,90,185,124,1,253,180,121,3,115,45,46,176,243,95,99,174,197,85,158,213,63,176,239,79,246,254,233,244,92,147,102,38,141,185,98,37,31,238,126,40,25,72,52,176,
90,246,69,228,109,87,162,111,178,205,139,109,25,37,246,138,243,181,160,220,83,82,146,232,238,221,91,138,27,218,14,250,138,20,184,132,27,254,179,150,247,39,120,97,189,222,124,199,162,209,129,151,134,129,
205,86,224,149,188,208,188,149,176,87,6,222,235,218,181,72,30,114,146,2,113,130,88,161,37,30,62,184,79,103,34,78,41,126,86,113,187,127,239,14,19,84,143,201,158,137,136,10,21,148,231,102,192,198,64,124,
29,61,178,159,247,59,37,220,221,92,237,82,211,50,236,211,51,178,118,162,125,250,53,106,16,188,204,211,163,130,166,33,188,99,167,151,168,25,235,148,95,173,90,82,42,53,139,138,75,184,245,175,196,58,2,220,
98,63,230,122,253,240,253,122,170,29,20,72,201,73,165,9,23,170,90,205,143,178,115,11,105,204,152,9,20,25,25,73,158,158,158,236,75,78,166,115,103,78,82,82,162,177,243,60,142,125,196,179,195,248,32,112,
133,181,208,247,189,161,236,220,213,133,61,163,66,250,229,231,31,77,12,17,12,80,118,86,38,239,208,214,120,82,3,136,247,24,62,106,2,79,32,136,192,96,29,58,184,135,203,115,17,200,118,148,8,197,61,182,28,
59,123,169,91,79,170,233,111,154,212,249,109,199,86,222,80,148,64,7,192,53,214,97,110,19,140,172,8,174,11,229,70,15,162,77,147,17,45,91,183,227,163,166,148,176,83,199,185,178,84,2,157,14,13,17,159,15,
174,179,148,76,33,249,34,199,141,117,242,190,206,249,84,207,161,72,223,100,91,93,182,93,44,114,164,34,5,111,7,157,29,241,52,181,13,34,1,137,4,41,8,243,236,253,235,119,254,24,109,161,113,147,166,124,112,
82,3,238,50,146,123,182,242,110,191,33,60,230,174,68,108,204,35,62,96,74,129,23,83,177,162,250,117,160,93,125,187,110,21,237,219,179,75,241,179,138,219,197,11,103,121,219,199,64,31,201,6,103,180,115,37,
197,9,145,150,197,60,74,244,89,53,242,243,11,106,197,196,38,44,183,119,114,114,236,90,181,138,143,106,84,18,202,169,255,128,97,60,51,10,144,41,68,205,158,52,158,230,232,96,199,71,146,99,199,142,241,55,
78,76,76,100,198,47,152,127,9,82,50,50,210,200,193,174,152,246,239,223,207,19,35,25,25,25,204,74,23,153,148,85,196,51,11,143,27,136,17,16,163,216,139,47,189,66,3,6,13,47,149,235,24,101,170,49,67,42,2,
69,41,186,219,34,80,69,184,73,48,120,82,58,49,69,37,85,98,79,27,24,147,202,149,77,27,198,233,240,147,116,252,232,65,30,156,150,210,249,197,151,133,71,234,160,110,82,142,181,216,33,26,211,137,227,135,185,
122,150,110,30,21,204,27,10,98,163,114,242,20,146,89,114,78,157,60,106,118,126,169,209,151,82,88,98,71,97,6,39,125,83,217,12,54,132,122,68,80,162,164,20,219,19,221,95,35,37,180,241,187,117,92,13,170,33,
175,218,208,2,66,60,245,234,151,13,230,114,2,101,238,103,85,102,63,106,7,213,229,143,33,152,144,181,149,130,126,241,235,47,91,184,129,243,15,8,164,23,187,246,48,219,186,116,237,110,214,190,16,187,92,48,
127,54,87,201,74,132,182,228,30,174,42,85,124,43,33,223,209,210,161,70,245,42,163,153,79,172,26,180,170,86,221,159,134,13,31,195,131,247,59,119,254,78,111,190,213,155,206,50,43,12,151,167,136,93,124,113,
81,49,57,56,58,80,97,161,129,30,60,124,72,62,204,32,253,242,243,38,230,103,251,115,67,134,57,121,80,100,48,60,5,249,249,76,57,212,165,235,215,175,83,120,120,24,101,48,9,126,226,232,94,4,38,121,122,30,
30,33,12,28,178,87,48,120,127,254,185,155,221,128,238,204,112,117,101,35,75,44,183,232,239,188,59,144,75,91,100,185,64,247,30,175,115,23,92,202,239,191,109,163,59,183,111,242,64,175,52,30,128,155,200,
141,119,188,229,100,200,147,42,64,12,18,126,126,53,133,61,35,155,54,126,203,149,23,98,38,210,81,208,152,12,49,119,75,165,64,193,162,81,72,169,89,51,128,223,215,52,161,204,65,9,184,19,123,152,18,144,110,
80,7,114,112,110,185,187,142,196,9,212,162,37,117,138,90,67,249,249,81,18,163,4,204,126,44,115,243,244,77,121,211,86,192,97,74,199,78,93,169,73,83,211,46,139,25,87,223,173,95,107,18,226,65,27,57,119,38,
156,25,76,111,110,184,80,234,36,117,137,247,252,181,147,43,54,91,104,223,177,139,197,216,162,147,179,51,15,239,136,192,155,19,251,231,145,67,123,105,205,170,47,41,157,121,69,8,151,32,19,189,121,211,122,
38,18,78,112,151,118,214,39,95,240,36,40,74,118,164,27,226,209,80,124,114,240,89,97,64,27,55,49,143,71,162,252,103,207,238,157,102,194,67,196,197,197,153,238,69,199,220,176,247,240,40,175,152,38,66,221,
25,252,246,90,129,70,87,7,247,205,193,209,145,41,28,95,46,157,237,29,28,105,210,212,217,244,217,252,229,204,184,33,21,110,160,138,94,229,232,226,185,48,10,102,174,239,77,230,106,102,231,228,81,106,122,
46,115,123,139,40,51,199,64,5,204,72,226,67,87,171,234,67,126,213,124,40,43,61,137,141,16,85,41,46,46,142,38,76,249,152,198,140,159,65,46,174,238,165,174,154,212,173,245,175,21,68,13,152,194,250,115,215,
175,165,174,49,140,106,123,89,66,33,159,25,89,241,249,83,39,142,242,255,165,116,150,197,10,159,22,40,81,105,214,44,84,216,51,2,35,141,41,127,32,76,118,45,184,246,142,204,176,91,226,206,29,227,223,74,129,
226,157,243,249,151,52,121,218,199,212,174,67,23,238,138,60,169,170,69,195,146,131,134,51,121,234,44,250,120,206,2,214,120,123,146,95,141,154,172,227,96,141,91,157,103,133,214,10,241,180,27,215,34,75,
107,255,164,60,126,28,67,171,86,44,162,241,163,7,51,225,82,22,82,66,172,23,34,198,86,90,182,106,199,255,135,167,161,84,89,128,48,24,146,36,0,153,97,84,9,136,192,221,70,12,25,37,101,136,85,34,185,6,91,
2,222,238,243,158,162,155,140,129,21,130,70,13,216,19,37,92,93,93,89,191,80,117,108,249,64,80,185,146,119,35,123,102,9,205,146,31,80,6,253,222,27,202,101,233,189,187,70,63,26,234,172,65,131,134,60,139,
137,184,93,80,112,8,181,104,17,74,117,234,212,225,95,8,20,3,20,210,181,171,151,184,175,158,199,92,181,156,220,66,242,40,239,204,55,7,59,3,219,55,112,139,124,237,234,101,30,192,199,107,209,9,91,182,238,
64,161,161,45,153,193,109,199,148,95,75,230,66,39,240,247,108,212,168,17,27,33,141,99,228,195,232,59,116,137,157,23,129,91,17,184,190,80,156,82,46,93,60,91,42,179,17,239,147,151,190,96,68,241,246,54,13,
30,63,13,96,140,48,64,72,9,103,95,184,56,2,97,148,195,40,45,5,217,96,165,186,69,17,252,189,244,243,138,224,111,160,144,71,140,154,72,75,87,172,163,21,171,215,211,148,233,31,211,171,175,255,139,103,15,
145,1,212,2,84,33,98,77,114,208,56,80,147,57,112,240,8,90,176,120,53,253,251,171,13,244,225,172,185,244,175,222,253,184,98,116,115,211,190,44,26,6,78,55,151,98,125,83,217,108,117,128,17,146,170,29,84,
71,216,43,35,204,196,253,53,7,6,15,113,122,17,132,137,16,183,181,5,84,126,4,5,27,5,17,68,138,146,1,197,96,44,122,45,1,181,2,75,61,34,216,135,187,10,3,58,128,155,220,190,131,121,21,7,196,204,198,239,190,
230,198,86,141,180,212,84,197,231,225,37,90,171,251,101,158,103,128,93,104,243,198,57,245,234,212,50,41,50,131,154,201,204,204,228,174,43,98,90,176,226,120,252,136,185,70,211,62,152,67,31,78,31,199,228,
117,26,205,254,116,17,187,41,62,244,197,188,79,232,222,29,211,128,99,49,187,168,132,196,116,170,234,235,197,254,79,97,157,210,104,28,176,166,160,248,88,196,175,70,32,125,54,111,49,143,25,126,52,99,34,
143,41,46,89,241,53,237,216,254,19,95,61,6,245,69,81,81,200,70,154,222,240,137,83,62,50,203,70,173,88,58,223,196,29,123,251,157,247,232,245,55,122,11,123,70,182,111,219,108,113,198,137,173,133,208,48,
24,139,150,126,197,191,72,17,24,190,15,166,142,225,49,77,17,204,14,193,236,25,41,43,151,125,65,231,206,158,22,246,204,65,44,20,159,19,238,139,86,224,86,99,197,157,176,176,99,220,5,82,203,134,1,191,26,
254,52,115,246,124,213,172,154,18,24,249,111,69,221,228,51,10,194,79,29,183,232,198,187,179,78,62,184,135,190,242,143,18,232,183,235,119,87,101,158,145,118,5,255,198,91,125,232,173,183,75,39,50,112,96,
40,38,141,27,106,177,254,45,160,86,109,250,124,254,50,222,86,1,20,216,161,3,88,60,89,59,61,122,246,162,190,253,135,242,199,40,191,130,183,32,239,91,0,165,83,187,118,254,194,94,59,164,180,202,0,125,25,
229,90,74,160,68,6,213,19,114,180,76,62,64,194,227,127,190,217,44,236,149,129,144,218,148,9,239,91,52,158,145,87,163,174,216,179,251,97,38,23,224,163,195,224,129,196,196,120,250,227,247,95,120,217,133,
120,131,145,156,200,201,206,164,105,147,71,210,208,65,239,152,25,63,128,19,99,158,106,114,74,26,102,153,112,159,27,55,95,110,252,64,204,163,123,244,254,144,190,52,106,248,0,74,73,142,199,186,251,252,120,
14,123,191,136,211,39,105,23,123,127,185,241,67,32,88,30,139,64,201,141,60,86,128,10,113,249,77,64,12,197,146,242,178,21,148,147,72,141,31,64,144,86,106,252,0,106,245,228,116,234,98,57,25,2,21,62,119,
206,135,60,238,167,21,40,52,100,234,199,142,159,78,11,191,92,195,174,79,185,24,22,96,128,153,51,107,10,157,97,238,145,90,188,68,14,20,38,138,206,135,12,27,195,21,104,219,118,157,132,103,116,254,73,208,
127,16,35,147,19,201,220,64,75,198,15,180,107,223,165,212,248,33,145,22,17,110,178,38,128,38,74,221,95,214,78,196,146,21,37,176,224,9,250,87,168,196,93,134,55,163,4,127,157,66,194,2,127,163,197,64,203,
51,225,34,104,215,150,140,31,96,247,195,25,10,48,155,41,64,77,62,13,124,244,229,171,190,165,85,43,22,242,186,51,107,32,195,155,146,150,205,110,120,30,85,175,206,70,186,188,108,42,87,206,250,140,6,168,
47,168,48,196,46,212,74,62,148,70,194,131,251,119,211,247,76,50,203,65,204,12,211,189,164,44,253,114,46,119,169,149,176,85,1,142,155,56,195,236,75,220,176,158,141,176,7,77,191,64,212,232,173,92,253,31,
42,39,201,190,194,232,76,159,60,138,15,52,214,64,130,162,217,11,173,184,241,129,59,163,150,121,149,131,44,59,62,175,181,36,14,234,202,160,168,17,107,197,253,66,50,74,43,27,55,172,227,117,130,114,208,229,
156,28,45,55,196,255,207,20,24,180,59,193,129,129,193,244,217,252,165,194,94,25,171,87,46,230,66,65,13,40,53,244,91,177,189,160,93,162,125,218,2,18,138,139,150,124,197,93,92,132,77,62,97,131,38,18,43,
43,215,152,247,9,132,157,190,251,118,13,125,48,115,46,223,199,66,40,159,206,158,206,31,203,65,153,215,252,133,43,133,189,50,16,27,156,61,115,178,176,167,14,148,35,20,164,156,45,155,254,195,11,249,45,193,
21,32,115,59,53,47,213,129,148,51,84,86,96,109,243,24,132,18,142,142,14,228,235,227,65,1,53,125,201,201,161,88,147,241,3,136,113,192,122,139,1,82,57,198,228,135,121,204,64,109,14,49,84,160,156,206,86,
148,151,86,16,46,192,50,96,82,10,11,10,40,66,193,112,23,176,227,80,90,82,140,201,144,151,132,61,203,32,99,7,53,190,120,193,28,26,55,106,16,205,152,58,154,214,174,94,74,7,152,225,71,253,164,218,136,135,
216,228,192,33,35,217,104,107,57,153,129,216,46,86,228,129,91,14,151,106,50,115,33,48,95,244,79,166,254,209,232,45,41,196,62,239,14,228,115,87,229,224,138,208,201,245,77,121,179,133,86,109,205,213,31,
202,92,46,93,82,159,127,11,164,101,36,88,0,1,43,54,217,74,104,104,91,222,86,1,226,217,0,89,230,84,214,102,228,96,121,60,169,75,123,234,164,122,173,33,6,117,37,180,76,209,131,162,109,217,202,92,61,34,148,
134,242,51,107,20,22,26,146,237,243,243,11,162,133,125,77,92,101,42,2,137,4,81,78,131,236,156,92,202,202,206,225,191,208,148,195,30,247,233,55,132,169,148,231,249,113,241,88,118,182,240,26,241,24,219,
178,178,114,248,241,140,76,83,249,142,184,23,74,85,146,146,140,201,16,57,13,27,61,111,86,111,135,56,87,7,230,218,14,25,54,218,108,171,87,191,161,240,170,50,26,55,105,198,51,170,127,23,76,87,18,39,132,
139,96,57,176,222,239,244,87,188,22,37,201,222,190,67,23,155,98,124,0,13,25,129,101,100,214,16,40,70,92,118,214,135,19,121,9,130,60,217,2,224,162,203,107,180,44,1,99,135,34,246,115,103,195,105,235,230,
13,124,196,159,54,105,36,175,217,194,180,69,57,152,78,215,212,202,212,43,157,39,7,174,98,75,5,87,17,51,116,44,205,110,130,250,67,169,152,72,120,216,9,62,88,218,2,250,122,168,96,104,208,46,196,108,50,6,
220,187,119,111,243,199,82,112,173,98,120,10,253,210,146,58,117,87,73,168,105,241,136,16,215,148,207,122,2,232,19,106,245,129,82,152,13,138,118,112,113,113,14,173,21,224,167,62,121,85,6,62,80,247,87,94,
167,203,23,207,243,149,24,192,115,141,95,160,122,245,26,240,154,59,108,45,66,91,243,233,42,80,71,88,53,34,160,86,16,191,88,108,112,221,16,35,192,230,143,125,246,122,191,154,1,20,31,23,195,207,133,231,
123,189,217,135,47,142,128,76,177,18,125,250,14,52,171,183,195,232,132,247,198,223,203,55,4,250,229,224,245,185,108,244,196,52,50,57,90,235,0,113,142,161,195,199,153,37,16,176,88,132,210,117,96,83,170,
160,71,204,14,106,87,172,109,4,56,55,190,92,140,166,210,77,105,196,21,225,203,11,93,58,207,182,115,236,51,116,48,51,204,81,81,215,77,102,131,192,165,194,245,72,207,143,184,171,90,210,4,106,3,247,43,236,
228,81,190,168,173,188,144,26,171,194,200,239,81,9,19,157,121,13,138,200,224,91,162,111,242,173,114,9,57,166,216,147,157,134,8,1,178,251,47,75,12,153,200,206,95,183,50,207,64,189,160,25,97,34,113,222,
46,60,147,53,255,254,210,106,188,80,78,117,214,215,80,1,0,67,120,255,222,109,250,99,215,175,194,51,204,53,174,82,213,172,14,23,136,2,9,125,248,208,129,191,248,99,37,176,104,72,115,102,47,228,92,188,112,
70,177,76,75,4,231,199,226,10,210,82,57,128,54,138,144,128,165,196,28,128,241,190,112,241,250,38,251,199,113,137,167,176,190,150,86,208,193,98,152,43,38,157,103,152,157,157,205,19,39,40,217,64,39,76,77,
77,165,199,143,227,120,38,57,61,61,157,31,51,110,198,231,141,175,99,155,248,28,251,95,4,231,133,130,81,11,128,138,69,210,79,3,148,161,252,157,26,55,148,138,216,186,132,148,26,93,100,51,67,48,128,76,251,
224,19,154,253,233,66,147,13,70,203,26,112,87,81,106,36,199,78,86,116,49,152,41,82,249,249,173,85,208,3,184,202,200,254,202,17,219,131,148,18,199,18,202,11,41,210,55,149,205,184,28,137,117,176,240,176,
18,152,82,169,6,140,166,116,174,247,222,61,187,204,18,115,90,64,155,16,191,219,136,211,166,161,29,181,210,22,17,204,26,178,132,218,245,88,43,85,67,172,26,94,156,156,31,190,255,134,146,147,203,166,223,
170,145,150,158,73,153,89,217,97,246,6,67,209,129,184,248,68,205,63,36,12,9,140,2,70,84,162,99,157,58,16,117,227,42,83,132,103,233,226,249,8,186,196,44,247,131,7,119,153,204,142,54,238,95,60,195,173,57,
142,139,155,241,117,17,236,111,140,251,87,34,141,197,140,144,205,72,62,32,152,142,52,182,18,168,183,179,213,93,84,195,56,141,206,252,38,106,229,105,174,48,211,160,81,99,94,238,35,98,96,131,0,202,142,228,
244,126,119,128,85,163,141,231,81,131,37,71,94,19,137,209,92,206,107,111,244,86,156,34,39,39,72,161,22,77,105,185,49,251,2,59,42,127,204,81,223,84,54,59,141,107,146,170,205,165,45,40,200,23,30,153,130,
16,209,184,137,211,185,59,10,80,16,253,36,139,13,227,239,219,180,51,22,94,163,239,203,147,146,48,192,106,177,103,132,130,46,156,83,47,241,2,15,162,239,43,214,186,54,148,205,80,146,130,121,238,24,188,229,
3,46,42,85,78,30,231,203,252,89,37,62,33,57,133,253,23,129,187,147,229,230,234,210,217,175,122,21,243,165,148,85,64,48,190,90,117,63,46,201,113,67,10,10,242,120,121,11,58,30,54,20,32,167,50,31,220,120,
204,129,156,216,49,60,150,190,6,27,92,52,28,115,118,118,226,177,177,41,211,103,83,114,82,2,173,93,179,140,199,184,228,192,45,28,54,98,188,89,7,221,182,117,19,179,252,235,120,50,192,210,230,236,226,194,
221,112,41,112,63,229,19,194,181,184,192,112,123,135,190,63,198,44,177,176,106,229,34,94,243,164,244,254,210,13,197,162,210,24,36,170,230,209,152,165,110,191,43,115,165,229,203,14,225,62,97,206,113,74,
10,150,191,79,230,1,95,17,52,8,124,62,184,6,112,183,165,192,237,249,233,199,239,76,94,143,250,49,196,31,165,224,222,98,96,67,163,196,72,10,67,44,5,239,143,41,127,98,137,131,8,138,78,145,37,55,91,23,144,
245,13,135,108,59,125,83,217,180,130,82,43,76,254,151,131,213,216,239,203,146,133,120,221,84,230,61,136,70,19,201,183,229,75,230,241,95,101,84,2,6,5,109,30,113,98,92,17,60,58,124,159,104,147,111,188,245,
110,169,208,65,217,203,238,93,59,248,99,17,212,132,194,64,42,13,154,103,35,194,173,42,64,148,219,161,47,73,23,11,1,240,244,48,37,19,182,70,10,236,14,106,145,49,227,68,10,22,129,192,10,70,90,185,114,237,
214,230,140,140,172,223,248,55,224,226,236,220,247,213,30,29,55,99,78,174,86,144,85,250,232,227,121,60,248,141,172,164,210,82,72,90,65,117,251,116,246,161,80,212,248,197,220,89,138,202,7,160,227,127,48,
243,115,97,207,8,58,232,132,113,67,173,174,122,12,96,20,62,155,103,90,70,0,67,59,99,202,232,210,217,39,64,75,25,12,2,203,253,6,12,19,246,140,64,1,161,164,69,109,68,148,130,44,246,240,145,19,132,61,35,
152,99,59,117,210,136,210,36,6,86,196,153,183,112,133,89,141,161,8,94,135,152,32,70,90,76,251,241,174,88,81,181,52,6,170,125,231,14,211,31,197,130,193,196,74,220,74,107,187,129,98,102,44,83,216,53,33,
46,136,215,122,120,122,241,105,78,242,145,23,32,51,136,248,146,206,63,3,140,208,132,201,31,10,123,101,192,0,225,167,26,96,156,96,132,224,22,194,147,130,88,0,24,240,190,90,189,132,206,200,92,87,145,186,
204,77,158,254,225,167,38,107,66,98,32,78,78,74,226,43,181,75,23,202,197,106,237,88,104,67,206,232,177,83,20,167,231,45,251,114,30,247,254,172,129,122,225,57,159,47,225,198,77,10,214,14,248,117,251,22,
46,10,208,23,16,250,194,10,73,210,107,69,31,216,186,101,3,237,219,83,54,255,216,26,73,201,169,37,127,237,59,222,134,61,12,231,250,152,221,164,40,23,23,231,254,85,124,43,105,46,252,194,141,199,242,238,
40,204,132,18,196,202,18,241,79,176,52,58,50,190,152,215,138,15,181,100,209,231,170,165,47,0,11,33,200,151,247,190,192,110,48,86,91,209,2,12,12,226,25,226,92,69,192,147,33,185,185,38,191,103,96,77,1,226,
111,134,12,31,107,114,30,128,18,18,204,192,208,2,6,140,110,221,95,229,74,88,4,13,14,11,25,196,8,65,109,52,94,156,175,121,104,27,62,183,81,14,220,19,44,151,142,242,19,15,79,79,94,103,168,196,197,243,103,
104,211,198,111,184,11,35,39,146,125,38,116,26,165,229,246,237,216,231,196,210,93,56,63,158,199,53,40,25,63,92,51,140,159,154,59,86,194,117,133,190,41,109,248,87,11,24,92,49,80,73,13,18,64,27,64,172,15,
237,26,134,15,237,86,252,142,32,10,214,172,90,194,127,26,65,9,120,47,80,138,248,129,45,41,56,14,85,38,93,133,28,137,175,223,126,221,170,56,184,99,201,45,121,60,14,57,129,77,204,43,83,106,115,114,96,196,
48,133,21,211,44,165,125,10,229,91,56,134,181,62,49,121,1,49,119,105,127,193,194,38,168,21,182,52,147,74,137,200,107,183,142,37,167,164,205,195,227,210,251,239,238,230,58,160,91,215,182,27,43,148,55,255,
33,31,75,96,201,166,17,163,38,241,27,128,116,55,38,46,171,41,56,41,40,128,68,49,115,243,22,173,216,235,31,240,204,13,226,20,106,160,3,46,91,249,13,95,109,66,10,92,78,181,209,77,137,158,175,189,85,186,
180,151,8,82,230,40,241,16,179,159,214,20,32,190,8,44,22,32,231,131,105,99,232,113,172,250,103,144,51,106,204,100,190,184,164,20,140,118,139,190,248,68,216,51,130,76,237,208,247,199,154,173,221,103,13,
52,44,148,197,96,109,68,204,5,85,3,170,241,189,65,195,249,96,38,42,7,45,160,113,67,249,253,176,97,157,217,50,71,34,121,206,229,105,87,219,25,194,158,142,20,59,102,76,122,157,88,64,78,6,235,139,244,2,184,
133,99,39,206,224,21,23,150,64,6,20,63,90,133,190,8,67,164,6,140,38,138,248,45,1,15,3,117,160,136,203,171,25,51,132,114,22,44,94,197,75,110,68,224,142,34,38,103,11,16,0,175,244,124,147,215,45,202,197,
133,8,50,217,88,116,21,153,101,204,146,210,98,96,165,36,36,166,20,31,56,124,170,83,81,81,49,207,226,73,7,32,135,224,32,255,131,173,90,52,233,168,52,202,91,2,157,6,147,153,223,122,187,47,87,11,72,95,195,
162,35,67,148,196,92,75,124,33,88,93,6,101,22,40,114,134,234,67,137,7,234,151,80,173,13,227,146,159,111,185,17,32,235,211,243,181,55,133,61,35,88,130,107,201,162,207,184,26,213,10,70,187,113,19,166,155,
41,25,44,91,37,102,180,172,253,42,28,50,107,40,245,145,146,192,20,29,150,244,183,5,188,135,220,24,179,47,134,207,180,65,118,92,10,174,23,107,192,33,9,4,67,136,206,160,100,172,96,244,48,144,92,56,23,65,
199,142,30,176,41,52,225,207,6,165,14,157,94,226,223,143,79,229,202,102,241,77,128,144,65,82,98,34,175,6,192,249,45,41,118,96,112,112,166,27,254,101,43,130,232,148,97,199,180,113,253,232,99,228,80,172,
49,19,194,192,119,142,239,31,63,187,128,34,98,168,114,44,57,151,153,153,206,87,98,190,197,60,149,235,87,47,19,22,38,182,6,92,78,249,170,210,34,80,122,168,206,64,105,147,90,89,148,20,76,142,232,250,82,
15,170,224,225,193,60,165,75,22,13,166,53,32,114,2,3,131,152,183,23,192,207,7,48,192,162,238,245,222,189,219,148,147,173,190,198,161,37,224,81,29,61,113,246,251,152,216,248,193,194,33,51,5,30,220,186,
229,243,103,130,107,251,219,246,59,124,2,72,50,160,88,19,170,6,42,73,172,67,195,205,20,13,14,46,226,225,195,251,116,58,236,4,255,1,21,165,12,144,142,101,112,47,17,143,131,59,132,184,15,220,32,36,52,96,
52,49,98,91,171,129,210,2,206,139,206,81,158,185,66,248,30,97,88,241,93,225,252,106,106,79,71,231,89,38,242,74,212,253,139,145,55,16,240,70,6,152,99,38,245,220,92,93,222,236,208,174,249,54,223,202,149,
254,214,106,1,144,195,198,17,198,135,89,116,39,62,138,100,102,100,240,73,202,122,7,210,209,209,249,111,18,253,32,54,251,100,248,133,46,76,128,153,172,220,171,232,235,122,120,148,31,223,174,117,179,149,
149,42,122,41,62,175,163,163,163,243,127,133,216,199,9,5,204,248,189,147,151,151,111,182,58,130,162,202,203,207,47,136,72,72,76,78,246,242,242,232,86,190,156,187,246,168,184,142,142,142,206,51,196,131,
135,177,57,225,17,151,250,42,25,63,160,234,230,194,8,198,60,78,184,236,236,236,244,114,69,111,79,55,49,134,167,163,163,163,243,172,131,4,204,213,235,183,31,158,189,112,245,245,130,130,66,229,95,107,103,
88,140,243,25,12,69,55,99,98,19,182,101,103,231,52,242,244,168,80,27,139,154,234,232,232,232,60,203,36,37,167,149,68,156,139,220,26,117,235,254,155,197,197,37,22,215,213,210,42,235,236,93,93,93,122,215,
9,10,248,52,40,176,102,253,10,21,108,171,21,212,209,209,209,249,167,73,77,77,47,185,115,239,225,153,219,119,31,124,92,88,104,216,47,28,182,136,173,126,173,163,147,147,227,171,1,254,213,135,249,86,174,
212,181,170,175,143,171,187,187,242,236,0,29,29,29,157,127,18,148,215,101,102,101,83,92,124,82,102,124,66,242,31,15,30,62,254,150,185,190,152,171,167,97,129,49,35,127,199,114,121,50,187,215,190,82,69,
239,150,222,94,30,33,76,33,214,112,112,112,192,49,84,207,234,22,81,71,71,231,105,195,108,94,73,161,193,80,148,154,155,151,255,32,37,37,237,106,106,90,6,126,155,3,83,193,158,160,248,149,232,127,1,196,140,
25,241,201,170,195,253,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* AiassAudioProcessorEditor::typenschild_a_png = (const char*) resource_AiassAudioProcessorEditor_typenschild_a_png;
const int AiassAudioProcessorEditor::typenschild_a_pngSize = 11020;


//[EndFile] You can add extra defines here...
//[/EndFile]

