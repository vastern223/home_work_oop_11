#include "Stack.h"

template<class T>
Stack<T>::Stack()
{
	topIndex = 0;
	max_size = 0;
	data = nullptr;
}
template<class T>
Stack<T>::Stack(int max_size) : Stack()
{
	this->max_size = max_size;

}

template<class T>
Stack<T>::~Stack()
{
	if (data != nullptr)
		delete[] data;
}


template<class T>
bool Stack<T>:: Push(T elem)
{
	if (IsFull())
	{
		T* new_data = new T[topIndex+1];

		for (int i = 0; i < topIndex; i++)
		{
			new_data[i] = data[i];
		}
		new_data[topIndex++] = elem;
		delete[] data;
		data = new_data;
		return true;
	}
		return false;
	
}

template<class T>
T Stack<T>::Pop()
{
	if (!IsEmpty())
	{
		T count = data[topIndex-1];
		T* new_data = new T[--topIndex];

		for (int i = 0; i < topIndex; i++)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		return 	count;
	}
	return 0;
}

template<class T>
int Stack<T>::GetCount() const
{
	return topIndex;
}

template<class T>
bool  Stack<T>::IsEmpty() const
{
	return topIndex == 0;
}

template<class T>
bool  Stack<T>::IsFull() const
{
	return (max_size == 0 || topIndex < max_size);
		
}

template<class T>
void  Stack<T>::Clear()
{
	topIndex = -1;
}


template<class T>
void Stack<T>::print()
{
	for (int i = 0; i <topIndex; i++)
	{
		cout << data[i] << endl;
	}
}

template<class T>
T Stack<T>::Peek()
{
	if (!IsEmpty())
		return data[topIndex-1];

	return 0;
}