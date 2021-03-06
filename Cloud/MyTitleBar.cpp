#include "MyTitleBar.h"

#include <QLabel>
#include <QPushButton>
/*#include <QEvent>
#include <QMouseEvent>
#include <QApplication>*/

MyTitleBar::MyTitleBar(QWidget *parent)
    :QWidget(parent)
{
    setFixedHeight(22);

    createWidget();

    createLayout();

    setButtonStyle();
    connect(lpCloseButton, SIGNAL(clicked()), parent, SLOT(close()));
    connect(lpMinimizeButton, SIGNAL(clicked()), this, SLOT(showSmall()));
}

void MyTitleBar::createWidget(){
    lpIconLabel = new QLabel(this);
    lpTitleLabel = new QLabel(this);
    lpMinimizeButton = new QPushButton(this);
    lpMaximizeButton = new QPushButton(this);
    lpCloseButton = new QPushButton(this);

    QPixmap pixmap(22, 22);
    pixmap.load("image/title/icon.png");
    lpIconLabel->setPixmap(pixmap);
    lpIconLabel->setFixedSize(22, 22);
    lpIconLabel->setScaledContents(true);

    lpTitleLabel->setText("my cloud storage");
    lpTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    lpMinimizeButton->setFixedSize(27, 22);
    lpMaximizeButton->setFixedSize(27, 22);
    lpCloseButton->setFixedSize(27, 22);

    lpTitleLabel->setObjectName("whiteLabel");
    lpMinimizeButton->setObjectName("minimizeButton");
    lpMaximizeButton->setObjectName("maximizeButton");
    lpCloseButton->setObjectName("closeButton");

    lpMinimizeButton->setToolTip("Minimize");
    lpMaximizeButton->setToolTip("Maximize");
    lpCloseButton->setToolTip("Close");
}

void MyTitleBar::createLayout()
{
    lpLayout = new QHBoxLayout(this);
    lpLayout->setMargin(0);

    lpLayout->addWidget(lpIconLabel);
    lpLayout->addSpacing(5);
    lpLayout->addWidget(lpTitleLabel);
    lpLayout->addWidget(lpMinimizeButton);
    lpLayout->addWidget(lpMaximizeButton);
    lpLayout->addWidget(lpCloseButton);
    lpLayout->setSpacing(0);
    lpLayout->setContentsMargins(5, 0, 0, 0);

    setLayout(lpLayout);
}

void MyTitleBar::setButtonStyle()
{
    setStyleSheet("QPushButton{background-color: rgb(1, 195, 255);"
                  "color: rgb(0, 0, 0);"
                  "border-style: outset;"
                  "border-width: 0px;"
                  "border-color: beige;"
                  "font: bold 14px;"
                  "padding: 6px;"
                  "text-align: center;}"
                  "QPushButton:hover{background-color: rgb(128, 226, 255)}");

    setIcon(lpMinimizeButton, "image/title/min.png");
    setIcon(lpMaximizeButton, "image/title/max.png");
    setIcon(lpCloseButton, "image/title/close.png");
}

void MyTitleBar::setIcon(QPushButton* b, QString path)
{
    QPixmap *pixmap = new QPixmap(22, 22);
    pixmap->load(path);
    QIcon *icon = new QIcon(*pixmap);
    b->setIcon(*icon);
    b->setIconSize(QSize(22, 22));
}
