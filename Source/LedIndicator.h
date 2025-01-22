/*
  ==============================================================================

    LedIndicator.h
    Created: 22 Oct 2024 10:28:42am
    Author:  Andreas Schumm (gh0stless)

  ==============================================================================
*/
#pragma once

#include <JuceHeader.h>

class LedIndicator : public juce::Component, public juce::Timer
{
public:
    LedIndicator() {
        // Lade die Bilder aus den Ressourcen (im Projucer eingebunden)
        ledOffImage = juce::ImageFileFormat::loadFrom(BinaryData::redledoff_png, BinaryData::redledoff_pngSize);
        ledOnImage = juce::ImageFileFormat::loadFrom(BinaryData::redledon_png, BinaryData::redledon_pngSize);
    }
    ~LedIndicator() override {}

    // Setzt den Zustand der LED und aktualisiert die Anzeige
    void setOn(bool state)
    {
        std::scoped_lock lock(stateMutex);
        isOn = state;
        repaint();
    }

    // Setzt den Blinkzustand der LED
    void setBlinkingRed(bool state)
    {
        std::scoped_lock lock(stateMutex);
        isBlinking = state;
        blinkColour = juce::Colours::red;
        if (state)
            startTimer(500); // Timer starten
        else
            stopTimer(); // Timer stoppen
    }

    // Überschreibt die paint-Methode, um die LED als Bild anzuzeigen
    void paint(juce::Graphics& g) override
    {
        auto bounds = getLocalBounds().toFloat();

        std::scoped_lock lock(stateMutex);
        if (isOn && ledOnImage.isValid()) {
            g.drawImage(ledOnImage, bounds);  // Zeichnet das „LED an“-Bild
        }
        else if (!isOn && ledOffImage.isValid()) {
            g.drawImage(ledOffImage, bounds);  // Zeichnet das „LED aus“-Bild
        }
    }

    // Timer-Callback für das Blinken
    void timerCallback() override
    {
        setOn(!isOn); // Zustand der LED umschalten
    }

    // Getter für den Blinkzustand (threadsicher)
    bool isBlinkingState() const
    {
        std::scoped_lock lock(stateMutex);
        return isBlinking;
    }

    // Getter für den Zustand der LED (threadsicher)
    bool isOnState() const
    {
        std::scoped_lock lock(stateMutex);
        return isOn;
    }

private:

    juce::Image ledOffImage;
    juce::Image ledOnImage;
    bool isOn = false;         // Status der LED
    bool isBlinking = false;   // Blinkzustand der LED
    juce::Colour blinkColour;  // Farbe der blinkenden LED (rot oder grün)
    mutable std::mutex stateMutex; // Mutex für die threadsichere Verarbeitung
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LedIndicator)
};
