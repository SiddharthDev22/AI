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

#ifndef LINK_H
#define LINK_H

class Link {
public:

	Link();
	Link(char c1, char c2, float linkCost);
	virtual ~Link();

	Link& operator=(const Link& right);

	char GetC1() const;
	char GetC2() const;
	float GetLinkCost() const;
	
private:
	char c1;
	char c2;
	float linkCost;
};

#endif /* LINK_H */

