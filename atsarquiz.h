#ifndef ATSARQUIZ_H
#define ATSARQUIZ_H
#include <QMessageBox>
#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QByteArray>
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
    void update_Quiz_progression(int currentQuestion, size_t totalQuestions);

private:
    Ui::atsarquiz *ui;
};

#endif // ATSARQUIZ_H
