#include "includes.h"
#include <stddef.h>

using namespace std;

Node::Node() {
	pParent = pNext = NULL;
	name = cost = huristic = explored = expanded = 0;
}

Node::Node(char name, Node* pParent, Node* pNext, float cost, bool explored) :
	name(name),
	pParent(pParent),
	pNext(pNext),
	cost(cost),
	explored(explored),
	expanded(NULL),
	huristic(0) {}

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
	this->huristic = right.huristic;
	this->expanded = right.expanded;
	
	return *this;
}

ostream& operator<<(std::ostream& os, const Node& obj) {
	os << obj.name << "\t\t" 
		<< (obj.pParent != NULL ? obj.pParent->name : ' ') << "\t\t" 
		<< obj.huristic << "\t\t" 
		<< obj.cost << "\t\t" 
		<< obj.expanded;

	return os;
}

bool Node::isGoal(char goalCity) { return this->name == goalCity; }

char Node::getName() const { return this->name; }
Node* Node::getParent() const { return this->pParent; }
Node* Node::getNext() const { return this->pNext; }
float Node::getCost() const { return this->cost + this->huristic; }
bool Node::isExplored() const { return this->explored; }
int Node::getExpanded() const { return this->expanded; }

/**
 * finds potential sibling nodes of the calling node 
 * pushes potential nodes to list pFrontier (by calling pushNodetoList(pFrontier)).
 */
void Node::expand(vector<Link> &links, List* pFrontier) {
	this->explored = true;

	for (int i = 0; i < links.size(); i++) {
		if (links[i].getC1() == this->name || links[i].getC2() == this->name) {

			Node tmpNode;
			tmpNode.name =	(links[i].getC1() == this->name) ? links[i].getC2() : links[i].getC1();
			tmpNode.pParent = this;
			tmpNode.cost = this->cost + links[i].getLinkCost(); // <<<<<<<<<<<<<<<

			if (tmpNode.isQualified(pFrontier)) {
				tmpNode.pushNodeToList(pFrontier);
				this->expanded++;
			}
		}
	}

}

void Node::pushNodeToList(List* pFrontier) {
	//<<<<<<<<<<<<<<<<<<<<
	pFrontier->getLastNode()->pNext = this;
	pFrontier->setLastNode(this);
}

/**
 * determines if the calling node (which is a potential node) is qualified to be added to the input argument list.
 * The function should also discard from the list any node once a cheaper replacement for it is found.
 * @param pFrontier
 * @return 
 */
bool Node::isQualified(List* pFrontier){

	Node* current = pFrontier->getFirstNode();
	
	// if not same as parrent

	while (current != NULL){
		if(current->name == this->name){
			//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		}
		current = current->getNext();
	}
}