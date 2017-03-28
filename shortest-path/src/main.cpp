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
	Node* currentNode = new Node(startCity, NULL, NULL, 0, false);
	List* frontier = new List(currentNode, currentNode);

	cout << "\n===============================================\n";
	for (int i = 0; i < links.size(); i++) {
		cout << links[i] << endl;
	}
	cout << "\n===============================================\n";

	while (!currentNode->isGoal(endCity)) {
		currentNode->expand(links, frontier);
		currentNode = currentNode->getNext();
		cout << *frontier;
		if(currentNode == NULL) {
			cout << "\n\n================ NO SOLUTION =================\n";
			return 2; // no solution
		}
	}
	
	cout << "\n\n=================== RESULT ====================\n";
	frontier->printResult();

	return 0;
}