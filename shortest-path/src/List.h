#ifndef LIST_H
#define LIST_H

#include "includes.h"

class List {
public:

	List();
	List(Node* pFirstNode, Node* pLastNode);
	virtual ~List();

	List& operator=(const List& right);
	friend std::ostream& operator<<(std::ostream& os, const List& obj);

	Node* getFirstNode() const;
	Node* getLastNode() const;

	void setLastNode(Node* LastNode);

	void printResult();

private:
	Node* pFirstNode;
	Node* pLastNode;
};

#endif /* LIST_H */

