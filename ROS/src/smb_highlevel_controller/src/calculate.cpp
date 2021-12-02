#include "ros/ros.h"
#include <cmath>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

geometry_msgs::Twist g_twist={};

void pub(float x,float y,float angle) {
                                                //what's this means?
    geometry_msgs::Twist twist;

    int a=0;
    if(angle<-0.05&&angle>0.05)
    {
        a=1;
        twist.angular.z=0;
    }
    else if(angle<-0.04)
    {
        twist.angular.z=-0.6;
    }
    else if(angle>0.04)
    {
        twist.angular.z=0.6;
    }
    if(a=1)
    {
        twist.linear.x=0.3;
    }

    g_twist=twist;
}

void getLocation(sensor_msgs::LaserScan::ConstPtr scan_msg)
{
    int scan_size=floor((scan_msg->angle_max - scan_msg->angle_min)/(scan_msg->angle_increment));
    float min_distance=99999;

    for(int j=0; j<scan_size; j++)
    {
        if(min_distance>scan_msg->ranges[j])
            min_distance=scan_msg->ranges[j];
    }

    int i=0;
    for(; ; )
    {
        if(scan_msg->ranges[i]>min_distance)
        {   //ROS_INFO("wwwwww: %d",i);
            i++; continue;

        }
        else
            break;

    }

    float angle_min_distance=((scan_msg->angle_min)+((float)(i)*scan_msg->angle_increment));

    float x_distance=min_distance* cos(angle_min_distance);
    float y_distance=min_distance* sin(angle_min_distance);
    ROS_INFO("\nget angle:%f\nget distance x:%f   y:%f",angle_min_distance,x_distance,y_distance);

    pub(x_distance,y_distance,angle_min_distance);



}


int main(int argc, char **argv)
{


    ros::init(argc,argv,"scan_Control");
    ros::init(argc, argv, "scan_Listener");
    ros::NodeHandle n;

    ros::Rate loop_rate(10);

    ros::Subscriber sub=n.subscribe("/scan",10,&getLocation);
    ros::Publisher publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel",1);

    while(true)
    {
        publisher.publish(g_twist);
        ROS_INFO("\ng_twist date : %f %f",g_twist.angular.z,g_twist.linear.x);
        ros::spinOnce();
        loop_rate.sleep();
    }

     return 0;

}
