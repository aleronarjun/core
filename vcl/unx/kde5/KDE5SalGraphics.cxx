/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#include "KDE5SalGraphics.hxx"

#include <salbmp.hxx>

#include <Qt5Tools.hxx>

static void QImage2BitmapBuffer(QImage* pImg, BitmapBuffer* pBuf)
{
    pBuf->mnWidth = pImg->width();
    pBuf->mnHeight = pImg->height();
    pBuf->mnBitCount = getFormatBits(pImg->format());
    pBuf->mpBits = pImg->bits();
    pBuf->mnScanlineSize = pImg->bytesPerLine();
}

KDE5SalGraphics::KDE5SalGraphics()
    : SvpSalGraphics()
{
}

bool KDE5SalGraphics::drawNativeControl(ControlType nType, ControlPart nPart,
                                        const tools::Rectangle& rControlRegion, ControlState nState,
                                        const ImplControlValue& aValue, const OUString& aCaption)
{
    bool bHandled
        = m_aControl.drawNativeControl(nType, nPart, rControlRegion, nState, aValue, aCaption);
    if (bHandled)
    {
        QImage* pImage = &m_aControl.getImage();
        BitmapBuffer* pBuffer = new BitmapBuffer;
        QImage2BitmapBuffer(pImage, pBuffer);
        SalTwoRect aTR(0, 0, pImage->width(), pImage->height(), rControlRegion.getX(),
                       rControlRegion.getY(), rControlRegion.GetWidth(),
                       rControlRegion.GetHeight());
        drawBitmap(aTR, pBuffer, CAIRO_OPERATOR_OVER);
    }
    return bHandled;
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
