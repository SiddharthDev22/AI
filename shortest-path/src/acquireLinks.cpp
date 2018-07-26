#include <fstream>
#include <iostream>
#include <vector>
#include "includes.h"

using namespace std;

void acquireLinks(vector<Link>& links) {

	char city1 = ' ', city2 = ' ';
	int weight = 0;

	string filePath;
	cout << "   Links File path: ";
	cin >> filePath;
	filePath = "test\\" + filePath + ".lin";

	ifstream fin("D:/AAGOOGLE/AI/shortest-path/test/1.lin");

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

			links.push_back(Link(city1, city2, weight));
		}
		
		fin.close();

	} else {
		cout << "Unable to open file";
	}

}
