#include  "daisy_seed.h"
{display_conditional}
// name: {target_name}
struct Daisy {{
	void Init(bool boost = false) {{
		seed.Configure();
 		seed.Init(boost);
        {init}
        {switch}
        {switch3}