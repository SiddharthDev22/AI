#include "includes.h"

using namespace std;

int main(int argc, char** argv) {
	vector<Link> links;
	char startCity, endCity;

	acquireLinks(links);

	cout << "      Start city: ";
	cin >> startCity;
	cout << "       Goal city: ";
	cin >> endCity;
	cout << endl;
	
	Node* currentNode = new Node(startCity);
	List* frontier = new List(currentNode);

	for (int i = 0; i < links.size(); i++) {
		cout << links[i] << endl;
	}

	while (!currentNode->isGoal(endCity)) {
		currentNode->expand(links, frontier);
		currentNode = frontier->getNextNode();
		cout << *frontier;
		if (currentNode == NULL) {
			cout << "\n\n================ NO SOLUTION =================\n";
			return 2; // no solution
		}
	}
	
	cout << "\n\n=================== RESULT ====================\n";
	frontier->printResult();

	return 0;
}