cmake_minimum_required(VERSION 3.16.0)
project(pyrosmsg)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  geometry_msgs
  nav_msgs
  pybind11
  pybind11_catkin
  roscpp
  rospy
  sensor_msgs
  std_msgs
  visualization_msgs
  # pcl library
  #pcl_conversions
  # msgs
)

find_package(NUMPY REQUIRED)
#find_package(pybind11 REQUIRED)

catkin_python_setup()

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES
  CATKIN_DEPENDS
    cmake_modules
    geometry_msgs
    nav_msgs
    pybind11_catkin
    roscpp
    rospy
    sensor_msgs
    std_msgs
    visualization_msgs
    #DEPENDS system_lib
)
set(PCL_DIR "/software/pcl/pcl-pcl-1.8.1")
find_package(PCL 1.8 REQUIRED common)

#include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

 set(VTK_DIR /software/vtk/VTK-7.1.1/build)
 find_package(VTK 7.1.1 REQUIRED)
 include_directories(${VTK_INCLUDE_DIRS})
 link_directories(${VTK_LIBRARY_DIRS})


find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
#link_directories(${Boost_LIBRARY_DIRS})
add_definitions(${Boost_DEFINITIONS})

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${VTK_INCLUDE_DIRS}
    ${PCL_INCLUDE_DIRS}
    ${Boost_LIBRARY_DIRS}
    #${PYBIND11_INCLUDE_DIRS}
)

#message("pybind11_include_dir " ${PYBIND11_INCLUDE_DIRS})
#add_subdirectory(pybind11)
pybind_add_module(libpyrosmsg ${PYTHON_EXECUTABLE}
    src_wrap/module.cpp
)

target_link_libraries(libpyrosmsg PRIVATE pybind11::module 
                     #${catkin_LIBRARIES} 
                     pcl_visualization
                     )
