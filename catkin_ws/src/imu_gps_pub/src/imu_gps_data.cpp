#include "ros/ros.h"
#include <sensor_msgs/Imu.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "imu_gps");
    ros::NodeHandle n;

    ros::Publisher IMU_pub = n.advertise<sensor_msgs::Imu>("IMU_data", 20);
    ros::Publisher GPS_pub = n.advertise <sensor_msgs::NavSatFix>("GPS_data", 20);

    ros::Rate loop_rate(50);

    while (ros::ok())
    {
        /**************** imu消息的赋值和发布 ****************/
        sensor_msgs::Imu imu_data;
        imu_data.header.stamp = ros::Time::now();
        imu_data.header.frame_id = "base_link";
        // 四元数位姿,所有数据设为固定值
        imu_data.orientation.x = -1;
        imu_data.orientation.y = -5;
        imu_data.orientation.z = 6;
        imu_data.orientation.w = 6;
        // 线加速度
        imu_data.linear_acceleration.x = 0.01;
        imu_data.linear_acceleration.y = 0.02;
        imu_data.linear_acceleration.z = 0.03;
        // 角速度
        imu_data.angular_velocity.x = 0.05;
        imu_data.angular_velocity.y = 0.06;
        imu_data.angular_velocity.z = 0.07;

        /**************** gps消息的赋值和发布 ****************/
        sensor_msgs::NavSatFix gps_data;
        gps_data.header.stamp = ros::Time::now();
        gps_data.header.frame_id = "base_link";

        //gps_data.status="working";
        gps_data.latitude=36.6555;
        gps_data.longitude=117.2656;
        gps_data.altitude=40.5;

        IMU_pub.publish(imu_data);
        GPS_pub.publish(gps_data);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}