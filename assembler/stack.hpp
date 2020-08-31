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
#include <iostream>

////////////////////////////////////////////////////////////////////////////
//           
template<typename T> 
class Node {
	public:
		Node(){
			next = NULL;
		}
		Node(const T &item){
			data = item;
			next= NULL;
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
	tos=0;
}

template<typename T>
stack<T>::stack(const stack<T>& stackToCopy):stack(){
	if(!stackToCopy.empty()){
		Node<T> *bottom, *tmpTos, *tmpNode;

		tmpTos = stackToCopy.tos;

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

template<typename T>
bool stack<T>::empty() const{
	if (tos==0) return true;
	else return false;
} 

template<typename T>
bool stack<T>::full() const{

	Node<T> *tmp;
	tmp = 0;
	tmp = new Node<T>;
	if (tmp == 0) return true;
	else{
		delete tmp;
		return false;
	}
}

template<typename T>
T stack<T>::top() const{
	if (!empty()) return tos->data;
	else throw std::runtime_error("ERROR: empty stack");
}

template<typename T>
T stack<T>::pop(){
	if(!empty()){
		T result = tos->data;
		Node<T> *tmp = tos;
		tos = tos->next;
		delete tmp;
		return result;
	}else {
    throw std::runtime_error("ERROR empty stack");
	}
}


template<typename T>
void stack<T>::push(const T& item){
	if (!full()){
		if (empty()){
			tos = new Node<T>(item);
			tos->next=NULL;
			return;
		}else{
			Node<T> *tmp = tos;
			tos= new Node<T>(item);
			tos->next = tmp;
			return;
		}

	}else{
		std::cerr<<"Stack is out of memory!"<<std::endl;
	}
}

#endif