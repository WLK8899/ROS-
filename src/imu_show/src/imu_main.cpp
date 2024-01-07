#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include <iostream>

void callbacki(const sensor_msgs::Imu::ConstPtr &a){
    std::cout<<"std_msgs/Header header"<<std::endl;
    std::cout<<"uint32 seq: "<<a->header.seq<<std::endl;
    std::cout<<"time stamp: "<<a->header.stamp<<std::endl;
    std::cout<<"frame_id: "<<a->header.frame_id<<std::endl;
    std::cout<<"orientation: "<<std::endl;
    std::cout<<"float64 x: "<<a->orientation.x<<std::endl;
    std::cout<<"float64 y: "<<a->orientation.y<<std::endl;
    std::cout<<"float64 z: "<<a->orientation.z<<std::endl;
    std::cout<<"float64 w: "<<a->orientation.w<<std::endl;
    for(int i=0;i<9;i++){
        std::cout<<"orientation_covariance: "<<a->orientation_covariance[i]<<std::endl;
    }
    std::cout<<"angular_velocity: "<<std::endl;
    std::cout<<"float64 x: "<<a->angular_velocity.x<<std::endl;
    std::cout<<"float64 y: "<<a->angular_velocity.y<<std::endl;
    std::cout<<"float64 z: "<<a->angular_velocity.z<<std::endl;
    for(int i=0;i<9;i++){
        std::cout<<"angular_velocity_covariance: "<<a->angular_velocity_covariance[i]<<std::endl;
    }
    std::cout<<"linear_acceleration: "<<std::endl;
    std::cout<<"float64 x: "<<a->linear_acceleration.x<<std::endl;
    std::cout<<"float64 y: "<<a->linear_acceleration.y<<std::endl;
    std::cout<<"float64 z: "<<a->linear_acceleration.z<<std::endl;
    for(int i=0;i<9;i++){
        std::cout<<"linear_acceleration_covariance: "<<a->linear_acceleration_covariance[i]<<std::endl;
    }

    std::cout<<"                 end                 "<<std::endl;
    return ;

}

int main(int argc,char **argv){
    ros::init(argc,argv,"imu_show");
    ros::NodeHandle n;
    ros::Subscriber nn = n.subscribe("/imu/data_raw",1000,callbacki);
    ros::spin();

    return 0;
}