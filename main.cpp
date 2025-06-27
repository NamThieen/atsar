#include "atsar.h"
#include "atsarquiz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    atsar w;
    w.show();
    return a.exec();
}
