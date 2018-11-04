# **Calibration of 2 X 2 Infrared sensor Array for Multirobot Localization.**

This project deals with implementing a system that uses infrared cameras to capture data of the position of several robots in a pre-defined workspace. This is an absolute localization for several robots equipped with IR LEDs on their top, and detected using multiple infrared cameras.

### Ecole Centrale de Nantes, France.
### Developed on June 2018 by:

1. Ragesh RAMACHANDRAN
2. Olena HRYSHAIENKO

# RUN

In the terminal go to the directory 'RUN' and then execute the shell script: 
```
./init.sh
```

# ROS catkin_ws

```
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
```

# CALIBRATION SOFTWARE

The calibration software is provided by [BKhomutenko] (https://github.com/BKhomutenko/visgeom)

## Installation


## Requred packages:
```
    ceres-solver 1.10.0+
    Eigen3
    OpenCV 2.4.9+
```
After you have installed the needed libraries, go to the directory visgeom in the terminal and run:
```
$ mkdir build
$ cd build
$ cmake ..
$ make 
```
## To run the program
```
/calib ../data/IR_CAMERA/calib_ir.json 
```

For details read the project report




