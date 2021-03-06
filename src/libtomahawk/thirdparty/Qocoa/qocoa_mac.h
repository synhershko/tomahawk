/*
Copyright (C) 2011 by Mike McQuaid

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef QCOCOA_MAC_H
#define QCOCOA_MAC_H

#include <Foundation/NSString.h>
#include <QString>
#include <QVBoxLayout>
#include <QMacCocoaViewContainer>

static inline NSString* fromQString(const QString &string)
{
    char* cString = string.toUtf8().data();
    return [[NSString alloc] initWithUTF8String:cString];
}

static inline QString toQString(NSString *string)
{
    if (!string)
        return QString();
    return QString::fromUtf8([string UTF8String]);
}

static inline void zeroLayout(void *cocoaView, QWidget *parent)
{
    QVBoxLayout *layout = new QVBoxLayout(parent);
    layout->setMargin(0);
    parent->setAttribute(Qt::WA_NativeWindow);
    layout->addWidget(new QMacCocoaViewContainer(cocoaView, parent));
}

#endif
