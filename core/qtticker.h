/**
 * @copyright Copyright (c) Yuji Iwanaga
 * @date 19th Sep. 2020
 */

#ifndef QTTICKER_H
#define QTTICKER_H

#include <QtWidgets/QMainWindow>
#include <QString>
#include <QFont>
#include <QSize>
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

    QDirect3D11Widget *mDx11Scene;
    QGraphicsScene *mGraphicsScene;
    QGraphicsPixmapItem *mStrImg;
    QSize mWindowSize;
    QFont mFont;
    double mScrollPosPeriod;
    double mMovingAmount;
    double mScrollPos;

    void adjustWindowSize();
    void connectSlots();

private slots:
    void init(bool success);
    void tick();
    void render();
};

#endif