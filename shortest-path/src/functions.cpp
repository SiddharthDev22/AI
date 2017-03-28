#include <iostream>
#include <vector>
#include "includes.h"

using namespace std;

void acquireLinks(vector<Link> &links) {

	char city1 = ' ', city2 = ' ';
	int weight = 0;
	
	cin >> city1 >> city2 >> weight;

	while (city1 !='0' && city2 != '0' && weight != 0) {
		if (city1 == city2) {
			cout << "a start city can't be the destination" << endl;
			continue;
		}
		if (weight == 0) {
			cout << "weight can't be 0" << endl;
			continue;
		}

		links.push_back(*new Link(city1, city2, weight));

		cin >> city1 >> city2 >> weight;
	}
	
}

void acquireHuristics(std::map<char,float>& huristicMap) {

	char city = ' ';
	float weight = 0;
	cout << "City -> huristic" << endl;
	cin >> city >> weight;

	while (city !='0' && weight != 0) {
		huristicMap[city] = weight;
		cin >> city >> weight;
	}
	
}