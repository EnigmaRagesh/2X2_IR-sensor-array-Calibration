#!/usr/bin/python
# -*- coding: utf-8 -*-
import rospy
import json
from std_msgs.msg import String
from pixart.msg import raw_point
from pandas.io.json import json_normalize
from pandas import DataFrame
from pprint import pprint
from operator import itemgetter
from operator import itemgetter
from operator import sub
from operator import add
import numpy as np
import atexit



## Global variables to store the temporary variabbles before dumping into JSON file
dataPoints_0 = []
dataPoints_1 = []
dataPoints_2 = []
dataPoints_3 = []

## The node receives data from pixart node    
def subscriber():
    rospy.init_node('Calibration_data', anonymous=False)
    rospy.Subscriber('/pixart_raw', raw_point, callback)
    while not rospy.is_shutdown():
          rospy.sleep(1)


## The incoming RAW data is redirected into 4 different files
def callback(data):
    
   if data.camera_id == 0:
      CAM0 = {'x':data.x, 'y':data.y,'cameraID':data.camera_id, 'time ms':data.stamp.secs, 'time ns':data.stamp.nsecs }
      dataPoints_0.append(CAM0)
   elif data.camera_id == 1:
      CAM1 = {'x':data.x, 'y':data.y,'cameraID':data.camera_id, 'time ms':data.stamp.secs, 'time ns':data.stamp.nsecs }
      dataPoints_1.append(CAM1)
   elif data.camera_id == 2:
      CAM2 = {'x':data.x, 'y':data.y,'cameraID':data.camera_id, 'time ms':data.stamp.secs, 'time ns':data.stamp.nsecs }
      dataPoints_2.append(CAM2)
   else:
      CAM3 = {'x':data.x, 'y':data.y,'cameraID':data.camera_id, 'time ms':data.stamp.secs, 'time ns':data.stamp.nsecs } 
      dataPoints_3.append(CAM3)


### Filtering raw data of each camera to remove errors
def filter_raw(data_points):
    filtered_data = []
    filtered_time = []
    filtered = []
    last = {"y": 0, "x": 0, "time ns": 0, "time ms": 0, "cameraID": 0}
    data_points.append(last)    
    prev =  itemgetter('x', 'y')(data_points[0])
    acc = (0,0)
    count = 0
    tol_pix = [3,3]
    prev =  itemgetter('x', 'y')(data_points[0])
    save_time =  itemgetter('time ms','time ns')(data_points[0])
    n = len(data_points)
    for i in range(1,n):
         cur = itemgetter('x', 'y')(data_points[i])
         cur_time = itemgetter('time ms','time ns')(data_points[i])
         diff = np.abs(tuple(map(sub, prev, cur)))  
         res = np.any(diff <= tol_pix)
         if (res):
              acc = tuple(map(add, cur, acc))
              count = count + 1.
              prev = cur
         else:
              filtered_time.append(save_time)
              save_data = [x / count for x in acc]
              save_time = cur_time
              prev = cur
              acc = cur
              count = 1
              filtered_data.append(save_data)
              
    for i in range(0, len(filtered_data)):
        temp = [filtered_time[i],filtered_data[i]]
        filtered.append(temp)    
    return filtered

    
## Dumping the temporary lists into JSON files
def exit_handler():
     print 'Filtering.....'
     print 'Saving data into files.....'
     Fil_cam0 = filter_raw(dataPoints_0)
     Fil_cam1 = filter_raw(dataPoints_1)
     Fil_cam2 = filter_raw(dataPoints_2)
     Fil_cam3 = filter_raw(dataPoints_3)
     dumpFile_0(Fil_cam0)
     dumpFile_1(Fil_cam1)
     dumpFile_2(Fil_cam2)
     dumpFile_3(Fil_cam3)
     print 'Save completed!'
     print 'Synchronizing.....'
     print 'Synchronizing data completed .....'
     
if __name__ == '__main__':
    subscriber()
    

## Storing data into 4 different files
def dumpFile_0(data):
     with open('/home/ragesh/catkin_ws/src/pixart/src/DATA/camera_0.json', 'a') as f:
        json.dump(data, f, indent=5)
     print data

def dumpFile_1(data):
     with open('/home/ragesh/catkin_ws/src/pixart/src/DATA/camera_1.json', 'a') as f:
        json.dump(data, f, indent=5)
     print data

def dumpFile_2(data):
     with open('/home/ragesh/catkin_ws/src/pixart/src/DATA/camera_2.json', 'a') as f:
        json.dump(data, f, indent=5)
     print data

def dumpFile_3(data):
     with open('/home/ragesh/catkin_ws/src/pixart/src/DATA/camera_3.json', 'a') as f:
        json.dump(data, f, indent=5)
     print data


atexit.register(exit_handler)
