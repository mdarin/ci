main.c#include <QtGui/QApplication>#include <QLibrary>#include "mainwindow.h"#include "compdispatcher.h"
int main(int argc, char *argv[]){    QApplication a(argc, argv);    MainWindow w;    w.show();    CompDispatcher* cd = CompDispatcher::instance();    cd->refreshIElements();    cd->printControls();    cd->printIndicators();    return a.exec();}