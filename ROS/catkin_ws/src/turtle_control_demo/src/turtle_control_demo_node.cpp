/**
 * \file turtle_control_demo_node.cpp
 * \A node to control a turtle using localization data 
 * \authors Haorui PENG, Leonardo STRETTI, Anusha Srihari ARVA
 * \version 0.1
 * \date 25 June 2016
 * 

 * 
 * Subscribes to: 
 *    ° Relative topic "/measurements"
 * 
 * Publishes to: 
 *    ° Relative topic "/cmd_vel_mux/input/teleop"
 *
 *
 */
 //cpp Libraries
#include <math.h>
#include <time.h>
//ROS
#include "ros/ros.h"

//ROS msgs
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
#include <pixart/world_point.h>
#include <pixart_localization/measured_point.h>

#define DIST -0.147
#define PI 3.14
#define FREQUENCY 20

//Namespaces
using namespace std;

//Global variables
ros::Publisher pub_command ;

pixart_localization::measured_point turtle_pose; 
double vturtle, wturtle                      ;


bool localizationInfoReceived   = false ;

double x, y, xp,yp,x_des, y_des, theta_des, xp_des, yp_des;
double center_x = 0.65;
double center_y = 0.3;
double Kp = 0.5;
double R = 0.6;
double t ; // the program runs at 20 Hz
double v_des = 0.2 ;
double w_des = v_des/R; //we want the robot to ideally complete a circle in 40 sec
double theta = 0.0; //initail pose
double d=0;


void turtleCallback(pixart_localization::measured_point msg){
    // Copy leader information into global variables
    turtle_pose.x   = msg.x                ;
    turtle_pose.y   = msg.y                ;
    
    x = turtle_pose.x[turtle_pose.x.size()-1] ;
    y = turtle_pose.y[turtle_pose.y.size()-1] ;
    d=sqrt((x-center_x)*(x-center_x)+(y-center_y)*(y-center_y));

    localizationInfoReceived = true ;
   
}


int main (int argc, char** argv)
{

    //ROS Initialization
    ros::init(argc, argv, "turtle_control_demo_node");
    ROS_INFO("Connected !!!!!");
    ros::NodeHandle nh_("~");//ROS Handler - local namespace.
	
    nh_.param("Kp",Kp,1.0);

    //Subscribing
    ROS_INFO("Subscribing to topics\n");

    //ros::Subscriber pose
    ros::Subscriber turtle
        = nh_.subscribe<pixart_localization::measured_point> ("/measurements"  , 1, turtleCallback);
	
    //Publishing follower velocity
    pub_command = nh_.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);

    ros::Rate rate(FREQUENCY) ;
    ROS_INFO("Turtle control spinning @ 20Hz");

    
    while (ros::ok()){

        // Attend callbacks
        ros::spinOnce();

        geometry_msgs::Twist cmd_msg;


        if( !localizationInfoReceived){ 

            // Inform if there is no localization information
            ROS_INFO("No localization information!") ;
            
            // No velocities sent if no localization data
            cmd_msg.linear.x  = 0.0 ;
            cmd_msg.linear.y  = 0.0 ;
            cmd_msg.angular.z = 0.0 ;

        }
        else{
                
                cmd_msg.linear.x  = v_des ;
                cmd_msg.linear.y  = 0.0   ;
                cmd_msg.angular.z = w_des+Kp*(d-R) ;
            
                pub_command.publish(cmd_msg) ;					
                // We expect new information before next control period.
                localizationInfoReceived   = false ;

            }

        rate.sleep();
    } 

    ROS_INFO("ROS-Node Terminated\n");
}
