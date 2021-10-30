#pragma once
const int DefaultVertices = 30; //最大顶点数(=n) 
const int DefaultSize = 30;
const int maxWeight = 9999; //无穷大的值


struct MSTEdgeNode {		//T为顶点类型
	int tail, head;			//两顶点位置
	int key;				//边上的权值,为结点关键码
	MSTEdgeNode() {		//构造函数
		tail = -1;   head = -1;  key = 0;
	}
	

};

class MinSpanTree {
protected:
	MSTEdgeNode *edgevalue;	//边值数组   
	int maxSize, n;				//最大元素个数和当前个数
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
	int maxVertices;		    	//图中最大顶点数
	int numEdges;			//当前边数
	int numVertices;		    	//当前顶点数
public:
	int *VerticesList; 			//顶点表Verticeslist
	int **Edge;				//邻接矩阵

public:
	Graphmtx(int sz = DefaultVertices);    			//构造函数
	//～Graphmtx() { delete[]VerticesList;  delete[]Edge; }      	//析构函数
	int getValue(int i)
	{
		return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
	};  			//取顶点 i 的值, i 不合理返回0

	int getWeight(int v1, int v2) { return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0; }; 		//取边(v1,v2)上权值

	int getFirstNeighbor(int v);       		//取顶点 v 的第一个邻接顶点 
	int getNextNeighbor(int v, int w);	     	//取 v 的邻接顶点 w 的下一邻接顶点
	bool insertVertex(const int vertex);	    	//插入顶点vertex
	bool insertEdge(int v1, int v2, int cost);       	//插入边(v1, v2),权值为cost
	bool removeVertex(int v);                          	//删去顶点 v 和所有与它相关联的边
	bool removeEdge(int v1, int v2);               	//在图中删去边(v1,v2)
	int getVertexPos(int Vertex) {	   	//给出顶点vertex在图中的位置
		for (int i = 0; i < numVertices; i++)
			if (VerticesList[i] == Vertex) return i;
		return -1;
	};
	int NumberOfVertices() { return numVertices; }     		//返回当前顶点数
	int NumberOfEdges() { return numEdges; }

	

};