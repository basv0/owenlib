#include <QApplication>
#include <QtGui>
#include "testowen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("Utf8");
    QTextCodec::setCodecForTr(codec);

    TestOwen w;
    w.show();
    
    return a.exec();
}
