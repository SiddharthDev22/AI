#include "includes.h"
#include <stddef.h>

using namespace std;

Node::Node() {}

Node::Node(char name, Node& pParent, Node& pNext, float cost, bool explored) :
	name(name),
	pParent(&pParent),
	pNext(&pNext),
	cost(cost),
	explored(explored) {}

Node::~Node() {
	pParent->pNext = NULL;
	delete pNext;
}

Node& Node::operator=(const Node& right) {
	// Check for self-assignment!
	if (this == &right) // Same object?
		return *this; // Yes, so skip assignment, and just return *this.
	// Deallocate, allocate new space, copy values...
	this->name = right.name;
	this->pParent = right.pParent;
	this->pNext = right.pNext;
	this->cost = right.cost;
	this->explored = right.explored;
	return *this;
}

bool Node::isGoal(char goalCity) { return this->name == goalCity; }

char Node::getName() const { return this->name; }
Node* Node::getParent() const { return this->pParent; }
Node* Node::getNext() const { return this->pNext; }
float Node::getCost() const { return this->cost; }
bool Node::isExplored() const { return this->explored; }

/**
 * finds potential sibling nodes of the calling node 
 * pushes potential nodes to list pFrontier (by calling pushNodetoList(pFrontier)).
 */
void Node::expand(vector<Link> &links, List* pFrontier) {

}

void Node::pushNodeToList(List* pFrontier) {
	//this->pNext = NULL;
	pFrontier->getLastNode()->pNext = this;
	pFrontier->setLastNode(this);
}