/**
 * @copyright Copyright (c) Yuji Iwanaga
 * @date 19th Sep. 2020
 */

#include "stringimagecreater.h"

#include <QFont>
#include <QImage>
#include <QPainter>

StringImageCreater::StringImageCreater()
    : mText("")
    , mImageWidth(0)
    , mImageHeight(0)
    , mFont(QFont())
    , mColor(Qt::black)
    , mFontSize(36)
{
}

StringImageCreater::~StringImageCreater()
{
}

QImage StringImageCreater::generate()
{
    QImage image(QSize(mImageWidth, mImageHeight), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.setBrush(QBrush(QColor(0, 0, 0, 0)));
    painter.fillRect(QRectF(0, 0, mImageWidth, mImageHeight), QColor(0, 0, 0, 0));
    painter.setPen(QPen(mColor));
    mFont.setPixelSize(mFontSize);
    painter.setFont(mFont);
    painter.drawText(QRectF(0, 0, mImageWidth, mImageHeight), Qt::AlignLeft | Qt::AlignVCenter, mText);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.end();
    return image;
}
