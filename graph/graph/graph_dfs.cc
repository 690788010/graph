#include "graph_dfs.h"

GraphDFS::GraphDFS(Graph g) : _g{ std::move(g) } {
	unsigned int V = _g.V();
	_visited = new bool[V];
	for (unsigned int i = 0; i < V; i++) {
		_visited[i] = false;
	}
	// ��ÿ����ͨ��������DFS����
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
	// ����ǰ�����ʶΪ�ѱ���
	_visited[v] = true;
	// ���浱ǰ����,��������������
	_pre.push_back(v);

	// ������ǰ������ڽӶ���
	for (auto& w : _g.adj(v)) {
		if (!_visited[w]) {
			dfs(w);
		}
	}
	// ���浱ǰ����,������Ⱥ������
	_post.push_back(v);
};

void GraphDFS::dfs2(unsigned int v) {
	std::list<unsigned int> stack;
	stack.push_back(v);
	// ����ǰ�����ʶΪ�ѱ���
	_visited[v] = true;
	// ���浱ǰ����,��������������
	_pre.push_back(v);
	
	while (!stack.empty()) {
		unsigned int s = stack.back();
		stack.pop_back();

		for (auto& w : _g.adj(s)) {
			if (!_visited[w]) {
				stack.push_back(w);
				_visited[w] = true;
				// ���浱ǰ����,��������������
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
