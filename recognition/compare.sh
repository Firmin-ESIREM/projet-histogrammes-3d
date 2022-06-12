#!/bin/bash

if [ -d "output_training" ] && [ -d "output_test" ]
then
  ls -p output_training | grep -v "/" | grep -E ".*.csv" > training_models.txt
  ls -p output_test | grep -v "/" | grep -E ".*.csv" > test_models.txt 
  python3 compare.py training_models.txt test_models.txt
else
  >&2 echo "Please check that the training histograms are in the \"output_training\" directory, and the test histograms in the \"output_test\" directory."
  exit 1
fi
