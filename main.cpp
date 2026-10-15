#include "tp1_com.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TP1_Com w;
    w.show();
    return QApplication::exec();
}
