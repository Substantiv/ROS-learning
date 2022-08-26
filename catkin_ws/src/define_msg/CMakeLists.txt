cmake_minimum_required(VERSION 3.0.2)
project(define_msg)


find_package(catkin REQUIRED COMPONENTS
        message_generation
        message_runtime
        roscpp
        rospy
        std_msgs
        )

## 添加消息文件，指定.msg文件
add_message_files(
        FILES
        topic_msg.msg
)

## 指定生成消息文件时的依赖项
generate_messages(
        DEPENDENCIES
        std_msgs
)

catkin_package(
        #  INCLUDE_DIRS include
        #  LIBRARIES define_msg
        #  CATKIN_DEPENDS message_generation message_runtime roscpp rospy std_msgs
        #  DEPENDS system_lib
)

## 编写编译规则，生成的可执行文件名字、源码、链接库、依赖等内容
add_executable(define_msg_pub src/define_msg_pub.cpp)
target_link_libraries(define_msg_pub ${catkin_LIBRARIES})
add_dependencies(define_msg_pub ${PROJECT_NAME}_generate_messages_cpp)

add_executable(define_msg_sub2 src/define_msg_sub.cpp)
target_link_libraries(define_msg_sub ${catkin_LIBRARIES})
add_dependencies(define_msg_sub ${PROJECT_NAME}_generate_messages_cpp)
