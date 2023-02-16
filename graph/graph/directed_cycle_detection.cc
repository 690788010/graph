#include "directed_cycle_detection.h"
#include <iostream>

DirectedCycleDetection::DirectedCycleDetection(Graph g) : _g{ std::move(g) } {
	if (!_g.isDirected()) {
		throw std::invalid_argument("DirectedCycleDetection only works in directed graph.");
	}
	unsigned int V = _g.V();
	_visited = new bool[V];
	_onPath = new bool[V];
	for (unsigned int v = 0; v < V; v++) {
		_visited[v] = false;
		_onPath[v] = false;
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

DirectedCycleDetection::~DirectedCycleDetection() {
	if (_visited != nullptr) {
		delete[] _visited;
		_visited = nullptr;
	}
};

bool DirectedCycleDetection::hasCycle() {
	return _hasCycle;
};

bool DirectedCycleDetection::_dfs(int v, int parent) {
	_visited[v] = true;
	_onPath[v] = true;

	for (auto& w : _g.adj(v)) {
		if (!_visited[w]) {
			if (_dfs(w, v)) {
				return true;
			}
		}
		else if (_onPath[w]) {
			// ��ǰ������ڽӶ����б��������Ķ���,�Ҹö����ڵ�ǰ·���У������������ͼ�л���
			return true;
		}
	}

	_onPath[v] = false;
	return false;
};

bool DirectedCycleDetection::_dfs2(unsigned int v, int parent) {
	// ��ջ
	std::list<unsigned int> stack;
	stack.push_back(v);

	// ��ͣȡ��ջ��Ԫ�ر������ﵽ�����������Ч��
	while (!stack.empty()) {
		// ��ջ
		unsigned int s = stack.back();
		stack.pop_back();
		if (_visited[s]) {
			continue;
		}
		_visited[s] = true;
		_onPath[s] = true;

		// ����ǰ������ڽӶ������ջ��
		for (auto& w : _g.adj(s)) {
			if (!_visited[w]) {
				stack.push_back(w);
			}
			else if (_onPath[w]) {
				// ��ǰ������ڽӶ����б��������Ķ���,�Ҹö����ڵ�ǰ·���У������������ͼ�л���
				return true;
			}
		}
		parent = s;
	}
	return false;
};
