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

#include <sfx2/objsh.hxx>
#include "sddlgfact.hxx"
#include <BreakDlg.hxx>
#include <copydlg.hxx>
#include <svx/xtable.hxx>
#include <custsdlg.hxx>
#include <dlg_char.hxx>
#include <dlgpage.hxx>
#include <dlgfield.hxx>
#include <dlgsnap.hxx>
#include <layeroptionsdlg.hxx>
#include <ins_paste.hxx>
#include <inspagob.hxx>
#include <morphdlg.hxx>
#include <OutlineBulletDlg.hxx>
#include <paragr.hxx>
#include <present.hxx>
#include "RemoteDialog.hxx"
#include <prltempl.hxx>
#include <sdpreslt.hxx>
#include <tabtempl.hxx>
#include <tpaction.hxx>
#include <vectdlg.hxx>
#include <tpoption.hxx>
#include <prntopts.hxx>
#include <pubdlg.hxx>
#include <masterlayoutdlg.hxx>
#include <headerfooterdlg.hxx>
#include "PhotoAlbumDialog.hxx"

IMPL_ABSTDLG_BASE(SdVclAbstractDialog_Impl);

short SdAbstractGenericDialog_Impl::Execute()
{
    return m_xDlg->run();
}

IMPL_ABSTDLG_BASE(AbstractCopyDlg_Impl);

short AbstractSdCustomShowDlg_Impl::Execute()
{
    return m_xDlg->run();
}

IMPL_ABSTDLG_BASE(SdAbstractTabDialog_Impl);
IMPL_ABSTDLG_BASE(SdPresLayoutTemplateDlg_Impl);

short AbstractSdModifyFieldDlg_Impl::Execute()
{
    return m_xDlg->run();
}

short AbstractSdSnapLineDlg_Impl::Execute()
{
    return m_xDlg->run();
}

short AbstractSdInsertLayerDlg_Impl::Execute()
{
    return m_xDlg->run();
}

IMPL_ABSTDLG_BASE(AbstractSdInsertPagesObjsDlg_Impl);

short AbstractMorphDlg_Impl::Execute()
{
    return m_xDlg->run();
}

short AbstractSdStartPresDlg_Impl::Execute()
{
    return m_xDlg->run();
}

IMPL_ABSTDLG_BASE(AbstractSdPresLayoutDlg_Impl);
IMPL_ABSTDLG_BASE(SdAbstractSfxDialog_Impl);

short AbstractSdVectorizeDlg_Impl::Execute()
{
    return m_xDlg->run();
}

IMPL_ABSTDLG_BASE(AbstractSdPublishingDlg_Impl);
IMPL_ABSTDLG_BASE(AbstractHeaderFooterDialog_Impl);
IMPL_ABSTDLG_BASE(AbstractBulletDialog_Impl);

AbstractBreakDlg_Impl::AbstractBreakDlg_Impl(::sd::BreakDlg* pDlg)
    : m_xDlg(pDlg)
{
}

short AbstractBreakDlg_Impl::Execute()
{
    return m_xDlg->execute();
}

AbstractMasterLayoutDialog_Impl::AbstractMasterLayoutDialog_Impl(::sd::MasterLayoutDialog* pDlg)
    : m_xDlg(pDlg)
{
}

short AbstractMasterLayoutDialog_Impl::Execute()
{
    return m_xDlg->execute();
}

void AbstractCopyDlg_Impl::GetAttr( SfxItemSet& rOutAttrs )
{
    pDlg->GetAttr( rOutAttrs );
}

bool AbstractSdCustomShowDlg_Impl::IsModified() const
{
    return m_xDlg->IsModified();
}

bool AbstractSdCustomShowDlg_Impl::IsCustomShow() const
{
    return m_xDlg->IsCustomShow();
}

void SdAbstractTabDialog_Impl::SetCurPageId( const OString& rName )
{
    pDlg->SetCurPageId( rName );
}

const SfxItemSet* SdAbstractTabDialog_Impl::GetOutputItemSet() const
{
    return pDlg->GetOutputItemSet();
}

const sal_uInt16* SdAbstractTabDialog_Impl::GetInputRanges(const SfxItemPool& pItem )
{
    return pDlg->GetInputRanges( pItem );
}

void SdAbstractTabDialog_Impl::SetInputSet( const SfxItemSet* pInSet )
{
     pDlg->SetInputSet( pInSet );
}

//From class Window.
void SdAbstractTabDialog_Impl::SetText( const OUString& rStr )
{
    pDlg->SetText( rStr );
}

void AbstractBulletDialog_Impl::SetCurPageId( const OString& rName )
{
    static_cast< ::sd::OutlineBulletDlg*>(pDlg.get())->SetCurPageId( rName );
}

const SfxItemSet* AbstractBulletDialog_Impl::GetOutputItemSet() const
{
    return static_cast< ::sd::OutlineBulletDlg*>(pDlg.get())->GetOutputItemSet();
}

const sal_uInt16* AbstractBulletDialog_Impl::GetInputRanges(const SfxItemPool& pItem )
{
    return static_cast< ::sd::OutlineBulletDlg*>(pDlg.get())->GetInputRanges( pItem );
}

void AbstractBulletDialog_Impl::SetInputSet( const SfxItemSet* pInSet )
{
     static_cast< ::sd::OutlineBulletDlg*>(pDlg.get())->SetInputSet( pInSet );
}

void AbstractBulletDialog_Impl::SetText( const OUString& rStr )
{
    static_cast< ::sd::OutlineBulletDlg*>(pDlg.get())->SetText( rStr );
}

void SdPresLayoutTemplateDlg_Impl::SetCurPageId( const OString& rName )
{
    pDlg->SetCurPageId( rName );
}

const SfxItemSet* SdPresLayoutTemplateDlg_Impl::GetOutputItemSet() const
{
    return pDlg->GetOutputItemSet();
}

const sal_uInt16* SdPresLayoutTemplateDlg_Impl::GetInputRanges(const SfxItemPool& pItem )
{
    return pDlg->GetInputRanges( pItem );
}

void SdPresLayoutTemplateDlg_Impl::SetInputSet( const SfxItemSet* pInSet )
{
     pDlg->SetInputSet( pInSet );
}

void SdPresLayoutTemplateDlg_Impl::SetText( const OUString& rStr )
{
    pDlg->SetText( rStr );
}

SvxFieldData* AbstractSdModifyFieldDlg_Impl::GetField()
{
    return m_xDlg->GetField();
}

SfxItemSet AbstractSdModifyFieldDlg_Impl::GetItemSet()
{
    return m_xDlg->GetItemSet();
}

void AbstractSdSnapLineDlg_Impl::GetAttr(SfxItemSet& rOutAttrs)
{
    m_xDlg->GetAttr(rOutAttrs);
}

void AbstractSdSnapLineDlg_Impl::HideRadioGroup()
{
    m_xDlg->HideRadioGroup();
}

void AbstractSdSnapLineDlg_Impl::HideDeleteBtn()
{
    m_xDlg->HideDeleteBtn();
}

void AbstractSdSnapLineDlg_Impl::SetInputFields(bool bEnableX, bool bEnableY)
{
    m_xDlg->SetInputFields(bEnableX, bEnableY);
}

void AbstractSdSnapLineDlg_Impl::SetText( const OUString& rStr )
{
    m_xDlg->set_title(rStr);
}

void AbstractSdInsertLayerDlg_Impl::GetAttr( SfxItemSet& rOutAttrs )
{
    m_xDlg->GetAttr(rOutAttrs);
}

void AbstractSdInsertLayerDlg_Impl::SetHelpId( const OString& rHelpId )
{
    m_xDlg->set_help_id(rHelpId);
}

std::vector<OUString> AbstractSdInsertPagesObjsDlg_Impl::GetList(const sal_uInt16 nType)
{
    return pDlg->GetList(nType);
}

bool AbstractSdInsertPagesObjsDlg_Impl::IsLink()
{
    return pDlg->IsLink();
}

bool AbstractSdInsertPagesObjsDlg_Impl::IsRemoveUnnessesaryMasterPages() const
{
    return pDlg->IsRemoveUnnessesaryMasterPages();
}

void AbstractMorphDlg_Impl::SaveSettings() const
{
    m_xDlg->SaveSettings();
}

sal_uInt16 AbstractMorphDlg_Impl::GetFadeSteps() const
{
    return m_xDlg->GetFadeSteps();
}

bool AbstractMorphDlg_Impl::IsAttributeFade() const
{
    return m_xDlg->IsAttributeFade();
}

bool AbstractMorphDlg_Impl::IsOrientationFade() const
{
    return m_xDlg->IsOrientationFade();
}

void AbstractSdStartPresDlg_Impl::GetAttr( SfxItemSet& rOutAttrs )
{
    m_xDlg->GetAttr( rOutAttrs );
}

void AbstractSdPresLayoutDlg_Impl::GetAttr( SfxItemSet& rOutAttrs )
{
    pDlg->GetAttr( rOutAttrs );
}

const SfxItemSet* SdAbstractSfxDialog_Impl::GetOutputItemSet() const
{
    return pDlg->GetOutputItemSet();
}

void SdAbstractSfxDialog_Impl::SetText( const OUString& rStr )
{
    pDlg->SetText( rStr );
}

const GDIMetaFile& AbstractSdVectorizeDlg_Impl::GetGDIMetaFile() const
{
    return m_xDlg->GetGDIMetaFile();
}

void AbstractSdPublishingDlg_Impl::GetParameterSequence( css::uno::Sequence< css::beans::PropertyValue >& rParams )
{
    pDlg->GetParameterSequence( rParams );
}

//-------------- SdAbstractDialogFactory implementation--------------

VclPtr<VclAbstractDialog> SdAbstractDialogFactory_Impl::CreateBreakDlg(
                                            weld::Window* pParent,
                                            ::sd::DrawView* pDrView,
                                            ::sd::DrawDocShell* pShell,
                                            sal_uLong nSumActionCount,
                                            sal_uLong nObjCount )
{
    return VclPtr<AbstractBreakDlg_Impl>::Create(new ::sd::BreakDlg(pParent, pDrView, pShell, nSumActionCount, nObjCount));
}

VclPtr<AbstractCopyDlg> SdAbstractDialogFactory_Impl::CreateCopyDlg(vcl::Window* pParent,
                                            const SfxItemSet& rInAttrs,
                                            ::sd::View* pView )
{
    return VclPtr<AbstractCopyDlg_Impl>::Create( VclPtr<::sd::CopyDlg>::Create( pParent, rInAttrs, pView ) );
}

VclPtr<AbstractSdCustomShowDlg> SdAbstractDialogFactory_Impl::CreateSdCustomShowDlg(weld::Window* pParent, SdDrawDocument& rDrawDoc )
{
    return VclPtr<AbstractSdCustomShowDlg_Impl>::Create(new SdCustomShowDlg(pParent, rDrawDoc));
}

VclPtr<SfxAbstractTabDialog>  SdAbstractDialogFactory_Impl::CreateSdTabCharDialog(vcl::Window* pParent, const SfxItemSet* pAttr, SfxObjectShell* pDocShell )
{
    return VclPtr<SdAbstractTabDialog_Impl>::Create( VclPtr<SdCharDlg>::Create(pParent, pAttr, pDocShell) );
}

VclPtr<SfxAbstractTabDialog>  SdAbstractDialogFactory_Impl::CreateSdTabPageDialog(vcl::Window* pParent, const SfxItemSet* pAttr, SfxObjectShell* pDocShell, bool bAreaPage )
{
    return VclPtr<SdAbstractTabDialog_Impl>::Create( VclPtr<SdPageDlg>::Create( pDocShell, pParent, pAttr, bAreaPage ) );
}

VclPtr<AbstractSdModifyFieldDlg> SdAbstractDialogFactory_Impl::CreateSdModifyFieldDlg(weld::Window* pParent, const SvxFieldData* pInField, const SfxItemSet& rSet)
{
    return VclPtr<AbstractSdModifyFieldDlg_Impl>::Create(new SdModifyFieldDlg(pParent, pInField, rSet));
}

VclPtr<AbstractSdSnapLineDlg> SdAbstractDialogFactory_Impl::CreateSdSnapLineDlg(weld::Window* pParent, const SfxItemSet& rInAttrs, ::sd::View* pView)
{
    return VclPtr<AbstractSdSnapLineDlg_Impl>::Create(new SdSnapLineDlg(pParent, rInAttrs, pView));
}

VclPtr<AbstractSdInsertLayerDlg> SdAbstractDialogFactory_Impl::CreateSdInsertLayerDlg(weld::Window* pParent, const SfxItemSet& rInAttrs, bool bDeletable, const OUString& aStr)
{
    return VclPtr<AbstractSdInsertLayerDlg_Impl>::Create(new SdInsertLayerDlg(pParent, rInAttrs, bDeletable, aStr));
}

VclPtr<AbstractSdInsertPagesObjsDlg> SdAbstractDialogFactory_Impl::CreateSdInsertPagesObjsDlg( vcl::Window* pParent, const SdDrawDocument* pDoc, SfxMedium* pSfxMedium, const OUString& rFileName )
{
    return VclPtr<AbstractSdInsertPagesObjsDlg_Impl>::Create( VclPtr<SdInsertPagesObjsDlg>::Create( pParent, pDoc, pSfxMedium, rFileName ) );
}

VclPtr<AbstractMorphDlg> SdAbstractDialogFactory_Impl::CreateMorphDlg(weld::Window* pParent, const SdrObject* pObj1, const SdrObject* pObj2)
{
    return VclPtr<AbstractMorphDlg_Impl>::Create(new ::sd::MorphDlg(pParent, pObj1, pObj2));
}

VclPtr<SfxAbstractTabDialog>  SdAbstractDialogFactory_Impl::CreateSdOutlineBulletTabDlg(vcl::Window* pParent, const SfxItemSet* pAttr, ::sd::View* pView )
{
    return VclPtr<AbstractBulletDialog_Impl>::Create( VclPtr<::sd::OutlineBulletDlg>::Create( pParent, pAttr, pView ) );
}

VclPtr<SfxAbstractTabDialog> SdAbstractDialogFactory_Impl::CreateSdParagraphTabDlg(vcl::Window* pParent, const SfxItemSet* pAttr )
{
    return VclPtr<SdAbstractTabDialog_Impl>::Create( VclPtr<SdParagraphDlg>::Create( pParent, pAttr ) );
}

VclPtr<AbstractSdStartPresDlg> SdAbstractDialogFactory_Impl::CreateSdStartPresentationDlg(weld::Window* pParent,
        const SfxItemSet& rInAttrs, const std::vector<OUString> &rPageNames, SdCustomShowList* pCSList)
{
    return VclPtr<AbstractSdStartPresDlg_Impl>::Create(new SdStartPresentationDlg(pParent, rInAttrs, rPageNames, pCSList));
}

VclPtr<VclAbstractDialog> SdAbstractDialogFactory_Impl::CreateRemoteDialog( vcl::Window* pParent )
{
     return VclPtr<SdVclAbstractDialog_Impl>::Create( VclPtr<::sd::RemoteDialog>::Create( pParent ) );
}

VclPtr<SfxAbstractTabDialog>  SdAbstractDialogFactory_Impl::CreateSdPresLayoutTemplateDlg( SfxObjectShell* pDocSh, vcl::Window* pParent, bool bBackgroundDlg, SfxStyleSheetBase& rStyleBase, PresentationObjects ePO, SfxStyleSheetBasePool* pSSPool )
{
    return VclPtr<SdPresLayoutTemplateDlg_Impl>::Create( VclPtr<SdPresLayoutTemplateDlg>::Create( pDocSh, pParent, bBackgroundDlg, rStyleBase, ePO, pSSPool ) );
}

VclPtr<AbstractSdPresLayoutDlg>  SdAbstractDialogFactory_Impl::CreateSdPresLayoutDlg(  ::sd::DrawDocShell* pDocShell, const SfxItemSet& rInAttrs)
{
    return VclPtr<AbstractSdPresLayoutDlg_Impl>::Create( VclPtr<SdPresLayoutDlg>::Create( pDocShell, nullptr, rInAttrs ) );
}

VclPtr<SfxAbstractTabDialog>  SdAbstractDialogFactory_Impl::CreateSdTabTemplateDlg(vcl::Window* pParent, const SfxObjectShell* pDocShell, SfxStyleSheetBase& rStyleBase, SdrModel* pModel, SdrView* pView )
{
    return VclPtr<SdAbstractTabDialog_Impl>::Create( VclPtr<SdTabTemplateDlg>::Create( pParent, pDocShell, rStyleBase, pModel, pView ) );
}

VclPtr<SfxAbstractDialog> SdAbstractDialogFactory_Impl::CreatSdActionDialog(vcl::Window* pParent, const SfxItemSet* pAttr, ::sd::View* pView )
{
    return VclPtr<SdAbstractSfxDialog_Impl>::Create( VclPtr<SdActionDlg>::Create( pParent, pAttr, pView ) );
}

VclPtr<AbstractSdVectorizeDlg>  SdAbstractDialogFactory_Impl::CreateSdVectorizeDlg(weld::Window* pParent, const Bitmap& rBmp, ::sd::DrawDocShell* pDocShell)
{
    return VclPtr<AbstractSdVectorizeDlg_Impl>::Create(new SdVectorizeDlg(pParent, rBmp, pDocShell));
}

VclPtr<AbstractSdPublishingDlg>  SdAbstractDialogFactory_Impl::CreateSdPublishingDlg( vcl::Window* pParent, DocumentType eDocType)
{
    return VclPtr<AbstractSdPublishingDlg_Impl>::Create( VclPtr<SdPublishingDlg>::Create( pParent, eDocType ) );
}

// Factories for TabPages
CreateTabPage SdAbstractDialogFactory_Impl::GetSdOptionsContentsTabPageCreatorFunc()
{
    return SdTpOptionsContents::Create;
}

CreateTabPage SdAbstractDialogFactory_Impl::GetSdPrintOptionsTabPageCreatorFunc()
{
    return SdPrintOptions::Create;
}

CreateTabPage SdAbstractDialogFactory_Impl::GetSdOptionsMiscTabPageCreatorFunc()
{
    return SdTpOptionsMisc::Create;
}

CreateTabPage SdAbstractDialogFactory_Impl::GetSdOptionsSnapTabPageCreatorFunc()
{
    return SdTpOptionsSnap::Create;
}

VclPtr<VclAbstractDialog> SdAbstractDialogFactory_Impl::CreateMasterLayoutDialog(weld::Window* pParent, SdDrawDocument* pDoc, SdPage* pCurrentPage)
{
  return VclPtr<AbstractMasterLayoutDialog_Impl>::Create(new ::sd::MasterLayoutDialog(pParent, pDoc, pCurrentPage));
}

VclPtr<AbstractHeaderFooterDialog> SdAbstractDialogFactory_Impl::CreateHeaderFooterDialog( sd::ViewShell* pViewShell,
  vcl::Window* pParent, SdDrawDocument* pDoc, SdPage* pCurrentPage )
{
    return VclPtr<AbstractHeaderFooterDialog_Impl>::Create( VclPtr<::sd::HeaderFooterDialog>::Create( pViewShell, pParent, pDoc, pCurrentPage ));
}

VclPtr<VclAbstractDialog> SdAbstractDialogFactory_Impl::CreateSdPhotoAlbumDialog(weld::Window* pParent, SdDrawDocument* pDoc)
{
    return VclPtr<SdAbstractGenericDialog_Impl>::Create(new sd::SdPhotoAlbumDialog(pParent, pDoc));
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
