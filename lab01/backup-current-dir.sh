#!/bin/bash

# this script creates a backup of the current directory inside the /tmp/ directory of the operating system
# to uniqely identify the backups the file name contains the directory name for which a backup was created
# as well as a timestamp of the backup creation

timestamp=$(date '+%Y%m%d-%H%M%S')      # create timestamp
location=${PWD////_}			# replace / returned from PWD variable with _
name="backup_${location}_${timestamp}"	# create a filename containing the previously created variables
fullname=/tmp/$name.tgz			# create now the full path for the file within the /tmp/ directory

tar czvf $fullname .			# use the tar command to create an archive of the current direcotry which is identified
					# with the "." sign

if [ $? -ne 0 ]				# check via the $? the value of the return code for the previous tar command to determine
then					# its success and print a message for the user
	echo "FAILURE: $fullname"
else
	echo "SUCCESSS: $fullname"
fi
