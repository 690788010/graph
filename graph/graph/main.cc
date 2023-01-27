#include <iostream>

//#include "graph.h"
#include "weighted_graph.h"

int main() {
	WeightedGraph graph("./data/gw2.txt", true);
	//Graph graph("./data/tinyG.txt", true);

	/*std::cout << graph << std::endl;
	std::cout << graph.getWeight(5, 0) << std::endl;

	std::cout << graph.degree(1) << std::endl;*/
	std::cout << graph << std::endl;
}
