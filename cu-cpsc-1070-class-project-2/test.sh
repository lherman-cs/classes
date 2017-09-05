#!/bin/bash

python3 gen.py
xargs -a test.dat -P 0 -I '{}' ./hw5 '{}'
