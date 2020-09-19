/**
 * @copyright Copyright (c) Yuji Iwanaga
 * @date 19th Sep. 2020
 */

#include "qtticker.h"

QtTicker::QtTicker(QWidget *parent)
    : QMainWindow(parent)
	, ui(new Ui::QtTickerClass())
{
    ui->setupUi(this);
}
