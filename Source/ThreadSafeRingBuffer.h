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

    // Füge ein neues Element zum Ringpuffer hinzu
    void add(const T& value) {
        juce::ScopedLock lock(mutex); // Sperrt den Zugriff während der add-Operation

        buffer[head] = value;
        head = (head + 1) % BufferSize;

        // Wenn head den tail überschreibt, bewegt sich der tail-Zeiger weiter
        if (head == tail) {
            tail = (tail + 1) % BufferSize;
        }
    }

    // Entferne ein Element aus dem Ringpuffer
    bool remove(T& value) {
        juce::ScopedLock lock(mutex); // Sperrt den Zugriff während der remove-Operation
        if (head == tail) { // Direkte Prüfung, ob der Puffer leer ist
            return false;
        }

        value = buffer[tail];
        tail = (tail + 1) % BufferSize;

        return true;
    }

    // Überprüfe, ob der Puffer voll ist
    bool isFull() const {
        juce::ScopedLock lock(mutex); // Sperrt den Zugriff während der Überprüfung
        return (head + 1) % BufferSize == tail;
    }

private:
    T buffer[BufferSize];                 // Statisches Array für den Puffer
    int head;                             // Kopfzeiger
    int tail;                             // Schwanzzeiger
    mutable juce::CriticalSection mutex;  // Mutex für die Synchronisation
};
