#!/usr/bin/env bash

NUM=0

while true; do
	printf "$NUM \n"
	NUM=$(( NUM + 1 ))
	sleep 1
done

exit 0
