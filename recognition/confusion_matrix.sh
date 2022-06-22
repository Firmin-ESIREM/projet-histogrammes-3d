#!/bin/bash

original_path="$PWD"

shapes="tetrahedron cube octahedron dodecahedron icosahedron"
categories=""

cd "$1"

for i in $(ls -d */)
do
  categories="$categories ${i%%/}"
done

cd "$original_path"

overall=0

for shape in $shapes
do
  file_name="matrix_$shape.csv"
  for category in $categories
  do
    echo -n ";$category" >> $file_name
  done
  echo "" >> $file_name

  for category in $categories
  do
    echo -n "$category;" >> $file_name
    nb_of_items="$(grep -E "$category.*_$shape.csv ->.*" "$2" | wc -l)"
    for cat in $categories
    do
      nb="$(grep -E "$category.*_$shape.csv -> $cat$" "$2" | wc -l)"
      echo -n "$(echo "($nb/$nb_of_items)" | bc -l | tr "." ",");" >> $file_name
    done
    echo "" >> $file_name
  done
done
