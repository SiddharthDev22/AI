#ifndef NODE_H
#define NODE_H

class Node {
public:

	Node();
	Node(char name, Node* pParent, Node* pNext, float cost, bool explored);
	virtual ~Node();

	Node& operator=(const Node& right);

	/**
	 * @returns {bool} true if the calling node name is the same as the goalCity, and returns false otherwise.
	 */
	bool isGoal(char goalCity);
	bool isExplored() const;

	char getName() const;
	Node* getParent() const;
	Node* getNext() const;
	float getCost() const;
	int getExpanded() const;

	void expand(std::vector<Link> &links, List* pFrontier);
	void pushNodeToList(List* pFrontier);
	bool isQualified(List* pFrontier);

	friend std::ostream& operator<<(std::ostream& os, const Node& obj);

private:
	char name;
	Node* pParent;
	Node* pNext;
	float cost;
	bool explored;
	int expanded;
};

#endif /* NODE_H */