#pragma once

#include"Graph.h"
#include <iostream>
using namespace std;

class MinHeap {
public:
	MinHeap(int sz = DefaultSize);		//���캯��
	MinHeap(MSTEdgeNode arr[], int n);		//���캯��
	//��MinHeap() { delete[] heap; }		//��������
	bool Insert(MSTEdgeNode& x);			//����
	bool Remove(MSTEdgeNode& d);			//ɾ��
	bool IsEmpty() const { return  currentSize == 0; } 	//�жѿշ�
	bool IsFull() const { return currentSize == maxHeapSize; } //�ж�����
	void MakeEmpty() { currentSize = 0; }	//�ÿն�
private:
	MSTEdgeNode *heap;			//��С��Ԫ�ش洢����
	int currentSize;		//��С�ѵ�ǰԪ�ظ���
	int maxHeapSize;		//��С���������
	void siftDown(int start, int m);		//�����㷨
	void siftUp(int start);		          	//�����㷨
};


MinHeap::MinHeap(int sz) {
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new MSTEdgeNode[maxHeapSize];  	//�����ѿռ�
	if (heap == NULL) {
		cerr << "�Ѵ洢����ʧ�ܣ�" << endl;  exit(1);
	}
	currentSize = 0;				//������ǰ��С
};


MinHeap::MinHeap(MSTEdgeNode arr[], int n) {
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new MSTEdgeNode[maxHeapSize];
	if (heap == NULL) {
		cerr << "�Ѵ洢����ʧ�ܣ�" << endl;  exit(1);
	}
	for (int i = 0; i < n; i++) heap[i] = arr[i];
	currentSize = n;	       	//���ƶ�����, ������ǰ��С
	int currentPos = (currentSize - 2) / 2;        //���������λ��:����֧���
	while (currentPos >= 0) {	    //�����������
		siftDown(currentPos, currentSize - 1);      //�ֲ����������»�����
		currentPos--;
	}
};

void MinHeap::siftDown(int start, int m) {
	int i = start, j = 2 * i + 1; MSTEdgeNode temp = heap[i]; 	//j��i������Ůλ��	
	while (j <= m) {			//����Ƿ����λ��
		if (j < m && heap[j].key > heap[j + 1].key) j++;     	//��jָ������Ů�е�С��
		if (temp.key <= heap[j].key) break;	//С��������
		else { 	//����С������, i, j�½�
			heap[i] = heap[j];  i = j; j = 2 * j + 1;
		}
	}
	heap[i] = temp; //�ط�temp
};


bool MinHeap::Insert(MSTEdgeNode& x) {
	//��������: ��x���뵽��С����
	if (currentSize == maxHeapSize) { 	//����
		cerr << "Heap Full" << endl;  return false;
	}
	heap[currentSize] = x;  		//����
	siftUp(currentSize);			//���ϵ���
	currentSize++;				//�Ѽ�����1
	return true;
};


void MinHeap::siftUp(int start) {
	//˽�к���: �ӽ��start��ʼ�����0Ϊֹ, ��������
	//�Ƚ�, �����Ů��ֵС�ڸ�����ֵ, ���໥����, 
	//�������������µ���Ϊ��С�ѡ��ؼ���ȽϷ�<=��E�ж���
	int j = start, i = (j - 1) / 2;   MSTEdgeNode temp = heap[j];
	while (j > 0) {		//�ظ����·������ֱ���
		if (heap[i].key <= temp.key) break;	//�����ֵС, ������
		else {		//�������ֵ��, ����
			heap[j] = heap[i];  j = i;  i = (i - 1) / 2;
		}
	}
	heap[j] = temp;				//����
};


bool MinHeap::Remove(MSTEdgeNode& x) {
	if (!currentSize) {		//�ѿ�, ����false
		cout << "Heap empty" << endl;  return false;
	}
	x = heap[0];
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);    	//�������µ���Ϊ��
	return true;			//������СԪ��
};

