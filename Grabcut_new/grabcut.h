//
// Created by j11218gpu on 18-10-11.
//

#ifndef GRABCUT_GRABCUT_H
#define GRABCUT_GRABCUT_H

#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

static void wevents( int e, int x, int y, int flags, void* ptr );

class GrabCut
{
public:
    GrabCut();
    void	run(Mat img, Mat &msk);
    void	events( int e, int x, int y, int flags);
    void    redo();
    void    undo();
    void    deletePathMask();
    void    deleteAllMask();

private:
    void	show();
    Mat		getFG();
    Mat		getBinMask();
    //jiangbo creat
    Mat		getFGByMask(Mat mask);
    Rect    getMaskRct( Mat maskMat );
    Mat     filterMaskAndMergeMat(Mat srcMat, Mat matStore, Mat filterRuleMat);
    bool    diffRect(Rect r1, Rect r2);
    void    showBit( cv::Mat gray, cv::Mat & out );
    Mat     mergeMat( Mat mergeMat, Mat mergeToMat, Rect mergeRect );
    //void    processCut(const Mat mergeToMat ,const Mat msk, Mat & resultMaskMat, Mat &resultColorMat);
    void    grabcutByMergeToMatAndMskMat(const Mat mergeToMat ,const Mat msk, Mat & resultMaskMat, Mat &resultColorMat);
    Mat		getBinMaskByMask(cv::Mat mask);
    void    processGrabCut(std::vector<cv::Point> maskPoint, int lineWidth, Mat &resultMaskMat, Mat &resultColorMat);

    //creat end
    Mat _gcut;
    int _mode;
    Mat _src;
    Mat _bin;
    Mat _tmp;
    Mat _mask;
    Mat _fgd;
    Mat _bgd;
    Mat _dsp;
    Point _pt;
    Point lstart;
    Point rstart;
    bool ldrag;
    bool rdrag;
    //int lab;
    string _name;
private:
    Mat _gcutBuffer;
    Mat _cutResultMask;
    Mat _maskStore;
    vector<Mat> matStoreArray;
};


#endif //GRABCUT_GRABCUT_H
