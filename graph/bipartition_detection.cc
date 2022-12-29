#include "bipartition_detection.h"

BipartitionDetection::BipartitionDetection(Graph g) : _g{ std::move(g) } {
	unsigned int V = _g.V();
	_visited = new bool[V];
	_colors = new char[V];
	for (unsigned int v = 0; v < V; v++) {
		_visited[v] = false;
		_colors[v] = 0;
	}
	_isBipartite = true;
	for (unsigned int v = 0; v < V; v++) {
		if (!_visited[v]) {
			if (!_dfs(v, 0)) {
				_isBipartite = false;
				break;
			}
		}
	}
};

BipartitionDetection::~BipartitionDetection() {
	if (_visited != nullptr) {
		delete[] _visited;
		_visited = nullptr;
	}
	if (_colors != nullptr) {
		delete[] _colors;
		_colors = nullptr;
	}
};

// 是否为二分图
bool BipartitionDetection::isBipartite() {
	return _isBipartite;
};

// 深度优先遍历，递归方式
bool BipartitionDetection::_dfs(int v, char color) {
	_visited[v] = true;
	_colors[v] = color;

	for (auto& w : _g.adj(v)) {
		if (!_visited[w]) {
			if (!_dfs(w, 1 - color)) {
				return false;
			}
		}
		else if (_colors[w] == _colors[v]) {
			return false;
		}
	}
	return true;
};

// 深度优先遍历，非递归方式
bool BipartitionDetection::_dfs2(int v, char color) {
	// 入栈
	std::list<unsigned int> stack;
	stack.push_back(v);
	_visited[v] = true;
	_colors[v] = color;

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
				_colors[w] = 1 - color;
			}
			else if (_colors[w] == _colors[s]) {
				// 当前顶点的邻接顶点中有被遍历过的顶点，且该顶点颜色和当前顶点一致，则表明该无向图不是二分图。
				return false;
			}
		}
		color = 1 - color;
	}
	return true;
};
