#pragma once
#include<vector>
using namespace std;

enum heaptype
{
	MAXHEAP, MINHEAP,
};
template<class T>
class Myheap
{

private:
	std::vector<T>_vecdata;
	int _size;//Ԫ������
	int _capacity;//�����ѵĴ�С
	heaptype _type;
public:
	Myheap(T data[], int len, heaptype);
	Myheap(int capacity, heaptype);//һ���ն�
	virtual ~Myheap();
	bool push(T data);
	bool pop(T index);
	void print();
	bool full()
	{
		if (_size >= _capacity)
		{
			return true;
		}
		return false;
	}
	bool empty()
	{
		//�����Ƕ��Ƿ�Ϊ�ն�����_capacity�Ĵ�С
		return _size == 0;
	}

private:
	void _swap(int i, int j);

	//Ԫ���³�
	void _sink(int index);
	//Ԫ���ϸ�
	void _floating(int index);
};
template <class T>
Myheap<T>::Myheap(T data[], int len, heaptype type) :_size(0), _capacity(len), _type(type)
{
	_vecdata.resize(_capacity);
	//��data������Ԫ�ؼ������
	for (int i = 0; i < len; i++)
		push(data[i]);
}
template <class T>
Myheap<T>::Myheap(int capacity, heaptype type) :_size(0), _capacity(capacity), _type(type)   //����һ��capacity�ռ��С�Ŀն�
{
	_vecdata.resize(_capacity);
}
template <class T>
Myheap<T>::~Myheap()
{
	//vector�Զ�����
}
template<class T>
bool Myheap<T>::push(T data)
{
	if (full()) {
		throw("The heap is full !!\n");
		return false;
	}
	else
	{
		_vecdata[_size] = data;
		++_size;
		_floating(_size);
		//������λ�õ����ݽ����ж��ϸ�(�����λ�ô�1��ʼ�㣬����0)
		//����Ϊ�˸��������������ҽ���λ��
		//��ǰ�ڵ�: i   ����: 2i  �ҽ��: 2i+1
		return true;
	}
}
template<class T>
void Myheap<T>::_floating(int index)
{
	//ֻ��һ��Ԫ��&�նѲ���Ҫ���в���
	if (_size == 1)
		return;
	if (_type == MINHEAP)
	{
		for (int i = index; i > 0; i *= 0.5)
		{
			//С���ѵ��ϸ�
			//������ж������෴
			if (_vecdata[i - 1] < _vecdata[i*0.5 - 1])
				_swap(i - 1, i*0.5 - 1);
			else
				break;
		}
	}
	else if (_type == MAXHEAP)
	{
		for (int i = index; i > 0; i *= 0.5)
		{
			//����ѵ��ϸ�
			if (_vecdata[i - 1] > _vecdata[i*0.5 - 1])
				_swap(i - 1, i*0.5 - 1);
			else
				break;
		}
	}
	return;
}
template<class T>
void Myheap<T>::_swap(int i, int j)
{
	T temp = _vecdata[i];
	_vecdata[i] = _vecdata[j];
	_vecdata[j] = temp;
	return;
}
template<class T>
void Myheap<T>::_sink(int index)
{
	int i = index;
	if (_type == MINHEAP)
	{
		while (i * 2 <= _size)
		{
			//�������
			if (_vecdata[i - 1] > _vecdata[i * 2 - 1])
			{
				_swap(i - 1, i * 2 - 1);
				//������indexλ�õĽ�������ҽ���
				if (i * 2 + 1 <= _size && _vecdata[i - 1] > _vecdata[i * 2])
					_swap(i - 1, i * 2);
				i = i * 2;
			}
			//���ҽ���
			else if (i * 2 + 1 <= _size && _vecdata[i - 1] > _vecdata[i * 2])
			{
				_swap(i - 1, i * 2);
				i = i * 2 + 1;
			}
			else
				break;
		}
	}
	else if (_type == MAXHEAP)
	{
		while (i * 2 <= _size)
		{
			//�������
			if (_vecdata[i - 1] < _vecdata[i * 2 - 1])
			{
				_swap(i - 1, i * 2 - 1);
				//������indexλ�õĽ�������ҽ���
				if (i * 2 + 1 <= _size && _vecdata[i - 1] < _vecdata[i * 2])
					_swap(i - 1, i * 2);
				i = i * 2;
			}
			//���ҽ���
			else if (i * 2 + 1 <= _size && _vecdata[i - 1] < _vecdata[i * 2])
			{
				_swap(i - 1, i * 2);
				i = i * 2 + 1;
			}
			else
				break;
		}
	}
}
template<class T>
void Myheap<T>::print() {
	for (int i = 0; i < _size; i++)
		std::cout << _vecdata[i] << " ";
	std::cout << endl;
	return;
}
template<class T>
bool  Myheap<T>::pop(T index)
{
	if (empty())
	{
		throw("This is an empty heap !!\n");
		return false;
	}
	_vecdata[index] = _vecdata[_size - 1];
	--_size;
	_sink(index + 1);
	return true;
}