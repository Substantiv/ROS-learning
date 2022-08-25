#include "ros/ros.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "hello_io");
    ROS_INFO("[By IO] Hello ROS!!!");

    return 0;
}
