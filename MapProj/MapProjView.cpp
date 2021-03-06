
// MapProjView.cpp: CMapProjView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MapProj.h"
#endif

#include "MapProjDoc.h"
#include "MapProjView.h"
#include "Graph.h"
#include "Myheap.h"
#include <stack>
#include <windows.h>
#include "heap.h"
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMapProjView

IMPLEMENT_DYNCREATE(CMapProjView, CView)

BEGIN_MESSAGE_MAP(CMapProjView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMapProjView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMapProjView 构造/析构

CMapProjView::CMapProjView() noexcept
{
	// TODO: 在此处添加构造代码
	
}

CMapProjView::~CMapProjView()
{
}

BOOL CMapProjView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMapProjView 绘图



void CMapProjView::OnDraw(CDC* pDC)
{
	CMapProjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CPoint point[10] = { {CPoint(500,100)},{CPoint(400,120)},{CPoint(500,210)},{CPoint(230,300)},{CPoint(410,280)},{CPoint(520,320)},{CPoint(200,400)},{CPoint(380,390)},{CPoint(280,520)},{CPoint(410,600)} };

	CPen pen0(PS_SOLID, 1, RGB(0, 0, 0));
	CPen pen1(PS_SOLID, 1, RGB(30, 20, 10));
	CPen pen2(PS_SOLID, 5, RGB(0, 255, 0));
	pDC->SelectObject(&pen0);
	CPoint p1(500, 100);
	CPoint p2(400, 120);
	CPoint p3(500, 210);
	CPoint p4(230, 300);
	CPoint p5(410, 280);
	CPoint p6(520, 320);
	CPoint p7(200, 400);
	CPoint p8(380, 390);
	CPoint p9(280, 520);
	CPoint p10(410, 600);
	
	
	pDC->MoveTo(p1);
	pDC->LineTo(p2);
	pDC->LineTo(p3);
	pDC->LineTo(p1);//123Succ
	pDC->MoveTo(p2);
	pDC->LineTo(p4);
	pDC->LineTo(p5);
	pDC->LineTo(p2);//245Succ
	pDC->MoveTo(p3);
	pDC->LineTo(p5);//235Succ
	pDC->LineTo(p6);
	pDC->LineTo(p3);//356Succ
	pDC->MoveTo(p4);
	pDC->LineTo(p7);
	pDC->LineTo(p9);
	pDC->LineTo(p8);
	pDC->LineTo(p5);//47985Succ
	pDC->MoveTo(p8);
	pDC->LineTo(p6);//586Succ
	pDC->LineTo(p10);
	pDC->LineTo(p9);
	pDC->MoveTo(p8);
	pDC->LineTo(p10);

	pDC->TextOut(p1.x, p1.y, _T("0"));
	pDC->TextOut(p2.x, p2.y, _T("1"));
	pDC->TextOut(p3.x, p3.y, _T("2"));
	pDC->TextOut(p4.x, p4.y, _T("3"));
	pDC->TextOut(p5.x, p5.y, _T("4"));
	pDC->TextOut(p6.x, p6.y, _T("5"));
	pDC->TextOut(p7.x, p7.y, _T("6"));
	pDC->TextOut(p8.x, p8.y, _T("7"));
	pDC->TextOut(p9.x, p9.y, _T("8"));
	pDC->TextOut(p10.x, p10.y, _T("9"));


	pDC->MoveTo(p1.x + 500, p1.y);
	pDC->LineTo(p2.x + 500, p2.y);
	pDC->LineTo(p3.x + 500, p3.y);
	pDC->LineTo(p1.x + 500, p1.y);//123Succ
	pDC->MoveTo(p2.x + 500, p2.y);
	pDC->LineTo(p4.x + 500, p4.y);
	pDC->LineTo(p5.x + 500, p5.y);
	pDC->LineTo(p2.x + 500, p2.y);//245Succ
	pDC->MoveTo(p3.x + 500, p3.y);
	pDC->LineTo(p5.x + 500, p5.y);//235Succ
	pDC->LineTo(p6.x + 500, p6.y);
	pDC->LineTo(p3.x + 500, p3.y);//356Succ
	pDC->MoveTo(p4.x + 500, p4.y);
	pDC->LineTo(p7.x + 500, p7.y);
	pDC->LineTo(p9.x + 500, p9.y);
	pDC->LineTo(p8.x + 500, p8.y);
	pDC->LineTo(p5.x + 500, p5.y);//47985Succ
	pDC->MoveTo(p8.x + 500, p8.y);
	pDC->LineTo(p6.x + 500, p6.y);//586Succ
	pDC->LineTo(p10.x + 500, p10.y);
	pDC->LineTo(p9.x + 500, p9.y);
	pDC->MoveTo(p8.x + 500, p8.y);
	pDC->LineTo(p10.x + 500, p10.y);

	pDC->TextOut(p1.x + 500, p1.y, _T("0"));
	pDC->TextOut(p2.x + 500, p2.y, _T("1"));
	pDC->TextOut(p3.x + 500, p3.y, _T("2"));
	pDC->TextOut(p4.x + 500, p4.y, _T("3"));
	pDC->TextOut(p5.x + 500, p5.y, _T("4"));
	pDC->TextOut(p6.x + 500, p6.y, _T("5"));
	pDC->TextOut(p7.x + 500, p7.y, _T("6"));
	pDC->TextOut(p8.x + 500, p8.y, _T("7"));
	pDC->TextOut(p9.x + 500, p9.y, _T("8"));
	pDC->TextOut(p10.x + 500, p10.y, _T("9"));

	pDC->MoveTo(p1.x + 1000, p1.y);
	pDC->LineTo(p2.x + 1000, p2.y);
	pDC->LineTo(p3.x + 1000, p3.y);
	pDC->LineTo(p1.x + 1000, p1.y);//123Succ
	pDC->MoveTo(p2.x + 1000, p2.y);
	pDC->LineTo(p4.x + 1000, p4.y);
	pDC->LineTo(p5.x + 1000, p5.y);
	pDC->LineTo(p2.x + 1000, p2.y);//245Succ
	pDC->MoveTo(p3.x + 1000, p3.y);
	pDC->LineTo(p5.x + 1000, p5.y);//235Succ
	pDC->LineTo(p6.x + 1000, p6.y);
	pDC->LineTo(p3.x + 1000, p3.y);//356Succ
	pDC->MoveTo(p4.x + 1000, p4.y);
	pDC->LineTo(p7.x + 1000, p7.y);
	pDC->LineTo(p9.x + 1000, p9.y);
	pDC->LineTo(p8.x + 1000, p8.y);
	pDC->LineTo(p5.x + 1000, p5.y);//47985Succ
	pDC->MoveTo(p8.x + 1000, p8.y);
	pDC->LineTo(p6.x + 1000, p6.y);//586Succ
	pDC->LineTo(p10.x + 1000, p10.y);
	pDC->LineTo(p9.x + 1000, p9.y);
	pDC->MoveTo(p8.x + 1000, p8.y);
	pDC->LineTo(p10.x + 1000, p10.y);

	pDC->TextOut(p1.x + 1000, p1.y, _T("0"));
	pDC->TextOut(p2.x + 1000, p2.y, _T("1"));
	pDC->TextOut(p3.x + 1000, p3.y, _T("2"));
	pDC->TextOut(p4.x + 1000, p4.y, _T("3"));
	pDC->TextOut(p5.x + 1000, p5.y, _T("4"));
	pDC->TextOut(p6.x + 1000, p6.y, _T("5"));
	pDC->TextOut(p7.x + 1000, p7.y, _T("6"));
	pDC->TextOut(p8.x + 1000, p8.y, _T("7"));
	pDC->TextOut(p9.x + 1000, p9.y, _T("8"));
	pDC->TextOut(p10.x + 1000, p10.y, _T("9"));
	

	pDC->TextOut(p1.x, p1.y, _T("0"));
	pDC->TextOut(p2.x, p2.y, _T("1"));
	pDC->TextOut(p3.x, p3.y, _T("2"));
	pDC->TextOut(p4.x, p4.y, _T("3"));
	pDC->TextOut(p5.x, p5.y, _T("4"));
	pDC->TextOut(p6.x, p6.y, _T("5"));
	pDC->TextOut(p7.x, p7.y, _T("6"));
	pDC->TextOut(p8.x, p8.y, _T("7"));
	pDC->TextOut(p9.x, p9.y, _T("8"));
	pDC->TextOut(p10.x, p10.y, _T("9"));
	
	Graphmtx G;
	
	bool DFSvisited[50];
	int boo;//逻辑数组初始化用
	for (boo = 0; boo < 50; boo++) DFSvisited[boo] = false;
	stack<int> s;
	int i = 5;//此为开始节点号
	s.push(i);
	int original = i;
	DFSvisited[i] = true;
	int offset[3] = { 0,0,0 };
	int o = 0;


	int n = G.NumberOfVertices();	  //顶点数
	int v, count;
	int m = G.NumberOfEdges();	  //边数
	int u = G.getVertexPos(i);		  //起始顶点号

	MSTEdgeNode ed; //边结点辅助单元

	MinHeap MinHeap(DefaultSize);  //最小堆
	bool Vmst[50];   	//最小生成树顶点集合
	for (boo = 0; boo < n; boo++)   Vmst[boo] = false;
	Vmst[u] = true;		        	//u 加入生成树
	count = 1;
	bool visited=false;

	int dist[11];
	int path[11];
	bool *S = new bool[n]; 	   		//最短路径顶点集 n为边数
	int l, j, k;  int w, min;
	for (l = 0; l < n; l++) {
		dist[l] = G.getWeight(i, l);
		S[l] = false;
		if (l != i && dist[l] != maxWeight) {
			path[l] = i;
			/*
			CPen pen1(PS_SOLID, 1, RGB(255, 0, 0));
			CPen pen2(PS_SOLID, 5, RGB(0, 255, 0));
			pDC->SelectObject(&pen1);
			pDC->MoveTo(point[i].x+1000,point[i].y);
			pDC->LineTo(point[l].x+1000,point[l].y);
			*/
		}
		else path[l] = -1;
	}
	S[i] = true;  dist[i] = 0;     		//顶点i加入顶点集合
	//-------------------------------------------------
	while(1){
L1:		while(1) {
		if (G.Edge[i][o] != maxWeight && DFSvisited[o] == false) {//出现于i的邻接点
				CString str;
				str.Format(_T("%d"), o);
				pDC->TextOut(200+offset[0],680, str);
				offset[0]=offset[0]+10;
				pDC->SelectObject(&pen2);
				pDC->MoveTo(point[i]);
				pDC->LineTo(point[o]);
			
				Sleep(1000);
				DFSvisited[o] = true;
				s.push(o);
				i = o;
				o = -1;//这两步赋值操作为了寻找o的邻接点//o=-1的目的是为了防止0号节点无法访问
				visited = true;
			}
			if (o == G.numVertices) {//意味着上面的那个if判断条件从来没成立过 即找不到i的邻接点
				if (original == s.top()) break;//栈顶元素与初始元素相同时意味着所有的节点都被访问 遍历结束！！
				s.pop();
				i = s.top();
				o = -1;//以栈顶元素为开始节点 继续查找出栈的栈顶元素的邻接点//o=-1的目的是为了防止0号节点无法访问
			}
			o++;
			if (S[1] && S[2] && S[3] && S[4] && S[5] && S[6] && S[7] && S[8] && S[9] && S[0] && Vmst[1] && Vmst[2] && Vmst[3] && Vmst[4] && Vmst[5] && Vmst[6] && Vmst[7] && Vmst[8] && Vmst[9] && DFSvisited[0] && DFSvisited[1] && DFSvisited[2] && DFSvisited[3] && DFSvisited[4] && DFSvisited[5] && DFSvisited[6] && DFSvisited[7] && DFSvisited[8] && DFSvisited[9])goto L4;
			if (visited) {
				visited = false;
				goto L2;
			}
		}//DFS 算法
	

	
L2:		do {			        	//迭代
			v = G.getFirstNeighbor(u);
			while (v != -1) {	        	//检测u所有邻接顶点
				if (!Vmst[v]) {	        	//v不在mst中
				
					ed.tail = u;  ed.head = v;
					ed.key = G.getWeight(u, v);
					MinHeap.Insert(ed);	        	//(u,v)加入堆
					CPen pen1(PS_SOLID, 1, RGB(255, 0, 0));
					CPen pen2(PS_SOLID, 5, RGB(0, 255, 0));
					pDC->SelectObject(&pen1);
					pDC->MoveTo(point[u].x+500,point[u].y);
					pDC->LineTo(point[v].x+500,point[v].y); 
					CString str;
					str.Format(_T("(""%d"",""%d"",""%d"")"),u,v,ed.key);
					pDC->TextOut(700 + offset[1], 680+offset[2], str);
				
					offset[1] = offset[1] + 80;
					if (offset[1] >= 320) {
						offset[2] = offset[2]+30;
						offset[1] = 0;
					}
					Sleep(1000);
				}     			//堆中存所有u在mst中, v不在mst中的边
				v = G.getNextNeighbor(u, v);
			}
			while (!MinHeap.IsEmpty() && count < n) {
				MinHeap.Remove(ed);	         	//选堆中具最小权的边

				if (!Vmst[ed.head]) {
					//MST.Insert(ed);       	//加入最小生成树
					u = ed.head;  Vmst[u] = true; 	//u加入生成树顶点集合
					CPen pen2(PS_SOLID, 5, RGB(0, 255, 0));
					pDC->SelectObject(&pen2);
					pDC->MoveTo(point[ed.head].x + 500, point[ed.head].y);
					pDC->LineTo(point[ed.tail].x + 500, point[ed.tail].y);
					Sleep(1000);
					count++;  break;
				}
			}
			if (S[1] && S[2] && S[3] && S[4] && S[5] && S[6] && S[7] && S[8] && S[9] && S[0] && Vmst[1] && Vmst[2] && Vmst[3] && Vmst[4] && Vmst[5] && Vmst[6] && Vmst[7] && Vmst[8] && Vmst[9] && DFSvisited[0] && DFSvisited[1] && DFSvisited[2] && DFSvisited[3] && DFSvisited[4] && DFSvisited[5] && DFSvisited[6] && DFSvisited[7] && DFSvisited[8] && DFSvisited[9])goto L4;
			goto L3;
		} while (count < n);//Prim算法

	
L3:		for (l = 0; l < n - 1; l++) {       		//求解各顶点最短路径
			min = 9999;  int u = i;
			for (j = 0; j < n; j++){
				if (!S[j] && dist[j] < min && dist[j]!=maxWeight) 		//选不在S中具有最短路径的顶点u
				{
					u = j; 
					min = dist[j];
				}
			}
			S[u] = true;	               		//将顶点u加入集合S
			CPen pen2(PS_SOLID, 5, RGB(0, 255, 0));
			pDC->SelectObject(&pen2);
			pDC->MoveTo(point[path[u]].x + 1000, point[path[u]].y);
			pDC->LineTo(point[u].x + 1000, point[u].y);
			for (k = 0; k < n; k++) {       		//修改
				w = G.getWeight(u, k);
				if (!S[k] && w !=maxWeight && dist[u] + w < dist[k]) {    //顶点k未加入S                
					dist[k] = dist[u] + w;
					path[k] = u;     			//修改到k的最短路径
					
				}
			}
			Sleep(1000);
			MessageBox(_T("a"));
			goto L1;
		}if (S[1] && S[2] && S[3] && S[4] && S[5] && S[6] && S[7] && S[8] && S[9] && S[0] && Vmst[1] && Vmst[2] && Vmst[3] && Vmst[4] && Vmst[5] && Vmst[6] && Vmst[7] && Vmst[8] && Vmst[9] && DFSvisited[0] && DFSvisited[1] && DFSvisited[2] && DFSvisited[3] && DFSvisited[4] && DFSvisited[5] && DFSvisited[6] && DFSvisited[7] && DFSvisited[8] && DFSvisited[9])goto L4;
	}
L4: return; }










// CMapProjView 打印


void CMapProjView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMapProjView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMapProjView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMapProjView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMapProjView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMapProjView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMapProjView 诊断

#ifdef _DEBUG
void CMapProjView::AssertValid() const
{
	CView::AssertValid();
}

void CMapProjView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMapProjDoc* CMapProjView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapProjDoc)));
	return (CMapProjDoc*)m_pDocument;
}
#endif //_DEBUG


// CMapProjView 消息处理程序
/*
Graphmtx G;
void DFS(int i, Graphmtx  G)
{
	bool DFSvisited[50];
	for (int boo = 0; boo < 50; boo++) DFSvisited[boo] = false;
	stack<int> s;
	s.push(i);
	int original = i;
	DFSvisited[i] = true;
	for (int j = i;; j++) {
		if (G.Edge[i][j] != maxWeight && DFSvisited[j] == false) {//出现于i的邻接点
			DFSvisited[j] = true;
			s.push(j);
			i = j;
			j = 0;//这两步赋值操作为了寻找j的邻接点
		}
		if (j == G.numVertices) {//意味着上面的那个if判断条件从来没成立过 即找不到i的邻接点
			if (original == s.top()) break;//栈顶元素与初始元素相同时意味着所有的节点都被访问 遍历结束！！
			s.pop();
			i = s.top();
			j = 0;//以栈顶元素为开始节点 继续查找出栈的栈顶元素的邻接点
		}
	}
}
*/	