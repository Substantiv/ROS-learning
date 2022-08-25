#include "ros/ros.h"
#include "std_msgs/String.h"

void callback(const std_msgs::String::ConstPtr & string_ptr)
{
    ROS_INFO("This is subscriber, I have received the data : %s", string_ptr->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "topic_sub_cpp");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe<std_msgs::String>("chatter", 1000, callback);
    // 循环执行callback
    ros::spin();
    return 0;
}
