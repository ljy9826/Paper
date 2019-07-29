#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <sys/time.h>
#include <iostream>

using namespace cv;
using namespace std;

Vec3b RandomColor(int value);  //生成随机颜色函数

const int mx[] = {0, 0, 1, -1};
const int my[] = {1, -1, 0, 0};
int v[1000][1000];
Mat image;

void dfs(int x, int y, Mat mask) {
  cout <<x<<' '<<y<<endl;
  image.at<Vec3b>(y, x) = Vec3b(0, 0, 0);
  imshow("AddWeighted Image", image);
  waitKey(1);
  int dx, dy;
  int mask_col = image.cols;
  int mask_row = image.rows;
  for (int i = 0; i < 4; i++) {
    dx = x + mx[i];
    dy = y + my[i];
    if (dx > 0 && dx < mask_col && dy > 0 && dy < mask_row && !v[dx][dy] && mask.at<int>(dy,dx) != -1) {
      v[dx][dy] = 1;
      dfs(dx,dy,mask);
    }
  }
}

//*******************************************************************//
//鼠标回调函数
int kx,ky;

void fun(int x,int y)
{
  kx = x;
  ky = y;
}
void OnMouseAction(int event,int x,int y,int flags,void *ustc)
{
  kx = ky = -1;
  if(event==CV_EVENT_LBUTTONDOWN)
  {
    cout<<"触发左键按下事件"<<endl;

    fun(x,y);
    cout <<kx<<'#'<<ky<<endl;
  }
}

int main() {
  struct timeval start, end;

//  namedWindow("After Watershed",WINDOW_NORMAL);

  image = imread("/home/j11218gpu/ljy_projects/paper/image/img2.png");    //载入RGB彩色图像

  resize(image, image, Size(320, 240));

  gettimeofday(&start, NULL);

  //imshow("Source Image",image);

  //灰度化，滤波，Canny边缘检测
  Mat imageGray;
  cvtColor(image, imageGray, CV_RGB2GRAY);//灰度转换
  GaussianBlur(imageGray, imageGray, Size(5, 5), 2);   //高斯滤波
  //imshow("Gray Image",imageGray);
  int canny_key = 110;
  Canny(imageGray, imageGray, canny_key, canny_key * 3);
  //imshow("Canny Image",imageGray);

  //查找轮廓
  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;
  findContours(imageGray, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
  Mat imageContours = Mat::zeros(image.size(), CV_8UC1);  //轮廓
  Mat marks(image.size(), CV_32S);   //Opencv分水岭第二个矩阵参数
  marks = Scalar::all(0);
  int index = 0;
  int compCount = 0;
  for (; index >= 0; index = hierarchy[index][0], compCount++) {
    //对marks进行标记，对不同区域的轮廓进行编号，相当于设置注水点，有多少轮廓，就有多少注水点
    drawContours(marks, contours, index, Scalar::all(compCount + 1), 1, 8, hierarchy);
    drawContours(imageContours, contours, index, Scalar(255), 1, 8, hierarchy);
  }

  //我们来看一下传入的矩阵marks里是什么东西
  Mat marksShows;
  convertScaleAbs(marks, marksShows);
  imshow("marksShow", marksShows);
  imshow("轮廓", imageContours);
  watershed(image, marks);

  gettimeofday(&end, NULL);

  double timeuse = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

  printf("time=%f\n", timeuse);

  //我们再来看一下分水岭算法之后的矩阵marks里是什么东西
  Mat afterWatershed;
  convertScaleAbs(marks, afterWatershed);
  imshow("After Watershed", afterWatershed);

//  //对每一个区域进行颜色填充
//  Mat PerspectiveImage = Mat::zeros(image.size(), CV_8UC3);
//  for (int i = 0; i < marks.rows; i++) {
//    for (int j = 0; j < marks.cols; j++) {
//      int index = marks.at<int>(i, j);
//      if (marks.at<int>(i, j) == -1) {
//        PerspectiveImage.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
//      } else {
//        PerspectiveImage.at<Vec3b>(i, j) = RandomColor(index);
//      }
//    }
//  }
//  imshow("After ColorFill", PerspectiveImage);

  //分割并填充颜色的结果跟原始图像融合
  Mat wshed;
  //addWeighted(image, 0.4, PerspectiveImage, 0.6, 0, wshed);
  Mat PerspectiveImage = Mat::zeros(image.size(), CV_8UC3);
  for (int i = 0; i < marks.rows; i++) {
    for (int j = 0; j < marks.cols; j++) {
      int index = marks.at<int>(i, j);
      if (marks.at<int>(i, j) == -1) {
        circle(image, Point(j, i), 3, Scalar(0, 0, 0));
        //image.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
      }
    }
  }

  imshow("AddWeighted Image", image);
  setMouseCallback("AddWeighted Image",OnMouseAction);
  while(1)
  {

    if(kx!=-1){
      cout <<kx<<'*'<<ky<<endl;
      dfs(kx,ky,marks);
      imwrite("/home/j11218gpu/ljy_projects/paper/image/img_wshed2.png", image);
    }
    imshow("AddWeighted Image dfs", image);
    waitKey(1);
  }

  waitKey();
}

Vec3b RandomColor(int value) {
  value = value % 255;  //生成0~255的随机数
  RNG rng;
//        int aa=rng.uniform(0,value);
//        int bb=rng.uniform(0,value);
//        int cc=rng.uniform(0,value);

  int aa = 255;
  int bb = 255;
  int cc = 255;
  return Vec3b(aa, bb, cc);
}