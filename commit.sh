#!/bin/bash
#
# patch.list to contain a list of commit hashes available in the current repo, either from fetched remotes, or other branches.
# An original/unusual script by David Savage (bedalus@gmail.com)

while read line
do
COMMITHASH=$line
echo "hash is $COMMITHASH"

# here we go...

git cherry-pick $COMMITHASH --exit-code
if [ "$?" = "0" ]; then
	echo "successful commit"
else
	git cherry-pick --abort
fi

# go back to top, get next patch
done <patch.list

# it's all over
exit 0
