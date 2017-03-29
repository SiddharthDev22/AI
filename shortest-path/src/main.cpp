#include "includes.h"

using namespace std;

int main(int argc, char** argv) {
	std::vector<Link> links;
	std::map<char,float> huristicMap;
	char startCity, endCity;
	int algori;

	cout << BFS << "->BFS \t| "
		<< ASTAR << "->A* \t| "
		<< UCS << "->UCS \t| "
		<< HURISTIC <<"->Huristic \t| "
		<< DFS << "->DFS"<< endl;

	cout << " pick an algorithm: ";
	cin >> algori;
	acquireLinks(links);
	if (algori == HURISTIC || algori == ASTAR) {
		acquireHuristics(huristicMap);
	}
	cout << "Start -> Goal city: ";
	cin >> startCity >> endCity;

	Node* currentNode = new Node(startCity, huristicMap[startCity]);
	List* frontier = new List(currentNode);

	for (int i = 0; i < links.size(); i++) {
		cout << links[i] << endl;
	}

	while ( (currentNode != NULL) && (!currentNode->isGoal(endCity)) ) {
		currentNode->expand(links, huristicMap, frontier);
		currentNode = frontier->getNextNode(algori);
		cout << *frontier << endl;
	}

	if (currentNode == NULL) {
		cout << endl << "================= NO SOLUTION =================" << endl;
		return 2; // no solution
	} else {
		frontier->printResult();
		return 0;
	}
}