/*
 * Stack.cpp
 *
 *  Created on: Mar. 12, 2023
 *      Author: Darkb
 */

#include "Stack.h"
#include <iostream>

MyStack::MyStack(){
	items = new int[100];
	capacity=100;
}
MyStack::MyStack(int n){
	items = new int[n];
	capacity = n;
}

MyStack::~MyStack(){
	delete[] items;
}

bool MyStack::isEmpty(){
	return (topIndex<0);
}

void MyStack::push(const int& v){
	if(topIndex == capacity-1){
		int* newArray = new int[2*capacity];
		for(int i=0;i<capacity;i++){
			newArray[i]=items[i];
		}
		delete[] items;
		items = newArray;
		capacity*=2;
	}
	items[++topIndex]=v;
}

int MyStack::top(){
	if(isEmpty()){
		throw std::underflow_error("Stack underflow");
	}
	else{
		return(items[topIndex]);
	}
}

int MyStack::pop(){
	if(isEmpty()){
		throw std::underflow_error("Stack Underflow");
	}
	else{
		int temp = items[topIndex];
		topIndex--;
		return temp;
	}
}


