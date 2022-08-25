#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");              // 设置编码
    ros::init(argc, argv, "topic_pub_cpp");         // 初始化节点,节点名为topic_pub_cpp

    /*
     * NodeHandle是与ROS系统通信的主要访问点（句柄）,有了它节点就可以“说话了”（在话题上发布消息）
     * 构造的第一个NodeHandle将完全初始化该节点，最后一个被析构的NodeHandle将关闭该节点。
     */
    ros::NodeHandle n;

    /*
     * advertise()函数是你告诉ROS你想在给定的话题名上发布特定类型的消息
     * <>里面指定消息的类型
     * 第一个参数为话题名称,第二个参数为发布消息的队列大小
     */
    ros::Publisher pub = n.advertise<std_msgs::String>("chatter", 1000);
    std::string content = "Hello World!";       // 发布的字符串
    /* 要发布的数据类型,数据结构可理解为结构体String内包括data */
    std_msgs::String msgs;

    /*
     * 循环频率0.5Hz
     */
    ros::Rate loop_rate(0.5);
    int count = 0;

    while(ros::ok())
    {
        count ++;
        msgs.data = content + std::to_string(count);
        ROS_INFO("Publish Topic [chatter]: %s", msgs.data.c_str());
        /* 发布消息  */
        pub.publish(msgs);

        /* 以0.5Hz循环,如果循环过快,暂停进行调节 */
        loop_rate.sleep();
        /* 触发回调函数 */
        ros::spinOnce();
    }

    return 0;
}