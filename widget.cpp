#include "widget.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("欧式距离计算"));
    setWindowIcon(QIcon("euclidean_64x64.ico.ico"));

    srcLabel = new QLabel(tr("出发地坐标"));
    dstLabel = new QLabel(tr("目的地坐标"));

    src_xLineEdit = new QLineEdit;
    src_yLineEdit = new QLineEdit;
    dst_xLineEdit = new QLineEdit;
    dst_yLineEdit = new QLineEdit;
    src_xLineEdit->setFixedWidth(40);
    src_yLineEdit->setFixedWidth(40);
    dst_xLineEdit->setFixedWidth(40);
    dst_yLineEdit->setFixedWidth(40);
    displayLineEdit = new QLineEdit;
    displayLineEdit->setReadOnly(1);//设置为只读
    displayLineEdit->setAlignment( Qt::AlignRight);//设置对齐方式

    Calculate = new QPushButton(tr("计算"));

    QGridLayout *mainlayout = new QGridLayout(this);
    mainlayout->addWidget(displayLineEdit, 0, 0, 1, 3);
    mainlayout->addWidget(srcLabel,1,0);
    mainlayout->addWidget(dstLabel,2,0);
    mainlayout->addWidget(src_xLineEdit,1,1);
    mainlayout->addWidget(src_yLineEdit,1,2);
    mainlayout->addWidget(dst_xLineEdit,2,1);
    mainlayout->addWidget(dst_yLineEdit,2,2);

    QHBoxLayout *hBoxlayout = new QHBoxLayout;
    mainlayout->addLayout(hBoxlayout, 3, 0, 1, 3);
    hBoxlayout->addWidget(Calculate,1);

    mainlayout->setContentsMargins(50,30,50,30);

    connect(Calculate, SIGNAL(clicked()), this, SLOT(slotCalculate()));
    connect(src_yLineEdit, SIGNAL(returnPressed()), this, SLOT(slotCalculate()));

}

Widget::~Widget()
{

}
void Widget::slotCalculate()
{
    double distance =
     sqrt(pow(src_xLineEdit->text().toInt() - dst_xLineEdit->text().toInt(), 2) +
          pow(src_yLineEdit->text().toInt() - dst_yLineEdit->text().toInt(), 2));
    QString str_distance;
    displayLineEdit->setText(str_distance.setNum(distance));

}

