#include "includes.h"
#include <iostream>

using namespace std;

List::List() {
	pFirstNode = pLastNode = NULL;
}

List::List(Node* pFirstNode, Node* pLastNode) :
	pFirstNode (pFirstNode),
	pLastNode (pLastNode) {}

List::~List() {
	delete pFirstNode;
	delete pLastNode;
}

List& List::operator=(const List& right) {
	// Check for self-assignment!
	if (this == &right) // Same object?
		return *this; // Yes, so skip assignment, and just return *this.
	// Deallocate, allocate new space, copy values...
	this->pFirstNode = right.pFirstNode;
	this->pLastNode = right.pLastNode;
	return *this;
}

ostream& operator<<(std::ostream& os, const List& obj) {

	Node* current = obj.pFirstNode;
	os << "name" << "\t" 
		<< "parent" << "\t" 
		<< "cost" << "\t" 
		<< "expanded";
	
	while (current != NULL){
		os << current;
		current = current->getNext();
	}

	return os;
}

Node* List::getFirstNode() const { return this->pFirstNode; }
Node* List::getLastNode() const { return this->pLastNode; }

void List::setLastNode(Node* LastNode) { pLastNode = LastNode; }

/**
 * print to console the solution path along with its cost
 * It should also display number of nodes expanded 
 * i.e. how many times the method node::expand(vector<link>, list*) was called
 */
void List::printResult(){
	
	Node* current = this->pFirstNode;
	cout << "name" << "\t" 
		<< "parent" << "\t" 
		<< "cost" << "\t" 
		<< "expanded";
	
	while (current != NULL){
		cout << current;
		current = current->getParent();
	}
}