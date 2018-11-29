#include "SingleButtonRow.h"
#include <QDebug>
#include <QtWidgets/QSizePolicy>

SingleButtonRow::SingleButtonRow(QString buttonText, QWidget* parent)
    : QWidget(parent) {
    button = new QPushButton(buttonText, this);
    layout = new QHBoxLayout;
    layout->addStretch();
    layout->addWidget(button);
    setLayout(layout);
};
