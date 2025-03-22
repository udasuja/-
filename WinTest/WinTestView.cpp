
// WinTestView.cpp: CWinTestView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "WinTest.h"
#endif

#include "WinTestDoc.h"
#include "WinTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinTestView

IMPLEMENT_DYNCREATE(CWinTestView, CView)

BEGIN_MESSAGE_MAP(CWinTestView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWinTestView 생성/소멸

CWinTestView::CWinTestView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	
}

CWinTestView::~CWinTestView()
{
}

BOOL CWinTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWinTestView 그리기

void CWinTestView::OnDraw(CDC* pDC)
{
	CWinTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			unsigned char InVal = pDoc->m_InImg[i][j];
			unsigned char OutVal = pDoc->m_OutImg[i][j];
			pDC->SetPixel(j, i, RGB(InVal, InVal, InVal));
			pDC->SetPixel(j * 300, i, RGB(OutVal, OutVal, OutVal));
		}
	}
}


// CWinTestView 인쇄

BOOL CWinTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWinTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWinTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWinTestView 진단

#ifdef _DEBUG
void CWinTestView::AssertValid() const
{
	CView::AssertValid();
}

void CWinTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinTestDoc* CWinTestView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinTestDoc)));
	return (CWinTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CWinTestView 메시지 처리기


void CWinTestView::OnReverseImg()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	
}
