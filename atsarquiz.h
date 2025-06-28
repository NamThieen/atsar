#ifndef ATSARQUIZ_H
#define ATSARQUIZ_H

#include <QMainWindow>

namespace Ui {
class atsarquiz;
}

class atsarquiz : public QMainWindow
{
    Q_OBJECT

public:
    explicit atsarquiz(QWidget *parent = nullptr);
    ~atsarquiz();

private slots:
    void on_Quit_triggered();

private:
    Ui::atsarquiz *ui;
};

#endif // ATSARQUIZ_H
