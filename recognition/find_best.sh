#!/bin/bash

if [ $# -ne 2 ]
then
  >&2 echo "Usage: ./find_best.sh [database_directory] [result_text_file]"
  exit 1
fi

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

for category in $categories
do
  better=0
  better_shape=""
  for shape in $shapes
  do
    total_occurences="$(grep -E "$category.*_$shape.csv ->" "$2" | wc -l | xargs)"
    right_guesses="$(grep -E "$category.*_$shape.csv -> $category.*_$shape.csv" "$2" | wc -l | xargs)"
    res="$(echo "($right_guesses/$total_occurences)*100" | bc -l)"
    if (( $(echo "$res > $better" | bc -l) ))
    then
      better="$res"
      better_shape="$shape"
    fi
  done
  overall="$(echo "$overall+$better" | bc -l)"
  echo "$category compared to $better_shape -> $(echo "$better" | rev | cut -c 19- | rev) %" >> best.txt
done

echo "" >> best.txt
echo "Overall: $(echo "$overall/$(echo "$categories" | wc -w)" | bc -l | rev | cut -c 19- | rev) %" >> best.txt
