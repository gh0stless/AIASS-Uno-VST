/*
  ==============================================================================

    SIDBlasterClient.cpp
    Created: 31 Jan 2025 5:52:47pm
    Author:  andre

  ==============================================================================
*/

#include "SIDBlasterClient.h"
#include <iostream>

SIDBlasterClient::SIDBlasterClient() {}

SIDBlasterClient::~SIDBlasterClient() {
    disconnect();
}

bool SIDBlasterClient::connectToServer() {
    return connectToSocket("127.0.0.1", 12345, 1000);
}

void SIDBlasterClient::sendMessageToServer(const juce::String& message) {
    sendMessage(message.toRawUTF8(), message.getNumBytesAsUTF8());
}

void SIDBlasterClient::connectionMade() {
    std::cout << "Connected to SIDBlaster Server" << std::endl;
}

void SIDBlasterClient::connectionLost() {
    std::cout << "Lost connection to SIDBlaster Server" << std::endl;
}

void SIDBlasterClient::messageReceived(const juce::MemoryBlock& message) {
    std::cout << "Received from Server: " << message.toString() << std::endl;
}