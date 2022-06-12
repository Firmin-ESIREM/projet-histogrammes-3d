#!/bin/bash

if [ $# -eq 2 ]
then
    find "${2%/}/*/train/*.off" | xargs -I{} "./$1" {}
else
    >&2 echo "Usage: ./parse_database.sh [database_directory] [off_parser_executable]"
    exit 1
fi
