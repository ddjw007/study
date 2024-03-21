//这段代码主要是为了显示文件夹中的图像
#include <iostream>
// #include <opencv2/core.hpp>
// #include <opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;

int main()
{
   Mat img = imread("gangren.png");
   imshow("image",img);
   waitKey(0);
   return 0;
}
