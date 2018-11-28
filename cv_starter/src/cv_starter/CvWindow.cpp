#include "CvWindow.h"
#include <QDebug>
#include <QtWidgets/QSizePolicy>

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
                                          BrowsePurpose::GetDir, this);
    for (auto w : (QWidget*[]){filterOptWidget, inputBrowser, outputBrowser,
                               buttonRow}) {
        w->setSizePolicy(minPolicy);
        layout->addWidget(w);
    }
    widget->setLayout(layout);
    setCentralWidget(widget);
};

// void CvWindow::handleBrowseButton() { fileDialog->show(); }
