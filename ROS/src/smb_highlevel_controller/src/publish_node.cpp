//
// Created by yuchen on 2021/11/26.
//

#include <ros/ros.h>
#include <iostream>
#include "geometry_msgs/Twist.h"



int main(int argc, char **argv){
    ros::init(argc,argv,"move_control");
    ros::NodeHandle n;
    ros::Publisher publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel",1);

    int number_count = 0;
    //double x1=-0.2,x2=0,y1=0,y2=0,z1=0,z2=0;

    ros::Rate loop_rate(10);
   /* A:
    ROS_INFO("Please enter angular date in type:x y z");
    scanf("%d %d %d",&x1,&y1,&z1);                         //get angular date
    ROS_INFO("Please enter linear date in type: x y z");
    scanf("%d %d %d",&x2,&y2,&z2);                         //get linear date      */
    while(ros::ok())
    {   geometry_msgs::Twist twist;
        geometry_msgs::Twist twist2;

        geometry_msgs::Vector3 linear;
        linear.x=0.3;
        linear.y=0;
        linear.z=0;
        geometry_msgs::Vector3 angular;
        angular.x=0;
        angular.y=0;

        angular.z=0.2;
        twist.linear=linear;
        twist.angular=angular;


       /* twist.angular.x=x1; twist.angular.y=y1; twist.angular.z=z1;
        twist.linear.x=x2; twist.linear.y=y2; twist.linear.z=z2;
       */
        ROS_INFO("\nangular x:%.1f y:%.1f z:%.1f\n linear x:%.1f y:%.1f z:%.1f",
                 twist.angular.x,twist.angular.y,twist.angular.z,twist.linear.x,twist.linear.y,twist.linear.z);
       // if (getchar() == 'q'){goto A;}                                //enter new date

        publisher.publish(twist);                       //you should use "twist_topic" but not "chatter"!

        ros::spinOnce();
        loop_rate.sleep();

 /*       if (getchar() == '`')
        {
            printf("\n\n                 .     .\n              .  |\\-^-/|  .    \n             /| } O.=.O { |\\\n\n                 bye~\n\n");
            break;
        }
*/
        number_count++;
    }

    return 0;
}

