#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloud;

class PclSub
{
public:
    PclSub(ros::NodeHandle& nh) : viewer("PointCloud Viewer")
    {
        sub_novel = nh.subscribe<sensor_msgs::PointCloud2>("/rslidar_points", 1, &PclSub::topic_callback, this);
    }

private:
    ros::Subscriber sub_novel;
    pcl::visualization::CloudViewer viewer;

    void topic_callback(const sensor_msgs::PointCloud2ConstPtr& msg)
    {
        PointCloud::Ptr cloud(new PointCloud);
        pcl::fromROSMsg(*msg, *cloud);

        viewer.showCloud(cloud);
    }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pclsub");
    ros::NodeHandle nh;

    PclSub pcl_sub(nh);

    ros::spin();

    return 0;
}