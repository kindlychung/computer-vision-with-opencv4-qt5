
#pragma once
#include <QString>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "FilterTypeChooser.h"
#include "SimpleFileBrowser.h"
#include "SingleButtonRow.h"

class CvWindow : public QMainWindow {
    Q_OBJECT
   public:
    CvWindow(QWidget* parent = nullptr);
    virtual ~CvWindow(){};
    QString* filter;
    QString allFilters;
    //    private:
    //     QString image_path;

   private:
    QWidget* widget;
    QVBoxLayout* layout;
    FilterTypeChooser* filterOptWidget;
    SimpleFileBrowser* inputBrowser;
    SimpleFileBrowser* outputBrowser;
    SingleButtonRow* buttonRow;
    //    private slots:
    //     void handleBrowseButton();
    //     void handleFilePath();
    //    signals:
    //     void fileSelected(std::string);
};