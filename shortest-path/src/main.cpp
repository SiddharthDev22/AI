#include "includes.h"
#include <iostream>

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