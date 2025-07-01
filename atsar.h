#ifndef ATSAR_H
#define ATSAR_H
#include <QMessageBox>
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class atsar;
}
QT_END_NAMESPACE

class atsar : public QMainWindow
{
    Q_OBJECT

public:
    atsar(QWidget *parent = nullptr);
    ~atsar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::atsar *ui;
};
#endif // ATSAR_H
