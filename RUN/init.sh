#! /bin/bash
# this file we use to read data from CAN-USB reader
chmod a+x init.sh 
chmod a+x slcan0_up.sh 
chmod a+x slcand 
chmod +x ./slcan_attach

cd /home/ragesh/catkin_ws/src/pixart/src/can-utils
bash -c './configure'

ls /dev/ttyACM0

bash -c 'sh ./slcan0_up.sh'

# this file we use to build and set the environment
cd ..
cd ..
cd ..
cd ..
bash -c 'catkin_make'
bash -c 'source devel/setup.bash'
bash -c 'roslaunch pixart pixart.launch'
