#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtticker.h"

class QtTicker : public QMainWindow
{
    Q_OBJECT

public:
    QtTicker(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtTickerClass *ui;
};
