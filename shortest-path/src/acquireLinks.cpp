#include <fstream>
#include <iostream>
#include <vector>
#include "includes.h"

using namespace std;

void acquireLinks(vector<Link>& links) {

	char city1 = ' ', city2 = ' ';
	int weight = 0;

	string filePath;
	cout << "       File path: ";
	cin >> filePath;

	ifstream fin(filePath.c_str());

	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> city1 >> city2 >> weight;

			if (city1 == city2) {
				cout << "a start city can't be the destination" << endl;
				continue;
			}
			if (weight == 0) {
				cout << "weight can't be 0" << endl;
				continue;
			}

			links.push_back(*new Link(city1, city2, weight));
		}
		
		fin.close();

	} else {
		cout << "Unable to open file";
	}

}