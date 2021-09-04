#!/bin/sh

Serial_Port=$1
if [ -z "$Serial_Port" ]
then
	echo "Usage : $0 Serial_Port"
	echo "  Serial_Port is the full path to the board serial port device, like '/dev/ttyUSB0'."
	echo "  Make sure your user is part of the 'dialout' or 'uucp' group to allow this script to call 'stty' command with no privilege."
	exit 1
fi

echo "+------------------------+"
echo "| USB relays board tests |"
echo "+------------------------+"

echo "Configuring serial port..."
stty -F $Serial_Port 9600

echo "Turning led off for 2 seconds..."
echo "#L0" > $Serial_Port
sleep 2

echo "Turning led on for 2 seconds..."
echo "#L1" > $Serial_Port
sleep 2

echo "Making led blink for 5 seconds..."
echo "#L2" > $Serial_Port
sleep 5

echo "Stopping led blinking..."
echo "#L1" > $Serial_Port
# Give some time to the board to process the command and send the answer
sleep 0.1

for i in $(seq 1 16)
do
	Relay_ID=$(printf "%02d" $i)

	echo "Tuning relay $i on for 2 seconds..."
	echo "#S${Relay_ID}1" > $Serial_Port
	sleep 2

	echo "Tuning relay $i off..."
	echo "#S${Relay_ID}0" > $Serial_Port
	# Give some time to the board to process the command and send the answer
	sleep 0.1
done

echo "Turning all relays on for 5 seconds..."
for i in $(seq 1 16)
do
	Relay_ID=$(printf "%02d" $i)

	echo "#S${Relay_ID}1" > $Serial_Port
	# Give some time to the board to process the command and send the answer
	sleep 0.1
done
sleep 5

echo "Turning all relays off..."
for i in $(seq 1 16)
do
	Relay_ID=$(printf "%02d" $i)

	echo "#S${Relay_ID}0" > $Serial_Port
	# Give some time to the board to process the command and send the answer
	sleep 0.1
done

echo "Making led blink for 3 seconds to tell that tests are terminated..."
echo "#L2" > $Serial_Port
sleep 3

echo "Stopping led blinking..."
echo "#L1" > $Serial_Port
# Give some time to the board to process the command and send the answer
sleep 0.1

echo "All tests terminated."
