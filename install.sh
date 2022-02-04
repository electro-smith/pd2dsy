#!/bin/bash
echo "Installing python packages..." 

rm -rf pd_env

platform=$(uname)

if [ $platform = "Linux" ] || [ $platform = "Darwin" ]
then
python3 -m venv pd_env
source pd_env/bin/activate
python3 -m pip install wheel
python3 -m pip install -r requirements.txt
else
python -m venv pd_env
source pd_env/Scripts/activate
python -m pip install wheel
python -m pip install -r requirements.txt
fi

echo "Building libDaisy..."
git submodule update --init --recursive
cd libdaisy
make clean | grep "warningr:\|error:"
make -j4 | grep "warning:r\|error:"
echo "Setup complete!"