#ifndef DSY_BOARDS_H
#define DSY_BOARDS_H
#ifndef DSY_BOARD
#define DSY_BOARD DaisyPod
#endif
#include "daisy_seed.h"
#include "daisy_pod.h"
#include "daisy_patch.h"
#include "daisy_field.h"
#include "daisy_petal.h"

#include <string>
using namespace daisy;

//All the info we need for our parameters
struct DaisyHvParam{
    std::string name;

    Encoder* enc;
    Switch* sw;
    AnalogControl* knob;

    bool isBang;
    
    int mode;
    float Process()
    {
	switch (mode)
	{
	    case 0:
		return enc->Increment();
	    case 1:
		return enc->RisingEdge();
	    case 2:
		return sw->RisingEdge();
	    case 3:
		return knob->Process();
	}
	return 0.f;
    }
};

DSY_BOARD boardsHardware;

int DaisyNumParameters = 6;
DaisyHvParam DaisyParameters[6] = {
    {"Encoder", &boardsHardware.encoder, nullptr, nullptr, false, 0},
    {"EncSwitch", &boardsHardware.encoder, nullptr, nullptr, true, 1},
    {"Knob1",   nullptr, nullptr, &boardsHardware.knob1, false, 3},
    {"Knob2",   nullptr, nullptr, &boardsHardware.knob2, false, 3},
    {"Button1", nullptr, &boardsHardware.button1, nullptr, true, 2},
    {"Button2", nullptr, &boardsHardware.button2, nullptr, true, 2}  
};

#endif
