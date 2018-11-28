#include "CvWindow.h"
#include <QDebug>
#include <QtWidgets/QSizePolicy>
#include <opencv2/opencv.hpp>

CvWindow::CvWindow(QWidget* parent) : QMainWindow(parent) {
    auto minPolicy = QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    auto expandPolicy = QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    widget = new QWidget;
    buttonRow = new SingleButtonRow("&Apply filter");
    layout = new QVBoxLayout;
    filterOptWidget = new FilterTypeChooser;
    allFilters = tr("All files (*.*);;PNG (*.png)");
    *filter = tr("PNG (*.png)");
    inputBrowser = new SimpleFileBrowser(QString("Input"), allFilters, filter,
                                         BrowsePurpose::GetFile, this);
    outputBrowser = new SimpleFileBrowser(QString("Output"), allFilters, filter,
                                          BrowsePurpose::SaveFile, this);
    for (auto w : (QWidget*[]){filterOptWidget, inputBrowser, outputBrowser,
                               buttonRow}) {
        w->setSizePolicy(minPolicy);
        layout->addWidget(w);
    }
    widget->setLayout(layout);
    setCentralWidget(widget);
    connect(buttonRow->button, &QPushButton::clicked, [=]() {
        if (!inputBrowser->getPath().isEmpty()) {
            using namespace cv;
            Mat inImg, outImg;
            inImg = imread(inputBrowser->getPath().toStdString());
            if (filterOptWidget->medianBlurOpt->isChecked()) {
                medianBlur(inImg, outImg, 5);
            } else {
                GaussianBlur(inImg, outImg, Size(5, 5), 1.25);
            }
            imwrite(outputBrowser->getPath().toStdString(), outImg);
            if (filterOptWidget->displayOrNot->isChecked()) {
                imshow("Output image", outImg);
            }
        }
    });
};

// void CvWindow::handleBrowseButton() { fileDialog->show(); }
