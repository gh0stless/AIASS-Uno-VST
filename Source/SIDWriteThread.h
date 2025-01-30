/*
  ==============================================================================

    SIDWriteThread.h
    Created: 22 Oct 2024 10:28:42am
    Author:  andre

  ==============================================================================
*/
#pragma once

class SIDWriteThread : public juce::Thread {

public:
    SIDWriteThread( ThreadSafeRingBuffer<SIDWriteSet, MY_BUFFER_SIZE>& buffer)
      : Thread("SIDWriteThread"),
        ringBuffer(buffer) {}

    void run() override {
        while (!threadShouldExit()) {
                if (ringBuffer.remove(value)) {
                    bool RS = false;
                    while (!RS){
                        RS = HardSID_WriteWithTimeout(0, cycles, value.SIDRegister, value.SIDData);
                        if (!RS) juce::Thread::sleep(20);
                    }
                }
                else { // buffer empty
                    bool RS = false;
                    while (!RS) {
                        RS = HardSID_WriteWithTimeout(0, cycles, 0x1e, 0); // do nothing
                        if (!RS) juce::Thread::sleep(20);
                     }
                }
        }
    }

    bool HardSID_WriteWithTimeout(int dev_id, int cycles, int reg, int data) {
        auto startTime = juce::Time::getMillisecondCounter();
        while (HardSID_Try_Write(dev_id, cycles, reg, data) == HSID_USB_WSTATE_BUSY) {
            juce::Thread::yield();
            auto elapsedTime = juce::Time::getMillisecondCounter() - startTime;
            if (elapsedTime > LOOP_TIME_OUT_MILLIS) {
                return false;
            }
        }
        return true;
    }

private:
    const int LOOP_TIME_OUT_MILLIS = 500;
    const int cycles = 8;
    SIDWriteSet value ;
    ThreadSafeRingBuffer<SIDWriteSet, MY_BUFFER_SIZE>& ringBuffer;
};
