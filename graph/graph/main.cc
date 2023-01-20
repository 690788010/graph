#include <iostream>

#include "graph.h"
#include "weighted_graph.h"

int main() {
	WeightedGraph graph("./data/gw.txt");

	std::cout << graph << std::endl;
	std::cout << graph.getWeight(5, 0) << std::endl;

	std::cout << graph.degree(1) << std::endl;
}
