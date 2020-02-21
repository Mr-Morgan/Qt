#include "mysubwindow.h"

MySubWindow::MySubWindow(QWidget *parent) : QWidget(parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    textEdit = new MyTextEdit(this);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));
    textEdit->setUndoRedoEnabled(false);

    gridLayout->addWidget(textEdit, 0, 0, 1, 1);

    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

    label = new QLabel(this);
    label->setObjectName(QString::fromUtf8("label"));
    label->setTextFormat(Qt::RichText);

    horizontalLayout->addWidget(label);

    lineEdit = new QLineEdit(this);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setText("Author Name");

    horizontalLayout->addWidget(lineEdit);

    gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);
}//MySubWindow(QWidget *parent, MyTextEdit *te, QLineEdit *le, QLabel *l)

MySubWindow::~MySubWindow()
{
    delete label;
    delete lineEdit;
    delete textEdit;
}//~MySubWindow()

void MySubWindow::undo()
{
    textEdit->on_actionUndo_triggered();
}//void undo()

void MySubWindow::redo()
{
    textEdit->on_actionRedo_triggered();
}//void redo()

void MySubWindow::printText(QTextStream &s, bool binary, bool readonly)
{
    if (binary) lineEdit->setText(s.readLine());
    textEdit->setPlainText(QString(s.readAll()));
    textEdit->moveCursor(QTextCursor::Start);
    textEdit->setReadOnly(readonly);
    lineEdit->setReadOnly(readonly);
}//void printText(QString text, bool bynary = false, bool readonly = false)

void MySubWindow::scanText(QTextStream &s, bool binary)
{
    if (binary) s << lineEdit->text() << '\n';
    s << textEdit->toPlainText();
}//void scanText(QTextStream *s, bool bynary = false)

void MySubWindow::setLabelText(QString text)
{
    label->setText(text);
}//void setLabelText(QString text)

void MySubWindow::print(QPrinter *p)
{
    textEdit->print(p);
}//void print(QPrinter *p)
