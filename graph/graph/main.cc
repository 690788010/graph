#include <iostream>

//#include "weighted_graph.h"
//#include "max_flow.h"
#include "graph.h"
#include "cycle_detection.h"
//#include "directed_cycle_detection.h"

int main() {
	/*WeightedGraph graph("./data/network2.txt", true);
	MaxFlow maxFlow(graph, 0, 5);

	std::cout << maxFlow << std::endl;*/

	CycleDetection cycleDetection(Graph("./data/ug.txt", false));
	std::cout << cycleDetection.hasCycle() << std::endl;
}
