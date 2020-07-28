#ifndef DSY_BOARDS_H
#define DSY_BOARDS_H
#ifndef DSY_BOARD
#define DSY_BOARD DaisyPatch
#endif
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
    GateIn* gate;
    
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
	    case 4:
		return gate->Trig();
	}
	return 0.f;
    }
};

DSY_BOARD boardsHardware;

/* seed
int DaisyNumParameters = 0;
DaisyHvParam DaisyParameters[0];
seed */

/* pod
int DaisyNumParameters = 6;
DaisyHvParam DaisyParameters[6] = {
    {"Encoder", &boardsHardware.encoder, nullptr, nullptr, nullptr, false, 0},
    {"EncSwitch", &boardsHardware.encoder, nullptr, nullptr, nullptr, true, 1},
    {"Knob1",   nullptr, nullptr, &boardsHardware.knob1, nullptr, false, 3},
    {"Knob2",   nullptr, nullptr, &boardsHardware.knob2, nullptr, false, 3},
    {"Button1", nullptr, &boardsHardware.button1, nullptr, nullptr, true, 2},
    {"Button2", nullptr, &boardsHardware.button2, nullptr, nullptr, true, 2}  
};
pod */


int DaisyNumParameters = 8;
DaisyHvParam DaisyParameters[8] = {
    {"Encoder", &boardsHardware.encoder, nullptr, nullptr, nullptr, false, 0},
    {"EncSwitch", &boardsHardware.encoder, nullptr, nullptr, nullptr, true, 1},
    {"Ctrl1",   nullptr, nullptr, &boardsHardware.controls[0], nullptr, false, 3},
    {"Ctrl2",   nullptr, nullptr, &boardsHardware.controls[1], nullptr, false, 3},
    {"Ctrl3",   nullptr, nullptr, &boardsHardware.controls[2], nullptr, false, 3},
    {"Ctrl4",   nullptr, nullptr, &boardsHardware.controls[3], nullptr, false, 3},
    {"Gate1",   nullptr, nullptr, nullptr, &boardsHardware.gate_input[0], true, 4},
    {"Gate2",   nullptr, nullptr, nullptr, &boardsHardware.gate_input[1], true, 4},

};

