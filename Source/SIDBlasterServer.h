/*
  ==============================================================================

    SIDBlasterServer.h
    Created: 31 Jan 2025 5:51:22pm
    Author:  andre

  ==============================================================================
*/

#pragma once

#include <juce_core/juce_core.h>
#include <juce_events/juce_events.h>
#include "Sid.h"
#include <vector>
#include <map>

class SIDBlasterConnection : public juce::InterprocessConnection {
public:
    SIDBlasterConnection(int deviceID, Sid& sidInstance);
    void messageReceived(const juce::MemoryBlock& message) override;
    void connectionMade() override;
    void connectionLost() override;
    int deviceID;
private:
    Sid& sidInstance;
};

class SIDBlasterServer : public juce::InterprocessConnectionServer
{
public:
    SIDBlasterServer();
    ~SIDBlasterServer() override;
    bool startServer();
    void stopServer();
    juce::InterprocessConnection* createConnectionObject() override;
    void connectionClosed(juce::InterprocessConnection* connection);

private:
    Sid sidInstance;
    std::vector<bool> availableDevices;
    std::map<juce::InterprocessConnection*, int> clientDeviceMap;
};