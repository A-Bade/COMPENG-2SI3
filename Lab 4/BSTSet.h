#ifndef BSTSET_H_
#define BSTSET_H_

#include "TNode.h"
#include <vector>
#include <iostream>
#include <vector>
using namespace std;

class BSTSet
{
private:
	// must contain only one private field
	TNode* root;

public:
	// required constructors/destructor
	BSTSet();
	BSTSet(const std::vector<int>& input);
	~BSTSet();

	// required methods
	bool isIn(int v);
	void add(int v);
	bool remove(int v);
	void Union(const BSTSet& s);
	void intersection(const BSTSet& s);
	void difference(const BSTSet& s);
	int size();
	int height();
	void printNonRec(); // create and use class MyStack

	//Recursion Classes
	void rec_union(const TNode* n);
	void rec_intersec(const TNode* n, const BSTSet& s);
	void rec_diff(const TNode* n, const BSTSet& s);
	int rec_size(const TNode* n, int size);
	int rec_h(const TNode* n, int mh, int h);

	// provided recursive print method
	void printBSTSet();

	// Used for testing
	TNode* getRoot()
	{
		return root;
	}

private:
	// provided helper methods
	void printBSTSet(TNode* t);
};

#endif /* BSTSET_H_ */
