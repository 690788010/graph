#include "graph_bfs.h"

GraphBFS::GraphBFS(Graph g) : _g{std::move(g)} {
	unsigned int V = _g.V();
	_visited = new bool[V];
	for (unsigned int v = 0; v < V; v++) {
		_visited[v] = false;
	}
	// 对每个联通分量进行BFS搜索
	for (unsigned int v = 0; v < V; v++) {
		if (!_visited[v]) {
			_bfs(v);
		}
	}
};

GraphBFS::~GraphBFS() {
	if (_visited != nullptr) {
		delete[] _visited;
		_visited = nullptr;
	}
};

std::list<int> GraphBFS::order() {
	return _order;
};

void GraphBFS::_bfs(int v) {
	std::list<int> queue;
	queue.push_back(v);
	_visited[v] = true;

	while (!queue.empty()) {
		int s = queue.front();
		queue.pop_front();
		_order.push_back(s);

		for (auto& w : _g.adj(s)) {
			if (!_visited[w]) {
				_visited[w] = true;
				queue.push_back(w);
			}
		}
	}
};
