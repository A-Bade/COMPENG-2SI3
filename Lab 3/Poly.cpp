#include "Poly.h"
#include <cmath>
#include <string>
using namespace std;


Poly::Poly()
{
	head = new PolyNode(-1, 0, NULL);	//Creates the head of poly linked list
}
//THETA(c),THETA(c)

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{
	PolyNode* reader;	//Initializes a pointer
	head = new PolyNode(-1, 0, NULL);		//Creates the head of the linked list
	reader = head;		//Points to the head of the linked list

	for (int i = 0; i < deg.size(); i++) {		//For loops from 0 to size creating a new node each loop
		reader->next = new PolyNode(deg[i], coeff[i], NULL);	//Creates poly with deg and coeff data
		reader = reader->next;		//Reader is the next node
	}
}
//THETA(N),THETA(C)

Poly::~Poly()
{
	PolyNode* reader = head;		//Initializes a pointer to move forward
	PolyNode* previous = NULL;	//Initializes a pointer that stores previous node

	while (reader != NULL) {		//Runs until the end of the linked list
		previous = reader;		//Stores the current node
		reader = reader->next;	//Moves to next node
		delete previous;		//Deletes the node that was just moved from
	}
}
//THETA(N),THETA(C)
// We’re
void Poly::addMono(int i, double c)
{
	PolyNode* reader = head->next;//Initializes a pointer to move forward
	PolyNode* previous = head; 	//Initializes a pointer that stores previous node

	while (reader != NULL) {		//Loops until end of list is reached
		if (i < reader->deg) {	//If addmono has smaller degree than current node
			if (reader->next == NULL) {		//If end is reached place new node at the end
				reader->next = new PolyNode(i, c, NULL);
				return;
			}
			previous = reader;	//Stores current node
			reader = reader->next;	//Moves to next node
			continue;			//Reruns while loop with new node
		}
		if (i == reader->deg) {	//If addmono is has same degree as current node
			reader->coeff += c;		//Adds coefficient to current node
			if (reader->coeff == 0) { // Should the two coefficient terms cancel each other out, deletes node
				previous->next = reader->next;	//Previous node is connected to next node
				delete reader;				//Current node is deleted
			}
			return;
		}
		if (i > reader->deg) {			//If current node is less than addmono
			PolyNode* adder = new PolyNode(i, c, reader); //Creates new node pointing to current node
			previous->next = adder;		//Previous node points to newly created node
			return;
		}
	}

	head->next = new PolyNode(i, c, NULL);	//If end is reached and nose is not added, add it to the end
}
//THETA(N),THETA(C)

void Poly::addPoly(const Poly& p)
{
	PolyNode* reader = p.head->next;		//Initliazes pointer to store current node of p

	if (reader == NULL) {	//If p is empty, the function ends.
		return;
	}

	while (reader != NULL) { //Moves through linked list p
		this->addMono(reader->deg, reader->coeff); //Calls addmono to add current node of p
		reader = reader->next;				//Moves to next node in p
	}
}
//THETA(N*P),THETA(C),N is the number of nodes in what is being added to, P is the number of nodes in p

void Poly::multiplyMono(int i, double c)
{
	if ((c == 0) || (head->next == NULL)) { //If list is empty or c is 0, empties list
		this->~Poly();
		head = new PolyNode(-1, 0, NULL);
		return;
	}

	PolyNode* reader = head->next; //Initializes a pointer to move forward

	while (reader != NULL) {		//Moves through linked list until NULL pointer
		reader->deg += i;		//Add i to degree
		reader->coeff *= c;		//Multiple coefficients by c
		reader = reader->next;	//Moves to next node
	}
}
//THETA(N),THETA(C)

void Poly::multiplyPoly(const Poly& p)
{
	PolyNode* creader = head->next;	//Initializes a pointer to move forward in list
PolyNode* preader = p.head->next;	//Initializes a pointer to move forward in p list
	Poly thisCopy;		//Makes a temporary node to store partial products
	Poly tempPoly = Poly();		//Creates list to store final products

	if (preader == NULL || creader == NULL) {	//If either list is empty, empties list
		this->~Poly();
		head = new PolyNode(-1, 0, NULL);
		return;
	}

	while (preader != NULL) {		//Moves through linked list until NULL pointer
		this->duplicate(thisCopy); //Creates copy of list in thisCopy
		thisCopy.multiplyMono(preader->deg, preader->coeff); //Multiplies thiscopy by current p list node
		tempPoly.addPoly(thisCopy); //Adds this copy to tempoly list
		preader = preader->next; //Moves to next node in p list
	}
	tempPoly.duplicate(*this); //Duplicates temppoly with final product into current list

}
//THETA(N*P),THETA(C),N is the number of nodes in what is being added to, P is the number of nodes in pREDO PLEASE

void Poly::duplicate(Poly& outputPoly)
{
	outputPoly.~Poly();		//Empties output
	outputPoly.head = new PolyNode(-1, 0, NULL);		//Creates dummy head for output
	PolyNode* creader = head->next;				//Initializes a pointer to move forward in list
	PolyNode* outputreader = outputPoly.head;		//Initializes a pointer to move forward in output list

	while (creader) {	//Run until the end of the list
		outputreader->next = new PolyNode(creader->deg, creader->coeff, NULL); //Adds node to output list
		outputreader = outputreader->next;	//Moves to next node in output list
		creader = creader->next;		//Moves to next node in list
	}
}

// The value for both the time and space complexity should be THETA(n)and THETA(n)respectively.
// T(n) = THETA(1) b/c there’s only one conditional statement.
// S(n) = THETA(1) b/c only one value is needed to be stored


int Poly::getDegree() // Returns greatest degree of poly
{
	int deg = 0;
	if (head->next != NULL) // When going forward, if the list isn’t empty.
	{
			deg = head->next->deg; // The degree element of the first non-dummy node will be the degree of the polynomial
	}
	else
	{
			deg = head->deg; //
	}
	return deg;
}

// The value for both the time and space complexity should be THETA(1)and THETA(1)respectively.
// T(n) = THETA(1) b/c there’s only one conditional statement.
// S(n) = THETA(1) b/c only one value is needed to be stored

int Poly::getTermsNo()
{
	PolyNode* reader = head->next; 	 //Initializes a pointer to move forward in list
	int count = 0;				//Initializes counter integer
	while (reader != NULL) {		//Moves through linked list until NULL pointer
		reader = reader->next;	//Moves to next node
		count++;				//Adds 1 to count
	}
	return count;				//Returns count
}
//THETA(N),THETA(C)

double Poly::evaluate(double x)
{
	double answer = 0;
	PolyNode* reader = head->next; 	 //Initializes a pointer to move forward in list

	while (reader) {		//Moves through list until end
		answer += reader->coeff * (pow(x, reader->deg));  //Coefficient*x^deg
		reader = reader->next;		//Moves to next node
	}

	return answer;
}
//THETA(N),THETA(C)

string Poly::toString()
{
	string pstring = ""; //Initializes empty string
	PolyNode* reader = head;

	if (reader != NULL) { //If list is not empty
		reader = head->next; //Skips dummy node
		string pstring = "degree=" + to_string(reader->deg) + ';'; //Adds test with += appender

		while (reader) { //Runs through list until null pointer
			pstring += (' ' + "a(" + to_string(reader->deg) + ")=" + to_string(reader->coeff) + ';'); //Appends
			reader = reader->next; //Moves to next node in list
		}
	}
	else { //If it was empty, string becomes dummy header representation
		pstring = "degree=-1; a(-1)=0;";
	}
	return pstring; //Returns the string
}
//THETA(N^2),THETA(N), Must store string of size N*c in memory, append function is of linear complexity[1].


/*References:
[1] cplusplus.com, “Std::string::operator+=,” cplusplus.com. [Online]. Available: https://cplusplus.com/reference/string/string/operator+=/. [Accessed: 07-Mar-2023].
*/

