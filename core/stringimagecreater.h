/**
 * @copyright Copyright (c) Yuji Iwanaga
 * @date 19th Sep. 2020
 */

#ifndef STRINGIMAGECREATER_H
#define STRINGIMAGECREATER_H

#include <QString>
#include <QFont>
#include <QColor>
#include <QImage>
#include <QObject>
#include <stdint.h>

class StringImageCreater : public QObject
{
    Q_OBJECT

public:
    StringImageCreater();
	~StringImageCreater();

    void setText(const QString text) { mText = text; }
    void setImageWidth(const int width) { mImageWidth = width; }
    void setImageHeight(const int height) { mImageHeight = height; }
    void setFont(const QFont font) { mFont = font; }
    void setFontColor(const QColor color) { mColor = color; }
    void setFontSize(const uint32_t size) { mFontSize = size; }

    QImage generate();
    
private:
    QString mText;
    int mImageWidth;
    int mImageHeight;
    QFont mFont;
    QColor mColor;
    uint32_t mFontSize;
};

#endif
