#include <iostream>

#include "graph.h"
#include "graph_dfs.h"

int main() {
	GraphDFS graphDFS(Graph("./data/tinyG.txt"));
	for (auto& v : graphDFS.pre()) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
	for (auto& v : graphDFS.post()) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}
