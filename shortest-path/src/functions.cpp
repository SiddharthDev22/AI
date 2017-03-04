#include <iostream>
#include <vector>
#include "Link.h"
#include "functions.h"

using namespace std;

void acquireLinks(vector<Link> &links) {

	char city1 = ' ', city2 = ' ';
	int weight = 0;
	
	cin >> city1 >> city2 >> weight;

	while (city1 !='0' && city2 != '0' && weight != 0) {
		if (city1 == city2) {
			cout << "a start city can't be the destination \n";
			continue;
		}
		if (weight == 0) {
			cout << "weight can't be 0 \n";
			continue;
		}

		Link* tmp = new Link(city1, city2, weight);
		cin >> city1 >> city2 >> weight;
	}
	
}