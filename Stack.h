#pragma once
#include<iostream>
using namespace std;

template<class T>

class Stack
{
	T*data;
	int topIndex;
	int max_size;

public:
	
	Stack();
	Stack(int max_size);
	~Stack();
	bool Push(T elem);
	T Pop();
	T Peek();
	int GetCount() const;
	bool IsEmpty() const;
	bool IsFull() const;
	void print();
	void Clear();
};
