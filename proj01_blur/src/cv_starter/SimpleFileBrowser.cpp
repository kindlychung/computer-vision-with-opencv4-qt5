#include "SimpleFileBrowser.h"
#include <QDebug>
#include <QStandardPaths>
#include <QtWidgets/QSizePolicy>

SimpleFileBrowser::SimpleFileBrowser(QString const& placeholderText,
                                     QString const& filter,
                                     QString* selectedFilter,
                                     BrowsePurpose::Purpose purpose,
                                     QWidget* parent)
    : QWidget(parent) {
    filePathField = new QLineEdit(this);
    filePathField->setPlaceholderText(placeholderText);
    filePathField->setTextMargins(2, 0, 0, 2);
    filePathField->setEnabled(false);
    browseButton = new QPushButton("Browse", this);
    layout = new QHBoxLayout;
    layout->addWidget(filePathField);
    layout->addWidget(browseButton);
    setLayout(layout);
    fileDialog =
        new QFileDialog(this, "Choose", QString("/home/kaiyin"), filter);
    connect(browseButton, &QPushButton::clicked, [=]() {
        if (purpose == BrowsePurpose::GetFile) {
            this->path = this->fileDialog->getOpenFileName(
                this, "Choose",
                QStandardPaths::writableLocation(
                    QStandardPaths::PicturesLocation),
                filter, selectedFilter);
        } else if (purpose == BrowsePurpose::SaveFile) {
            this->path = this->fileDialog->getSaveFileName(
                this, "Save",
                QStandardPaths::writableLocation(
                    QStandardPaths::PicturesLocation),
                filter, selectedFilter);
        } else {
            this->path = this->fileDialog->getExistingDirectory(
                this, "Choose folder",
                QStandardPaths::writableLocation(
                    QStandardPaths::PicturesLocation));
        }
        this->filePathField->setText(path);
    });
};

QString SimpleFileBrowser::getPath() { return path; }
