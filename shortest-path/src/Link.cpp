#include "includes.h"

using namespace std;

Link::Link() {
}

Link::Link(char c1, char c2, float linkCost) :
c1(c1), c2(c2), linkCost(linkCost) {
}

Link::~Link() {}

Link& Link::operator=(const Link& right) {
	// Check for self-assignment!
	if (this == &right) // Same object?
		return *this; // Yes, so skip assignment, and just return *this.
	// Deallocate, allocate new space, copy values...
	this->c1 = right.c1;
	this->c2 = right.c2;
	this->linkCost = right.linkCost;
	return *this;
}

char Link::getC1() const { return this->c1; }
char Link::getC2() const { return this->c2; }
float Link::getLinkCost() const { return this->linkCost; }