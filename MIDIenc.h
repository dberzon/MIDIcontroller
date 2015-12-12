#ifndef MIDIenc_h
#define MIDIenc_h

#include "Arduino.h"
#include "Bounce.h"
#include "Encoder.h"

extern int MIDIchannel;

class MIDIenc{
    int channel;
    int number;
    int outLo, outHi;

  public:
    // default constructor
    MIDIenc();
    
    // constructor when only pins and control number are given
    MIDIenc(int a, int b, int num);
    
    // " when pins, control number, minimum and maximum outgoing MIDI values set
    MIDIenc(int a, int b, int num, int min, int max);
    
    // destructor
    ~MIDIenc();

    int read(); // read input and return value of message sent (or -1 if none)
    int value = 0;
    Encoder *myKnob;
    void setControlNumber(int num);
    void setChannel(int ch);	
    void outputRange(int min, int max);
};

#endif