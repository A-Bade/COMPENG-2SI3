/*
 * Stack
 *
 *  Created on: Mar. 13, 2023
 *      Author: Darkb
 */

#ifndef STACK_H_
#define STACK_H_

class MyStack{
private:
	int capacity;
	int* items;
	int topIndex = -1;

public:
	MyStack();
	MyStack(int n);
	~MyStack();

	bool isEmpty();
	void push(const int& v);
	int top();
	int pop();
};



#endif /* STACK_H_ */
