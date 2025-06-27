#include "atsarquiz.h"
#include "ui_atsarquiz.h"

atsarquiz::atsarquiz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::atsarquiz)
{
    ui->setupUi(this);
}

atsarquiz::~atsarquiz()
{
    delete ui;
}
