#include "stack.h"
template<class T>
Stack<T>::Stack()
{
	count = 0;
	top_ptr = expression-1;
};
template<class T>
Stack<T>::~Stack()
{
}
template<class T>
bool Stack<T>::push(T s)
{
	if (count < MAX_SIZE) {
		*(++top_ptr) = s;
		count++;
		return true;
	}
	else return false;
}
template<class T>
T Stack<T>::pop()
{
	if (count) {
		count--;
		return *top_ptr--;
	}
	else return false;
}
template<class T>
T Stack<T>::top()
{
		return *top_ptr;
}
template<class T>
int Stack<T>::size()
{
	return count;
}
template<class T>
bool Stack<T>::is_empty()
{
	return count;
}
