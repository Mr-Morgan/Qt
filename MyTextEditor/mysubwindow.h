#ifndef MYSUBWINDOW_H
#define MYSUBWINDOW_H

#include <QGridLayout>
#include <QTextStream>
#include <QLineEdit>
#include <QPrinter>
#include <QWidget>
#include <QLabel>

#include "mytextedit.h"

class MySubWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MySubWindow(QWidget *parent = nullptr);
    ~MySubWindow();
    void undo();
    void redo();
    void printText(QTextStream &s, bool binary = false, bool readonly = false);
    void scanText(QTextStream &s, bool binary = false);
    void setLabelText(QString text);
    void print(QPrinter *p);
    void insertTable(int32_t n, int32_t m);
    void setCursor(const QCursor &c);
    void setFormatNeedsInserted(bool needs);
    void saveTextFormat();
    void setTextFormat(QTextCharFormat f);
    QTextCharFormat getTextFormat();
    void setAlign(Qt::Alignment a);
    bool getFNI();

signals:

private:
    MyTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLabel *label;
};//class MySubWindow : public QWidget

#endif // MYSUBWINDOW_H
