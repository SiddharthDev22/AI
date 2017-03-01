[Project 1](http://csocal.com/msys/mod/forum/discuss.php?d=454)
===============================================================

- This project is divided into parts, To get you started, the following is part 1.
- Part 1 contains some methods and simple data structures that you have to develop and of course an application function.
- What you should do keep track of the modules that you build and understand what you are doing as you might have to produce variant versions of any codeline.
- You will build more into the project as you go. 



Part 1 [6 points]: 
---------------------

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



Class name: `Link`
------------------

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

<hr>

### Input:
a reference to the vector links

<hr>

### Process:
Takes from the user, by reference, constructed values of links which will be pushed_back into the vector structure as a triplet of the 	private class link members.  
This triplet is entered by the user (e.g. a b 3). A terminating character should be included to stop the acquisition 	process.

<hr>

### File:
Makefile: with a target named base1