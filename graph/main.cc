#include <iostream>

#include "adj_list.h"

int main() {
	AdjList adjSet("./data/mediumG.txt");
	//std::cout << adjSet << std::endl;
	std::cout << adjSet.hasEdge(9, 31592) << std::endl;
	for (auto& v : adjSet.adj(9)) {
		std::cout << v << " ";
	}
}
