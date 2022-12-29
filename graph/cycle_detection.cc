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
			// ��ǰ������ڽӶ����б��������Ķ���,�Ҹö��㲻����һ�����㣨parent���������������ͼ�л���
			return true;
		}
		return false;
	}
};

bool CycleDetection::_dfs2(unsigned int v, int parent) {
	// ��ջ
	std::list<unsigned int> stack;
	stack.push_back(v);
	_visited[v] = true;

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
			}
			else if (w != parent) {
				return true;
			}
		}
		parent = s;
	}
	return false;
};
