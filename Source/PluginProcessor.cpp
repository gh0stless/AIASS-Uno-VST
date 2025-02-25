/*
  ==============================================================================

	AIASS-Mono VST by gh0stless for www.crazy-midi.de Start: Oct. 2017

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Sid.h"


	//==============================================================================
	AiassAudioProcessor::AiassAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
		 : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
			.withInput("Input", AudioChannelSet::stereo(), true)
#endif
			.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
		)
#endif
		
		,parameters(*this, nullptr)
	{
		using Parameter = AudioProcessorValueTreeState::Parameter;
		
		parameters.createAndAddParameter(std::make_unique<Parameter>("SidVol",       // parameterID
			"SIDVolume",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			15.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("VelVol",       // parameterID
			"Velocity",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("AttAck1",       // parameterID
			"Attack1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			1.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("AttAck2",       // parameterID
			"Attack2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			1.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("AttAck3",       // parameterID
			"Attack3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			1.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("DeCay1",       // parameterID
			"Decay1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			7.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("DeCay2",       // parameterID
			"Decay2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			7.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("DeCay3",       // parameterID
			"Decay3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			7.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SuStain1",       // parameterID
			"Sustain1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			7.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SuStain2",       // parameterID
			"Sustain2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			7.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SuStain3",       // parameterID
			"Sustain3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			7.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("ReLease1",       // parameterID
			"Release1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			7.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("ReLease2",       // parameterID
			"Release2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			7.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("ReLease3",       // parameterID
			"Release3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			7.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("PulsW1",       // parameterID
			"Pulswith1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(1.0f, 4094.0f, 1.0f),    // range
			1024.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("PulsW2",       // parameterID
			"Pulswith2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(1.0f, 4094.0f, 1.0f),    // range
			1024.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("PulsW3",       // parameterID
			"Pulswith3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(1.0f, 4094.0f, 1.0f),    // range
			1024.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("VoiCe1",       // parameterID
			"Voice1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			1.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("VoiCe2",       // parameterID
			"Voice2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			1.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("VoiCe3",       // parameterID
			"Voice3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			1.0f,         // default value
			[](float value)
			{
				// value to text function
				return value < 0.5 ? "Off" : "On";
			},
			[](const String& text)
			{
				// text to value function
				if (text == "Off") return 0.0f;
				if (text == "On")  return 1.0f;
				return 0.0f;
			}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("OcTave1",       // parameterID
			"Octave1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-4.0f, 4.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("OcTave2",       // parameterID
			"Octave2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-4.0f, 4.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("OcTave3",       // parameterID
			"Octave3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-4.0f, 4.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SeMi1",       // parameterID
			"Semitone1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-12.0f, 12.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SeMi2",       // parameterID
			"Semitone2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-12.0f, 12.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SeMi3",       // parameterID
			"Semitone3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-12.0f, 12.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("CenT1",       // parameterID
			"Cent1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-100.0f, 100.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("CenT2",       // parameterID
			"Cent2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-100.0f, 100.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("CenT3",       // parameterID
			"Cent3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-100.0f, 100.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("NoiSe1",       // parameterID
			"Noise1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("NoiSe2",       // parameterID
			"Noise2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("NoiSe3",       // parameterID
			"Noise3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("PulSe1",       // parameterID
			"Pulse1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			1.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("PulSe2",       // parameterID
			"Pulse2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			1.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("PulSe3",       // parameterID
			"Pulse3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			1.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SaW1",       // parameterID
			"Saw1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SaW2",       // parameterID
			"Saw2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SaW3",       // parameterID
			"Saw3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("TriA1",       // parameterID
			"Tria1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("TriA2",       // parameterID
			"Tria2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("TriA3",       // parameterID
			"Tria3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("RingMod1",       // parameterID
			"Ringmod1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("RingMod2",       // parameterID
			"Ringmod2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("RingMod3",       // parameterID
			"Ringmod3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SynC1",      // parameterID
			"Sync1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SynC2",      // parameterID
			"Sync2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("SynC3",      // parameterID
			"Sync3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));
		
		parameters.createAndAddParameter(std::make_unique<Parameter>("FilterFreq",       // parameterID
			"Cutoff",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 2047.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));
		
		parameters.createAndAddParameter(std::make_unique<Parameter>("ResoNance",       // parameterID
			"Resonance",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 15.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("FilterScale",       // parameterID
			"Filterscale",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("FilTer1",       // parameterID
			"Filter1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("FilTer2",       // parameterID
			"Filter2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("FilTer3",       // parameterID
			"Filter3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("FilTerIn",       // parameterID
			"FilterIn",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("FilTerLP",       // parameterID
			"LowPass",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("FilTerBP",       // parameterID
			"BandPass",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("FilTerHP",       // parameterID
			"HighPass",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("FilTer3OFF",       // parameterID
			"3OFF",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
		{
			// value to text function
			return value < 0.5 ? "Off" : "On";
		},
			[](const String& text)
		{
			// text to value function
			if (text == "Off") return 0.0f;
			if (text == "On")  return 1.0f;
			return 0.0f;
		}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("LegatoMode",       // parameterID
			"Legatomode",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 2.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("NotePriorityMode",       // parameterID
			"Notepriority",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 2.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("MidiChannel",       // parameterID
			"Midichannel",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 16.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("LinkButton",       // parameterID
			"Linkbutton",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
			{
				// value to text function
				return value < 0.5 ? "Off" : "On";
			},
			[](const String& text)
			{
				// text to value function
				if (text == "Off") return 0.0f;
				if (text == "On")  return 1.0f;
				return 0.0f;
			}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("ResetButton",       // parameterID
			"ReSetbutton",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
			{
				// value to text function
				return value < 0.5 ? "Off" : "On";
			},
			[](const String& text)
			{
				// text to value function
				if (text == "Off") return 0.0f;
				if (text == "On")  return 1.0f;
				return 0.0f;
			}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("PitchBender",       // parameterID
			"Pitchbender",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-8191.0f, 8191.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));

		parameters.createAndAddParameter(std::make_unique<Parameter>("InitButton",       // parameterID
			"InItbutton",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
			{
				// value to text function
				return value < 0.5 ? "Off" : "On";
			},
			[](const String& text)
			{
				// text to value function
				if (text == "Off") return 0.0f;
				if (text == "On")  return 1.0f;
				return 0.0f;
			}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("BeNd1",       // parameterID
			"Bend1",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			1.0f,         // default value
			[](float value)
			{
				// value to text function
				return value < 0.5 ? "Off" : "On";
			},
			[](const String& text)
			{
				// text to value function
				if (text == "Off") return 0.0f;
				if (text == "On")  return 1.0f;
				return 0.0f;
			}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("BeNd2",       // parameterID
			"Bend2",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			1.0f,         // default value
			[](float value)
			{
				// value to text function
				return value < 0.5 ? "Off" : "On";
			},
			[](const String& text)
			{
				// text to value function
				if (text == "Off") return 0.0f;
				if (text == "On")  return 1.0f;
				return 0.0f;
			}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("BeNd3",       // parameterID
			"Bend3",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			1.0f,         // default value
			[](float value)
			{
				// value to text function
				return value < 0.5 ? "Off" : "On";
			},
			[](const String& text)
			{
				// text to value function
				if (text == "Off") return 0.0f;
				if (text == "On")  return 1.0f;
				return 0.0f;
			}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("ModeButton",       // parameterID
			"Modebutton",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(0.0f, 1.0f, 1.0f),    // range
			0.0f,         // default value
			[](float value)
			{
				// value to text function
				return value < 0.5 ? "Off" : "On";
			},
			[](const String& text)
			{
				// text to value function
				if (text == "Off") return 0.0f;
				if (text == "On")  return 1.0f;
				return 0.0f;
			}));

		parameters.createAndAddParameter(std::make_unique<Parameter>("TuNe",       // parameterID
			"Tune",       // parameter name
			String(),     // parameter label (suffix)
			NormalisableRange<float>(-100.0f, 100.0f, 1.0f),    // range
			0.0f,         // default value
			nullptr,
			nullptr));
		
		parameters.state = ValueTree(Identifier("AIASS"));

		parameters.addParameterListener("SidVol", this);		//0
		parameters.addParameterListener("VelVol", this);
		parameters.addParameterListener("AttAck1", this);
		parameters.addParameterListener("AttAck2", this);
		parameters.addParameterListener("AttAck3", this);
		parameters.addParameterListener("DeCay1", this);
		parameters.addParameterListener("DeCay2", this);
		parameters.addParameterListener("DeCay3", this);
		parameters.addParameterListener("SuStain1", this);
		parameters.addParameterListener("SuStain2", this);
		parameters.addParameterListener("SuStain3", this);		//10
		parameters.addParameterListener("ReLease1", this);
		parameters.addParameterListener("ReLease2", this);
		parameters.addParameterListener("ReLease3", this);
		parameters.addParameterListener("PulsW1", this);
		parameters.addParameterListener("PulsW2", this);
		parameters.addParameterListener("PulsW3", this);
		parameters.addParameterListener("VoiCe1", this);
		parameters.addParameterListener("VoiCe2", this);
		parameters.addParameterListener("VoiCe3", this);
		parameters.addParameterListener("OcTave1", this);		//20
		parameters.addParameterListener("OcTave2", this);
		parameters.addParameterListener("OcTave3", this);
		parameters.addParameterListener("SeMi1", this);
		parameters.addParameterListener("SeMi2", this);
		parameters.addParameterListener("SeMi3", this);
		parameters.addParameterListener("CenT1", this);
		parameters.addParameterListener("CenT2", this);
		parameters.addParameterListener("CenT3", this);
		parameters.addParameterListener("NoiSe1", this);
		parameters.addParameterListener("NoiSe2", this);		//30
		parameters.addParameterListener("NoiSe3", this);
		parameters.addParameterListener("PulSe1", this);
		parameters.addParameterListener("PulSe2", this);
		parameters.addParameterListener("PulSe3", this);
		parameters.addParameterListener("SaW1", this);
		parameters.addParameterListener("SaW2", this);
		parameters.addParameterListener("SaW3", this);
		parameters.addParameterListener("TriA1", this);
		parameters.addParameterListener("TriA2", this);
		parameters.addParameterListener("TriA3", this);			//40
		parameters.addParameterListener("RingMod1", this);
		parameters.addParameterListener("RingMod2", this);
		parameters.addParameterListener("RingMod3", this);
		parameters.addParameterListener("SynC1", this);
		parameters.addParameterListener("SynC2", this);
		parameters.addParameterListener("SynC3", this);
		parameters.addParameterListener("FilterFreq", this);
		parameters.addParameterListener("ResoNance", this);
		parameters.addParameterListener("FilterScale", this);
		parameters.addParameterListener("FilTer1", this);		//50
		parameters.addParameterListener("FilTer2", this);
		parameters.addParameterListener("FilTer3", this);
		parameters.addParameterListener("FilTerIn", this);
		parameters.addParameterListener("FilTerLP", this);
		parameters.addParameterListener("FilTerBP", this);
		parameters.addParameterListener("FilTerHP", this);
		parameters.addParameterListener("FilTer3OFF", this);
		parameters.addParameterListener("LegatoMode", this);
		parameters.addParameterListener("NotePriorityMode", this);
		parameters.addParameterListener("MidiChannel", this);	//60
		parameters.addParameterListener("LinkButton",this);
		parameters.addParameterListener("ResetButton", this);
		parameters.addParameterListener("PitchBender", this);
		parameters.addParameterListener("InitButton", this);
		parameters.addParameterListener("BeNd1", this);		//65
		parameters.addParameterListener("BeNd2", this);
		parameters.addParameterListener("BeNd3", this);
		parameters.addParameterListener("ModeButton", this);
		parameters.addParameterListener("TuNe", this);

		sid = new Sid();

		if (!sid->GetErrorState()) sid->startPlayerThread();

		sid->init();
		
		sid->set_volume(15);
		sid->set_a(1, 1);
		sid->set_d(1, 7);
		sid->set_s(1, 7);
		sid->set_r(1, 7);
		sid->set_a(2, 1);
		sid->set_d(2, 7);
		sid->set_s(2, 7);
		sid->set_r(2, 7);
		sid->set_a(3, 1);
		sid->set_d(3, 7);
		sid->set_s(3, 7);
		sid->set_r(3, 7);
		sid->set_pulsw(1, 1024);
		sid->set_pulsw(2, 1024);
		sid->set_pulsw(3, 1024);

		setWaveformStatus(1, 3, true);
		setWaveformStatus(2, 3, true);
		setWaveformStatus(3, 3, true);

		SIDSTATE.ensureStorageAllocated(3);
	}

	AiassAudioProcessor::~AiassAudioProcessor()
	{
		sid->init();
		if (!sid->GetErrorState()) sid->stopPlayerThread();
		delete sid;
	}

	//==============================================================================
	const String AiassAudioProcessor::getName() const
	{
		return JucePlugin_Name;
	}

	bool AiassAudioProcessor::acceptsMidi() const
	{
#if JucePlugin_WantsMidiInput
		return true;
#else
		return false;
#endif
	}

	bool AiassAudioProcessor::producesMidi() const
	{
#if JucePlugin_ProducesMidiOutput
		return true;
#else
		return false;
#endif
	}

	bool AiassAudioProcessor::isMidiEffect() const
	{
#if JucePlugin_IsMidiEffect
		return true;
#else
		return false;
#endif
	}

	double AiassAudioProcessor::getTailLengthSeconds() const
	{
		return 0.0;
	}

	int AiassAudioProcessor::getNumPrograms()
	{
		return 3;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
					// so this should be at least 1, even if you're not really implementing programs.
	}

	int AiassAudioProcessor::getCurrentProgram()
	{
		return MyProgram;
	}

	void AiassAudioProcessor::setCurrentProgram(int index)
	{
		//Value SIDVolume = parameters.getParameterAsValue("SidVol");
		switch (index) {
		case 0:	//SIDVolume = 15.0f;
			parameters.replaceState(ValueTree(Identifier("AIASS")));
			MyProgram = 0;
			break;
		case 1: //SIDVolume = 7.0f;
			parameters.replaceState(ValueTree(Identifier("AIASS")));
			MyProgram = 1;
			break;
		case 2: //SIDVolume = 1.0f;
			parameters.replaceState(ValueTree(Identifier("AIASS")));
			MyProgram = 2;
			break;
		}
	}

	const String AiassAudioProcessor::getProgramName(int index)
	{
		switch (index) {
		case 0:	return { "init 1" };
				break;
		case 1:	return { "init 2" };
				break;
		case 2:	return { "init 3" };
				break;
		default: return {};
		}
	}

	void AiassAudioProcessor::changeProgramName(int index, const String& newName)
	{
	}

	//==============================================================================
	void AiassAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
	{
		// Use this method as the place to do any pre-playback
		// initialisation that you need..
		keyboardState.reset();

	}

	void AiassAudioProcessor::releaseResources()
	{
		// When playback stops, you can use this as an opportunity to free up any
		// spare memory, etc.
	}

#ifndef JucePlugin_PreferredChannelConfigurations
	bool AiassAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
	{
#if JucePlugin_IsMidiEffect
		ignoreUnused(layouts);
		return true;
#else
		// This is the place where you check if the layout is supported.
		// In this template code we only support mono or stereo.
		if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
			&& layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
			return false;

		// This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
		if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
			return false;
#endif

		return true;
#endif
	}
#endif

	void AiassAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
	{
		ScopedNoDenormals noDenormals;
		const int totalNumInputChannels = getTotalNumInputChannels();
		const int totalNumOutputChannels = getTotalNumOutputChannels();

		// In case we have more outputs than inputs, this code clears any output
		// channels that didn't contain input data, (because these aren't
		// guaranteed to be empty - they may contain garbage).
		// This is here to avoid people getting screaming feedback
		// when they first compile a plugin, but obviously you don't need to keep
		// this code if your algorithm always overwrites all the output channels.
		for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
			buffer.clear(i, 0, buffer.getNumSamples());

		// This is the place where you'd normally do the guts of your plugin's
		// audio processing...
		for (int channel = 0; channel < totalNumInputChannels; ++channel)
		{
			//float* channelData = buffer.getWritePointer(channel);

			// ..do something to the data...
		}

		buffer.clear();

		auto numSamples = buffer.getNumSamples();
		// Now pass any incoming midi messages to our keyboard state object, and let it
		// add messages to the buffer if the user is clicking on the on-screen keys	
		keyboardState.processNextMidiBuffer(midiMessages, 0, numSamples, true);
		
		for (auto meta : midiMessages)
		{
			auto m = meta.getMessage();

			if (m.isNoteOn())
			{	
				if ((m.getChannel()) == MIDICHANNEL || (MIDICHANNEL == 0))
				{
					if (MODE == false) //MONO Mode
					{
						int lowestNote = 127;
						int highestNote = 0;
						MidiMessage MIDImsgWithLowestNote;
						MidiMessage MIDImsgWithHighestNote;
						heldNotesList.add(m);  //add held notes to a Juce Array so we can use for note memory, arpeggiator or other 
						for (int j = 0; j < heldNotesList.size(); ++j)
						{
							if (heldNotesList[j].getNoteNumber() < lowestNote) {
								lowestNote = heldNotesList[j].getNoteNumber();
								MIDImsgWithLowestNote = heldNotesList[j];
							}
							if (heldNotesList[j].getNoteNumber() > highestNote) {
								highestNote = heldNotesList[j].getNoteNumber();
								MIDImsgWithHighestNote = heldNotesList[j];
							}
						}
						if (heldNotesList.size() == 1)
						{
							isPlaying = m;
							noteOn(m, true, 0);
						}
						else
						{
							switch (NOTEPRIORITYMODE)
							{
							case LastNote:
								switch (LEGATOMODE)
								{
								case Retrigger:
									noteOff(isPlaying,0);
									isPlaying = m;
									noteOn(m, true, 0);
									break;
								case Legato:
									isPlaying = m;
									noteOn(m, false, 0);
									break;
								case LastStep:
									isPlaying = m;
									noteOn(m, false, 0);
									break;
								}
								break;
							case LowNote:
								switch (LEGATOMODE)
								{
								case Retrigger:
									if (lowestNote >= m.getNoteNumber())
									{
										noteOff(isPlaying,0);
										isPlaying = MIDImsgWithLowestNote;
										noteOn(MIDImsgWithLowestNote, true, 0);
									}
									break;
								case Legato:
									if (lowestNote >= m.getNoteNumber())
									{
										isPlaying = MIDImsgWithLowestNote;
										noteOn(MIDImsgWithLowestNote, false, 0);
									}
									break;
								case LastStep:
									if (lowestNote >= m.getNoteNumber())
									{
										isPlaying = MIDImsgWithLowestNote;
										noteOn(MIDImsgWithLowestNote, false,0);
									}
									break;
								}
								break;
							case HighNote:
								switch (LEGATOMODE)
								{
								case Retrigger:
									if (highestNote <= m.getNoteNumber())
									{
										noteOff(isPlaying,0);
										isPlaying = MIDImsgWithHighestNote;
										noteOn(MIDImsgWithHighestNote, true, 0);
									}
									break;
								case Legato:
									if (highestNote <= m.getNoteNumber())
									{
										isPlaying = MIDImsgWithHighestNote;
										noteOn(MIDImsgWithHighestNote, false,0);
									}
									break;
								case LastStep:
									if (highestNote <= m.getNoteNumber())
									{
										isPlaying = MIDImsgWithHighestNote;
										noteOn(MIDImsgWithHighestNote, false, 0);
									}
									break;
								}
								break;
							}
						}
					}
					else{
						//Poly Mode
						SIDStateVoice mySIDSTATUS;
						if (SIDSTATE.size() == 0) {
							noteOn(m, true, 1);
							mySIDSTATUS.PlayingNote = m;
							mySIDSTATUS.VoiceNo = 1;
							SIDSTATE.add(mySIDSTATUS);
						}
						else {
							if (SIDSTATE.size() >= 3) {
								noteOff(SIDSTATE.getFirst().PlayingNote, SIDSTATE.getFirst().VoiceNo);
								SIDSTATE.removeAndReturn(0);
							}
							int freeVoice = 0;
							bool Spielt[3]{ false, false, false };
							for (int i = 0; i < SIDSTATE.size(); i++) {
								if (SIDSTATE[i].VoiceNo == 1)  Spielt[0] = true;
								if (SIDSTATE[i].VoiceNo == 2)  Spielt[1] = true;
								if (SIDSTATE[i].VoiceNo == 3)  Spielt[2] = true;
							}
							for (int i = 0; i < 3; i++) {
								if (!Spielt[i]) {
									freeVoice = i + 1;
									break;
								}
							}
							noteOn(m, true, freeVoice);
							mySIDSTATUS.PlayingNote = m;
							mySIDSTATUS.VoiceNo = freeVoice;
							SIDSTATE.add(mySIDSTATUS);
						}
					}
				}
			}
			else if (m.isNoteOff())
			{
				if ((m.getChannel()) == MIDICHANNEL || (MIDICHANNEL == 0))
				{	
					if (MODE == false) { //MONO Mode
						int lowestNote = 127;
						int highestNote = 0;
						MidiMessage MIDImsgWithLowestNote;
						MidiMessage MIDImsgWithHighestNote;
						for (int j = 0; j < heldNotesList.size(); ++j)
						{
							if (heldNotesList[j].getNoteNumber() < lowestNote) {
								lowestNote = heldNotesList[j].getNoteNumber();
								MIDImsgWithLowestNote = heldNotesList[j];
							}
							if (heldNotesList[j].getNoteNumber() > highestNote) {
								highestNote = heldNotesList[j].getNoteNumber();
								MIDImsgWithHighestNote = heldNotesList[j];
							}
						}
						const int noteNumberToRemove = m.getNoteNumber();
						for (int j = 0; j < heldNotesList.size(); ++j)
						{
							if (heldNotesList[j].getNoteNumber() == noteNumberToRemove)
							{
								if (heldNotesList.size() == 1)
								{
									noteOff(j,0);
									//isPlaying = NULL;
									heldNotesList.remove(j);
								}
								if (heldNotesList.size() > 1)
								{
									switch (NOTEPRIORITYMODE)
									{
									case LastNote:
										switch (LEGATOMODE)
										{
										case Retrigger:
											noteOff(m,0);
											heldNotesList.remove(j);
											noteOn(heldNotesList.getLast(), true, 0);
											isPlaying = heldNotesList.getLast();
											break;
										case Legato:
											//noteOff(m);
											heldNotesList.remove(j);
											noteOn(heldNotesList.getLast(), true, 0);
											isPlaying = heldNotesList.getLast();
											break;
										case LastStep:
											heldNotesList.remove(j);
											noteOn(heldNotesList.getLast(), false, 0);
											isPlaying = heldNotesList.getLast();
											break;
										}
										break;
									case LowNote:
										switch (LEGATOMODE)
										{
										case Retrigger:
											noteOff(isPlaying,0);
											heldNotesList.remove(j);
											noteOn(MIDImsgWithLowestNote, true, 0);
											isPlaying = MIDImsgWithLowestNote;
											break;
										case Legato:
											//noteOff(isPlaying);
											heldNotesList.remove(j);
											noteOn(MIDImsgWithLowestNote, true, 0);
											isPlaying = MIDImsgWithLowestNote;
											break;
										case LastStep:
											heldNotesList.remove(j);
											noteOn(MIDImsgWithLowestNote, false, 0);
											isPlaying = MIDImsgWithLowestNote;
											break;

										}
										break;
									case HighNote:
										switch (LEGATOMODE)
										{
										case Retrigger:
											noteOff(isPlaying,0);
											heldNotesList.remove(j);
											noteOn(MIDImsgWithHighestNote, true, 0);
											isPlaying = MIDImsgWithHighestNote;
											break;
										case Legato:
											//noteOff(isPlaying);
											heldNotesList.remove(j);
											noteOn(MIDImsgWithHighestNote, true, 0);
											isPlaying = MIDImsgWithHighestNote;
											break;
										case LastStep:
											heldNotesList.remove(j);
											noteOn(MIDImsgWithHighestNote, false, 0);
											isPlaying = MIDImsgWithHighestNote;
											break;
										}
										break;
									}
								}
								break;
							}
						}
					}
					else {
						//POLY Mode
						if (!SIDSTATE.isEmpty()) {
							for (int i = 0; i < SIDSTATE.size(); i++){
								if (SIDSTATE[i].PlayingNote.getNoteNumber() == m.getNoteNumber()) {
									noteOff(SIDSTATE.getUnchecked(i).PlayingNote, SIDSTATE.getUnchecked(i).VoiceNo);
									SIDSTATE.removeAndReturn(i);
									break;
								}
							}	
						}
					}
				}
			}
			else if (m.isAftertouch())
			{
			}
			else if (m.isPitchWheel())
			{
				if ((m.getChannel()) == MIDICHANNEL || (MIDICHANNEL == 0))
				{
					float CCBend = (float)(m.getPitchWheelValue());
					if ((m.getPitchWheelValue() >= (8191+100)) || (m.getPitchWheelValue() <= (8191 - 100))) MIDIBENDACTIVE = true;
					else  MIDIBENDACTIVE = false;
					float newBend = (CCBend - 8192);
					parameterChanged("PitchBender", newBend);
					float newGUIBend = 0;
					if (newBend == 0) newGUIBend = 0.5f;
					else newGUIBend = ((float)CCBend) * (1.0f / 16383.0f);
					sendParamChangeMessageToListeners(63, newGUIBend);
				}
			}

			else if (m.isController())
			{
				if ((m.getChannel()) == MIDICHANNEL || (MIDICHANNEL == 0))
				{
					if (m.getControllerNumber() == 7) //Volume
					{
						int CCVolume = m.getControllerValue();
						float newVolume = ((float)CCVolume) * (15.0f / 127.0f);
						parameterChanged("SidVol", newVolume);
						float newGUIVolume = ((float)CCVolume) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(0, newGUIVolume);
					}
					if (m.getControllerNumber() == 74) //Filterfrq.
					{
						int CCFilterFreq = m.getControllerValue();
						float newFilterFreq = ((float)CCFilterFreq) * (2047.0f / 127.0f);
						parameterChanged("FilterFreq", newFilterFreq);
						float newGUIFilterFreq = ((float)CCFilterFreq) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(47, newGUIFilterFreq);
					}
					if (m.getControllerNumber() == 71) //Resonance
					{
						int CCFilterRes = m.getControllerValue();
						float newFilterRes = ((float)CCFilterRes) * (15.0f / 127.0f);
						parameterChanged("ResoNance", newFilterRes);
						float newGUIFilterRes = ((float)CCFilterRes) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(48, newGUIFilterRes);
					}
					if (m.getControllerNumber() == 73) //Attack1
					{
						int CCAttack1 = m.getControllerValue();
						float newAttack1 = ((float)CCAttack1) * (15.0f / 127.0f);
						parameterChanged("AttAck1", newAttack1);
						float newGUIAttack1 = ((float)CCAttack1) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(2, newGUIAttack1);
					}
					if (m.getControllerNumber() == 75) //Decay1
					{
						int CCDecay1 = m.getControllerValue();
						float newDecay1 = ((float)CCDecay1) * (15.0f / 127.0f);
						parameterChanged("DeCay1", newDecay1);
						float newGUIDecay1 = ((float)CCDecay1) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(5, newGUIDecay1);
					}
					if (m.getControllerNumber() == 76) //Sustain1
					{
						int CCSustain1 = m.getControllerValue();
						float newSustain1 = ((float)CCSustain1) * (15.0f / 127.0f);
						parameterChanged("SuStain", newSustain1);
						float newGUISustain1 = ((float)CCSustain1) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(8, newGUISustain1);
					}
					if (m.getControllerNumber() == 72) //Release1
					{
						int CCRelease1 = m.getControllerValue();
						float newRelease1 = ((float)CCRelease1) * (15.0f / 127.0f);
						parameterChanged("ReLease1", newRelease1);
						float newGUIRelease1 = ((float)CCRelease1) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(11, newGUIRelease1);
					}
					if (m.getControllerNumber() == 77) //Pulsew1
					{
						int CCPulsew1 = m.getControllerValue();
						float newPulsew1 = ((float)CCPulsew1) * (4094.0f / 127.0f);
						parameterChanged("PulsW1", newPulsew1);
						float newGUIPulsew1 = ((float)CCPulsew1) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(14, newGUIPulsew1);
					}
					if (!LINK) {
						if (m.getControllerNumber() == 20) //Attack2
						{
							int CCAttack2 = m.getControllerValue();
							float newAttack2 = ((float)CCAttack2) * (15.0f / 127.0f);
							parameterChanged("AttAck2", newAttack2);
							float newGUIAttack2 = ((float)CCAttack2) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(3, newGUIAttack2);
						}
						if (m.getControllerNumber() == 21) //Decay2
						{
							int CCDecay2 = m.getControllerValue();
							float newDecay2 = ((float)CCDecay2) * (15.0f / 127.0f);
							parameterChanged("DeCay2", newDecay2);
							float newGUIDecay2 = ((float)CCDecay2) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(6, newGUIDecay2);
						}
						if (m.getControllerNumber() == 22) //Sustain2
						{
							int CCSustain2 = m.getControllerValue();
							float newSustain2 = ((float)CCSustain2) * (15.0f / 127.0f);
							parameterChanged("SuStain2", newSustain2);
							float newGUISustain2 = ((float)CCSustain2) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(9, newGUISustain2);
						}
						if (m.getControllerNumber() == 23) //Release2
						{
							int CCRelease2 = m.getControllerValue();
							float newRelease2 = ((float)CCRelease2) * (15.0f / 127.0f);
							parameterChanged("ReLease2", newRelease2);
							float newGUIRelease2 = ((float)CCRelease2) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(12, newGUIRelease2);
						}
						if (m.getControllerNumber() == 24) //Pulsew2
						{
							int CCPulsew2 = m.getControllerValue();
							float newPulsew2 = ((float)CCPulsew2) * (4094.0f / 127.0f);
							parameterChanged("PulsW2", newPulsew2);
							float newGUIPulsew2 = ((float)CCPulsew2) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(15, newGUIPulsew2);
						}
						if (m.getControllerNumber() == 25) //Attack3
						{
							int CCAttack3 = m.getControllerValue();
							float newAttack3 = ((float)CCAttack3) * (15.0f / 127.0f);
							parameterChanged("AttAck3", newAttack3);
							float newGUIAttack3 = ((float)CCAttack3) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(4, newGUIAttack3);
						}
						if (m.getControllerNumber() == 26) //Decay3
						{
							int CCDecay3 = m.getControllerValue();
							float newDecay3 = ((float)CCDecay3) * (15.0f / 127.0f);
							parameterChanged("DeCay3", newDecay3);
							float newGUIDecay3 = ((float)CCDecay3) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(7, newGUIDecay3);
						}
						if (m.getControllerNumber() == 27) //Sustain3
						{
							int CCSustain3 = m.getControllerValue();
							float newSustain3 = ((float)CCSustain3) * (15.0f / 127.0f);
							parameterChanged("SuStain3", newSustain3);
							float newGUISustain3 = ((float)CCSustain3) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(10, newGUISustain3);
						}
						if (m.getControllerNumber() == 28) //Release3
						{
							int CCRelease3 = m.getControllerValue();
							float newRelease3 = ((float)CCRelease3) * (15.0f / 127.0f);
							parameterChanged("ReLease3", newRelease3);
							float newGUIRelease3 = ((float)CCRelease3) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(13, newGUIRelease3);
						}
						if (m.getControllerNumber() == 29) //Pulsew3
						{
							int CCPulsew3 = m.getControllerValue();
							float newPulsew3 = ((float)CCPulsew3) * (4094.0f / 127.0f);
							parameterChanged("PulsW3", newPulsew3);
							float newGUIPulsew3 = ((float)CCPulsew3) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(16, newGUIPulsew3);
						}
					}
					if (m.getControllerNumber() == 78) //Octave1
					{
						int CCOctave1 = m.getControllerValue();
						float newOctave1 = -4.00 + ((float)CCOctave1) * ((4.0f - -4.0f) / 127.0f);
						parameterChanged("OcTave1", newOctave1);
						float newGUIOctave1 = ((float)CCOctave1) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(20, newGUIOctave1);
					}
					if (m.getControllerNumber() == 79) //Semi1
					{
						int CCSemi1 = m.getControllerValue();
						float newSemi1 = -12 + ((float)CCSemi1) * ((12.0f - -12.0f) / 127.0f);
						parameterChanged("SeMi1", newSemi1);
						float newGUISemi1 = ((float)CCSemi1) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(23, newGUISemi1);
					}
					if (m.getControllerNumber() == 70) //Cent1
					{
						int CCCent1 = m.getControllerValue();
						float newCent1 = ((float)CCCent1) * ((100.0f - -100.0f) / 127.0f);
						parameterChanged("CenT1", newCent1);
						float newGUICent1 = ((float)CCCent1) * (1.0f / 127.0f);
						sendParamChangeMessageToListeners(26, newGUICent1);
					}
					if (!LINK) {
						if (m.getControllerNumber() == 85) //Octave2
						{
							int CCOctave2 = m.getControllerValue();
							float newOctave2 = -4.00 + ((float)CCOctave2) * ((4.0f - -4.0f) / 127.0f);
							parameterChanged("OcTave2", newOctave2);
							float newGUIOctave2 = ((float)CCOctave2) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(21, newGUIOctave2);
						}
						if (m.getControllerNumber() == 86) //Semi2
						{
							int CCSemi2 = m.getControllerValue();
							float newSemi2 = -12 + ((float)CCSemi2) * ((12.0f - -12.0f) / 127.0f);
							parameterChanged("SeMi2", newSemi2);
							float newGUISemi2 = ((float)CCSemi2) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(24, newGUISemi2);
						}
						if (m.getControllerNumber() == 87) //Cent2
						{
							int CCCent2 = m.getControllerValue();
							float newCent2 = ((float)CCCent2) * ((100.0f - -100.0f) / 127.0f);
							parameterChanged("CenT2", newCent2);
							float newGUICent2 = ((float)CCCent2) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(27, newGUICent2);
						}
						if (m.getControllerNumber() == 88) //Octave3
						{
							int CCOctave3 = m.getControllerValue();
							float newOctave3 = -4.00 + ((float)CCOctave3) * ((4.0f - -4.0f) / 127.0f);
							parameterChanged("OcTave3", newOctave3);
							float newGUIOctave3 = ((float)CCOctave3) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(22, newGUIOctave3);
						}
						if (m.getControllerNumber() == 89) //Semi3
						{
							int CCSemi3 = m.getControllerValue();
							float newSemi3 = -12 + ((float)CCSemi3) * ((12.0f - -12.0f) / 127.0f);
							parameterChanged("SeMi3", newSemi3);
							float newGUISemi3 = ((float)CCSemi3) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(25, newGUISemi3);
						}
						if (m.getControllerNumber() == 90) //Cent3
						{
							int CCCent3 = m.getControllerValue();
							float newCent3 = ((float)CCCent3) * ((100.0f - -100.0f) / 127.0f);
							parameterChanged("CenT3", newCent3);
							float newGUICent3 = ((float)CCCent3) * (1.0f / 127.0f);
							sendParamChangeMessageToListeners(28, newGUICent3);
						}
					}
				}
			}
		}
	}

	//==============================================================================
	bool AiassAudioProcessor::hasEditor() const
	{
		return true; // (change this to false if you choose to not supply an editor)
	}

	AudioProcessorEditor* AiassAudioProcessor::createEditor()
	{
		return new AiassAudioProcessorEditor(*this, parameters);

	}

	//==============================================================================
	void AiassAudioProcessor::getStateInformation(MemoryBlock& destData)
	{
		// You should use this method to store your parameters in the memory block.
		// You could do that either as raw data, or use the XML or ValueTree classes
		// as intermediaries to make it easy to save and load complex data.
		std::unique_ptr<XmlElement> xml(parameters.state.createXml());
		copyXmlToBinary(*xml, destData);
	}

	void AiassAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
	{
		// You should use this method to restore your parameters from this memory block,
		// whose contents will have been created by the getStateInformation() call.
		std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

		if (xmlState != nullptr)
			if (xmlState->hasTagName(parameters.state.getType()))
				parameters.state = ValueTree::fromXml(*xmlState);
	}

	void AiassAudioProcessor::parameterChanged(const String& parameterID, float newValue)
	{
		if (parameterID == "SidVol")
		{
			SIDVOL = (int)newValue;
			sid->set_volume((Uint8)newValue);
		}
		else if (parameterID == "AttAck1")
		{
			ATTACK1 = (int)newValue;
			sid->set_a(1, (Uint8)newValue);
		}
		else if (parameterID == "AttAck2")
		{
			ATTACK2 = (int)newValue;
			sid->set_a(2, (Uint8)newValue);
		}
		else if (parameterID == "AttAck3")
		{
			ATTACK3 = (int)newValue;
			sid->set_a(3, (Uint8)newValue);
		}
		else if (parameterID == "DeCay1")
		{
			DECAY1 = (int)newValue;
			sid->set_d(1, (Uint8)newValue);
		}
		else if (parameterID == "DeCay2")
		{
			DECAY2 = (int)newValue;
			sid->set_d(2, (Uint8)newValue);
		}
		else if (parameterID == "DeCay3")
		{
			DECAY3 = (int)newValue;
			sid->set_d(3, (Uint8)newValue);
		}
		else if (parameterID == "SuStain1")
		{
			SUSTAIN1 = (int)newValue;
			sid->set_s(1, (Uint8)newValue);
		}
		else if (parameterID == "SuStain2")
		{
			SUSTAIN2 = (int)newValue;
			sid->set_s(2, (Uint8)newValue);
		}
		else if (parameterID == "SuStain3")
		{
			SUSTAIN3 = (int)newValue;
			sid->set_s(3, (Uint8)newValue);
		}
		else if (parameterID == "ReLease1")
		{
			RELEASE1 = (int)newValue;
			sid->set_r(1, (Uint8)newValue);
		}
		else if (parameterID == "ReLease2")
		{
			RELEASE2 = (int)newValue;
			sid->set_r(2, (Uint8)newValue);
		}
		else if (parameterID == "ReLease3")
		{
			RELEASE3 = (int)newValue;
			sid->set_r(3, (Uint8)newValue);
		}
		else if (parameterID == "PulsW1")
		{
			PULSEW1 = (int)newValue;
			sid->set_pulsw(1, (Uint16)newValue);
		}
		else if (parameterID == "PulsW2")
		{
			PULSEW2 = (int)newValue;
			sid->set_pulsw(2, (Uint16)newValue);
		}
		else if (parameterID == "PulsW3")
		{
			PULSEW3 = (int)newValue;
			sid->set_pulsw(3, (Uint16)newValue);
		}
		else if (parameterID == "VoiCe1")
		{
			if (newValue == 0) VOICE1 = false;
			else VOICE1 = true;
		}
		else if (parameterID == "VoiCe2")
		{
			if (newValue == 0) VOICE2 = false;
			else VOICE2 = true;
		}
		else if (parameterID == "VoiCe3")
		{
			if (newValue == 0) VOICE3 = false;
			else VOICE3 = true;
		}
		else if (parameterID == "OcTave1")
		{
			OCTAVE1 = (int)newValue;
		}
		else if (parameterID == "OcTave2")
		{
			OCTAVE2 = (int)newValue;
		}
		else if (parameterID == "OcTave3")
		{
			OCTAVE3 = (int)newValue;
		}
		else if (parameterID == "SeMi1")
		{
			SEMI1 = (int)newValue;
		}
		else if (parameterID == "SeMi2")
		{
			SEMI2 = (int)newValue;
		}
		else if (parameterID == "SeMi3")
		{
			SEMI3 = (int)newValue;
		}
		else if (parameterID == "CenT1")
		{
			CENT1 = newValue;
		}
		else if (parameterID == "CenT2")
		{
			CENT2 = newValue;
		}
		else if (parameterID == "CenT3")
		{
			CENT3 = newValue;
		}
		else if (parameterID == "NoiSe1")
		{
			if (newValue == 0) setWaveformStatus(1, 4, false);
			else               setWaveformStatus(1, 4, true);
		}
		else if (parameterID == "NoiSe2")
		{
			if (newValue == 0) setWaveformStatus(2, 4, false);
			else               setWaveformStatus(2, 4, true);
		}
		else if (parameterID == "NoiSe3")
		{
			if (newValue == 0) setWaveformStatus(3, 4, false);
			else               setWaveformStatus(3, 4, true);
		}
		else if (parameterID == "PulSe1")
		{
			if (newValue == 0) setWaveformStatus(1, 3, false);
			else               setWaveformStatus(1, 3, true);
		}
		else if (parameterID == "PulSe2")
		{
			if (newValue == 0) setWaveformStatus(2, 3, false);
			else               setWaveformStatus(2, 3, true);
		}
		else if (parameterID == "PulSe3")
		{
			if (newValue == 0) setWaveformStatus(3, 3, false);
			else               setWaveformStatus(3, 3, true);
		}
		else if (parameterID == "SaW1")
		{
			if (newValue == 0) setWaveformStatus(1, 2, false);
			else               setWaveformStatus(1, 2, true);
		}
		else if (parameterID == "SaW2")
		{
			if (newValue == 0) setWaveformStatus(2, 2, false);
			else               setWaveformStatus(2, 2, true);
		}
		else if (parameterID == "SaW3")
		{
			if (newValue == 0) setWaveformStatus(3, 2, false);
			else               setWaveformStatus(3, 2, true);
		}
		else if (parameterID == "TriA1")
		{
			if (newValue == 0) setWaveformStatus(1, 1, false);
			else               setWaveformStatus(1, 1, true);
		}
		else if (parameterID == "TriA2")
		{
			if (newValue == 0) setWaveformStatus(2, 1, false);
			else               setWaveformStatus(2, 1, true);
		}
		else if (parameterID == "TriA3")
		{
			if (newValue == 0) setWaveformStatus(3, 1, false);
			else               setWaveformStatus(3, 1, true);
		}
		else if (parameterID == "RingMod1")
		{
			if (newValue == 0) RINGMOD1 = false;
			else               RINGMOD1 = true;
			sid->set_ringmod(1, RINGMOD1);
		}
		else if (parameterID == "RingMod2")
		{
			if (newValue == 0) RINGMOD2 = false;
			else               RINGMOD2 = true;
			sid->set_ringmod(2, RINGMOD2);
		}
		else if (parameterID == "RingMod3")
		{
			if (newValue == 0) RINGMOD3 = false;
			else               RINGMOD3 = true;
			sid->set_ringmod(3, RINGMOD3);
		}
		else if (parameterID == "SynC1")
		{
			if (newValue == 0) SYNC1 = false;
			else               SYNC1 = true;
					sid->set_sync(1, SYNC1);
		}
		else if (parameterID == "SynC2")
		{
			if (newValue == 0) SYNC2 = false;
			else               SYNC2 = true;
			sid->set_sync(2, SYNC2);
		}
		else if (parameterID == "SynC3")
		{
			if (newValue == 0) SYNC3 = false;
			else               SYNC3 = true;
			sid->set_sync(3, SYNC3);
		}
		else if (parameterID == "FilterFreq")
		{
			if (!FILTERSCALE) {
				FILTERFREQ = (int)newValue;
			}
			else { //scale
				FILTERFREQ = ((int)(newValue * (71.0f / 2047.0f)));
			}
			sid->set_filterfreq((Uint16)FILTERFREQ);
		}
		else if (parameterID == "ResoNance")
		{
			sid->set_filterres((Uint8)newValue);
			FILTERRES = (int)newValue;
		}
		else if (parameterID == "FilterScale")
		{
			if (newValue == 0) FILTERSCALE = false;
			else FILTERSCALE = true;
		}
		else if (parameterID == "FilTer1")
		{
			if (newValue == 0) FILTER1 = false;
			else               FILTER1 = true;
			setFilterStatus(1, FILTER1);
		}
		else if (parameterID == "FilTer2")
		{
			if (newValue == 0) FILTER2 = false;
			else               FILTER2 = true;
			setFilterStatus(2, FILTER2);
		}
		else if (parameterID == "FilTer3")
		{
			if (newValue == 0) FILTER3 = false;
			else               FILTER3 = true;
			setFilterStatus(3, FILTER3);
		}
		else if (parameterID == "FilTerIn")
		{
			if (newValue == 0) FILTERIN = false;
			else               FILTERIN = true;
			setFilterStatus(4, FILTERIN);
		}
		else if (parameterID == "FilTerLP")
		{
			if (newValue == 0) LOWPASS = false;
			else			   LOWPASS = true;
			setFilterMode(1, LOWPASS);
		}
		else if (parameterID == "FilTerBP")
		{
			if (newValue == 0) BANDPASS = false;
			else			   BANDPASS = true;
			setFilterMode(2, BANDPASS);
		}
		else if (parameterID == "FilTerHP")
		{
			if (newValue == 0) HIGHPASS = false;
			else			   HIGHPASS = true;
			setFilterMode(3, HIGHPASS);
		}
		else if (parameterID == "FilTer3OFF")
		{
			if (newValue == 0) F3OFF = false;
			else			   F3OFF = true;
			setFilterMode(4, F3OFF);
		}
		else if (parameterID == "VelVol")
		{
			if (newValue == 0) VELVOL = false;
			else VELVOL = true;
		}
		else if (parameterID == "LegatoMode")
		{
			LEGATOMODE = (PlayModes)(int)newValue;
		}
		else if (parameterID == "NotePriorityMode")
		{
			NOTEPRIORITYMODE = (PriorityModes)(int)newValue;
		}
		else if (parameterID == "MidiChannel")
		{
			MIDICHANNEL = (int)newValue;
		}
		else if (parameterID == "LinkButton")
		{
			LINK = (bool)newValue;
		}
		else if (parameterID == "ResetButton")
		{
			RESET = (bool)newValue;
			
			sid->init();
			
			sid->set_volume((Uint8)SIDVOL);
			
			sid->set_a(1, (Uint8)ATTACK1);
			sid->set_d(1, (Uint8)DECAY1);
			sid->set_s(1, (Uint8)SUSTAIN1);
			sid->set_r(1, (Uint8)RELEASE1);
			sid->set_a(2, (Uint8)ATTACK2);
			sid->set_d(2, (Uint8)DECAY2);
			sid->set_s(2, (Uint8)SUSTAIN2);
			sid->set_r(2, (Uint8)RELEASE2);
			sid->set_a(3, (Uint8)ATTACK3);
			sid->set_d(3, (Uint8)DECAY3);
			sid->set_s(3, (Uint8)SUSTAIN3);
			sid->set_r(3, (Uint8)RELEASE3);
			
			sid->set_pulsw(1, (Uint16)PULSEW1);
			sid->set_pulsw(2, (Uint16)PULSEW2);
			sid->set_pulsw(3, (Uint16)PULSEW3);

			setWaveformStatus(1, 1, TRIA1);
			setWaveformStatus(2, 1, TRIA2);
			setWaveformStatus(3, 1, TRIA3);
			setWaveformStatus(1, 2, SAW1);
			setWaveformStatus(2, 2, SAW2);
			setWaveformStatus(3, 2, SAW3);
			setWaveformStatus(1, 3, PULSE1);
			setWaveformStatus(2, 3, PULSE2);
			setWaveformStatus(3, 3, PULSE3);
			setWaveformStatus(1, 4, NOISE1);
			setWaveformStatus(2, 4, NOISE2);
			setWaveformStatus(3, 4, NOISE3);

			sid->set_ringmod(1, RINGMOD1);
			sid->set_ringmod(2, RINGMOD2);
			sid->set_ringmod(3, RINGMOD3);
			sid->set_sync(1, SYNC1);
			sid->set_sync(2, SYNC2);
			sid->set_sync(3, SYNC3);

			sid->set_filterfreq((Uint16)FILTERFREQ);
			sid->set_filterres((Uint8)FILTERRES);
			setFilterStatus(1, FILTER1);
			setFilterStatus(2, FILTER2);
			setFilterStatus(3, FILTER3);
			setFilterStatus(4, FILTERIN);

			setFilterMode(1, LOWPASS);
			setFilterMode(2, BANDPASS);
			setFilterMode(3, HIGHPASS);
			setFilterMode(4, F3OFF);
		}
		else if (parameterID == "InitButton")
		{
			INIT = (bool)newValue;
			parameters.replaceState(ValueTree(Identifier("AIASS")));
			SIDSTATE.clearQuick();
			heldNotesList.clearQuick();
		}
		else if (parameterID == "PitchBender")
		{
			PITCHBEND = newValue;
			handlepitch(false);
		}
		else if (parameterID == "BeNd1")
		{
			BEND1 = (bool)newValue;
		}
		else if (parameterID == "BeNd2")
		{
			BEND2 = (bool)newValue;
		}
		else if (parameterID == "BeNd3")
		{
			BEND3 = (bool)newValue;
		}
		else if (parameterID == "ModeButton")
		{
		MODE = (bool)newValue;
		SIDSTATE.clearQuick();
		heldNotesList.clearQuick();
		sid->stop(1);
		sid->stop(2);
		sid->stop(3);
		}
		else if (parameterID == "TuNe")
		{
		TUNE = newValue;
		}

	}

	void AiassAudioProcessor::setWaveformStatus(Uint8 Voice, Uint8 Waveform, bool State)
	{
		Uint8 Waveformnibble = 0;

		switch (Voice)
		{
		case 1:
			switch (Waveform)
			{
			case 1: //Tria
				TRIA1 = State;
				break;
			case 2: //Saw
				SAW1 = State;
				break;
			case 3: //Pulse
				PULSE1 = State;
				break;
			case 4: //Noise
				NOISE1 = State;
				break;
			default:
				break;
			}
			//Hier nibble berechnen
			Waveformnibble = 0;
			if (NOISE1) Waveformnibble = 1;
			Waveformnibble = Waveformnibble << 1;
			if (PULSE1) Waveformnibble = Waveformnibble | 0b00000001;
			Waveformnibble = Waveformnibble << 1;
			if (SAW1) Waveformnibble = Waveformnibble | 0b00000001;
			Waveformnibble = Waveformnibble << 1;
			if (TRIA1) Waveformnibble = Waveformnibble | 0b00000001;
			break;
		case 2:
			switch (Waveform)
			{
			case 1: //Tria
				TRIA2 = State;
				break;
			case 2: //Saw
				SAW2 = State;
				break;
			case 3: //Pulse
				PULSE2 = State;
				break;
			case 4: //Noise
				NOISE2 = State;
				break;
			default:
				break;
			}
			//Hier nibble berechnen
			Waveformnibble = 0;
			if (NOISE2) Waveformnibble = 1;
			Waveformnibble = Waveformnibble << 1;
			if (PULSE2) Waveformnibble = Waveformnibble | 0b00000001;
			Waveformnibble = Waveformnibble << 1;
			if (SAW2) Waveformnibble = Waveformnibble | 0b00000001;
			Waveformnibble = Waveformnibble << 1;
			if (TRIA2) Waveformnibble = Waveformnibble | 0b00000001;
			break;
		case 3:
			switch (Waveform)
			{
			case 1: //Tria
				TRIA3 = State;
				break;
			case 2: //Saw
				SAW3 = State;
				break;
			case 3: //Pulse
				PULSE3 = State;
				break;
			case 4: //Noise
				NOISE3 = State;
				break;
			default:
				break;
			}
			//Hier nibble berechnen
			Waveformnibble = 0;
			if (NOISE3) Waveformnibble = 1;
			Waveformnibble = Waveformnibble << 1;
			if (PULSE3) Waveformnibble = Waveformnibble | 0b00000001;
			Waveformnibble = Waveformnibble << 1;
			if (SAW3) Waveformnibble = Waveformnibble | 0b00000001;
			Waveformnibble = Waveformnibble << 1;
			if (TRIA3) Waveformnibble = Waveformnibble | 0b00000001;
			break;
		default:
			break;
		}
		
		sid->set_waveform(Voice, Waveformnibble);
	}

	void AiassAudioProcessor::setFilterStatus(Uint8 FilterStatusBit, bool State)
	{
		Uint8 Statusnibble = 0;
		
		switch (FilterStatusBit)
		{
		case 1: 
			FILTER1 = State;
			break;
		case 2: 
			FILTER2 = State;
			break;
		case 3: 
			FILTER3 = State;
			break;
		case 4: 
			FILTERIN = State;
			break;
		default:
			break;
		}
		//Hier nibble berechnen
		Statusnibble = 0;
		if (FILTERIN) Statusnibble = 1;
		Statusnibble = Statusnibble << 1;
		if (FILTER3) Statusnibble = Statusnibble | 0b00000001;
		Statusnibble = Statusnibble << 1;
		if (FILTER2) Statusnibble = Statusnibble | 0b00000001;
		Statusnibble = Statusnibble << 1;
		if (FILTER1) Statusnibble = Statusnibble | 0b00000001;
		
		sid->set_filterfilt(Statusnibble);
	}

	void AiassAudioProcessor::setFilterMode(Uint8 FilterModeBit, bool State)
	{
		Uint8 Modenibble = 0;

			switch (FilterModeBit)
			{
			case 1: 
				LOWPASS = State;
				break;
			case 2:
				BANDPASS = State;
				break;
			case 3:
				HIGHPASS = State;
				break;
			case 4:
				F3OFF = State;
				break;
			default:
				break;
			}
			//Hier nibble berechnen
			Modenibble = 0;
			if (F3OFF) Modenibble = 1;
			Modenibble = Modenibble << 1;
			if (HIGHPASS) Modenibble = Modenibble | 0b00000001;
			Modenibble = Modenibble << 1;
			if (BANDPASS) Modenibble = Modenibble | 0b00000001;
			Modenibble = Modenibble << 1;
			if (LOWPASS) Modenibble = Modenibble | 0b00000001;

			sid->set_filtermode(Modenibble);
	}

	void AiassAudioProcessor::noteOn(MidiMessage mm, bool triggernote, int VoiceNo)
	{
		LED = true;
		Value SIDVolume = parameters.getParameterAsValue("SidVol");

		int MyNote = mm.getNoteNumber();
		int MyVel = mm.getVelocity();
		int MyNote1, MyNote2, MyNote3;
		if (VELVOL) {
			SIDVolume = (float)(MyVel * (15.0f / 127.0f));
		}
		
		if (MODE) { //Polymode
			switch (VoiceNo) {
				case 1:	
					LED1 = true;
					MyNote1 = (MyNote + (OCTAVE1 * 12)) + SEMI1;
					MyFreq1 = mm.getMidiNoteInHertz(MyNote1, 440.0);
					MyFreq1 = MyFreq1 * pow(2, ((CENT1 + TUNE) / 1200.0));
					newFreq1 = MyFreq1;
					if (BEND1 && (PITCHBEND != 0)) newFreq1 = scaleInterval(PITCHBEND, -8191.0f, 8191.0f, MyFreq1 / 2.0f, MyFreq1 * 2.0f);
					sid->set_freq(1, (float)newFreq1);
					sid->play(1);
				break;
				case 2:
					LED2 = true;
					MyNote2 = (MyNote + (OCTAVE2 * 12)) + SEMI2;
					MyFreq2 = mm.getMidiNoteInHertz(MyNote2, 440.0);
					MyFreq2 = MyFreq2 * pow(2, ((CENT2 + TUNE) / 1200.0));
					newFreq2 = MyFreq2;
					if (BEND2 && (PITCHBEND != 0)) newFreq2 = scaleInterval(PITCHBEND, -8191.0f, 8191.0f, MyFreq2 / 2.0f, MyFreq2 * 2.0f);
					sid->set_freq(2, (float)newFreq2);
					sid->play(2);
				break;
				case 3:
					LED3 = true;
					MyNote3 = (MyNote + (OCTAVE3 * 12)) + SEMI3;
					MyFreq3 = mm.getMidiNoteInHertz(MyNote3, 440.0);
					MyFreq3 = MyFreq3 * pow(2, ((CENT3 + TUNE) / 1200.0));
					newFreq3 = MyFreq3;
					if (BEND3 && (PITCHBEND != 0)) newFreq3 = scaleInterval(PITCHBEND, -8191.0f, 8191.0f, MyFreq3 / 2.0f, MyFreq3 * 2.0f);
					sid->set_freq(3, (float)newFreq3);
					sid->play(3);
				break;
			}
		}
		else { //Mono Mode
			

			MyNote1 = (MyNote + (OCTAVE1 * 12)) + SEMI1;
			MyFreq1 = mm.getMidiNoteInHertz(MyNote1, 440.0);
			MyFreq1 = MyFreq1 * pow(2, ((CENT1 + TUNE) / 1200.0));

			MyNote2 = (MyNote + (OCTAVE2 * 12)) + SEMI2;
			MyFreq2 = mm.getMidiNoteInHertz(MyNote2, 440.0);
			MyFreq2 = MyFreq2 * pow(2, ((CENT2 + TUNE) / 1200.0));

			MyNote3 = (MyNote + (OCTAVE3 * 12)) + SEMI3;
			MyFreq3 = mm.getMidiNoteInHertz(MyNote3, 440.0);
			MyFreq3 = MyFreq3 * pow(2, ((CENT3 + TUNE) / 1200.0));

			handlepitch(true);
			
			if (VOICE1)
			{
				
				sid->set_freq(1, (float)newFreq1);
				if (triggernote)
				{
					LED1 = true;
					//if (V1isPlaying) sid->stop(1);
					sid->play(1);
				}
				V1isPlaying = true;
			}

			if (VOICE2)
			{
				
				sid->set_freq(2, (float)newFreq2);
				if (triggernote)
				{
					LED2 = true;
					//if (V2isPlaying) sid->stop(2);
					sid->play(2);
				}
				V2isPlaying = true;
			}
			if (VOICE3)
			{
				LED3 = true;
				sid->set_freq(3, (float)newFreq3);
				if (triggernote)
				{
					LED3 = true;
					//if (V3isPlaying) sid->stop(3);
					sid->play(3);
				}
				V3isPlaying = true;
			}
		}
	}

	void AiassAudioProcessor::noteOff(MidiMessage mm,int VoiceNo)
	{
		LED = false;
		if (MODE) {
			switch (VoiceNo) {
			case 1:
				LED1 = false;
				sid->stop(1);
				break;
			case 2:
				LED2 = false;
				sid->stop(2);
				break;
			case 3:
				LED3 = false;
				sid->stop(3);
				break;
			}
		}
		else
		{
			
			if (VOICE1)
			{
				LED1 = false;
				sid->stop(1);
				V1isPlaying = false;
			}
			else
			{
				if (V1isPlaying)
				{
					LED1 = false;
					sid->stop(1);
					V1isPlaying = false;
				}
			}
			if (VOICE2)
			{
				LED2 = false;
				sid->stop(2);
				V2isPlaying = false;
			}
			else
			{
				if (V2isPlaying)
				{
					LED2 = false;
					sid->stop(2);
					V2isPlaying = false;
				}
			}
			if (VOICE3)
			{
				LED3 = false;
				sid->stop(3);
				V3isPlaying = false;
			}
			else
			{
				if (V3isPlaying)
				{
					LED3 = false;
					sid->stop(3);
					V3isPlaying = false;
				}
			}
		}
	}

	void AiassAudioProcessor::handlepitch(bool newnote)
	{
		newFreq1 = MyFreq1;
		newFreq2 = MyFreq2;
		newFreq3 = MyFreq3;

		if (BEND1 && (PITCHBEND != 0)) newFreq1 = scaleInterval(PITCHBEND, -8191.0f, 8191.0f, MyFreq1 / 2.0f, MyFreq1 * 2.0f);
		if (BEND2 && (PITCHBEND != 0)) newFreq2 = scaleInterval(PITCHBEND, -8191.0f, 8191.0f, MyFreq2 / 2.0f, MyFreq2 * 2.0f);
		if (BEND3 && (PITCHBEND != 0)) newFreq3 = scaleInterval(PITCHBEND, -8191.0f, 8191.0f, MyFreq3 / 2.0f, MyFreq3 * 2.0f);

		if (!newnote) {
			if (VOICE1) sid->set_freq(1, newFreq1);
			if (VOICE2) sid->set_freq(2, newFreq2);
			if (VOICE3) sid->set_freq(3, newFreq3);
		}
	}

	float AiassAudioProcessor::scaleInterval(float  Wert,	float minActualInterval, float maxActualInterval,	float minDesiredInterval, float maxDesiredInterval)
	{
		return ((Wert - minActualInterval) / (maxActualInterval - minActualInterval)) * (maxDesiredInterval - minDesiredInterval) + minDesiredInterval;
	}

	//==============================================================================
	// This creates new instances of the plugin..
	AudioProcessor* JUCE_CALLTYPE createPluginFilter()
	{
		return new AiassAudioProcessor();
	}
