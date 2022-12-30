#include <iostream>

#include "graph.h"
#include "graph_bfs.h"

int main() {
	GraphBFS graphBFS(Graph("./data/largeG.txt"));

	for (auto& v : graphBFS.order()) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}
