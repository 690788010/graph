#include <iostream>

#include "graph.h"
#include "cycle_detection.h"

int main() {
	CycleDetection cd(Graph("./data/mediumG.txt"));

	std::cout << cd.hasCycle() << std::endl;
}
