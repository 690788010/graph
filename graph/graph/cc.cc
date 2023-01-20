#include "cc.h"

CC::CC(Graph g) : _g{std::move(g)} {
	unsigned int V = _g.V();
	_visited = new int[V];
	for (unsigned int i = 0; i < V; i++) {
		_visited[i] = -1;
	}
	_ccCount = 0;
	for (unsigned int v = 0; v < V; v++) {
		if (_visited[v] == -1) {
			_dfs(v, _ccCount);
			_ccCount++;			// 联通分量数量加1
		}
	}
};

CC::~CC() {
	if (_visited != nullptr) {
		delete[] _visited;
		_visited = nullptr;
	}
};

int CC::getCCCount() {
	unsigned int V = _g.V();
	for (unsigned int v = 0; v < V; v++) {
		std::cout << _visited[v] << " ";
	}
	std::cout << std::endl;

	return _ccCount;
};

bool CC::isConnected(unsigned int v, unsigned int w) {
	_g._validateVertex(v);
	_g._validateVertex(w);

	return _visited[v] == _visited[w];
};

std::unique_ptr<std::list<unsigned int>[]> CC::components() {
	// 函数返回一个指向自由存储上的对象的指针非常危险，因为这个对象可能不会被释放内存。
	// 因此不要返回“裸指针”，而是返回一个标准库unique_ptr。当对象的unique_ptr离开了
	// 作用域时，unique_ptr将释放掉所指的对象。
	std::unique_ptr<std::list<unsigned int>[]> res{ new std::list<unsigned int>[_ccCount] };

	unsigned int V = _g.V();
	for (unsigned int v = 0; v < V; v++) {
		res[_visited[v]].push_back(v);
	}

	return res;
};

void CC::_dfs(unsigned int v, int ccid) {
	_visited[v] = ccid;

	for (auto& w : _g.adj(v)) {
		if (_visited[w] == -1) {
			_dfs(w, ccid);
		}
	}
}

void CC::_dfs2(unsigned int v, int ccid) {
	// 入栈
	std::list<unsigned int> stack;
	stack.push_back(v);
	// 将当前顶点标识为已遍历
	_visited[v] = ccid;

	// 不停取出栈顶元素遍历，达到深度优先搜索效果
	while (!stack.empty()) {
		// 出栈
		unsigned int s = stack.back();
		stack.pop_back();

		// 将当前顶点的邻接顶点加入栈中
		for (auto& w : _g.adj(s)) {
			if (_visited[w] == -1) {
				stack.push_back(w);
				_visited[w] = ccid;
			}
		}
	}
};
