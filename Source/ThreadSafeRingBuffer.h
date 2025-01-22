/*
  ==============================================================================

    ThreadSafeRingBuffer.h
    Created: 22 Oct 2024 10:28:42am
    Author:  andre

  ==============================================================================
*/
#include <JuceHeader.h>

template <typename T, int BufferSize>
class ThreadSafeRingBuffer {
public:
    ThreadSafeRingBuffer() : head(0), tail(0) {}

    // F�ge ein neues Element zum Ringpuffer hinzu
    void add(const T& value) {
        juce::ScopedLock lock(mutex); // Sperrt den Zugriff w�hrend der add-Operation

        buffer[head] = value;
        head = (head + 1) % BufferSize;

        // Wenn head den tail �berschreibt, bewegt sich der tail-Zeiger weiter
        if (head == tail) {
            tail = (tail + 1) % BufferSize;
        }
    }

    // Entferne ein Element aus dem Ringpuffer
    bool remove(T& value) {
        juce::ScopedLock lock(mutex); // Sperrt den Zugriff w�hrend der remove-Operation
        if (head == tail) { // Direkte Pr�fung, ob der Puffer leer ist
            return false;
        }

        value = buffer[tail];
        tail = (tail + 1) % BufferSize;

        return true;
    }

    // �berpr�fe, ob der Puffer voll ist
    bool isFull() const {
        juce::ScopedLock lock(mutex); // Sperrt den Zugriff w�hrend der �berpr�fung
        return (head + 1) % BufferSize == tail;
    }

private:
    T buffer[BufferSize];                 // Statisches Array f�r den Puffer
    int head;                             // Kopfzeiger
    int tail;                             // Schwanzzeiger
    mutable juce::CriticalSection mutex;  // Mutex f�r die Synchronisation
};
