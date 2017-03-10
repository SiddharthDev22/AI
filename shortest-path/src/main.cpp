#include <iostream>
#include <vector>
#include "Link.h"
#include "functions.h"

using namespace std;

int main(int argc, char** argv) {
	vector<Link> Links;
	char startCity , endCity;
	
	acquireLinks(Links);

	cout << "      start City: ";
	cin >> startCity;
	cout << "Destination City: ";
	cin >> endCity;

	return 0;
}