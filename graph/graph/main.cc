#include <iostream>

#include "graph.h"
#include "weighted_graph.h"

int main() {
	WeightedGraph graph("./data/gw.txt");

	WeightedGraph graph2 = graph;

	std::cout << graph << std::endl;
	std::cout << graph2 << std::endl;

	std::cout << graph.degree(1) << std::endl;
}
