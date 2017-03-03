using namespace std;

#include "Node.h"

Node::Node() {}

Node::Node(char name, Node pParent, Node pNext, float cost, bool explored) :
	name(name),
	pParent(pParent),
	pNext(pNext),
	cost(cost),
	explored(explored) {}

Node::~Node() {
	delete name;
	delete pParent;
	delete pNext;
	delete cost;
	delete explored;
}

Node& Node::operator=(const Node& right) {
	// Check for self-assignment!
	if (this == &right) // Same object?
		return *this; // Yes, so skip assignment, and just return *this.
	// Deallocate, allocate new space, copy values...
	return *this;
}

bool Node::isGoal(char goalCity) { return this->name == goalCity; }

char Node::getName() const { return this->Name; }
Node Node::getParent() const { return this->pParent; }
Node Node::getNext() const { return this->pNext; }
float Node::getCost() const { return this->C; }
bool Node::isExplored() const { return this->explored; }