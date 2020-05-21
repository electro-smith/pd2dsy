# !/usr/bin/env python
import os
import argparse

def main():
    parser = argparse.ArgumentParser(description='Utility for converting Puredate files to Daisy projects, uses HVCC inside')
    parser.add_argument('pd_input', help='path to puredata file.')
    parser.parse_args()
    inpath = os.path.abspath(args.pd_input)

if __name__ == "__main__":
    main()
