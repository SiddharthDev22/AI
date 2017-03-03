/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.h
 * Author: marcw
 *
 * Created on March 1, 2017, 6:37 AM
 */

#ifndef NODE_H
#define NODE_H

class Node {
public:

	Node();
	Node(char name, Node pParent, Node pNext, float cost, bool explored);
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
	Node pParent;
	Node pNext;
	float cost;
	bool explored;
};

#endif /* NODE_H */

