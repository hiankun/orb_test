# ORB test

## Introduction
This is a test of detecting planar objects by using [Opencv ORB](http://docs.opencv.org/modules/features2d/doc/feature_detection_and_description.html#orb).
I made the code based on [some OpenCV examples](http://docs.opencv.org/doc/tutorials/features2d/feature_homography/feature_homography.html#feature-homography)
for the purpose of self-study.

## Usage
There is a bash script named ``make_opencv.sh'' which can be used to compile the source code:

    bash make_opencv.sh orb_match.cpp

After compiling the source, just run the code by typing:

    orb_match <source image> <method: 0 or 1>

The pics folder has some photos for my own test, and you shall put in yours.

## License
[MIT](http://choosealicense.com/licenses/mit/)
