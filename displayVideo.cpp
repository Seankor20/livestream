#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

    VideoCapture cap(0);                                    // opens camera
    if(!cap.isOpened()){                                    // checks if it is opened
        cout << "Camera is not opened" << endl;             // error msg
        return -1;
    }

    double videoWidth = cap.get(CAP_PROP_FRAME_WIDTH);
    double videoHeight = cap.get(CAP_PROP_FRAME_HEIGHT);
    namedWindow("livestream");
    while(true){                                            // loops video frame
        Mat frame;                                          // initialize Mat obj frame
        if(!cap.read(frame)){                               // if video is not on, break
            break;
        }
        imshow("livestream", frame);                        // gets livestream of video
        if( waitKey(30) >= 27) {                            // wait for 30 ms until key is pressed
            break;                                          // if ESC is pressed, break
        }
    }

    return 0;
}
