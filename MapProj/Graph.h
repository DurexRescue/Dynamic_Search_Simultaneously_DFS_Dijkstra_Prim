#pragma once
const int DefaultVertices = 30; //��󶥵���(=n) 
const int DefaultSize = 30;
const int maxWeight = 9999; //������ֵ


struct MSTEdgeNode {		//TΪ��������
	int tail, head;			//������λ��
	int key;				//���ϵ�Ȩֵ,Ϊ���ؼ���
	MSTEdgeNode() {		//���캯��
		tail = -1;   head = -1;  key = 0;
	}
	

};

class MinSpanTree {
protected:
	MSTEdgeNode *edgevalue;	//��ֵ����   
	int maxSize, n;				//���Ԫ�ظ����͵�ǰ����
public:
	MinSpanTree(int sz = DefaultSize - 1) : maxSize(sz), n(0) {
		edgevalue = new MSTEdgeNode[sz];
	}
	/*
	int Insert(MSTEdgeNode& item) {
		
	}
	*/
	
};



class Graphmtx {
public:
	int maxVertices;		    	//ͼ����󶥵���
	int numEdges;			//��ǰ����
	int numVertices;		    	//��ǰ������
public:
	int *VerticesList; 			//�����Verticeslist
	int **Edge;				//�ڽӾ���

public:
	Graphmtx(int sz = DefaultVertices);    			//���캯��
	//��Graphmtx() { delete[]VerticesList;  delete[]Edge; }      	//��������
	int getValue(int i)
	{
		return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
	};  			//ȡ���� i ��ֵ, i ��������0

	int getWeight(int v1, int v2) { return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0; }; 		//ȡ��(v1,v2)��Ȩֵ

	int getFirstNeighbor(int v);       		//ȡ���� v �ĵ�һ���ڽӶ��� 
	int getNextNeighbor(int v, int w);	     	//ȡ v ���ڽӶ��� w ����һ�ڽӶ���
	bool insertVertex(const int vertex);	    	//���붥��vertex
	bool insertEdge(int v1, int v2, int cost);       	//�����(v1, v2),ȨֵΪcost
	bool removeVertex(int v);                          	//ɾȥ���� v ����������������ı�
	bool removeEdge(int v1, int v2);               	//��ͼ��ɾȥ��(v1,v2)
	int getVertexPos(int Vertex) {	   	//��������vertex��ͼ�е�λ��
		for (int i = 0; i < numVertices; i++)
			if (VerticesList[i] == Vertex) return i;
		return -1;
	};
	int NumberOfVertices() { return numVertices; }     		//���ص�ǰ������
	int NumberOfEdges() { return numEdges; }

	

};