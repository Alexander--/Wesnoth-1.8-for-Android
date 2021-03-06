#! /bin/bash

LOGFILE=runtests.log
POTENTIAL_TESTS='testboundaries testcolor testboundaries_ucd'

ECHO_C=''
ECHO_N='-n'

for I in $POTENTIAL_TESTS
do
    GOOD=yes
    test -f $I || {
        echo "WARNING: test program $I not found, not running"
        GOOD=no
    }

    if test x$GOOD = xyes; then
        test -x $I || {
            echo "WARNING: test program $I is not executable, not running"
            GOOD=no
        }
    fi
    
    if test x$GOOD = xyes; then
        TESTS="$TESTS$I "
    fi
done

echo "Logging to $LOGFILE"

echo "Log file for Pango test programs." > $LOGFILE
echo "" >> $LOGFILE
echo "Tests are: "$TESTS >> $LOGFILE
echo "" >> $LOGFILE

for I in $TESTS
do
    echo $ECHO_N "Running test program \"$I\", please wait:$ECHO_C"
    echo "" >> $LOGFILE
    echo "Output of $I:" >> $LOGFILE
    if ./$I >>$LOGFILE 2>&1; then
        echo " passed"
    else
        echo
        echo
        echo '***'
        echo " Test failed: $I"
        echo " See $LOGFILE for errors"
        echo 
        exit 1
    fi
done

echo 
echo "All tests passed."
