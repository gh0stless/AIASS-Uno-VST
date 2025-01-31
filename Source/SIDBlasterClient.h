/*
  ==============================================================================

    SIDBlasterClient.h
    Created: 31 Jan 2025 5:52:26pm
    Author:  andre

  ==============================================================================
*/

#pragma once

#include <juce_core/juce_core.h>
#include <juce_events/juce_events.h>
#include <juce_data_structures/juce_data_structures.h>
#include <juce_audio_processors/juce_audio_processors.h>
#include "Sid.h"
#include <vector>
#include <map>

class SIDBlasterClient : public juce::InterprocessConnection
{
public:
    SIDBlasterClient();
    ~SIDBlasterClient() override;
    bool connectToServer();
    void sendMessageToServer(const juce::String& message);
    void connectionMade() override;
    void connectionLost() override;
    void messageReceived(const juce::MemoryBlock& message) override;
};