
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
    QRadioButton* medianBlurOpt;
    QRadioButton* gaussianBlurOpt;
    QCheckBox* displayOrNot;

   private:
    QGroupBox* box;
    QHBoxLayout* hLayout;
    QVBoxLayout* vLayout;
    //    private slots:
    //     void handleBrowseButton();
    //     void handleFilePath();
    //    signals:
    //     void fileSelected(std::string);
};