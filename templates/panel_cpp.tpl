#include "{$imitator}.h"
#include "ui_{$imitator}.h"
 
form_{$imitator}::form_{$imitator}(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::form_{$imitator})
{
    ui->setupUi(this);
}

form_{$imitator}::~form_{$imitator}()
{
    delete ui;
}


MAIN_FORM(form_{$imitator});
