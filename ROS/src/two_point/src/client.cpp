//
// Created by yuchen on 2021/11/24.
//
#include "ros/ros.h"
#include "two_point/add_two.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<two_point::add_two>("service1");

    two_point::add_two srv;

    srv.request.i3 = 3;
    srv.request.i2 = 2;
    srv.request.i1 = 1;

    if(client.call(srv)) {
        ROS_INFO("service success result:%d", srv.response.result);
    }
    else
    {
        ROS_INFO("failed!");
        return 1;
    }

    return 0;
}
