using namespace std;

#include "Node.h"

Node::Node() {}

Node::Node(char name, Node& pParent, Node& pNext, float cost, bool explored) :
	name(name),
	pParent(&pParent),
	pNext(&pNext),
	cost(cost),
	explored(explored) {}

Node::~Node() {
	//delete pParent;
	//delete pNext;
}

Node& Node::operator=(const Node& right) {
	// Check for self-assignment!
	if (this == &right) // Same object?
		return *this; // Yes, so skip assignment, and just return *this.
	// Deallocate, allocate new space, copy values...
	return *this;
}

bool Node::isGoal(char goalCity) { return this->name == goalCity; }

char Node::getName() const { return this->name; }
Node Node::getParent() const { return *this->pParent; }
Node Node::getNext() const { return *this->pNext; }
float Node::getCost() const { return this->cost; }
bool Node::isExplored() const { return this->explored; }