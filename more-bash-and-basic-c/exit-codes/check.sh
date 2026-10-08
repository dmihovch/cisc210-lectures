#!/bin/bash
# usage:  ./check.sh ./some-program

program=$1

$program              # run it
status=$?               # $? = exit status of the command that just finished

echo ------------------------------------
echo "$program exited with status code $status"

if [ $status -eq 0 ]; then
    echo "SUCCESS: the program says everything went fine."
else
    echo "FAILURE: the program is reporting error code $status."
fi
