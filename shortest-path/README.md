[Project 1](http://csocal.com/msys/mod/forum/discuss.php?d=454)
================================================================

- This project is divided into parts, To get you started, the following is part 1.
- Part 1 contains some methods and simple data structures that you have to develop and of course an application function.
- What you should do keep track of the modules that you build and understand what you are doing as you might have to produce variant versions of any codeline.
- You will build more into the project as you go. 



Part 1 [6 points]: 
====================

Building and testing the link data structure.
This part is composed of 
- 3 codelines (1.main, 2.link, 3.functions)
- baseline (base1) (composed of the 3 codelines).

File            | Description
----------------|-------------------------------------------------------------------------
`main.cpp`      | contains the application function and a unit test for the baseline.
`link.h`        | contains the definition of the class link
`link.cpp`      | contains the implementation of the class link
`functions.h`   | contains the function signature: `void acquireLinks(vector<link> &links)`
`functions.cpp` | contains an implementation of the function acquireLinks. 
`Makefile`      | with a target named base1


Class: `Link`
-------------------

- private class members: 
	* `char c1`
	* `char c2`
	* `float linkCost`
- public class methods:
	* `constructor` default
	* `constructor` that sets all three private class members
	* `destructor`
	* `=operator`
	* `methods` to query the private class members.


Function: `void acquireLinks(vector<link> &links)`
---------------------------------------------------
- `Input:`
	* a reference to the vector links
- `process:` 
	* takes from the user, by reference, constructed values of links which will be
	pushed_back into the vector structure as a triplet of the private class link members.
	* This triplet is entered by the user (e.g. a b 3). A terminating character should be included to stop the acquisition process.





Part 2 [4 points]
==================

file: `main.cpp`
-----------------
* add a user console entries that specifies the following variables:
	1. char startCity
	2. char goalCity
* Also main should now contain a pointer to the class type node that gets assigned
dynamically to the first node that enters the frontier list (i.e. the node name is going to be the
startCity, and you can of course set the values of the other variables of the node becasue you have
made your analysis and understood the class of the algorithms we are using in this project).
* You should completely test this part and make sure that it passes the test.


file: `acquireLinks.cpp`
-------------------------
in this file you will implement the function `void acquireLinks(vector<link> &links)`
to read links data from a file (as opposed to the `function acquireLinks` found in file `functions.cpp`).   
Program should have the capability to compile using either versions of the function acquireLinks.   
However, the input via file should be the default input method.   
A perfect example of an input file for a uniform cost search algorithms would be a file that contains the following (using the example presented in class):

City 1 | City 2 | Weight
:-----:|:------:|:-----:
a      | b      | 4
c      | a      | 1
b      | d      | 3
e      | b      | 8
c      | d      | 2
g      | f      | 8
g      | e      | 2
c      | f      | 6
d      | e      | 4



Class: `Node`
--------------
- private class members:
	* `char name;`
	* `node pParent;`
	* `node pNext;`
	* `float cost;`
	* `bool explored;`
- public class methods: 

	* `default constructor`
	* `constructor that sets all 5 private class members`
	* `destructor`
	* `=operator`
	* methods to query the private class members (i.e. to guarantee data hiding)
	* `bool isGoal(char goalCity)` returns true if the calling node name is the same as the goalCity, and returns false otherwise.



File            | Description
----------------|-------------------------------------------------------------------------
`node.h`        | contains the definition of the class node
`node.cpp`      | contains the implementation of the class node
`Makefile`      | now the default target comes from Part 2, name it base2.



Part 3 [5 points]
==================

File            | Description
----------------|-------------------------------------------------------------------------
`list.h`        | contains the definition of the class list.
`list.cpp`      | contains the implementation of the class list.

class name: list
--------------
- private class members:
	* `node* pFirstNode`
	* `node* pLastNode`

- public class members: 

	* `default constructor`
	* `constructor` that sets all private class members
	* `destructor`
	* `=operator`
	* `void printList(void)`
	* methods to query the private class members (i.e. to guarantee data hiding)

	The function `printList` prints out on
	console the names of the nodes in the calling list (it should be easily modified to bring any
	information about the nodes in the calling list.

file: `node.h`
--------------
add 2 functions with signature:
void expand(vector<link> &links, list* pFrontier);
void pushNodeToList(list* pFrontier);

file: `node.cpp`
----------------
conatins the implementation of the function: 
expand: that finds potential sibling nodes of the calling node and pushes potential nodes to list pFrontier (by calling
pushNodetoList(pFrontier)).

file: `main.cpp`
----------------
should now construct the first node, initialize the Frontier list using the first node,
expand potential siblings to the list, and terminates only if a goal is picked.