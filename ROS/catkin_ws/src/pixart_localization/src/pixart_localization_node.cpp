/**
\file    pixart_localization_node.cpp
\brief  This node subscribes to pixart_world node, receives the world coordinates of the LEDs and removes redundant readings.
Pre-condition: The first LED should enter from the overlap-free zone under camera 0 and the remaining LEDs can enter from anywhere on the workspace.
				This program works for four robots moving in the workspace as maximum number of points detected by each of the cameras is 4.

\Authors:   Leaonardo STRETTI, Anusha Srihari ARVA, Haorui PENG. (EMARO/ARIA 2015-16)
\Date       25-06-2016
*/


//C++ libraries.
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>


//ROS.
#include "ros/ros.h"

//ROS msgs.
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <pixart_localization/world_point.h>
#include <pixart_localization/measured_point.h>
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PointStamped.h>

//Namespaces.
using namespace std;
using namespace Eigen;


//Global message types.
pixart_localization::world_point led_now;  //world_point: Represents one point per message. Contains X,Y,Z coordinates along with camera_ID and point_ID.
pixart_localization::measured_point led_old_data; // measured_point: Represents the positions of all active LEDs under workspace. Vectors of X,Y,Z, led_ID, led_status and camera details.



//Flags
bool msgFlag_world = false;
bool led_status = false;


//Initialization, declaration for distance calculation.
float distThres = 0.10; //minimum allowed separation between LEDs. 
float min_dist;
int min_index_dist;

vector<float> dist(1); // Dist is a vector of dim 1 and value 0 as default

//Parameters to set the buffer size
int number_of_cameras ;
double desired_frequency ;
double camera_frequency;


//To set buffer size according to desired frequency set by the user
double buffer_ratio = (((double)number_of_cameras/camera_frequency)*desired_frequency)+0.5;
int buffer_size = (int)buffer_ratio;

//Publisher that publishes data for localization
ros::Publisher measured_pub;
 
//Callback function that stores the world coordinates given by pixart package
void readworldCallback(pixart_localization::world_point pointsread){
   
      led_now.pt.header.stamp=pointsread.pt.header.stamp;
      led_now.camera_id = pointsread.camera_id;
      led_now.point_id = pointsread.point_id;
      led_now.pt.point.x = pointsread.pt.point.x;
      led_now.pt.point.y = pointsread.pt.point.y;
      led_now.pt.point.z = pointsread.pt.point.z;
      msgFlag_world = true;
    }

//Function to calculate the distance between two points. Called iteratively to locate the desired LED in the workspace.
float checkDistance (float x1, float y1, float x2,float y2){
  float d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
  return d;
}

//Function to calculate the minimum in the vector of distances
float min_distance (vector<float> v){

      float min = v[0];
      int min_index = 0;

      for(int k = 0; k < led_old_data.x.size(); k++){
          if(v[k] < min){
              min = v[k]; 
          }
      }
      return min;
}

//Function to retrieve the index of the LED that needs to be updated
int min_index (vector<float> v){

      float min = v[0];
      int min_ind = 0;

      for(int k = 0; k < led_old_data.x.size(); k++){
          if(v[k] < min){
              min_ind = k; 
          }
      }
      return min_ind;
}


//Main program
int main (int argc, char** argv)
{
  //ROS Initialization
  ros::init(argc, argv, "pixart_localization_node");
  ROS_INFO("pixart_localization_node connected to roscore");
  ros::NodeHandle nh_("~"); //ROS Handler - local namespace.

  //Retrieve camera frequency parameters from the user. Default: 270 Hz (same as the cameras)
   nh_.param("number_of_cameras",number_of_cameras,4);
   nh_.param("desired_frequency",desired_frequency,270.0);
   nh_.param("camera_frequency",camera_frequency,270.0);

  //Subscribing
  ROS_INFO("Subscription to topics\n");
  ros::Subscriber world_sub = nh_.subscribe<pixart_localization::world_point> ("/pixart_world"  , 4, readworldCallback);

   //Publishing 
    measured_pub = nh_.advertise<pixart_localization::measured_point>("/measurements", 4);

    ros::Rate rate(270);
    
    	//To initialize the vector that holds the previous status of the workspace. Initial Condition: First LED enters from camera 0.
		led_old_data.led_id.push_back(0); 
        led_old_data.led_status.push_back(false);
        led_old_data.camera_id.push_back(0);
        led_old_data.point_id.push_back(0);
        led_old_data.x.push_back(0.0);
        led_old_data.y.push_back(0.0);
        led_old_data.z.push_back(0.0);

    while (ros::ok()) {
    	
        ros::spinOnce();
        
        //Execute this section as long as world coordinates are being provided in pixart_world message
        if(msgFlag_world){ 
        	

           int i = 0;
           int nb_loops = led_old_data.led_id.size() ;
           
          		
				  //To create a vector of distances between the current message and the remaining LEDs in the workspace          		
                  while(i < nb_loops ){

                    dist[i] =  checkDistance(led_old_data.x[i], led_old_data.y[i], led_now.pt.point.x,led_now.pt.point.y);
                    
                    i = i + 1;
                  }                           

				 // To identify the LED in the workspace that needs to be updated with latest coordinates
                  min_index_dist = min_index(dist);
                  min_dist = min_distance(dist);
                  


                  //If the LED in the new message is detected under the same camera:
                  if(led_old_data.camera_id[min_index_dist] == led_now.camera_id){

                          //If the point_ID of the LED is same as the one identified from previous state, update the coordinates and keep the other IDs the same.
                          if(led_old_data.point_id[min_index_dist] == led_now.point_id){

                            led_old_data.led_id[min_index_dist] = led_old_data.led_id[min_index_dist];
                            led_old_data.led_status[min_index_dist] = true;
                            led_old_data.camera_id[min_index_dist]= led_now.camera_id;
                            led_old_data.point_id[min_index_dist] = led_now.point_id;
                            led_old_data.x[min_index_dist] = led_now.pt.point.x; 
                            led_old_data.y[min_index_dist] = led_now.pt.point.y;
                            led_old_data.z[min_index_dist] = led_now.pt.point.z;
                               measured_pub.publish(led_old_data);
                            
                             }
                           
                           //If the point_IDs are different, a new LED has entered the workspace, create a new led_ID.
                           if(led_old_data.point_id[min_index_dist] != led_now.point_id){


                                led_old_data.led_id.push_back(i); 
                                led_old_data.led_status.push_back(true);
                                led_old_data.camera_id.push_back(led_now.camera_id);
                                led_old_data.point_id.push_back(led_now.point_id);
                                led_old_data.x.push_back(led_now.pt.point.x);
                                led_old_data.y.push_back(led_now.pt.point.y);
                                led_old_data.z.push_back(led_now.pt.point.z);

                                dist.push_back(0);	// Increase the size of the distance vector to be filled in the next cycle

                                   measured_pub.publish(led_old_data);
                          
                           }

                  }

                  //If the LED in the new message is detected under a different camera:
                  if(led_old_data.camera_id[min_index_dist] != led_now.camera_id){
                            
                            // If the minimum distance calculated is less than the distance threshold, the point detected is under the overlapping region. Update position, keep the rest
                           if(min_dist <= distThres){
                               
                               led_old_data.led_id[min_index_dist] = led_old_data.led_id[min_index_dist];
                               led_old_data.led_status[min_index_dist] = true;
                               led_old_data.camera_id[min_index_dist]= led_now.camera_id;
                               led_old_data.point_id[min_index_dist] = led_now.point_id;
                               led_old_data.x[min_index_dist] = led_now.pt.point.x; 
                               led_old_data.y[min_index_dist] = led_now.pt.point.y;
                               led_old_data.z[min_index_dist] = led_now.pt.point.z;

                                  measured_pub.publish(led_old_data);
                           }
                            /// If the minimum distance calculated is more than the distance threshold, a new point has entered the workspace. Create a new instance 
                           if(min_dist > distThres){
                               
                                led_old_data.led_id.push_back(i); 
                                led_old_data.led_status.push_back(true);
                                led_old_data.camera_id.push_back(led_now.camera_id);
                                led_old_data.point_id.push_back(led_now.point_id);
                                led_old_data.x.push_back(led_now.pt.point.x);
                                led_old_data.y.push_back(led_now.pt.point.y);
                                led_old_data.z.push_back(led_now.pt.point.z);

                                dist.push_back(0);	// Increase the size of the distance vector to be filled in the next cycle

                                   measured_pub.publish(led_old_data);
                           }
                  } 
					

        		            
        		
         }  


            rate.sleep();
    }
 

    ROS_INFO("ROS-Node Terminated\n");
}
