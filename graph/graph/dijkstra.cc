#include "dijkstra.h"

Node::Node(int v, float weight) {
	this->v = v;
	this->weight = weight;
};

bool Node::operator<(const Node& node) const {
	return weight > node.weight;
};

Dijkstra::Dijkstra(WeightedGraph graph, int s) : _g{ std::move(graph) } {
	_g.validateVertex(s);
	_s = s;

	int V = _g.V();
	_visited = new bool[V];
	_dis = new float[V];
	for (int i = 0; i < V; i++) {
		_visited[i] = false;
		_dis[i] = FLT_MAX;
	}
	_dis[_s] = 0;

	std::priority_queue<Node> pq;
	pq.push(Node(_s, 0));
	while (!pq.empty()) {
		// 找到当前没有访问的最短路节点
		int cur = pq.top().v;
		pq.pop();
		if (_visited[cur]) {
			continue;
		}

		_visited[cur] = true;

		// 根据这个节点的最短路大小，更新其他节点的路径长度
		for (auto& w : _g.adj(cur)) {
			if (!_visited[w]) {
				if ((_dis[cur] + _g.getWeight(cur, w)) < _dis[w]) {
					_dis[w] = _dis[cur] + _g.getWeight(cur, w);
					pq.push(Node(w, _dis[w]));
				}
			}
		}
	}
};

Dijkstra::~Dijkstra() {
	if (_visited != nullptr) {
		delete[] _visited;
		_visited = nullptr;
	}
	if (_dis != nullptr) {
		delete[] _dis;
		_dis = nullptr;
	}
};

// 判断顶点v是否和源点联通
bool Dijkstra::isConnectedTo(int v) {
	_g.validateVertex(v);
	return _visited[v];
};

// 获取源点到顶点v的最短路径
float Dijkstra::disTo(int v) {
	_g.validateVertex(v);
	return _dis[v];
};