//
// Created by yuchen on 2021/11/24.
//
#include "ros/ros.h"
#include <two_point/add_two.h>


bool add(two_point::add_two::Request &req,
         two_point::add_two::Response &res)
{
    res.result = req.i1 + req.i2 + req.i3;
    ROS_INFO("sending service add");
    return true;
}
int main(int argc, char **argv)
{
    ros::init(argc,argv,"service_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("service1",add);
    ROS_INFO("service Ready!");
    ros::spin();

    return 0;
}







