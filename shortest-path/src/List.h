#ifndef LIST_H
#define LIST_H

#include "includes.h"

class List {
public:

	List();
	List(Node& pFirstNode, Node& pLastNode);
	virtual ~List();

	List& operator=(const List& right);

	Node* getFirstNode() const;
	Node* getLastNode() const;

	void setLastNode(Node* LastNode);


	void printList();

private:
	Node* pFirstNode;
	Node* pLastNode;
};

#endif /* LIST_H */

