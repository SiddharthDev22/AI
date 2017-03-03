/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.cpp
 * Author: marcw
 * 
 * Created on March 1, 2017, 6:37 AM
 */

using namespace std;

#include "Link.h"

Link::Link() {
}

Link::Link(char c1, char c2, float linkCost) :
c1(c1), c2(c2), linkCost(linkCost) {
}

Link::~Link() {
}

Link& Link::operator=(const Link& right) {
	// Check for self-assignment!
	if (this == &right) // Same object?
		return *this; // Yes, so skip assignment, and just return *this.
	// Deallocate, allocate new space, copy values...
	return *this;
}

char Link::getC1() const { return this->c1; }
char Link::getC2() const { return this->c2; }
float Link::getLinkCost() const { return this->linkCost; }