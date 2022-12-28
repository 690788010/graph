#include "single_source_path.h"

SingleSourcePath::SingleSourcePath(Graph g, int s) : _g{ std::move(g) } {
	_s = s;
	unsigned int V = _g.V();
	_pre = new int[V];
	for (unsigned int v = 0; v < V; v++) {
		_pre[v] = -1;
	}

	_dfs2(_s, _s);
};

SingleSourcePath::~SingleSourcePath() {
	if (_pre != nullptr) {
		delete[] _pre;
		_pre = nullptr;
	}
};

bool SingleSourcePath::isConnectedTo(int t) {
	_g._validateVertex(t);

	return _pre[t] != -1;
};

std::list<int> SingleSourcePath::path(int t) {
	std::list<int> res;

	// 如果顶点t和源顶点不连通则返回空容器
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

void SingleSourcePath::_dfs(int v, int parent) {
	_pre[v] = parent;

	for (auto& w : _g.adj(v)) {
		if (_pre[w] == -1) {
			_dfs(w, v);
		}
	}
};

void SingleSourcePath::_dfs2(unsigned int v, int parent) {
	// 入栈
	std::list<unsigned int> stack;
	stack.push_back(v);
	_pre[v] = parent;

	// 不停取出栈顶元素遍历，达到深度优先搜索效果
	while (!stack.empty()) {
		// 出栈
		unsigned int s = stack.back();
		stack.pop_back();

		// 将当前顶点的邻接顶点加入栈中
		for (auto& w : _g.adj(s)) {
			if (_pre[w] == -1) {
				stack.push_back(w);
				_pre[w] = s;
			}
		}
	}
};
