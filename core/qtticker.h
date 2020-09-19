/**
 * @copyright Copyright (c) Yuji Iwanaga
 * @date 19th Sep. 2020
 */

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
