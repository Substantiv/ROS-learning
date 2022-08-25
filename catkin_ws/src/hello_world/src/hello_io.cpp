#include "ros/ros.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "hello_io");              // 初始化节点
    ROS_INFO("[By IO] Hello ROS!!!");               // ROS自带IO

    return 0;
}
