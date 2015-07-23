#!/bin/bash
SUCCESS=1

for test in `ls bin/*`
do
    ./$test > /dev/null
    STATUS=$?
    if [[ "$STATUS" -ne "o0" ]]
    then
	echo "Test $test failed!";
	SUCCESS=0
    fi
done

if [[ "$SUCCESS" -eq "1" ]]
then
    echo "All tests passed!"
    exit 0
fi

exit 1