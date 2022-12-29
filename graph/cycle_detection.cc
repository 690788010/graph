#include "cycle_detection.h"

CycleDetection::CycleDetection(Graph g) : _g{ std::move(g) } {
	unsigned int V = _g.V();
	_visited = new bool[V];
	for (unsigned int v = 0; v < V; v++) {
		_visited[v] = false;
	}
	_hasCycle = false;
	for (unsigned int v = 0; v < V; v++) {
		if (!_visited[v]) {
			if (_dfs(v, v)) {
				_hasCycle = true;
				break;
			}
		}
	}
}

bool CycleDetection::hasCycle() {
	return _hasCycle;
};

bool CycleDetection::_dfs(int v, int parent) {
	_visited[v] = true;

	for (auto& w : _g.adj(v)) {
		if (!_visited[w]) {
			if (_dfs(w, v)) {
				return true;
			}
		}
		else if (w != parent) {	
			// 当前顶点的邻接顶点有被遍历过的顶点,且该顶点不是上一个顶点（parent），则表明该无向图有环。
			return true;
		}
		return false;
	}
};

bool CycleDetection::_dfs2(unsigned int v, int parent) {
	// 入栈
	std::list<unsigned int> stack;
	stack.push_back(v);
	_visited[v] = true;

	// 不停取出栈顶元素遍历，达到深度优先搜索效果
	while (!stack.empty()) {
		// 出栈
		unsigned int s = stack.back();
		stack.pop_back();

		// 将当前顶点的邻接顶点加入栈中
		for (auto& w : _g.adj(s)) {
			if (!_visited[w]) {
				stack.push_back(w);
				_visited[w] = true;
			}
			else if (w != parent) {
				return true;
			}
		}
		parent = s;
	}
	return false;
};
