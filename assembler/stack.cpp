#include "stack.hpp"
#include <iostream>


template<typename T>
stack<T>::stack(){
	tos =0;
}

template<typename T>
stack<T>::stack(const stack<T>& stackToCopy){
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
	tmp = new T;
	if (tmp == 0) return true;
	else{
		delete tmp;
		return false;
	}
}

template<typename T>
T stack<T>::top() const{
	if (!empty()) return tos->data;
	else return NULL;
}

template<typename T>
T stack<T>::pop(){
	T result;
	if(!empty()){
		result = tos->data;
		Node<T> *tmp = tos;
		tos = tos->next;
		delete tmp;
	}else{
		std::cerr<<"ERROR empty stack"<<std::endl;
		return NULL;
	}
	return result;
}

template<typename T>
void stack<T>::push(const T& item){
	if (!full()){
		if (empty()){
			tos = new Node<T>(item);
			tos->next=NULL;
			return;
		}else{
			T tmp = tos;
			tos= new Node<T>(item);
			tos->next = tmp;
			return;
		}

	}else{
		std::cerr<<"Stack is out of memory!"<<std::endl;
	}
}