#include "MyFileBrowser.h"
#include <QFile>
#include <QDebug>

MyFileBrowser::MyFileBrowser(QWidget *parent) : QWidget(parent)
{
    InitWidget();
    InitCounter();
    SetThisStyle();
}

bool MyFileBrowser::HasFileFocus()
{
    QList<QListWidgetItem*> list = lpListWidget->selectedItems();
    if(list.size() == 0){
        return false;
    }
    return true;
}

QString MyFileBrowser::GetSeletedFileName()
{
    QList<QListWidgetItem*> list = lpListWidget->selectedItems();
    return list[0]->text();
}

void MyFileBrowser::InitWidget()
{
    lpListWidget = new QListWidget(this);
    lpListWidget->setIconSize(QSize(100, 100));
    lpListWidget->setResizeMode(QListView::Adjust);
    lpListWidget->setViewMode(QListView::IconMode);
    lpListWidget->setMovement(QListView::Static);
    lpListWidget->setSpacing(10);
    lpListWidget->setGeometry(0, 0, 950, 410);
}

void MyFileBrowser::InitCounter()
{
//    line = row = fileNum = 0;
    fileNum = 0;
}

void MyFileBrowser::SetThisStyle()
{
    setMinimumSize(950, 410);
}
/*
QWidget* MyFileBrowser::CreateWidget()
{
    QString name;
    QLabel* temp = new QLabel(name);
    temp->setFixedSize(100, 100);
    temp->setStyleSheet("QLabel{background-color:rgb(200, 200, 255);}");
    return temp;
}*/

void MyFileBrowser::AddFile()
{
    QPixmap iconP;
    qDebug() << iconP.load("image/fileBrowser/director.png");
    QListWidgetItem* pItem = new QListWidgetItem(QIcon(iconP.scaled(QSize(80, 80))), QString("director%1").arg(fileNum++));
    pItem->setSizeHint(QSize(100, 100));
    lpListWidget->addItem(pItem);
}

void MyFileBrowser::AddDirector(QString name)
{
    QPixmap iconP;
    qDebug() << iconP.load("image/fileBrowser/director.png");
    QListWidgetItem* pItem = new QListWidgetItem(QIcon(iconP.scaled(QSize(80, 80))), name);
    pItem->setSizeHint(QSize(100, 100));
    lpListWidget->addItem(pItem);
}

void MyFileBrowser::DeleteFile()
{
    QList<QListWidgetItem*> list = lpListWidget->selectedItems();
    if(list.size() == 0){
        return;
    }

    QListWidgetItem* temp = list[0];
    if(temp){
        int row = lpListWidget->row(temp);
        lpListWidget->takeItem(row);
        delete temp;
    }
}
