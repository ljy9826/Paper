#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
  Mat src = imread("/home/j11218gpu/ljy_projects/paper/saliencymap/xian2.jpg", 0);
  Mat dst = imread("/home/j11218gpu/ljy_projects/paper/imag/img2.jpg");
  string write_path1 = "/home/j11218gpu/ljy_projects/paper/imag/cut2.jpg";
  string write_path2 = "/home/j11218gpu/ljy_projects/paper/imag/xianzhu2.jpg";
  Mat thre_src;
  threshold(src, thre_src, 180, 255, CV_THRESH_BINARY);

  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  findContours(thre_src, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

  vector<Rect> boundRect(contours.size());  //定义外接矩形集合

  for (int i = 0; i < contours.size(); i++) {
    boundRect[i] = boundingRect(Mat(contours[i]));
    if (boundRect[i].width < 30 || boundRect[i].height < 30) continue;
    Point lu = Point(boundRect[i].x - 15, boundRect[i].y - 15); //左上
    Point rd = Point(boundRect[i].x + boundRect[i].width + 30, boundRect[i].y + boundRect[i].height + 30); //右下
    rectangle(dst, lu, rd, Scalar(0, 255, 0), 2, 8);
    cout << lu << rd << endl;
    cout <<rd.x-lu.x<<endl;
    cout << boundRect[i].size() << endl;
  }
  imwrite(write_path1, dst);
  imwrite(write_path2, thre_src);
  imshow("src", src);
  imshow("thre_src", thre_src);
  imshow("dst", dst);
  waitKey();
  return 0;
}
