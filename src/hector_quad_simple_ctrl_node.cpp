#include <iostream>
#include <ros/ros.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <stdlib.h>

 //ROS Images

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
geometry_msgs::TwistStamped vel_cmd_msg;
geometry_msgs::PoseStamped pos_cmd_msg;
// command/pose
// command/twist
int main(int argc, char* argv[])
{
    ros::init(argc, argv, "test_vel_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");
    int ctrl_mode; // 0-pos_ctrl  1-vel_ctrl  2-att_ctrl
    pnh.param("ctrl_mode", ctrl_mode, 1);
    ros::Publisher vel_pub=nh.advertise<geometry_msgs::TwistStamped>("/command/twist",1);
    //ros::Publisher pos_pub = nh.advertise<geometry_msgs::PoseStamped>("/command/pose", 1);
    ros::Rate rate(30);
    while(ros::ok())
    {
        //if (ctrl_mode == 1)
        // {
            vel_cmd_msg.header.frame_id = "velocity_cmd";
            vel_cmd_msg.header.stamp = ros::Time::now();
            vel_cmd_msg.twist.linear.x = 0.0;
            vel_cmd_msg.twist.linear.y = 0.0;
            vel_cmd_msg.twist.linear.z = 0.5;
            vel_cmd_msg.twist.angular.x = 0.0;
            vel_cmd_msg.twist.angular.y = 0.0;
            vel_cmd_msg.twist.angular.z = 0.0;
            vel_pub.publish(vel_cmd_msg);
        // }
        // else if (ctrl_mode == 0)
        // {
        //     pos_cmd_msg.header.frame_id = "pose_cmd";
        //     pos_cmd_msg.header.stamp = ros::Time::now();
        //     pos_cmd_msg.pose.position.x = 0.0;
        //     pos_cmd_msg.pose.position.y = 0.0;
        //     pos_cmd_msg.pose.position.z = 0.5;
        //     pos_cmd_msg.pose.orientation.x = 0.0;
        //     pos_cmd_msg.pose.orientation.y = 0.0;
        //     pos_cmd_msg.pose.orientation.z = 1.0;
        //     pos_cmd_msg.pose.orientation.w = 0.0;
        //     pos_pub.publish(pos_cmd_msg);
        // }
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}