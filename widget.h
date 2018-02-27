#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include<cmath>
using namespace std;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QLabel *srcLabel;
    QLabel *dstLabel;

    QLineEdit *displayLineEdit;
    QLineEdit *src_xLineEdit, *src_yLineEdit;
    QLineEdit *dst_xLineEdit, *dst_yLineEdit;

    QPushButton *Calculate;
private slots:
    void slotCalculate();
};

#endif // WIDGET_H
