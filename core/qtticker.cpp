/**
 * @copyright Copyright (c) Yuji Iwanaga
 * @date 19th Sep. 2020
 */

#include "qtticker.h"
#include "stringimagecreater.h"

#include <QString>
#include <QFont>
#include <QFontMetrics>
#include <QMessageBox>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>


QtTicker::QtTicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtTickerClass())
    , mWindowSize(1920, 90)
    , mMovingAmount(0.0)
    , mScrollPos(0.0)
    , mGraphicsScene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    mDx11Scene = ui->view;

    /* init moving amount */
    mMovingAmount = 0.5;

    /* init position. */
    mScrollPos = mWindowSize.width();
    mScrollPosPeriod = 0;

    /* init font */
    mFont = QFont("Times", 36);
    QFontMetrics fm(mFont);

    /* create scene */
    if (mGraphicsScene != nullptr) {
        mGraphicsScene->clear();
    }
    mGraphicsScene->setSceneRect(0, 0, mWindowSize.width(), mWindowSize.height());

    /* create image */
    StringImageCreater *strImageCreater = new StringImageCreater();
    QString str = "Test Message";
    int width = fm.width(str);
    strImageCreater->setText(str);
    strImageCreater->setImageHeight(mWindowSize.height());
    strImageCreater->setImageWidth(width);
    strImageCreater->setFont(mFont);
    QImage dispImage = strImageCreater->generate();
    mStrImg = new QGraphicsPixmapItem(QPixmap::fromImage(dispImage));
    mStrImg->setPos(mScrollPos, 0);
    mGraphicsScene->addItem(mStrImg);

    /*
     * Set the scene in View and Layout.
     */
    QGraphicsView *graphicsView = new QGraphicsView(this);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setScene(mGraphicsScene);
    ui->view->layout()->addWidget(graphicsView);

    /* connection slots */
    adjustWindowSize();
    connectSlots();

    delete strImageCreater;
}

QtTicker::~QtTicker()
{
    delete mStrImg;
    delete mDx11Scene;
}

void QtTicker::adjustWindowSize()
{
    resize(mWindowSize.width(), mWindowSize.height());
}


void QtTicker::connectSlots()
{
    connect(mDx11Scene, &QDirect3D11Widget::deviceInitialized, this, &QtTicker::init);
    connect(mDx11Scene, &QDirect3D11Widget::ticked, this, &QtTicker::tick);
    connect(mDx11Scene, &QDirect3D11Widget::rendered, this, &QtTicker::render);
}

void QtTicker::init(bool success)
{
    if (!success) {
        QMessageBox::critical(
            this
            , "ERROR", "Direct3D widget initialization failed."
            , QMessageBox::Ok);
        return;
    }

    QTimer::singleShot(500, this, [&] { mDx11Scene->run(); });
    disconnect(mDx11Scene, &QDirect3D11Widget::deviceInitialized, this, &QtTicker::init);
}

void QtTicker::tick()
{
    mScrollPos -= mMovingAmount;
}

void QtTicker::render()
{
    mStrImg->setPos(mScrollPos, mWindowSize.height());
    /* check scroll position end.  */
    if (mScrollPos < (-mScrollPosPeriod)) {
        mScrollPos = mWindowSize.width();
    }
}