#ifndef TNODE_H_
#define TNODE_H_

class TNode
{
public:
    int element;
    TNode* left;
    TNode* right;

    TNode(int i, TNode* l, TNode* r)
    {
        element = i; left = l; right = r;
    }
};

#endif /* TNODE_H_ */
