# 博客说明: https://www.cnblogs.com/shepherd2015/p/11157240.html

cmake_minimum_required(VERSION 2.8)
project(example)

set(PCL_DIR "/software/pcl/pcl-pcl-1.8.1")
# 我没有把PCL装到系统目录里

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# find_package(catkin REQUIRED COMPONENTS
#   cmake_modules
#   pybind11_catkin
# )

# catkin_package(
#   INCLUDE_DIRS include
#   LIBRARIES
#   CATKIN_DEPENDS
#     cmake_modules
#     pybind11_catkin
# )


add_subdirectory(pybind11)
pybind11_add_module(example demo.cpp)

# target_link_libraries(example ${PCL_LIBRARIES}) # error

target_link_libraries(example PRIVATE pybind11::module ${PCL_LIBRARIES})
# https://github.com/pybind/pybind11/issues/976 