#pragma once
#include "stdafx.h"
#include"Graph.h"




Graphmtx::Graphmtx(int sz) {      	//构造函数
	maxVertices = sz;
	numVertices = 0;  numEdges = 0;
	int i, j;
	VerticesList = new int[maxVertices];  	//创建顶点表
	Edge = (int **) new int *[maxVertices];	//创建邻接矩阵
	insertVertex(0);
	insertVertex(1);
	insertVertex(2);
	insertVertex(3);
	insertVertex(4);
	insertVertex(5);
	insertVertex(6);
	insertVertex(7);
	insertVertex(8);
	insertVertex(9);

	for (i = 0; i < maxVertices; i++)
		Edge[i] = new int[maxVertices];
	for (i = 0; i < maxVertices; i++)    	//邻接矩阵初始化
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? 0 : maxWeight;
	insertEdge(0, 1, 750);
	insertEdge(0, 2, 680);
	insertEdge(1, 2, 800);
	insertEdge(1, 3, 1140);
	insertEdge(1, 4, 650);
	insertEdge(2, 4, 820);
	insertEdge(2, 5, 960);
	insertEdge(3, 4, 570);
	insertEdge(3, 6, 840);
	insertEdge(4, 5, 1200);
	insertEdge(4, 7, 530);
	insertEdge(5, 7, 680);
	insertEdge(5, 9, 2600);
	insertEdge(6, 8, 340);
	insertEdge(7, 8, 900);
	insertEdge(7, 9, 1380);
	insertEdge(8, 9, 2500);
};


bool Graphmtx::insertVertex(const int vertex) {
	//在图的顶点表中插入一个新顶点vertex。
	if (numVertices == maxVertices) {	//顶点表满, 不能插入		
		return false;
	}
	VerticesList[numVertices++] = vertex;	//插入在表的最后
	return true;
};



bool Graphmtx::insertEdge(int v1, int v2, int cost)
{	//插入边(v1, v2), 权值为cost  
	if (v1 > -1 && v1 < numVertices && v2 > -1 &&
		v2 < numVertices && Edge[v1][v2] == maxWeight)
	{  	// 若为有向图，则去掉另一条边
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else	return false;
};


bool Graphmtx::removeEdge(int v1, int v2)
{	//在图中删去边(v1,v2)
	if (v1 > -1 && v1 < numVertices && v2 > -1 && v2 < numVertices && Edge[v1][v2] > 0 && Edge[v1][v2] < maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = maxWeight;
		numEdges--;
		return true;
	}
	else          return false;
};


bool Graphmtx::removeVertex(int v) {
	if (v < 0 && v >= numVertices)	 return false;							  		        //v不在图中,不删除
	if (numVertices == 1) return false; 								                      	//只剩一个顶点,不删除
	int i, j; VerticesList[v] = VerticesList[numVertices - 1];		  //顶点表中删除该结点，用最后一个顶点填补第v个顶点
	for (i = 0; i < numVertices; i++) {	                          //减去与v相关联边数
		if (Edge[i][v] > 0 && Edge[i][v] < maxWeight)	numEdges--;
	}
	for (i = 0; i < numVertices; i++) {     	          //用最后一列填补第v列
		Edge[i][v] = Edge[i][numVertices - 1];
	}
	numVertices--;				//顶点数减一
	for (j = 0; j < numVertices; j++) {		//用最后一行填补第v行
		Edge[v][j] = Edge[numVertices][j];
	}
	return true;
};


int Graphmtx::getFirstNeighbor(int v) {
	//给出顶点位置为v的第一个邻接顶点的位置, 
	//如果找不到, 则函数返回-1
	if (v != -1) {
		for (int col = 0; col < numVertices; col++)
			if (Edge[v][col]!=maxWeight && Edge[v][col] != maxWeight)
				return col;
	}
	return -1;
};

int Graphmtx::getNextNeighbor(int v, int w) {
	//给出顶点 v 的某邻接顶点 w 的下一个邻接顶点 
	if (v != -1 && w != -1) {
		for (int col = w + 1; col < numVertices; col++)
			if (Edge[v][col]!=maxWeight && Edge[v][col]!= maxWeight)
				return col;
	}
	return -1;
};

