#include <iostream>

#include "graph.h"
#include "single_source_path_bfs.h"

int main() {
	SingleSourcePathBFS ssPathBFS(Graph("./data/largeG.txt"), 0);

	for (auto& v : ssPathBFS.path(11)) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}
