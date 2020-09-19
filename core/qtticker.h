/**
 * @copyright Copyright (c) Yuji Iwanaga
 * @date 19th Sep. 2020
 */

#ifndef QTTICKER_H
#define QTTICKER_H

#include <QtWidgets/QMainWindow>
#include <QString>
#include <QList>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "qdirect3d11widget.h"
#include "ui_qtticker.h"

class QtTicker : public QMainWindow
{
    Q_OBJECT

public:
    QtTicker(QWidget *parent = Q_NULLPTR);
	~QtTicker();

private:
    Ui::QtTickerClass *ui;

	QDirect3D11Widget *m_pScene;
	QList<QGraphicsPixmapItem *> mListStrImg;
};

#endif