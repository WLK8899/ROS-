# cmake_minimum_required(VERSION 2.8.3)
# project(usb_cam)


# find_package(catkin REQUIRED COMPONENTS
#   cv_bridge
#   image_transport
#   roscpp
#   sensor_msgs
#   std_msgs
# )


# find_package(OpenCV REQUIRED)
# find_package(PCL REQUIRED COMPONENTS common io)


# catkin_package(
# #  INCLUDE_DIRS include
# #  LIBRARIES usb_cam
# #  CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
# #  DEPENDS system_lib
# )
# include_directories(
#   ${catkin_INCLUDE_DIRS}
#   ${OpenCV_INCLUDE_DIRS}
#   ${PCL_INCLUDE_DIRS}
# )

# link_directories(${PCL_LIBRARY_DIRS})

# add_definitions(${PCL_DEFINITIONS})

# add_executable(usb_cam_node src/usb_cam_node.cpp)
# target_link_libraries(usb_cam_node  ${catkin_LIBRARIES} ${OpenCV_LIBS})

# add_executable(plc_node src/plc_node.cpp)
# target_link_libraries(plc_node ${catkin_LIBRARIES} ${PCL_LIBRARIES} pcl_visualization)

#add_executable(slam_node src/slam_node.cpp)
#target_link_libraries(slam_node ${catkin_LIBRARIES} ${PCL_LIBRARIES} pcl_visualization)

# add_executable(slam_node src/slam_node.cpp)
# target_link_libraries(slam_node ${catkin_LIBRARIES} ${PCL_LIBRARIES} pcl_common pcl_io pcl_registration)










cmake_minimum_required(VERSION 2.8.3)
project(usb_cam)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

find_package(OpenCV REQUIRED)
find_package(PCL REQUIRED COMPONENTS common io registration visualization)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

link_directories(${PCL_LIBRARY_DIRS})

add_definitions(${PCL_DEFINITIONS})

add_executable(usb_cam_node src/usb_cam_node.cpp)
target_link_libraries(usb_cam_node ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(plc_node src/plc_node.cpp)
target_link_libraries(plc_node ${catkin_LIBRARIES} ${PCL_LIBRARIES} pcl_visualization)

# add_executable(slam_node src/slam_node.cpp)
# target_link_libraries(slam_node ${catkin_LIBRARIES} ${PCL_LIBRARIES} pcl_visualization pcl_registration)
