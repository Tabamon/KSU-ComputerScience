#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer:
// Updated:    10/2019
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>

////////////////////////////////////////////////////////////////////////////
//           
template<typename T> 
class Node {
	public:
		Node(){
			data();
			next(0);
		}
		Node(const T &item){
			data(item);
			next(0);
		}
		T data;
		Node<T> *next;
	private:

};


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//    
template <typename T>
class stack {
public:
    stack();
    stack(const stack<T>&);
    ~stack();
    void swap(stack<T>&);
    stack<T>& operator=(stack<T>);
	bool empty() const;
	bool full() const;
	T top() const;
	T pop();
	void push(const T&);

private:
	Node<T> *tos;
};

template<typename T>
stack<T>::stack(){
	tos =0;
}

template<typename T>
stack<T>::stack(const stack<T>& stackToCopy){
	Node<T> *bottom, *tmpTos, *tmpNode;

	tmpTos = stackToCopy.tos;
	tos = 0;

	while(tmpTos != 0){
		tmpNode = new Node<T> (tmpTos -> data);
		
		if(tos==0){
			tos = tmpNode;
		}else{
			bottom->next = tmpNode;
		}

		bottom = tmpNode;
		tmpTos = tmpTos->next;
	}

}

template <typename T>
stack<T>::~stack()
{
	while (tos != 0) {
		Node<T> *tmp = tos;
		tos = tos->next;
		delete tmp;
	}

}

template<typename T>
void stack<T>::swap(stack<T> &swapStack){

	Node<T> *tmp = tos;
	tos = swapStack.tos;

	swapStack.tos = tmp;

}

template<typename T>
stack<T>& stack<T>::operator=(stack<T> assign){
	stack tmp(assign);
	swap(tmp);
	return *this;
}

#endif
