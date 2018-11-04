#!/usr/bin/python
# -*- coding: utf-8 -*-
import json
from operator import itemgetter
from operator import itemgetter
from operator import sub
from operator import add
import operator
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as grd

## Global variables to store the temporary variabbles before dumping into JSON file

tagged_data0 = []
tagged_data1 = []
tagged_data2 = []
tagged_data3 = []

## Read the JSON files and store into global variables
with open('/home/ragesh/catkin_ws/src/pixart/src/DATA_0/camera_0.json') as f0:
    dataPoints_0 = json.load(f0)

with open('/home/ragesh/catkin_ws/src/pixart/src/DATA_0/camera_1.json') as f1:
    dataPoints_1 = json.load(f1)

with open('/home/ragesh/catkin_ws/src/pixart/src/DATA_0/camera_2.json') as f2:
    dataPoints_2 = json.load(f2)

with open('/home/ragesh/catkin_ws/src/pixart/src/DATA_0/camera_3.json') as f3:
    dataPoints_3 = json.load(f3)



## Merging the data into list of four points

def merge_data(DATA):
    data = []
    for i in DATA:
        flat = reduce(operator.concat, i)
        data.append(flat)

    temp = []
    points = []
    count = 0
    tol = 4
    prev_time = data[0][0]

    for i in data:
        pt = [i[2], i[3]]
        cur_time = i[0]           #sec
        time_diff = np.abs(cur_time - prev_time)
        if count == 4:
            time_points = [cur_time, temp]
            points.append(time_points)
            count = 0
            temp = []

        if(time_diff < tol):
            count = count + 1

        else:
            temp = []
            count = 1
        temp.append(pt)
        prev_time = cur_time
    return points

## Merge overlapping part

def merge_overlap(data_0,data_1):
    tem = []
    temp0 = []
    temp1 = []
    for i in data_0:
        cam0_time = i[0]
        for j in data_1:
            cam1_time = j[0]
            diff = np.abs(cam0_time - cam1_time)
            if(diff < 2.0):
                temp0.append(i[1])
                temp1.append(j[1])

    return temp0,temp1


## Tagging the camera_id to each merged data

cam0 = merge_data(dataPoints_0)     ##Camera 0
for i in cam0:
    tagged_data0.append(i[1])

cam1 = merge_data(dataPoints_1)     ##Camera 1
for i in cam1:
    tagged_data1.append(i[1])

overlap_0,overlap_1= merge_overlap(cam0,cam1)

def get_dict(tag,list):
    listed = []
    for items in list:
        temp =  {}
        temp['Cam_id'] = "cam%d"%tag
        temp['points'] = items
        listed.append([temp])
    return listed

## Writing the merged data into a JSON file
merged = get_dict(0,tagged_data0) + get_dict(1,tagged_data1)
l = len(merged)
def get_overlap_dict(list1,list2):
    listed = []
    listed1 = get_dict(0,list1)
    listed2 = get_dict(1,list2)
    for i in range(len(listed1)):
        list = []
        list.append(listed1[i][0])
        list.append(listed2[i][0])
        listed.append(list)
    return listed

listed = get_overlap_dict(overlap_0,overlap_1)

for i in listed:
    merged.append(i)
for i in range(len(merged)):
    print merged[i]

print '____________________________________________________________________________'
print '____________________________________________________________________________'
print 'Merging_files.....'
print 'Saving data into files.....'

with open('/home/ragesh/catkin_ws/src/pixart/src/DATA/Merged_file.json','w') as outfile:
    json.dump(merged,outfile,indent=8)

print 'Save completed!'  
print '____________________________________________________________________________'
print '____________________________________________________________________________'  

##### Plottig the points in graph
Plot = []
for i in range(l):
    Plot.append(merged[i])
gs=grd.GridSpec(1,2)

ax1=plt.subplot(gs[:,0])
plt.title('CAMERA 0')
plt.xlabel('y_axis')
plt.ylabel('x_axis')

ax2=plt.subplot(gs[:,1])
plt.title('CAMERA 1')
plt.xlabel('x_axis')
plt.ylabel('y_axis')

for i in Plot:
 if(type(i[0]) == dict):
     if(i[0]["Cam_id"]=="cam0"):
         graph_points = i[0]["points"]
         graph_points.append(graph_points[0])
         x,y=zip(*graph_points)
         ax1.plot(y,x)
     if(i[0]["Cam_id"]=="cam1"):
         graph_points = i[0]["points"]
         graph_points.append(graph_points[0])
         x,y=zip(*graph_points)
         ax2.plot(y,x)
plt.show()
