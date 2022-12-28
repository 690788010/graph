#include <iostream>

#include "graph.h"
#include "single_source_path.h"

int main() {
	SingleSourcePath ssp(Graph("./data/largeG.txt"), 0);

	for (auto& v : ssp.path(12)) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}
