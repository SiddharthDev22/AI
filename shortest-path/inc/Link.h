#ifndef LINK_H
#define LINK_H

class Link {
public:

	Link();
	Link(char c1, char c2, float linkCost);
	virtual ~Link();

	Link& operator=(const Link& right);

	char getC1() const;
	char getC2() const;
	float getLinkCost() const;
	
private:
	char c1;
	char c2;
	float linkCost;
};

#endif /* LINK_H */

