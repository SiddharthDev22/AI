#ifndef NODE_H
#define NODE_H

class Node {
public:

	Node();
	Node(char name, Node& pParent, Node& pNext, float cost, bool explored);
	virtual ~Node();

	Node& operator=(const Node& right);

	/**
	* @returns {bool} true if the calling node name is the same as the goalCity, and returns false otherwise.
	*/
	bool isGoal(char goalCity);

	char getName() const;
	Node getParent() const;
	Node getNext() const;
	float getCost() const;
	bool isExplored() const;

private:
	char name;
	Node* pParent;
	Node* pNext;
	float cost;
	bool explored;
};

#endif /* NODE_H */