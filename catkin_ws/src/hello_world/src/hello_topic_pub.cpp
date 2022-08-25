#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "topic_pub_cpp");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<std_msgs::String>("chatter", 1000);
    std::string content = "Hello World!";
    std_msgs::String msgs;

    ros::Rate loop_rate(0.5);
    int count = 0;

    while(ros::ok())
    {
        count ++;
        msgs.data = content + std::to_string(count);
        ROS_INFO("Publish Topic [chatter]: %s", msgs.data.c_str());
        pub.publish(msgs);

        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}