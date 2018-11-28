
#pragma once
#include <QString>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class FilterTypeChooser : public QWidget {
    Q_OBJECT
   public:
    FilterTypeChooser(QWidget* parent = nullptr);
    virtual ~FilterTypeChooser(){};

    //    private:
    //     QString image_path;

   private:
    QGroupBox* box;
    QRadioButton* medianBlurOpt;
    QRadioButton* gaussianBlurOpt;
    QCheckBox* displayOrNot;
    QHBoxLayout* hLayout;
    QVBoxLayout* vLayout;
    //    private slots:
    //     void handleBrowseButton();
    //     void handleFilePath();
    //    signals:
    //     void fileSelected(std::string);
};