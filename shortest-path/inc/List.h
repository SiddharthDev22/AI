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
	void printResult();

	void setLastNode(Node* LastNode);
	
	Node* getFirstNode() const;
	Node* getLastNode() const;
	
	Node* getNextNode(int algo);

private:
	Node* pFirstNode;
	Node* pLastNode;
	Node* pCurrentNode;

	Node* getNextNodeUCS(int algo);
	Node* getNextNodeBFS(int algo);
	Node* getNextNodeDFS(int algo);
};

#endif /* LIST_H */

