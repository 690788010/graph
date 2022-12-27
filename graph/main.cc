#include <iostream>

#include "adj_list.h"

int main() {
	AdjList adjList("./data/largeG.txt");
	std::cout << adjList.hasEdge(7, 52993) << std::endl;
	for (auto& v : adjList.adj(7)) {
		std::cout << v << " ";
	}
}
