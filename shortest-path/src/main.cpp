#include "includes.h"

using namespace std;

int main(int argc, char** argv) {
	vector<Link> links;
	char startCity, endCity;

	acquireLinks(links);

	cout << "      Start City: ";
	cin >> startCity;
	cout << "Destination City: ";
	cin >> endCity;

	Node* currentNode = new Node(startCity, NULL, NULL, 0, false);
	List* frontier = new List(currentNode, currentNode);
	
	while(!currentNode->isGoal(endCity)){
		currentNode->expand(links, frontier);
		currentNode = currentNode->getNext();
		if(currentNode == NULL) {
			return 1; // no solution
		}
		cout << "\n\n========================================\n"
			 << frontier;
	}
	cout << "\n\n================ RESULT ================\n";
	frontier->printResult();

	return 0;
}