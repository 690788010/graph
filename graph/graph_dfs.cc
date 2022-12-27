#include "graph_dfs.h"

GraphDFS::GraphDFS(Graph g) : _g{ std::move(g) } {
	unsigned int V = _g.V();
	_visited = new bool[V];
	for (unsigned int i = 0; i < V; i++) {
		_visited[i] = false;
	}
	// 对每个联通分量进行DFS搜索
	for (unsigned int v = 0; v < V; v++) {
		if (!_visited[v]) {
			dfs(v);
		}
	}
};

GraphDFS::~GraphDFS() {
	if (_visited != nullptr) {
		delete[] _visited;
		_visited = nullptr;
	}
};

void GraphDFS::dfs(unsigned int v) {
	// 将当前顶点标识为已遍历
	_visited[v] = true;
	// 保存当前顶点,深度优先先序遍历
	_pre.push_back(v);

	// 遍历当前顶点的邻接顶点
	for (auto& w : _g.adj(v)) {
		if (!_visited[w]) {
			dfs(w);
		}
	}
	// 保存当前顶点,深度优先后序遍历
	_post.push_back(v);
};

void GraphDFS::dfs2(unsigned int v) {
	std::list<unsigned int> stack;
	stack.push_back(v);
	// 将当前顶点标识为已遍历
	_visited[v] = true;
	// 保存当前顶点,深度优先先序遍历
	_pre.push_back(v);
	
	while (!stack.empty()) {
		unsigned int s = stack.back();
		stack.pop_back();

		for (auto& w : _g.adj(s)) {
			if (!_visited[w]) {
				stack.push_back(w);
				_visited[w] = true;
				// 保存当前顶点,深度优先先序遍历
				_pre.push_back(w);
			}
		}
	}
};

std::list<unsigned int>& GraphDFS::pre() {
	return _pre;
};

std::list<unsigned int>& GraphDFS::post() {
	return _post;
};
