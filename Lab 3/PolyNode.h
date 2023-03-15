#ifndef POLYNODE_H_
#define POLYNODE_H_

class PolyNode
{
public:
	int deg;
	double coeff;
	PolyNode* next;

	PolyNode(int d, double c, PolyNode* n) {
		deg = d;
		coeff = c;
		next = n;
	}
};

#endif /* POLYNODE_H_ */
