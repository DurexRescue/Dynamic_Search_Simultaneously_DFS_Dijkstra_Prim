#pragma once
#include "stdafx.h"
#include"Graph.h"




Graphmtx::Graphmtx(int sz) {      	//���캯��
	maxVertices = sz;
	numVertices = 0;  numEdges = 0;
	int i, j;
	VerticesList = new int[maxVertices];  	//���������
	Edge = (int **) new int *[maxVertices];	//�����ڽӾ���
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
	for (i = 0; i < maxVertices; i++)    	//�ڽӾ����ʼ��
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
	//��ͼ�Ķ�����в���һ���¶���vertex��
	if (numVertices == maxVertices) {	//�������, ���ܲ���		
		return false;
	}
	VerticesList[numVertices++] = vertex;	//�����ڱ�����
	return true;
};



bool Graphmtx::insertEdge(int v1, int v2, int cost)
{	//�����(v1, v2), ȨֵΪcost  
	if (v1 > -1 && v1 < numVertices && v2 > -1 &&
		v2 < numVertices && Edge[v1][v2] == maxWeight)
	{  	// ��Ϊ����ͼ����ȥ����һ����
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else	return false;
};


bool Graphmtx::removeEdge(int v1, int v2)
{	//��ͼ��ɾȥ��(v1,v2)
	if (v1 > -1 && v1 < numVertices && v2 > -1 && v2 < numVertices && Edge[v1][v2] > 0 && Edge[v1][v2] < maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = maxWeight;
		numEdges--;
		return true;
	}
	else          return false;
};


bool Graphmtx::removeVertex(int v) {
	if (v < 0 && v >= numVertices)	 return false;							  		        //v����ͼ��,��ɾ��
	if (numVertices == 1) return false; 								                      	//ֻʣһ������,��ɾ��
	int i, j; VerticesList[v] = VerticesList[numVertices - 1];		  //�������ɾ���ý�㣬�����һ���������v������
	for (i = 0; i < numVertices; i++) {	                          //��ȥ��v���������
		if (Edge[i][v] > 0 && Edge[i][v] < maxWeight)	numEdges--;
	}
	for (i = 0; i < numVertices; i++) {     	          //�����һ�����v��
		Edge[i][v] = Edge[i][numVertices - 1];
	}
	numVertices--;				//��������һ
	for (j = 0; j < numVertices; j++) {		//�����һ�����v��
		Edge[v][j] = Edge[numVertices][j];
	}
	return true;
};


int Graphmtx::getFirstNeighbor(int v) {
	//��������λ��Ϊv�ĵ�һ���ڽӶ����λ��, 
	//����Ҳ���, ��������-1
	if (v != -1) {
		for (int col = 0; col < numVertices; col++)
			if (Edge[v][col]!=maxWeight && Edge[v][col] != maxWeight)
				return col;
	}
	return -1;
};

int Graphmtx::getNextNeighbor(int v, int w) {
	//�������� v ��ĳ�ڽӶ��� w ����һ���ڽӶ��� 
	if (v != -1 && w != -1) {
		for (int col = w + 1; col < numVertices; col++)
			if (Edge[v][col]!=maxWeight && Edge[v][col]!= maxWeight)
				return col;
	}
	return -1;
};

