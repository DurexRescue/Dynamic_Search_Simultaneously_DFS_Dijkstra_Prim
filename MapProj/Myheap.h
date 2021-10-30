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
	int _size;//元素数量
	int _capacity;//整个堆的大小
	heaptype _type;
public:
	Myheap(T data[], int len, heaptype);
	Myheap(int capacity, heaptype);//一个空堆
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
		//检查的是堆是否为空而不是_capacity的大小
		return _size == 0;
	}

private:
	void _swap(int i, int j);

	//元素下沉
	void _sink(int index);
	//元素上浮
	void _floating(int index);
};
template <class T>
Myheap<T>::Myheap(T data[], int len, heaptype type) :_size(0), _capacity(len), _type(type)
{
	_vecdata.resize(_capacity);
	//将data数组中元素加入堆中
	for (int i = 0; i < len; i++)
		push(data[i]);
}
template <class T>
Myheap<T>::Myheap(int capacity, heaptype type) :_size(0), _capacity(capacity), _type(type)   //创建一个capacity空间大小的空堆
{
	_vecdata.resize(_capacity);
}
template <class T>
Myheap<T>::~Myheap()
{
	//vector自动析构
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
		//将当期位置的数据进行判断上浮(这里的位置从1开始算，而非0)
		//这是为了更方便计算左结点和右结点的位置
		//当前节点: i   左结点: 2i  右结点: 2i+1
		return true;
	}
}
template<class T>
void Myheap<T>::_floating(int index)
{
	//只有一个元素&空堆不需要进行操作
	if (_size == 1)
		return;
	if (_type == MINHEAP)
	{
		for (int i = index; i > 0; i *= 0.5)
		{
			//小根堆的上浮
			//大根堆判断条件相反
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
			//大根堆的上浮
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
			//与左结点比
			if (_vecdata[i - 1] > _vecdata[i * 2 - 1])
			{
				_swap(i - 1, i * 2 - 1);
				//交换后，index位置的结点与其右结点比
				if (i * 2 + 1 <= _size && _vecdata[i - 1] > _vecdata[i * 2])
					_swap(i - 1, i * 2);
				i = i * 2;
			}
			//与右结点比
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
			//与左结点比
			if (_vecdata[i - 1] < _vecdata[i * 2 - 1])
			{
				_swap(i - 1, i * 2 - 1);
				//交换后，index位置的结点与其右结点比
				if (i * 2 + 1 <= _size && _vecdata[i - 1] < _vecdata[i * 2])
					_swap(i - 1, i * 2);
				i = i * 2;
			}
			//与右结点比
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