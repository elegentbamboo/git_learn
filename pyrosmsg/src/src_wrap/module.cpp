/**
 * @author  Daniel Maturana
 * @year    2015
 *
 * @attention Copyright (c) 2015
 * @attention Carnegie Mellon University
 * @attention All rights reserved.
 *
 **@=*/
// #include "vtkAutoInit.h" 
// VTK_MODULE_INIT(vtkRenderingOpenGL);
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

#include <pyrosmsg/converters.hpp>
#include <pyrosmsg/serialization.hpp>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/impl/point_cloud_geometry_handlers.hpp>
#include <pcl/visualization/point_cloud_geometry_handlers.h>
#include <pcl/console/parse.h>
#include <pcl/point_representation.h>
#include <pcl/filters/filter.h>
#include <pcl/registration/transforms.h>

namespace pyrosmsg {
pcl::visualization::PCLVisualizer *vis;
namespace py = pybind11;

void print_cam_info(const sensor_msgs::CameraInfo& ci) {
  std::cout << "distortion model\n";
  std::cout << ci.distortion_model << "\n";
  std::cout << "K R P [8]\n";
  std::cout << ci.K[8] << " " << ci.R[8] << " " << ci.P[8] << "\n";
  std::cout << "\n";
}

void print_centroid(const sensor_msgs::PointCloud2& cloud) {
  double cx = 0., cy = 0., cz = 0.;
  for (size_t i = 0; i < cloud.width; ++i) {
    float x =
        *reinterpret_cast<const float*>(&cloud.data[i * cloud.point_step]);
    float y = *reinterpret_cast<const float*>(
        &cloud.data[i * cloud.point_step + sizeof(float)]);
    float z = *reinterpret_cast<const float*>(
        &cloud.data[i * cloud.point_step + 2 * sizeof(float)]);
    cx += x;
    cy += y;
    cz += z;
  }
  std::cerr << "cloud.width = " << cloud.width << std::endl;
  cx /= cloud.width;
  cy /= cloud.width;
  cz /= cloud.width;
  std::cout << "centroid = [" << cx << " " << cy << " " << cz << "]"
            << std::endl;
  
  printf("1");
  
}

void print_centroid2(const std::string& smsg) {
  // using generic serialization method
  sensor_msgs::PointCloud2 cloud;
  pyrosmsg::deserialize<sensor_msgs::PointCloud2>(smsg, cloud);

  double cx = 0., cy = 0., cz = 0.;
  for (size_t i = 0; i < cloud.width; ++i) {
    float x =
        *reinterpret_cast<const float*>(&cloud.data[i * cloud.point_step]);
    float y = *reinterpret_cast<const float*>(
        &cloud.data[i * cloud.point_step + sizeof(float)]);
    float z = *reinterpret_cast<const float*>(
        &cloud.data[i * cloud.point_step + 2 * sizeof(float)]);
    cx += x;
    cy += y;
    cz += z;
  }
  std::cerr << "cloud.width = " << cloud.width << std::endl;
  cx /= cloud.width;
  cy /= cloud.width;
  cz /= cloud.width;
  std::cout << "centroid = [" << cx << " " << cy << " " << cz << "]"
            << std::endl;
}

sensor_msgs::PointCloud2 make_pc2(int rows) {
  sensor_msgs::PointCloud2 pc;
  pc.width = rows;
  pc.height = 1;
  sensor_msgs::PointField pfx;
  pfx.name = "x";
  pfx.offset = 0;
  pfx.datatype = sensor_msgs::PointField::FLOAT32;
  pfx.count = 1;
  pc.fields.push_back(pfx);
  pc.point_step = sizeof(float);
  float data[rows];
  for (int i = 0; i < rows; ++i) {
    data[i] = 28.0;
  }
  pc.data.insert(pc.data.end(),
                 reinterpret_cast<const uint8_t*>(data),
                 reinterpret_cast<const uint8_t*>(data + rows));
  return pc;
}

sensor_msgs::PointCloud2 make_pc2_from_numpy(py::array_t<float, 2> xyz) {
  sensor_msgs::PointCloud2 pc;

  sensor_msgs::PointField pfx;
  pfx.name = "x";
  pfx.offset = 0;
  pfx.datatype = sensor_msgs::PointField::FLOAT32;
  pfx.count = 1;
  pc.fields.push_back(pfx);

  sensor_msgs::PointField pfy;
  pfx.name = "y";
  pfx.offset = 4;
  pfx.datatype = sensor_msgs::PointField::FLOAT32;
  pfx.count = 1;
  pc.fields.push_back(pfy);

  sensor_msgs::PointField pfz;
  pfx.name = "z";
  pfx.offset = 4;
  pfx.datatype = sensor_msgs::PointField::FLOAT32;
  pfx.count = 1;
  pc.fields.push_back(pfz);

  pc.point_step = sizeof(float) * 3;

  // making assumptions on c-style numpy!
  auto xyz_buf = xyz.unchecked();
  pc.data.insert(
      pc.data.end(),
      reinterpret_cast<const uint8_t*>(xyz_buf.data(0, 0)),
      reinterpret_cast<const uint8_t*>(xyz_buf.data(0, 0) + xyz_buf.nbytes()));
  pc.width = xyz.shape(0);
  pc.height = 1;
  return pc;
}

ros::Time make_time() {
  ros::Time ts;
  ts.sec = 28;
  ts.nsec = 999;
  return ts;
}

void print_time(const ros::Time& ts) {
  std::cerr << "ts.sec = " << ts.sec << std::endl;
  std::cerr << "ts.nsec = " << ts.nsec << std::endl;
}

ros::Time increment_ts(const ros::Time& ts) {
  std::cerr << "ts.sec = " << ts.sec << ", ts.nsec = " << ts.nsec << std::endl;
  ros::Time newts(ts.sec + 1, ts.nsec + 1);
  std::cerr << "newts.sec = " << newts.sec << ", newts.nsec = " << newts.nsec
            << std::endl;
  return newts;
}

std_msgs::Header make_header(int seq, std::string frame_id) {
  std_msgs::Header out;
  out.frame_id = frame_id;
  out.seq = seq;
  return out;
}

void print_header_seq(std_msgs::Header& header) {
  std::cerr << "header.seq = " << header.seq << std::endl;
}

void print_img(const sensor_msgs::Image& img) {
  std::cerr << "img.width = " << img.width << std::endl;
  std::cerr << "img.height = " << img.height << std::endl;
  std::cerr << "img.step = " << img.step << std::endl;
  std::cerr << "[";
  for (int i = 0; i < img.width * img.height; ++i) {
    std::cerr << (int)img.data[i] << ", ";
  }
  std::cerr << "]\n";
}

sensor_msgs::Image make_img(int width, int height) {
  sensor_msgs::Image msg;
  msg.width = width;
  msg.height = height;
  msg.encoding = "8UC1";
  msg.step = width;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      msg.data.push_back(width * i + j);
    }
  }
  return msg;
}

void display(const sensor_msgs::PointCloud2& input) {
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);
  pcl::fromROSMsg(input, *cloud);
  if(vis==NULL)
        vis = new pcl::visualization::PCLVisualizer ("Original Lidar Point Cloud");
    vis->addCoordinateSystem(1.0);
    vis->removeAllPointClouds();
    vis->removeAllShapes();
    pcl::PointCloud<pcl::PointXYZI>::Ptr segClouds(new pcl::PointCloud<pcl::PointXYZI>);
        pcl::PointXYZI o;
        //pcl::visualization::PCLVisualizer viewer("display");
        for(int j=0;j<cloud->points.size();j++){
            o.x=cloud->points[j].x;
            o.y=cloud->points[j].y;
            o.z=cloud->points[j].z;
            o.intensity=cloud->points[j].intensity;
            segClouds->points.push_back(o);
        }
        pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZI> fildColor(segClouds, "intensity");//按照z字段进行渲染
        vis->addPointCloud<pcl::PointXYZI>(segClouds, fildColor);//显示点云，其中fildColor为颜色显示
        vis->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 0.2);//设置点云大小

//        if(pause)
//            vis->spin();
//        else
            vis->spinOnce(10);

}

}

PYBIND11_MODULE(libpyrosmsg, m) {
  // note - these methods are just sanity
  // checks. all the important stuff is in
  // the header.

  m.doc() = "libpyrosmsg module";

  m.def("print_cam_info", &pyrosmsg::print_cam_info);
  m.def("print_centroid", &pyrosmsg::print_centroid);
  m.def("print_centroid2", &pyrosmsg::print_centroid2);
  m.def("make_pc2", &pyrosmsg::make_pc2);
  m.def("make_pc2_from_numpy", &pyrosmsg::make_pc2_from_numpy);
  m.def("print_time", &pyrosmsg::print_time, "print time");
  m.def("make_time", &pyrosmsg::make_time, "make time");
  m.def("make_header", &pyrosmsg::make_header);
  m.def("increment_ts", &pyrosmsg::increment_ts);
  m.def("print_header_seq", &pyrosmsg::print_header_seq);
  m.def("print_img", &pyrosmsg::print_img);
  m.def("make_img", &pyrosmsg::make_img);
  m.def("display", &pyrosmsg::display);
}
