#include "atsarquiz.h"
#include "ui_atsarquiz.h"
#include "atsar-rust-lib/src/rust_questions_api.h"

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

void atsarquiz::on_Quit_triggered()
{
    this->close();
}

