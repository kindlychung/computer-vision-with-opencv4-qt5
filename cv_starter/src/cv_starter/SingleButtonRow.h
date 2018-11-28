
#pragma once
#include <QString>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

class SingleButtonRow : public QWidget {
    Q_OBJECT
   public:
    SingleButtonRow(QString buttonText, QWidget* parent = nullptr);

    //    private:
    //     QString image_path;

   private:
    QPushButton* button;
    QHBoxLayout* layout;
    //    private slots:
    //     void handleBrowseButton();
    //     void handleFilePath();
    //    signals:
    //     void fileSelected(std::string);
};