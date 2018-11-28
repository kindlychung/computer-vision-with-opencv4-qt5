#include <QtWidgets/QApplication>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "CvWindow.h"
int main(int argc, char** argv) {
    using namespace cv;
    QApplication app(argc, argv);
    // Mat image = imread(argv[1]);
    // imshow("Image", image);
    // SimpleFileBrowser window("Input image:");
    CvWindow window;
    window.show();

    return app.exec();
}
