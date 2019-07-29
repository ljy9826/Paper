#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("/home/j11218gpu/ljy_projects/VOC_img/JPEGImages/000002.jpg");
	Mat midImage, dstImage;

	imshow("srcImage", srcImage);
waitKey();
	cvtColor(srcImage, midImage, COLOR_BGR2GRAY);
	GaussianBlur(midImage, midImage, Size(9, 9), 2, 2);

	vector<Vec3f> circles;
	HoughCircles(midImage, circles, CV_HOUGH_GRADIENT, 1, 10, 150, 60, 0, 0);

	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
	}

	imshow("aaa", srcImage);

	waitKey(0);

	return 0;
}