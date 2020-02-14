#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->toolBar->addAction(ui->actionFullScreen);
    ui->toolBar->addAction(ui->actionUndo);
    ui->toolBar->addAction(ui->actionRedo);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionAbout);
}//MainWindow(QWidget *parent = nullptr)

MainWindow::~MainWindow()
{
    delete ui;
}//~MainWindow()

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Backspace)
        key = BDKey::Backspace;
    else if (event->key() == Qt::Key_Delete)
        key = BDKey::Delete;
}//void keyReleaseEvent(QKeyEvent *event)

void MainWindow::pushChanges(QStack<Changes> &st, Changes ch)
{
    if (st.count() == STACK_MAX_SIZE) st.pop_front();
    st.push(ch);
}//void pushChanges(QStack<Changes> &st, Changes &ch)

void MainWindow::on_actionFullScreen_triggered()
{
    (this->isFullScreen())?this->showNormal():this->showFullScreen();
}//on_actionFullScreen_triggered()

#define CUR_POS ui->textEdit->textCursor().position()
#define LIO(ch) text.lastIndexOf(ch, CUR_POS-1)
#define TLEN text.length()
#define TWCL twc.length()
#define UTOP undo.top()
#define RTOP redo.top()

void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    if (undoRedoFlag) {
        undoRedoFlag = false;
    } else {
        if (TLEN != TWCL) {
            if (undo.count()) {
                int32_t space = (LIO(' ') > LIO('\n'))? LIO(' ') : LIO('\n');
                if (TLEN > TWCL) {
                    if (space == -1 || space != (CUR_POS - 1))
                        UTOP.data += text.mid(CUR_POS - (TLEN - TWCL), TLEN - TWCL);
                    else pushChanges(undo, Changes(space, text.mid(space, TLEN - TWCL))); //
                } else if (TLEN < TWCL ) {
                    if (twc[CUR_POS] == ' ' || twc[CUR_POS] == '\n' || !UTOP.del)
                        pushChanges(undo, Changes(CUR_POS, twc.mid(CUR_POS, TWCL - TLEN), true));
                    else {
                        if (key == BDKey::Backspace) {
                            UTOP.data.prepend(twc.mid(CUR_POS, TWCL - TLEN));
                            UTOP.pos = CUR_POS;
                        } else if (key == BDKey::Delete)
                            UTOP.data += twc.mid(CUR_POS, TWCL - TLEN);
                    }//if (twc[CUR_POS] == ' ' || twc[CUR_POS] == '\n' || !UTOP.del)
                }//if (TLEN < TWCL)
            } else pushChanges(undo, Changes(0, text));
        }//if (TLEN != TWCL)
    }//if (undoRedoFlag)
    twc = text;
}//on_textEdit_textChanged()

void MainWindow::on_actionUndo_triggered()
{
    if (undo.count()) {
        undoRedoFlag = true;

        QTextCursor cursor = ui->textEdit->textCursor();
        QString text = ui->textEdit->toPlainText();

        if (UTOP.del) {
            // если "слово" было удалено
            text.insert(UTOP.pos, UTOP.data);
            pushChanges(redo, undo.pop());
            ui->textEdit->setPlainText(text);
            cursor.setPosition(RTOP.pos + RTOP.data.length());
        } else {
            // если "слово" было дописано
            QString r_text = text.right(TLEN - UTOP.pos - UTOP.data.length());
            text.truncate(UTOP.pos);
            pushChanges(redo, undo.pop());
            ui->textEdit->setPlainText(text + r_text);
            cursor.setPosition(RTOP.pos);
        }//if (UTOP.del)
        ui->textEdit->setTextCursor(cursor);
    }//if (count.size())
}//on_actionUndo_triggered()

void MainWindow::on_actionRedo_triggered()
{
    if (redo.count()) {
        undoRedoFlag = true;

        QTextCursor cursor = ui->textEdit->textCursor();
        QString text = ui->textEdit->toPlainText();

        if (RTOP.del) {
            // если "слово" было удалено
            QString r_text = text.right(TLEN - RTOP.pos - RTOP.data.length());
            text.truncate(RTOP.pos);
            pushChanges(undo, redo.pop());
            ui->textEdit->setPlainText(text + r_text);
            cursor.setPosition(UTOP.pos);
        } else {
            // если "слово" было дописано
            text.insert(RTOP.pos, RTOP.data);
            pushChanges(undo, redo.pop());
            ui->textEdit->setPlainText(text);
            cursor.setPosition(UTOP.pos + UTOP.data.length());
        }//if (RTOP.del)
        ui->textEdit->setTextCursor(cursor);
    }//if (count.size())
}//on_actionRedo_triggered()

void MainWindow::on_actionAbout_triggered()
{
    QFile file(":/about.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->textEdit->setPlainText(QString(file.readAll()));
        ui->textEdit->moveCursor(QTextCursor::Start);
        ui->lineEdit->setText("Mr. Morgan");
        file.close();
    }//if (file.open(QIODevice::ReadOnly | QIODevice::Text))
}//on_actionAbout_triggered()

void MainWindow::on_open_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Выберите файл для открытия", QDir::current().path(),
                                                    QString("Текстовый файл(*.txt);;Бинарный файл(*.binary);;Все файлы(*.*)"));
    if (filename.length()) {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            if (filename.right(7) == ".binary") ui->lineEdit->setText(stream.readLine());
            ui->textEdit->setPlainText(QString(stream.readAll()));
            ui->textEdit->moveCursor(QTextCursor::Start);
            file.close();
        }//if (file.open(..))
    } else QMessageBox::information(this, "Ошибка чтения файла", "Не удалось считать выбранный файл.");
}//on_open_triggered()

void MainWindow::on_save_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Выберите файл для сохранения", QDir::current().path(),
                                                    QString("Текстовый файл(*.txt);;Бинарный файл(*.binary)"));
    if (filename.length()) {
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::NewOnly)){
            QTextStream stream(&file);
            if (filename.right(7) == ".binary") stream << ui->lineEdit->text() << '\n';
            stream << ui->textEdit->toPlainText();
            file.close();
        }//if (file.open(..))
    }else QMessageBox::information(this, "Ошибка записи файла", "Не удалось записать данные в выбранный файл.");
}//on_save_triggered()
