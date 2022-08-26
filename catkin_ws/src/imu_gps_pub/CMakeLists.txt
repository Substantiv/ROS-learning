## 搜索头文件和库
find_package(catkin REQUIRED COMPONENTS
        roscpp rospy std_msgs)

# 为catkin提供构建、生成pkg-config和CMake文件所需要的信息
catkin_package(
        INCLUDE_DIRS include                    # 声明给其它package的include路径
        LIBRARIES imu_gps_pub                  # 声明给其它package的库
        CATKIN_DEPENDS roscpp rospy std_msgs    # 本包依赖的catkin package
        DEPENDS system_lib                      # 本包依赖的非catkin package
)

add_executable(${PROJECT_NAME}_node src/imu_gps_data.cpp)
target_link_libraries(${PROJECT_NAME}_node
        ${catkin_LIBRARIES}
        )