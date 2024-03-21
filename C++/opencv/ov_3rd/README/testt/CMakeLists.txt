cmake_minimum_required(VERSION 3.10)

find_package(OpenCV REQUIRED)
include_directories("/home/libb/opencv4.5")  #这的地址是刚编译的opencv文件，按实际情况填写
# add executable
add_executable( main main.cpp)
# link libraries
target_link_libraries( main ${OpenCV_LIBS})
