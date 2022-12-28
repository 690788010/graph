#include <iostream>

#include "graph.h"
#include "cc.h"

int main() {
	CC cc(Graph("./data/tinyG.txt"));
	std::cout << cc.isConnected(4, 5) << std::endl;

	int ccCount = cc.getCCCount();

	std::unique_ptr<std::list<unsigned int>[]> res = cc.components();
	for (int i = 0; i < ccCount; i++) {
		for (auto& v : res[i]) {
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}
}
