
#include <ros/ros.h>
#include <sensor_msgs//LaserScan.h>
#include "std_msgs/String.h"

void chatterCallback ( const sensor_msgs::LaserScan::ConstPtr& msg )
{
    ROS_INFO("I heard: [%.14f]",msg->range_min);

}

int main(int argc,char *argv[])
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;

    ros::Subscriber sub =
            n.subscribe("/scan",10,&chatterCallback);
    ros::spin();


    return 0;

}
