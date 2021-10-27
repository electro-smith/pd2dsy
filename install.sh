#!/bin/bash
echo "Installing python packages..." 
python -m venv pd_env
source pd_env/bin/activate
python -m pip install -r requirements.txt

echo "Building libDaisy..."
git submodule update --init --recursive
cd libdaisy
make clean | grep "warningr:\|error:"
make -j4 | grep "warning:r\|error:"
echo "Setup complete!"