#include <fstream>
#include <iostream>
#include <vector>
#include "Link.h"
#include "functions.h"

using namespace std;

void acquireLinks(vector<Link>& links) {

	char city1 = ' ', city2 = ' ';
	int weight = 0;

	ifstream fin("test1.txt");

	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> city1 >> city2 >> weight;

			if (city1 == city2) {
				cout << "a start city can't be the destination \n";
				continue;
			}
			if (weight == 0) {
				cout << "weight can't be 0 \n";
				continue;
			}

			Link* tmp = new Link(city1, city2, weight);
		}
		
		fin.close();

	} else {
		cout << "Unable to open file";
	}

}