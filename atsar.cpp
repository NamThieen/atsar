#include "atsar.h"
#include "ui_atsar.h"
#include "atsarquiz.h"
atsar::atsar(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::atsar)
{
    ui->setupUi(this);
}

atsar::~atsar()
{
    delete ui;
}

void atsar::on_pushButton_clicked()
{

}


void atsar::on_pushButton_2_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this,"Open Folder");

    if (!folderPath.isEmpty())
    {
        qDebug() << "Selected folder: " << folderPath;
    } else {
        qDebug() << "Folder selection cancelled!";
    }
}

void atsar::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file", "YAML Files (*.yaml *.yml);;All Files (*)");
    if (!fileName.isEmpty())
    {
        qDebug() << "Selected YAML file: " << fileName;
        atsarquiz* quizWindow = new atsarquiz();
        quizWindow->setAttribute(Qt::WA_DeleteOnClose);
        quizWindow->show();
        this->close();
    }
}

