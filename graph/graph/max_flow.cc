#include "max_flow.h"
#include <iostream>

MaxFlow::MaxFlow(WeightedGraph graph, int s, int t) : _network{ std::move(graph) }, _rG{WeightedGraph(_network.V(), true)} {
	_maxFlow = 0;

	if (!_network.isDirected()) {
		throw std::invalid_argument("MaxFlow only workds in directed graph!");
	}

	if (_network.V() < 2) {
		throw std::invalid_argument("The network should has at least two vertices!");
	}

	_network.validateVertex(s);
	_network.validateVertex(t);
	if (s == t) {
		throw std::invalid_argument("s and t should be different!");
	}
	_s = s;
	_t = t;

	// 构建残量图
	for (int v = 0; v < _network.V(); v++) {
		for (auto& w : _network.adj(v)) {
			int c = _network.getWeight(v, w);
			_rG.addEdge(v, w, c);
			_rG.addEdge(w, v, 0);		// 添加反向边
		}
	}

	// 在残量图中不断找增广路径，直到没有增广路径为止
	while (true) {
		std::vector<int> augPath = _getAugmentingPath();
		if (augPath.size() == 0) break;		// 没有增广路径，直接退出循环

		// 找到当前增广路径所有边的最小流量并添加到_maxFlow中
		int f = INT_MAX;
		for (int i = 1; i < augPath.size(); i++) {
			int v = augPath[i - 1];
			int w = augPath[i];
			f = std::min(f, _rG.getWeight(v, w));
		}
		_maxFlow += f;

		// 更新残量图
		for (int i = 1; i < augPath.size(); i++) {
			int v = augPath[i - 1];
			int w = augPath[i];
			_rG.setWeight(v, w, _rG.getWeight(v, w) - f);
			_rG.setWeight(w, v, _rG.getWeight(w, v) + f);
		}
	}
};

// 获取最大流结果
int MaxFlow::result() {
	return _maxFlow;
};

// 获取某条路径的流量
int MaxFlow::flow(int v, int w) {
	if (!_network.hasEdge(v, w)) {
		std::string msg = "No edge ";
		msg += v;
		msg += "-";
		msg += w;
		throw std::invalid_argument(msg);
	}
	
	return _rG.getWeight(w, v);
};

std::vector<int> MaxFlow::_getAugmentingPath() {
	std::list<int> queue;
	int* pre = new int[_network.V()];
	for (int i = 0; i < _network.V(); i++) {
		pre[i] = -1;
	}

	queue.push_back(_s);
	pre[_s] = _s;

	while (!queue.empty()) {
		int cur = queue.front();
		queue.pop_front();

		if (cur == _t) break;		// 已找到源点到汇点的增广路径，可以直接退出循环

		for (int next : _rG.adj(cur)) {
			if (pre[next] == -1 && _rG.getWeight(cur, next) > 0) {
				pre[next] = cur;
				queue.push_back(next);
			}
		}
	}

	std::vector<int> res;

	// 如果没有找到增广路径，直接返回空路径
	if (pre[_t] == -1) {		
		return res;
	}

	// 整理出增广路径并返回
	int cur = _t;
	while (cur != _s) {
		res.push_back(cur);
		cur = pre[cur];
	}
	res.push_back(_s);
	reverse(res.begin(), res.end());
	return res;
};


std::ostream& operator<<(std::ostream& os, MaxFlow& maxFlow) {
	os << "Max Flow = " << maxFlow.result() << "\n";
	for (int v = 0; v < maxFlow._network.V(); v++) {
		for (int w : maxFlow._network.adj(v)) {
			os << v << "-" << w << " : " << maxFlow.flow(v, w) << "/" << maxFlow._network.getWeight(v, w) << "\n";
		}
	}
	return os;
};
