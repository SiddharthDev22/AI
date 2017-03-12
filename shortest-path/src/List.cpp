#include "includes.h"
#include <iostream>

using namespace std;

List::List() {
}

List::List(Node& pFirstNode, Node& pLastNode) :
	pFirstNode (&pFirstNode),
	pLastNode (&pLastNode) {}

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

Node* List::getFirstNode() const { return this->pFirstNode; }
Node* List::getLastNode() const { return this->pLastNode; }

void List::setLastNode(Node* LastNode) { pLastNode = LastNode; }

void List::printList() {
	Node* current = this->pFirstNode;
	cout << "name" << "\t" << "parent" << "\t" << "cost";
	
	while (current != NULL){
		cout << current->getName() << "\t\t" << current->getParent()->getName() << "\t\t" << current->getCost() ;
		current = current->getNext();
	}
}