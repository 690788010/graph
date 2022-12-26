#include <iostream>

#include "adj_matrix.h"

int main() {
	AdjMatrix adjMatrix("./data/mediumG.txt");
	//std::cout << adjMatrix << std::endl;
	for (auto& v : adjMatrix.adj(4)) {
		std::cout << v << " ";
	}
}
