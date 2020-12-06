#!/bin/bash

target_dir=~/texmf/tex/xelatex
mkdir -p ${target_dir}
cp -r ../packages/* ${target_dir}
echo "Successfully Added!"
