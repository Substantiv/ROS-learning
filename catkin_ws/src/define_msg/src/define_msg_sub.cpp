#include <ros/ros.h>
#include "my_topic002/topic_msg.h"
#include <std_msgs/String.h>

// 接收到订阅的消息后，会进入消息回调函数
void test_topic_cb(const my_topic002::topic_msg::ConstPtr & msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("------------------ msg ---------------------");
    ROS_INFO("bool_msg:    [%d]", msg->bool_msg);
    ROS_INFO("string_msg:  [%s]", msg->string_msg.c_str());
    ROS_INFO("float32_msg: [%f]", msg->float32_msg);
    ROS_INFO("float64_msg: [%f]", msg->float64_msg);
    ROS_INFO("int8_msg:    [%d]", msg->int8_msg);
    ROS_INFO("int16_msg:   [%d]", msg->int16_msg);
    ROS_INFO("int32_msg:   [%d]", msg->int32_msg);
    ROS_INFO("int64_msg:   [%ld]", msg->int64_msg);
    ROS_INFO("uint8_msg:   [%d]", msg->uint8_msg);
    ROS_INFO("uint16_msg:  [%d]", msg->uint16_msg);
    ROS_INFO("uint32_msg:  [%d]", msg->uint32_msg);
    ROS_INFO("uint64_msg:  [%ld]", msg->uint64_msg);
    ROS_INFO("time_msg:    [%d.%d]", msg->time_msg.sec, msg->time_msg.nsec);
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "subscriber_topic002");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为my_topic_msg的消息，注册回调函数test_topic_cb
    ros::Subscriber sub_topic = n.subscribe<my_topic002::topic_msg>("my_topic_msg", 100, test_topic_cb);

    // 循环等待回调函数
    ros::spin();

    return 0;
}
