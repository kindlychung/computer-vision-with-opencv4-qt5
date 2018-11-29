
#pragma once
#include <QString>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

struct BrowsePurpose {
    enum Purpose { GetFile = 'g', SaveFile = 's', GetDir = 'd' };
};

class SimpleFileBrowser : public QWidget {
    Q_OBJECT
   public:
    SimpleFileBrowser(QString const& placeholderText, QString const& filter,
                      QString* selectedFilter, BrowsePurpose::Purpose purpose,
                      QWidget* parent = nullptr);

   public:
    QString getPath();

   private:
    QString path;
    QLineEdit* filePathField;
    QPushButton* browseButton;
    QHBoxLayout* layout;
    QFileDialog* fileDialog;
};
