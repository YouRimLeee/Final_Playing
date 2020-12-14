
// Final__View.cpp: CFinalView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Final__.h"
#endif

#include "Final__Doc.h"
#include "Final__View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFinalView

IMPLEMENT_DYNCREATE(CFinalView, CView)

BEGIN_MESSAGE_MAP(CFinalView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFinalView 생성/소멸

CFinalView::CFinalView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CFinalView::~CFinalView()
{
}

BOOL CFinalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFinalView 그리기

void CFinalView::OnDraw(CDC* /*pDC*/)
{
	CFinalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CFinalView 인쇄

BOOL CFinalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFinalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFinalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CFinalView 진단

#ifdef _DEBUG
void CFinalView::AssertValid() const
{
	CView::AssertValid();
}

void CFinalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFinalDoc* CFinalView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFinalDoc)));
	return (CFinalDoc*)m_pDocument;
}
#endif //_DEBUG


// CFinalView 메시지 처리기
