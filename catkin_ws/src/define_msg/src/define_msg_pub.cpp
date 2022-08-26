/*
 * @Author: jiejie
 * @Github: https://github.com/jiejieTop
 * @Date: 2020-04-11 23:16:46
 * @LastEditTime: 2020-04-12 12:17:00
 * @Description: the code belongs to jiejie, please keep the author information and source code according to the license.
 */
#include <ros/ros.h>
#include "my_topic002/topic_msg.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "publisher_topic002");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher，发布名为my_topic_msg，消息类型为my_topic002::topic_msg，队列长度100
    ros::Publisher pub_topic = n.advertise<my_topic002::topic_msg>("my_topic_msg",100);

    // 设置循环的频率
    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        // 初始化std_msgs::String类型的消息
        my_topic002::topic_msg msg;
        msg.bool_msg = true;
        msg.string_msg = "hello world!";
        msg.float32_msg = 6.66;
        msg.float64_msg = 666.666;
        msg.int8_msg = -66;
        msg.int16_msg = -666;
        msg.int32_msg = -6666;
        msg.int64_msg = -66666;
        msg.uint8_msg = 66;
        msg.uint16_msg = 666;
        msg.uint32_msg = 6666;
        msg.uint64_msg = 66666;
        msg.time_msg = ros::Time::now();

        // 发布消息
        pub_topic.publish(msg);

        // 按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}
