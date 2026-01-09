#!/bin/bash

END_TIME=$((SECONDS + 120)) # 2 minutes
MAX_OPS=5500
COUNT=0
TOTAL_OPS=0
MAX_SEEN=0
MIN_SEEN=100000

echo "Running push_swap stress test (100 numbers)"
echo "Fail if ops > $MAX_OPS"
echo "-------------------------------------------"

while [ $SECONDS -lt $END_TIME ]; do
	ARG=$(shuf -i 1-500 -n 500)
	OPS=$(./push_swap $ARG | wc -l)

	COUNT=$((COUNT + 1))
	TOTAL_OPS=$((TOTAL_OPS + OPS))

	[ "$OPS" -gt "$MAX_SEEN" ] && MAX_SEEN=$OPS
	[ "$OPS" -lt "$MIN_SEEN" ] && MIN_SEEN=$OPS

	if [ "$OPS" -gt "$MAX_OPS" ]; then
		AVG=$((TOTAL_OPS / COUNT))

		echo "❌ FAILURE DETECTED"
		echo "Test #:        $COUNT"
		echo "Operations:   $OPS"
		echo "Average ops:  $AVG"
		echo "Min ops:      $MIN_SEEN"
		echo "Max ops:      $MAX_SEEN"
		echo "Failing ARG:"
		echo "$ARG"
		exit 1
	fi

	echo "✔ Test $COUNT — ops: $OPS"
done

AVG=$((TOTAL_OPS / COUNT))

echo "✅ SUCCESS (2 minutes completed)"
echo "Tests run:    $COUNT"
echo "Average ops:  $AVG"
echo "Min ops:      $MIN_SEEN"
echo "Max ops:      $MAX_SEEN"
