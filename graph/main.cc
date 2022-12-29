#include <iostream>

#include "graph.h"
#include "bipartition_detection.h"

int main() {
	BipartitionDetection bd(Graph("./data/tinyG.txt"));

	std::cout << bd.isBipartite() << std::endl;
}
