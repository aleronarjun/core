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

#include <sfx2/sidebar/Tools.hxx>

#include <sfx2/sidebar/Theme.hxx>

#include <comphelper/processfactory.hxx>
#include <vcl/commandinfoprovider.hxx>
#include <vcl/gradient.hxx>

#include <com/sun/star/frame/XDispatchProvider.hpp>
#include <com/sun/star/util/URLTransformer.hpp>
#include <com/sun/star/frame/ModuleManager.hpp>

#include <cstring>

using namespace css;
using namespace css::uno;

namespace sfx2 { namespace sidebar {

Image Tools::GetImage (
    const ::rtl::OUString& rsImageURL,
    const ::rtl::OUString& rsHighContrastImageURL,
    const Reference<frame::XFrame>& rxFrame)
{
    if (Theme::IsHighContrastMode())
        return GetImage(rsHighContrastImageURL, rxFrame);
    else
        return GetImage(rsImageURL, rxFrame);
}

Image Tools::GetImage (
    const ::rtl::OUString& rsURL,
    const Reference<frame::XFrame>& rxFrame)
{
    if (rsURL.getLength() > 0)
    {
        if (rsURL.startsWith(".uno:"))
        {
            const Image aPanelImage(vcl::CommandInfoProvider::GetImageForCommand(rsURL, rxFrame));
            return aPanelImage;
        }
        else if (rsURL.startsWith("private:graphicrepository"))
        {
            const Image aPanelImage(rsURL);
            return aPanelImage;
        }
    }
    return Image();
}

css::awt::Gradient Tools::VclToAwtGradient (const Gradient& rVclGradient)
{
    css::awt::Gradient aAwtGradient (
        awt::GradientStyle(rVclGradient.GetStyle()),
        sal_Int32(rVclGradient.GetStartColor().GetRGBColor()),
        sal_Int32(rVclGradient.GetEndColor().GetRGBColor()),
        rVclGradient.GetAngle(),
        rVclGradient.GetBorder(),
        rVclGradient.GetOfsX(),
        rVclGradient.GetOfsY(),
        rVclGradient.GetStartIntensity(),
        rVclGradient.GetEndIntensity(),
        rVclGradient.GetSteps());
    return aAwtGradient;
}

Gradient Tools::AwtToVclGradient (const css::awt::Gradient& rAwtGradient)
{
    Gradient aVclGradient (
        GradientStyle(rAwtGradient.Style),
        Color(rAwtGradient.StartColor),
        Color(rAwtGradient.EndColor));
    aVclGradient.SetAngle(rAwtGradient.Angle);
    aVclGradient.SetBorder(rAwtGradient.Border);
    aVclGradient.SetOfsX(rAwtGradient.XOffset);
    aVclGradient.SetOfsY(rAwtGradient.YOffset);
    aVclGradient.SetStartIntensity(rAwtGradient.StartIntensity);
    aVclGradient.SetEndIntensity(rAwtGradient.EndIntensity);
    aVclGradient.SetSteps(rAwtGradient.StepCount);

    return aVclGradient;
}

util::URL Tools::GetURL (const ::rtl::OUString& rsCommand)
{
    util::URL aURL;
    aURL.Complete = rsCommand;

    const Reference<XComponentContext> xComponentContext (::comphelper::getProcessComponentContext());
    const Reference<util::XURLTransformer> xParser = util::URLTransformer::create( xComponentContext );
    xParser->parseStrict(aURL);

    return aURL;
}

Reference<frame::XDispatch> Tools::GetDispatch (
    const css::uno::Reference<css::frame::XFrame>& rxFrame,
    const util::URL& rURL)
{
    Reference<frame::XDispatchProvider> xProvider (rxFrame, UNO_QUERY_THROW);
    Reference<frame::XDispatch> xDispatch (xProvider->queryDispatch(rURL, ::rtl::OUString(), 0));
    return xDispatch;
}

::rtl::OUString Tools::GetModuleName (
    const css::uno::Reference<css::frame::XController>& rxController)
{
    if (!rxController.is())
        return ::rtl::OUString();

    try
    {
        const Reference<XComponentContext> xComponentContext (::comphelper::getProcessComponentContext());
        const Reference<frame::XModuleManager> xModuleManager = frame::ModuleManager::create( xComponentContext );
        return xModuleManager->identify(rxController);
    }
    catch (const Exception&)
    {
        // Ignored.
    }
    return ::rtl::OUString();
}

} } // end of namespace sfx2::sidebar

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
