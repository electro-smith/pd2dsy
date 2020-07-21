#ifndef DSY_BOARDS_H
#define DSY_BOARDS_H
#ifndef DSY_BOARD
// GENERATE BOARD
#endif
#include "daisy_seed.h"
#include "daisy_pod.h"
#include "daisy_patch.h"
#include "daisy_field.h"
#include "daisy_petal.h"
#include <string>

//All the info we need for our parameters
struct DaisyHvParam{
    std::string name;
    bool isBang;
};

DaisyHvParam DaisyParameters[1] = {{"Knob1", false}};

#endif
