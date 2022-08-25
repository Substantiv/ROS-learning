cmake_minimum_required(VERSION 3.0.2)
project(hello_world)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        )

catkin_package(
        INCLUDE_DIRS include
        LIBRARIES hello_world
        CATKIN_DEPENDS roscpp rospy std_msgs
        DEPENDS system_lib
)

include_directories(${catkin_INCLUDE_DIRS})

# compile hello_io.cpp
add_executable(hello_io src/hello_io.cpp)
target_link_libraries(hello_io ${catkin_LIBRARIES})
add_dependencies(hello_io ${PROJECT_NAME}_generate_messages_cpp)

add_executable(hello_topic_pub src/hello_topic_pub.cpp)
target_link_libraries(hello_topic_pub ${catkin_LIBRARIES})
add_dependencies(hello_topic_pub ${PROJECT_NAME}_generate_messages_cpp)

add_executable(hello_topic_sub src/hello_topic_sub.cpp)
target_link_libraries(hello_topic_sub ${catkin_LIBRARIES})
add_dependencies(hello_topic_sub ${PROJECT_NAME}_generate_messages_cpp)