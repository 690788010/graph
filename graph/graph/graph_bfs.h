#pragma once

#include <list>
#include "graph.h"

class GraphBFS {
public:
	GraphBFS(Graph g);
	~GraphBFS();

	std::list<int> order();

private:
	void _bfs(int v);

	Graph _g;
	bool* _visited;
	std::list<int> _order;
};
