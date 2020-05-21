#include "daisy_boards.h"

// GENERATE INCLUDES START
// GENERATE INCLUDES END

using namespace daisy;

DSY_BOARD hardware;

// GENERATE GLOBALS START
// GENERATE GLOBALS END

void audiocallback(float **in, float **out, size_t size)
{
    // GENERATE AUDIOCALLBACK START
    // GENERATE AUDIOCALLBACK END
}

int main(void)
{
    hardware.Init();
    // GENERATE PREINIT START
    // GENERATE PREINIT END
    hardware.StartAdc();
    hardware.StartAudio(audiocallback);
    // GENERATE POSTINIT START
    // GENERATE POSTINIT END
    for(;;)
    {
        // GENERATE INFINITELOOP START
        // GENERATE INFINITELOOP END
    }
}
