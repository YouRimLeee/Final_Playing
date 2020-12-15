
// Final__View.h: CFinalView 클래스의 인터페이스
//

#pragma once


class CFinalView : public CView
{
protected: // serialization에서만 만들어집니다.
	CFinalView() noexcept;
	DECLARE_DYNCREATE(CFinalView)

// 특성입니다.
public:
	CFinalDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CFinalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPlayButterfly();
	afx_msg void OnPlayChild();
	afx_msg void OnParkMove();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint m_pt;
	int m_xStep;
	int m_yStep;
	int m_WinRight;
	int m_WinBottom;
	int m_kind;
	int m_count;
	CPoint m_Child;
	int count;
	int m_index;
	int m_xPos;
	afx_msg void OnPlayPuzzle();
	bool Exist(int num[], int count);
};

#ifndef _DEBUG  // Final__View.cpp의 디버그 버전
inline CFinalDoc* CFinalView::GetDocument() const
   { return reinterpret_cast<CFinalDoc*>(m_pDocument); }
#endif

