#include "weighted_graph.h"


WeightedGraph::WeightedGraph(const std::string& filename) {
	std::ifstream ifs;
	ifs.open(filename, std::ios::in);
	if (!ifs.is_open()) {
		throw std::invalid_argument("文件打开失败!");
	}

	std::string buf;

	// 读取顶点数量
	getline(ifs, buf);
	_v = stoi(buf);
	if (_v < 0) {
		throw std::invalid_argument("V must be non-negative!");
	}

	// 读取边数量
	getline(ifs, buf);
	_e = stoi(buf);
	if (_e < 0) {
		throw std::invalid_argument("E must be non-negative!");
	}

	// 初始化邻接表
	_adj = new std::map<int, int>[_v];

	// 建图
	while (getline(ifs, buf)) {
		size_t idx = buf.find(" ");
		size_t idx2 = buf.find(" ", idx + 1);
		int a = stoi(buf.substr(0, idx));
		int b = stoi(buf.substr(idx + 1, idx2));
		int weight = stoi(buf.substr(idx2 + 1));

		// 验证顶点合法性
		_validateVertex(a);
		_validateVertex(b);

		// 自环边检测
		if (a == b) {
			throw std::invalid_argument("Self Loop is Detected!");
		}

		// 平行边检测
		if (_adj[a].find(b) != _adj[a].end()) {
			throw std::invalid_argument("Parallel Edges are Detected!");
		}

		_adj[a].insert(std::pair<int, int>(b, weight));
		_adj[b].insert(std::pair<int, int>(a, weight));
	}
};

// 拷贝构造函数
WeightedGraph::WeightedGraph(const WeightedGraph& graph) {
	_v = graph._v;
	_e = graph._e;

	// 初始化邻接表
	_adj = new std::map<int, int>[_v];

	for (int i = 0; i < _v; i++) {
		std::map<int, int>::iterator it = graph._adj[i].begin();
		while (it != graph._adj[i].end()) {
			_adj[i].insert(std::pair<int, int>(it->first, it->second));
			it++;
		}
	}
};

// 移动构造函数
WeightedGraph::WeightedGraph(WeightedGraph&& graph) {
	_v = graph._v;
	_e = graph._e;

	_adj = graph._adj;		// 从graph中夺取元素
	graph._adj = nullptr;
};

WeightedGraph::~WeightedGraph() {
	if (_adj != nullptr) {
		delete[] _adj;
		_adj = nullptr;
	}
};

bool WeightedGraph::hasEdge(int v, int w) {
	_validateVertex(v);
	_validateVertex(w);

	return _adj[v].find(w) != _adj[v].end();
};

std::set<int> WeightedGraph::adj(int v) {
	_validateVertex(v);

	std::set<int> res;
	std::map<int, int>::iterator it = _adj[v].begin();
	while (it != _adj[v].end()) {
		res.insert(it->first);
		it++;
	}
	return res;
};

unsigned int WeightedGraph::degree(int v) {
	_validateVertex(v);

	return _adj[v].size();
};

void WeightedGraph::_validateVertex(int v) {
	if (v < 0 || v >= _v) {
		std::string msg = "vertex " + v;
		msg += " is invalid!";
		throw std::invalid_argument(msg);
	}
};

unsigned int WeightedGraph::V() {
	return _v;
};

unsigned int WeightedGraph::E() {
	return _e;
};

std::ostream& operator<<(std::ostream& os, WeightedGraph& graph) {
	os << "V = " << graph.V() << ", E = " << graph.E() << "\n";
	int V = graph.V();
	for (int i = 0; i < V; i++) {
		os << i << ": ";
		for (auto& v : graph._adj[i]) {
			os << v.first << "-" << v.second << ", ";
		}
		os << "\n";
	}
	return os;
};