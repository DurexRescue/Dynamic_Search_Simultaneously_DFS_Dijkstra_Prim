#pragma once

#include"Graph.h"
#include <iostream>
using namespace std;

class MinHeap {
public:
	MinHeap(int sz = DefaultSize);		//构造函数
	MinHeap(MSTEdgeNode arr[], int n);		//构造函数
	//～MinHeap() { delete[] heap; }		//析构函数
	bool Insert(MSTEdgeNode& x);			//插入
	bool Remove(MSTEdgeNode& d);			//删除
	bool IsEmpty() const { return  currentSize == 0; } 	//判堆空否
	bool IsFull() const { return currentSize == maxHeapSize; } //判堆满否
	void MakeEmpty() { currentSize = 0; }	//置空堆
private:
	MSTEdgeNode *heap;			//最小堆元素存储数组
	int currentSize;		//最小堆当前元素个数
	int maxHeapSize;		//最小堆最大容量
	void siftDown(int start, int m);		//调整算法
	void siftUp(int start);		          	//调整算法
};


MinHeap::MinHeap(int sz) {
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new MSTEdgeNode[maxHeapSize];  	//创建堆空间
	if (heap == NULL) {
		cerr << "堆存储分配失败！" << endl;  exit(1);
	}
	currentSize = 0;				//建立当前大小
};


MinHeap::MinHeap(MSTEdgeNode arr[], int n) {
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new MSTEdgeNode[maxHeapSize];
	if (heap == NULL) {
		cerr << "堆存储分配失败！" << endl;  exit(1);
	}
	for (int i = 0; i < n; i++) heap[i] = arr[i];
	currentSize = n;	       	//复制堆数组, 建立当前大小
	int currentPos = (currentSize - 2) / 2;        //找最初调整位置:最后分支结点
	while (currentPos >= 0) {	    //逐步向上扩大堆
		siftDown(currentPos, currentSize - 1);      //局部自上向下下滑调整
		currentPos--;
	}
};

void MinHeap::siftDown(int start, int m) {
	int i = start, j = 2 * i + 1; MSTEdgeNode temp = heap[i]; 	//j是i的左子女位置	
	while (j <= m) {			//检查是否到最后位置
		if (j < m && heap[j].key > heap[j + 1].key) j++;     	//让j指向两子女中的小者
		if (temp.key <= heap[j].key) break;	//小则不做调整
		else { 	//否则小者上移, i, j下降
			heap[i] = heap[j];  i = j; j = 2 * j + 1;
		}
	}
	heap[i] = temp; //回放temp
};


bool MinHeap::Insert(MSTEdgeNode& x) {
	//公共函数: 将x插入到最小堆中
	if (currentSize == maxHeapSize) { 	//堆满
		cerr << "Heap Full" << endl;  return false;
	}
	heap[currentSize] = x;  		//插入
	siftUp(currentSize);			//向上调整
	currentSize++;				//堆计数加1
	return true;
};


void MinHeap::siftUp(int start) {
	//私有函数: 从结点start开始到结点0为止, 自下向上
	//比较, 如果子女的值小于父结点的值, 则相互交换, 
	//这样将集合重新调整为最小堆。关键码比较符<=在E中定义
	int j = start, i = (j - 1) / 2;   MSTEdgeNode temp = heap[j];
	while (j > 0) {		//沿父结点路径向上直达根
		if (heap[i].key <= temp.key) break;	//父结点值小, 不调整
		else {		//父结点结点值大, 调整
			heap[j] = heap[i];  j = i;  i = (i - 1) / 2;
		}
	}
	heap[j] = temp;				//回送
};


bool MinHeap::Remove(MSTEdgeNode& x) {
	if (!currentSize) {		//堆空, 返回false
		cout << "Heap empty" << endl;  return false;
	}
	x = heap[0];
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);    	//自上向下调整为堆
	return true;			//返回最小元素
};

