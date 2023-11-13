#pragma once
template <class T>
class Stack
{
public:
	Stack();
	~Stack();
	bool push(T s);
	T pop();
	T top();
	int size();
	bool is_empty();
private:
	static const int MAX_SIZE = 128;
	T expression[MAX_SIZE];
	T* top_ptr;
	int count;
};
template class Stack<char>;
template class Stack<double>;
