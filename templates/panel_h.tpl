#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ipanel.h"
 namespace Ui
{
    class form_{$imitator};
}
class form_{$imitator} : public QMainWindow
{
    Q_OBJECT
public:
    form_{$imitator}(QWidget *parent = 0);
    ~form_{$imitator}();
//    Q_DECL_EXPORT QWidget* createPanelForm();
private:
    Ui::form_{$imitator} *ui;
};
#endif // MAINWINDOW_H
