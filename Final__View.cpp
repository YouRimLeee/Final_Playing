
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

#define UNKNOWN 0
#define Butterfly 1
#define Child 2
#define Move 3 

// CFinalView

IMPLEMENT_DYNCREATE(CFinalView, CView)

BEGIN_MESSAGE_MAP(CFinalView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_COMMAND(ID_PLAY_BUTTERFLY, &CFinalView::OnPlayButterfly)
	ON_COMMAND(ID_PLAY_CHILD, &CFinalView::OnPlayChild)
	ON_COMMAND(ID_PARK_MOVE, &CFinalView::OnParkMove)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CFinalView 생성/소멸

CFinalView::CFinalView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_kind = UNKNOWN;
	count = 0;
	m_index = 1;//사진이 1부터이므로 1로 초기화함
	m_xPos = 0;
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

void CFinalView::OnDraw(CDC* pDC)
{
	CFinalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//첫 페이지 
	CRect rt(100, 100, 300, 200);
	pDC->DrawText(L"20162990 이유림 \n 기말고사 프로젝트", &rt, DT_CENTER | DT_VCENTER);
	CRect rt2(400, 300, 1000, 600);
	pDC->DrawText(L"어린이용 간단한 놀이 \n \n play 메뉴에서 원하는 작업을 누르세요", &rt2, DT_CENTER | DT_VCENTER);

	if (m_kind == Butterfly) {

		CBitmap forest;
		forest.LoadBitmapW(IDB_BIT_FOREST);
		CDC mdc;
		mdc.CreateCompatibleDC(pDC);
		//배경 숲
		CRect message(50,0, 600, 200);
		pDC->DrawText(L"마우스를 한번 누르면 나비가 날아다닙니다^^", &message, DT_CENTER | DT_VCENTER);
		mdc.SelectObject(&forest);
		pDC->BitBlt(0, 50, 1200, 700, &mdc, 0, 0, SRCCOPY);
		CImage butterfly;
		butterfly.Load(L"res/butterfly.png");
		butterfly.Draw(*pDC, m_pt.x - 50, m_pt.y - 50);

	}
	else if (m_kind == Child) {
		CRect message(50, 0, 800, 200);
		pDC->DrawText(L"마우스를 한번 누르면 아이가 공원에서 뛰어다니는 모습이 나옵니다^^", &message, DT_CENTER | DT_VCENTER);
		CBitmap forest;
		forest.LoadBitmapW(IDB_BIT_FOREST);
		CDC mdc;
		mdc.CreateCompatibleDC(pDC);
		mdc.SelectObject(&forest);
		pDC->BitBlt(0, 50, 1200, 700, &mdc, 0, 0, SRCCOPY);//배경 숲

		CString filename;
		CImage child;
		filename.Format(L"res/child(%d).png", m_index);
		child.Load(filename);
		child.Draw(*pDC, m_xPos, 200, 100, 200);
	}

		else if (m_kind == Move) {
			CRect message(50, 0, 1000, 200);
			pDC->DrawText(L"마우스를 한번 누르면 아이는 뛰어다니고 나비는 날아다니는 공원 모습이 나타납니다^^", &message, DT_CENTER | DT_VCENTER);

			CBitmap forest;
			forest.LoadBitmapW(IDB_BIT_FOREST);
			CDC mdc;
			mdc.CreateCompatibleDC(pDC);
			mdc.SelectObject(&forest);
			pDC->BitBlt(0 - count, 50, 1200, 700, &mdc, 0, 0, SRCCOPY);
			pDC->BitBlt(1200 - count, 50, 1200, 700, &mdc, 0, 0, SRCCOPY);
			//배경 숲이 이동하는 것처럼 보이게 만듦
			CImage butterfly;
			butterfly.Load(L"res/butterfly.png");
			butterfly.Draw(*pDC, m_pt.x - 50, m_pt.y - 50);
			//나비가 날아다니는 모습
			CString filename;
			CImage child;
			filename.Format(L"res/child(%d).png", m_index);
			child.Load(filename);
			child.Draw(*pDC, m_xPos, 200, 100, 200);
		}
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.



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


void CFinalView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point);
	if (m_kind == Butterfly) {
		SetTimer(1, 100, NULL);
		m_xStep = (int)(point.x - m_pt.x) / 10;
		m_yStep = (int)(point.y - m_pt.y) / 10;
	}
	else if (m_kind == Child) {
		SetTimer(0, 100, NULL);
	}
	else if (m_kind == Move) {
		SetTimer(1, 150, NULL);
		m_xStep = (int)(point.x - m_pt.x) / 10;
		m_yStep = (int)(point.y - m_pt.y) / 10;
		m_count = 0;

	}
}


void CFinalView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnTimer(nIDEvent);
	if (m_kind == Butterfly) {//메뉴에서 Butterfly 누르면 호출

		m_pt.x = m_pt.x + m_xStep;
		m_pt.y = m_pt.y + m_yStep;
		if ((m_pt.x - 50) < 0 || (m_pt.x + 50) > 1200) //숲 배경에 맞춰서 돌아다니게 함(x축).
		{
			m_pt.x = (m_xStep < 0) ? 50 : (1200 - 50);
			m_pt.y = m_pt.y - m_yStep;
			m_xStep = m_xStep * -1;
		}
		if ((m_pt.y - 50) < 0 || (m_pt.y + 50) > 750) // 숲 배경에 맞춰서 돌아다니게 함(y축).
		{
			m_pt.x = m_pt.x - m_xStep;
			m_pt.y = (m_yStep < 0) ? 50 : 750 - 50;
			m_yStep = m_yStep * -1;
		}
		Invalidate();
	}
	else if (m_kind == Child) {//메뉴에서 Child 누르면 호출

		m_index = m_index + 1;
		if (m_index == 7)
			m_index = 1;
		m_xPos = m_xPos + 10;
		Invalidate(0);//깜빡임이 덜하도록 0을 넣어준다.
	}
	else if (m_kind == Move) {//메뉴에서 Move 누르면 호출
		m_pt.x = m_pt.x + m_xStep;
		m_pt.y = m_pt.y + m_yStep;
		if ((m_pt.x - 50) < 0 || (m_pt.x + 50) > m_WinRight)//Butterfly 와는 다르게 윈도우창 좌우 끝까지 움직일수 있다.
		{
			m_pt.x = (m_xStep < 0) ? 50 : (m_WinRight - 50);
			m_pt.y = m_pt.y - m_yStep;
			m_xStep = m_xStep * -1;
		}
		if ((m_pt.y - 50) < 0 || (m_pt.y + 50) > 750)
		{
			m_pt.x = m_pt.x - m_xStep;
			m_pt.y = (m_yStep < 0) ? 50 : (750 - 50);
			m_yStep = m_yStep * -1;
		}
		m_index = m_index + 1;
		if (m_index == 7)
			m_index = 1;
		m_xPos = m_xPos + 10;
		
		m_count++;
		if (m_count == 6)
			m_count = 0;
		count = count + 30;
		Invalidate();
		if (count == 1200) {
			count = 0;
		
		}
		Invalidate(0);
	}
}


void CFinalView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_WinRight = cx;
	m_WinBottom = cy;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CFinalView::OnPlayButterfly()//나비가 날아다니는 모습
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_kind = Butterfly;
	Invalidate();
}


void CFinalView::OnPlayChild()//아이가 뛰어다니는 모습
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_kind = Child;
	Invalidate();
}


void CFinalView::OnParkMove()//공원에서 아이가 뛰어다니고 나비가 날아다니는 모습
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_kind = Move;
	Invalidate();
}


void CFinalView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetTimer(1, 100, NULL);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
