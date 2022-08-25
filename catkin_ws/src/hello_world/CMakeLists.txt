cmake_minimum_required(VERSION 3.0.2)
project(hello_world)

## 搜索头文件和库
find_package(catkin REQUIRED COMPONENTS
        roscpp rospy std_msgs)

# 为catkin提供构建、生成pkg-config和CMake文件所需要的信息
catkin_package(
        INCLUDE_DIRS include                    # 声明给其它package的include路径
        LIBRARIES hello_world                   # 声明给其它package的库
        CATKIN_DEPENDS roscpp rospy std_msgs    # 本包依赖的catkin package
        DEPENDS system_lib                      # 本包依赖的非catkin package
)

# 将指定目录添加到编译器的头文件搜索路径之下
include_directories(${catkin_INCLUDE_DIRS})

################### compile hello_io.cpp ###################
# 将工程外部的可执行目标文件导入进来
add_executable(hello_io src/hello_io.cpp)
# 设置要链接的库文件的名称
target_link_libraries(hello_io ${catkin_LIBRARIES})
# 提醒编译器需要生成依赖
add_dependencies(hello_io ${PROJECT_NAME}_generate_messages_cpp)

################### compile hello_topic_pub.cpp ###################
add_executable(hello_topic_pub src/hello_topic_pub.cpp)
target_link_libraries(hello_topic_pub ${catkin_LIBRARIES})
add_dependencies(hello_topic_pub ${PROJECT_NAME}_generate_messages_cpp)

################### compile hello_topic_sub.cpp ###################
add_executable(hello_topic_sub src/hello_topic_sub.cpp)
target_link_libraries(hello_topic_sub ${catkin_LIBRARIES})
add_dependencies(hello_topic_sub ${PROJECT_NAME}_generate_messages_cpp)