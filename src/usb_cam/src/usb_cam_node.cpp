#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>

void colorImageCallback(const sensor_msgs::Image::ConstPtr& msg)
{
    // Convert the ROS Image message to OpenCV format
    cv_bridge::CvImagePtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    // Display the color image using OpenCV
    cv::imshow("Color Image", cv_ptr->image);
    cv::waitKey(10);  // Adjust the wait time as needed
}

void depthImageCallback(const sensor_msgs::Image::ConstPtr& msg)
{
    // Convert the ROS Image message to OpenCV format
    cv_bridge::CvImagePtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_32FC1);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    // Display the depth image using OpenCV
    cv::imshow("Depth Image", cv_ptr->image);
    cv::waitKey(10);  // Adjust the wait time as needed
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "bag_parser_node");
    ros::NodeHandle nh;

    // Subscribe to color image topic
    ros::Subscriber color_sub = nh.subscribe("/camera/color/image_raw", 10, colorImageCallback);

    // Subscribe to depth image topic
    ros::Subscriber depth_sub = nh.subscribe("/camera/depth/image_rect_raw", 10, depthImageCallback);

    // Spin
    ros::spin();

    return 0;
}
