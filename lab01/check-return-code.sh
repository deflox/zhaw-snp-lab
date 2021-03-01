#!/bin/bash

type echo

echo $?

if [ $? ]
then
	echo "SUCCESS"
else
	echo "FAILURE"
fi
