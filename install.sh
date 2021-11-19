#!/bin/bash
echo "Installing python packages..." 
rm -rf pd_env
python3 -m venv pd_env
source pd_env/bin/activate
python3 -m pip install wheel
python3 -m pip install -r requirements.txt

echo "Building libDaisy..."
git submodule update --init --recursive
cd libdaisy
make clean | grep "warningr:\|error:"
make -j4 | grep "warning:r\|error:"
echo "Setup complete!"