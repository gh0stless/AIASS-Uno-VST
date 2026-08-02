/*
  ==============================================================================

    SIDBlasterServer.cpp
    Created: 31 Jan 2025 5:51:51pm
    Author:  andre

  ==============================================================================
*/

#include "SIDBlasterServer.h"
#include <iostream>

SIDBlasterConnection::SIDBlasterConnection(int deviceID, Sid& sidInstance)
    : deviceID(deviceID), sidInstance(sidInstance) {
}

void SIDBlasterConnection::messageReceived(const juce::MemoryBlock& message) {
    juce::String receivedMessage = message.toString();
    std::cout << "Received: " << receivedMessage << std::endl;

    auto tokens = juce::StringArray::fromTokens(receivedMessage, " ", "");
    if (tokens.size() < 2) return;

    juce::String command = tokens[0];

    if (command == "set_freq" && tokens.size() == 3) {
        float freq = tokens[2].getFloatValue();
        sidInstance.set_freq(deviceID, freq);
    }
    else if (command == "set_volume" && tokens.size() == 2) {
        int volume = tokens[1].getIntValue();
        sidInstance.set_volume(volume);
    }
    else if (command == "set_waveform" && tokens.size() == 3) {
        int waveform = tokens[2].getIntValue();
        sidInstance.set_waveform(deviceID, waveform);
    }
    else if (command == "push_event" && tokens.size() == 3) {
        int reg = tokens[1].getIntValue();
        int val = tokens[2].getIntValue();
        sidInstance.push_event(reg, val);
    }
}

void SIDBlasterConnection::connectionMade() {
    std::cout << "Client connected for device " << deviceID << std::endl;
}

void SIDBlasterConnection::connectionLost() {
    std::cout << "Client disconnected from device " << deviceID << std::endl;
}

SIDBlasterServer::SIDBlasterServer() {
    int deviceCount = sidInstance.GetNoOfDevices();
    availableDevices.resize(deviceCount, true);
}

SIDBlasterServer::~SIDBlasterServer() {
    stopServer();
}

bool SIDBlasterServer::startServer() {
    return beginWaitingForSocket(12345);
}

void SIDBlasterServer::stopServer() {
    stop();
}

juce::InterprocessConnection* SIDBlasterServer::createConnectionObject() {
    for (int i = 0; i < availableDevices.size(); ++i) {
        if (availableDevices[i]) {
            availableDevices[i] = false;
            auto* connection = new SIDBlasterConnection(i, sidInstance);
            clientDeviceMap[connection] = i;
            return connection;
        }
    }
    return nullptr; // Keine freien Geräte verfügbar
}

void SIDBlasterServer::connectionClosed(juce::InterprocessConnection* connection) {
    if (clientDeviceMap.find(connection) != clientDeviceMap.end()) {
        int deviceID = clientDeviceMap[connection];
        availableDevices[deviceID] = true;
        clientDeviceMap.erase(connection);
    }
}

