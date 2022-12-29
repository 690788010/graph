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

// �Ƿ�Ϊ����ͼ
bool BipartitionDetection::isBipartite() {
	return _isBipartite;
};

// ������ȱ������ݹ鷽ʽ
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

// ������ȱ������ǵݹ鷽ʽ
bool BipartitionDetection::_dfs2(int v, char color) {
	// ��ջ
	std::list<unsigned int> stack;
	stack.push_back(v);
	_visited[v] = true;
	_colors[v] = color;

	// ��ͣȡ��ջ��Ԫ�ر������ﵽ�����������Ч��
	while (!stack.empty()) {
		// ��ջ
		unsigned int s = stack.back();
		stack.pop_back();

		// ����ǰ������ڽӶ������ջ��
		for (auto& w : _g.adj(s)) {
			if (!_visited[w]) {
				stack.push_back(w);
				_visited[w] = true;
				_colors[w] = 1 - color;
			}
			else if (_colors[w] == _colors[s]) {
				// ��ǰ������ڽӶ������б��������Ķ��㣬�Ҹö�����ɫ�͵�ǰ����һ�£������������ͼ���Ƕ���ͼ��
				return false;
			}
		}
		color = 1 - color;
	}
	return true;
};
