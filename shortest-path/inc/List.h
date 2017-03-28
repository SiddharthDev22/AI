#ifndef LIST_H
#define LIST_H

#include "includes.h"

class List {
public:

	List();
	List(Node* pFirstNode);
	virtual ~List();

	List& operator=(const List& right);
	friend std::ostream& operator<<(std::ostream& os, const List& obj);

	Node* getFirstNode() const;
	Node* getLastNode() const;
	
	Node* getNextNode();

	void setLastNode(Node* LastNode);

	void printResult();

private:
	Node* pFirstNode;
	Node* pLastNode;
	Node* pCurrentNode;
};

#endif /* LIST_H */

