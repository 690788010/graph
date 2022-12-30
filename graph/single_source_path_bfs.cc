#include "single_source_path_bfs.h"

SingleSourcePathBFS::SingleSourcePathBFS(Graph g, int s) : _g{ std::move(g) } {
	_s = s;
	unsigned int V = _g.V();
	_visited = new bool[V];
	_pre = new int[V];
	for (unsigned int v = 0; v < V; v++) {
		_visited[v] = false;
		_pre[v] = -1;
	}
	_bfs(_s);
};

SingleSourcePathBFS::~SingleSourcePathBFS() {
	if (_visited != nullptr) {
		delete[] _visited;
		_visited = nullptr;
	}
	if (_pre != nullptr) {
		delete[] _pre;
		_pre = nullptr;
	}
};

bool SingleSourcePathBFS::isConnectedTo(int t) {
	_g._validateVertex(t);

	return _pre[t] != -1;
};

std::list<int> SingleSourcePathBFS::path(int t) {
	std::list<int> res;
	if (!isConnectedTo(t)) {
		return res;
	}

	int cur = t;
	while (cur != _s) {
		res.push_front(cur);
		cur = _pre[cur];
	}
	res.push_front(_s);

	return res;
};

void SingleSourcePathBFS::_bfs(int v) {
	std::list<int> queue;
	queue.push_back(v);
	_visited[v] = true;
	_pre[v] = v;

	while (!queue.empty()) {
		int s = queue.front();
		queue.pop_front();

		for (auto& w : _g.adj(s)) {
			if (!_visited[w]) {
				_visited[w] = true;
				_pre[w] = s;
				queue.push_back(w);
			}
		}
	}
};
