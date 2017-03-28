#include "includes.h"
#include <iostream>

using namespace std;

List::List() {
	this->pFirstNode = this->pLastNode = this->pCurrentNode = NULL;
}

List::List(Node* pFirstNode) {
	this->pFirstNode = this->pLastNode = this->pCurrentNode = pFirstNode;
}

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

	int totalExpanded = 0, total = 0;
	Node* current = obj.pFirstNode;

	os	<< "================================================" << endl
		<< "Name" << "\t"
		<< "Parent" << "\t"
		<< "Cost" << "\t"
		<< "Huris" << "\t" 
		<< "Expand" << "\t"
		<< "Explored" << endl
		<< "------------------------------------------------" << endl;
	
	while (current != NULL) {
		os << *current << endl;
		totalExpanded += current->isExplored() ? 1 : 0;
		total++;
		current = current->getNext();
	}

	os << "Total Expanded Nodes: " << totalExpanded << " of " << total << endl;
	return os;
}

Node* List::getFirstNode() const { return this->pFirstNode; }
Node* List::getLastNode() const { return this->pLastNode; }

Node* List::getNextNode(int algo) {

	switch (algo) {
		case BFS :
			this->pCurrentNode = this->pCurrentNode->getNext();
			return this->pCurrentNode;
		case ASTAR :
		case UCS :
		case HURISTIC:
			Node* current = this->pFirstNode;
			Node* smallest = NULL;
			float smallestCost = numeric_limits<float>::max();
			while (current != NULL) {
				if ( (!current->isExplored()) && (smallestCost > current->calcCost(algo)) ) {
					smallest = current;
					smallestCost = current->calcCost(algo);
				}
				current = current->getNext();
			}
			this->pCurrentNode = smallest;
			return this->pCurrentNode;
	}

}

void List::setLastNode(Node* LastNode) { this->pLastNode = LastNode; }

/**
 * print to console the solution path along with its cost
 * It should also display number of nodes expanded 
 * i.e. how many times the method node::expand(vector<link>, list*) was called
 */
void List::printResult() {
	
	Node* current = this->pCurrentNode;
	cout << "==================== RESULT ====================" << endl
		<< "Name" << "\t"
		<< "Parent" << "\t"
		<< "Cost" << "\t"
		<< "Huris" << "\t" 
		<< "Expand" << "\t"
		<< "Explored" << endl
		<< "------------------------------------------------" << endl;

	while (current != NULL) {
		cout << *current << endl;
		current = current->getParent();
	}
}