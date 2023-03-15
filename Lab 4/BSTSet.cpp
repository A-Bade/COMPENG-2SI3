#include "BSTSet.h"
#include <iostream>
#include <vector>
using namespace std;
#include "Stack.h"

BSTSet::BSTSet()
{
	root = 0;
}

BSTSet::BSTSet(const std::vector<int>& input)
{
	if (input.size() == 0) //if the size is 0
	{
		root = NULL; //empty tree
		return;
	}

	root = new TNode(input[0], NULL, NULL); //defining root as a new TNode with paramaters of the first, left, and right input
	TNode *temp = root; //create a temporary TNode that will point to root

	if (input.size() == 1) //if there is already only one input
	{
		return; //exit
	}

	for (int i = 1; i < input.size(); i++) //iterate from i to the value that is less than the input size
	{
		while (true) //infinite loop until can exit
		{
			if (input[i] < temp->element)
			{ //if the number that being added is smaller than the current node
				if (temp->left != NULL)
				{ //if the left node has value in it or if it exist
					temp = temp->left; //then set temp to point to left
				}

				else //if the node does exist on the left side
				{
					temp->left = new TNode(input[i], NULL, NULL); //created a new TNode for the left
					break; // breaks out of the while loop to the next i

				}
			}

			else if (input[i] > temp->element)
			{ //if the number to be added is greater than the current node
				if (temp->right != NULL)
					{ //if the right node has value in it or if it exist
						temp = temp->right; //then set temp to point to right
					}

					else //if the node does exist on the right side
					{
						temp->right = new TNode(input[i], NULL, NULL); //created a new TNode for the right side
						break; // breaks out of the while loop to the next i
					}
			}
			else { // value is already in the tree
				break;
			}
		}
		temp = root;
	}
}

BSTSet::~BSTSet()
{
	delete root; //free memory
}

bool BSTSet::isIn(int v)
//T(n) = O(log(n)) -Since this is bst, for every condition, we'll divide it's option by 2.
//S(n) = O(1) -THis only creating TNode* temp. & non-rec.
{
	if (root == NULL) //if the root is empty
	{ 
		return false; //return false
	}

	TNode *temp = root; //create temporary TNode pointing to root
	
	while (true) //infinite loop until it reaches null
	{
		if (v == temp->element) //if our int v is a value of the current node
		{
			return true;
		}

		else if (v > temp->element) //if v is greater than the current node element
		{
			if (temp->right == NULL) //if right is  NULL
			{
				return false;
			}

			else //If it contains a value
			{
				temp = temp->right; //set temp to the right
			}
		}

		else if (v < temp->element)
		{ //if the value is less than the current node element
			if (temp->left == NULL) //if right is  NULL
			{
				return false;
			}

			else //If it contains a value
			{
				temp = temp->left; //set temp to the right
			}
		}
	}
}

void BSTSet::add(int v)
//T(n) = O(log(n)) -Since this is bst, for every condition, we'll divide it's option by 2.
//S(n) = O(1) -THis only creating TNode* temp. & non-rec.
{
	if (root == NULL)
	{
		root = new TNode(v, NULL, NULL);
	}

	if (isIn(v) == false) //if the value (v) is not in the set
	{
		TNode *temp = root; //create temp TNode pointing to root
		while (true)
		{
			if (v > temp->element)
			{ //if the value is greater than the current node element
				if (temp->right != NULL)
				{ //if right is not NULL
					temp = temp->right; //set temp to the right
				}
				else
				{
					temp->right = new TNode(v, NULL, NULL); //if right does not exist, create it
					return;
				}
			}
			else if (v < temp->element)
			{ //if value is less than the current node element
				if (temp->left != NULL)
				{ //if left is not NULL
					temp = temp->left; //set temp to point to the left
				}
				else
				{
					temp->left = new TNode(v, NULL, NULL); //create a new TNode
					return;
				}
			}

	else
	{
		return;
	}

		}
	}
}


bool BSTSet::remove(int v)
//T(n) = O(log(n))(AVERAGE) -Since this is bst, for every condition, we'll divide it's option by 2.
//S(n) = O(1) -THis only creating TNode* temp. & non-rec.
{
	if (!isIn(v))//if v is not in the set
	{
		return false;
	}

	TNode *temp = root;
	TNode *removal;

	while (true)
	{
		//Right side of tree
		if (v > temp->element)
		{ // v is greater than the current element
			if (v == temp->right->element)
			{ //if the value is the element it is currently on
				removal = temp->right; //let removal be the current element
				if (removal->right == NULL && removal->left == NULL)
				{ //if the node to the left and right points to NULL
					temp->right = NULL; //set the node to NULL
				}
				else if (removal->right != NULL && removal->left == NULL)
				{ //if right is not pointing to NULL but left is
					temp->right = removal->right;  //let removal point right
				}
				else if (removal->right == NULL && removal->left != NULL)
				{ //if right is pointing to NULL but left is not
					temp->right = removal->left; //let removal point left
				}

				else
				{ // two children
					TNode *tempRemoval = removal->right; //create a new temporary TNode
					int minVal;

					while (tempRemoval->left != NULL)
					{ //while left is not NULL
						tempRemoval = tempRemoval->left; //let tempRemoval point left
					}

					minVal = tempRemoval->element; //minimum value is the current node
					remove(minVal); //remove the minimum value
					temp->right->element = minVal; //
				}
				return true;
			}
			temp = temp->right;
		}
		//Left side of tree
		else if (v < temp->element) // v is less than the current element
		{
			if (v == temp->left->element)
			{
				removal = temp->left;
				if (removal->right == NULL && removal->left == NULL)
				{
					temp->left = NULL;
				}
				else if (removal->right != NULL && removal->left == NULL)
				{
					temp->left = removal->right;
				}
				else if (removal->right == NULL && removal->left != NULL)
				{
					temp->left = removal->left;
				}

				else
				{ // two children
					TNode *tempRemoval = removal->right; //set tempRemoval to point to the right
					int minVal;

					while (tempRemoval->left != NULL)
					{ //iterate until left is NULL
						tempRemoval = tempRemoval->left; //remove that node
					}

					minVal = tempRemoval->element; //store removed node in minVal
					remove(minVal); //remove it
					temp->left->element = minVal; //change element to new one
				}
				return true;
			}
			temp = temp->left;
		}

		else if (v == root->element)

		{ //if v is the root
			if (root->right == NULL && root->left == NULL)
			{ //if the root pointing to left and right are NULL
				root = NULL; //set the root as NULL
			}
			else if (root->right != NULL && root->left == NULL)
			{ //if the root pointing to right is not NULL and root pointing left is NULL
				root = root->right; //set the root to point to the right
			}
			else if (root->right == NULL && root->left != NULL)
			{ //if the root pointing right is NULL and left is not
				root = root->left; //set root to point to left
			}
			else
			{
				TNode *tempRemoval = root->right; //
				int minVal;

				while (tempRemoval->left != NULL)
				{
					tempRemoval = tempRemoval->left;
				}

				minVal = tempRemoval->element;
				remove(minVal);
				root->element = minVal;
			}
			return true;
		}
	}
	return true;
}

void BSTSet::rec_union(const TNode *a)
{
	if (a == NULL)
	{
		return;
	}

	rec_union(a -> left); //THe root of (a) gets pointed to the left-side
	add(a -> element); // THe current node gets (a) added into it
	rec_union(a -> right); //THe root of (a) gets pointed to the right-side
}

void BSTSet::Union(const BSTSet& s)
//T(n) = O(n) -We're going through every single node until n is reached
//S(n) = O(1)
{
	if (s.root == NULL) //If the root of s is NULL
	{
		return;
	}
	else if (root == NULL)  //If the root itself is NULL
	{
		root = s.root; //The original root will become the s set root
		return;
	}

	rec_union(s.root);

}

void BSTSet::rec_intersec(const TNode *n, const BSTSet &s)
{
	if (n == NULL)
	{
		return; //if root of s is NULL
	}

	BSTSet set = BSTSet(); //create an empty set
	set.root = s.root; //root of s becomes root of set

	rec_intersec(n->left, set);

	if (!set.isIn(n->element)) //if the element isn't in the set
	{
		remove(n->element); //remove the element
	}

	rec_intersec(n->right, set);

}

void BSTSet::intersection(const BSTSet& s)
//T(n) = O((n)) -We're going through every single node until n is reached
//S(n) = O(1) -We're only storing rec_h
{
	BSTSet set = BSTSet();
	set = s;

	if (s.root == NULL) //If root of s is NULL
	{
		root = NULL;
		return;
	}

	else if (root == NULL) //if root is already empty
	{
		return;
	}

	rec_intersec(root, set);
}

void BSTSet::rec_diff(const TNode *n, const BSTSet &s)
{
	if (n == NULL) //if root of s is NULL
	{
		return;
	}

	BSTSet set = BSTSet(); //create empty set
	set.root = s.root; //let root of s become root of set

	rec_diff(n->left, set); //moves left until the last element
	if (set.isIn(n->element) == true) //if element is in the set
	{
		remove(n->element); //remove it
	}
	rec_diff(n->right, set); //moves to the right until last element
	if (set.isIn(n->element) == true) //if element is in set
	{
		remove(n->element); //remove it

	}

}

void BSTSet::difference(const BSTSet& s)
//T(n) = O((n)) -We're going through every single node until n is reached
//S(n) = O(1) -We're only storing rec_h
{
	BSTSet set = BSTSet(); //empty set
	set = s;

	if (s.root == NULL || root == NULL) //if the root of s is empty or the root is empty
	{
		return;
	}

	rec_diff(root, set);
}

int BSTSet::rec_size(const TNode *n, int size)
{

	if (n == NULL)
	{
		return 0; //if root of s is NULL
	}
	if (n->left == NULL && n->right == NULL) //if right and left sides are both pointing to NULL
	{
		return 1;
	}

	size += rec_size(n->left, 1); //increase so long as you can keep moving left
	size += rec_size(n->right, 1); //increase so long as you can keep moving right

	return size;
}

int BSTSet::size()
//T(n) = O((n)) -We're going through every single node until n is reached
//S(n) = O(1) -We're only storing rec_h
{
	if (root == NULL)
	{ //if root is NULL
		return 0;
	}

	return rec_size(root, 1); //call recursion function and change values everytime
}

int BSTSet::rec_h(const TNode *n, int max_h, int height1) {

	if (n == NULL) { //if root of s is NULL
		return max_h; //return the max height
	}

	height1++; //increment height1
	if (height1 > max_h) //if the height is greater than the max height
	{
		max_h = height1; //make that equal that
	}

	max_h = rec_h(n->left, max_h, height1); //move left and return the max height and height1
	max_h = rec_h(n->right, max_h, height1);
	return max_h; //return the max height
}

int BSTSet::height()
//T(n) = O((n)) -We're going through every single node until n is reached
//S(n) = O(1) -We're only storing rec_h
{
	if (root == NULL) {
		return -1; //if root is NULL height is -1
	}

	return rec_h(root, 0, -1);

}

// Following code uses class "Stack"
void BSTSet::printNonRec()
{
	MyStack* n = new MyStack(this->size());
	TNode* m = root;


	while(n->isEmpty() == false || m != NULL)
	{
		while(m != NULL)
		{
			n->push(m->element);
			m = m->left;
		}

		int npop = n->pop();
		std::cout<<std::to_string(npop)<<",";
		m = root;

		while(m != NULL)
		{
			if(m->element > npop)
			{
				m = m->left;
			}
			else if(m->element < npop)
			{
				m = m->right;
			}
			else if(m->element == npop)
			{
				break;
			}
		}
		m = m->right;

	}
}

// Do not modify following provided methods

void BSTSet::printBSTSet()
{
    if (root == NULL)
        std::cout << "";
    else {
        printBSTSet(root);
    }
}

void BSTSet::printBSTSet(TNode* t)
{
    if (t != NULL) {
        printBSTSet(t->left);
        std::cout << t->element << ",";
        printBSTSet(t->right);
    }
}
