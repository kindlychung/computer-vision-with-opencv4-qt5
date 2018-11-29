#include "FilterTypeChooser.h"
#include <QDebug>
#include <QtWidgets/QSizePolicy>

FilterTypeChooser::FilterTypeChooser(QWidget* parent) : QWidget(parent) {
    auto minPolicy = QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    auto expandPolicy = QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    box = new QGroupBox("Blur method", this);
    medianBlurOpt = new QRadioButton(tr("&Median blur"), this);
    gaussianBlurOpt = new QRadioButton(tr("&Gaussian blur"), this);
    medianBlurOpt->setChecked(true);
    displayOrNot = new QCheckBox("Display image after filtering", this);
    displayOrNot->setChecked(false);
    hLayout = new QHBoxLayout;
    hLayout->addWidget(medianBlurOpt);
    hLayout->addWidget(gaussianBlurOpt);
    hLayout->addWidget(displayOrNot);
    box->setLayout(hLayout);
    box->setSizePolicy(expandPolicy);
    vLayout = new QVBoxLayout;
    vLayout->addWidget(box);
    setLayout(vLayout);
};
