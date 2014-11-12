#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cout << "usage: " << argv[0] << " <source image>\n";
        return -1;
    }

    cv::VideoCapture cap(0);

    if(!cap.isOpened())
        return -1;

    cv::ORB orb;
    std::vector<cv::KeyPoint> kp;
    cv::Mat src_img = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    std::vector<cv::KeyPoint> kp_src;

    orb.detect(src_img, kp_src);
    //cv::drawKeypoints(src_img, kp_src, src_img, cv::Scalar(0,255,255));
    //cv::imshow("template", src_img);

    cv::Mat desc_src;
    orb.compute(src_img, kp_src, desc_src);

    for(;;) {

        cv::Mat frame;
        cap >> frame;

        cv::Mat frame_gray = cv::Mat(frame.size(), CV_8UC1);
        cv::cvtColor(frame, frame_gray, CV_RGB2GRAY);

        orb.detect(frame_gray, kp);
        //cv::drawKeypoints(frame, kp, frame, cv::Scalar(0,255,255));
        //cv::imshow("key points", frame);

        cv::Mat descriptors;
        orb.compute(frame_gray, kp, descriptors);

        cv::FlannBasedMatcher matcher;
        std::vector<cv::DMatch> matches;

        // http://stackoverflow.com/a/11798593
        if(desc_src.type() != CV_32F)
            desc_src.convertTo(desc_src, CV_32F);
        if(descriptors.type() != CV_32F)
            descriptors.convertTo(descriptors, CV_32F);

        if(!desc_src.empty() && !descriptors.empty())
            matcher.match(desc_src, descriptors, matches);

        cv::drawMatches(src_img, kp_src, frame_gray, kp, matches, frame, \
                cv::Scalar(255,0,0), cv::Scalar::all(-1), \
                std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

        cv::imshow("match result", frame);

        if(cv::waitKey(30) >= 0) break;
    }


    return 0;
}
