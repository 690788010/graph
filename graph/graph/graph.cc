#include "graph.h"

Graph::Graph(std::string filename) {
	std::ifstream ifs;
	ifs.open(filename, std::ios::in);
	if (!ifs.is_open()) {
		throw std::invalid_argument("文件打开失败!");
	}

	std::string buf;

	// 读取顶点数量
	getline(ifs, buf);
	_v = stoul(buf);
	if (_v < 0) {
		throw std::invalid_argument("V must be non-negative!");
	}

	// 读取边数量
	getline(ifs, buf);
	_e = stoul(buf);
	if (_e < 0) {
		throw std::invalid_argument("E must be non-negative!");
	}

	// 初始化邻接表
	_adj = new std::set<unsigned int>[_v];
	for (unsigned int i = 0; i < _v; i++) {
		_adj[i] = std::set<unsigned int>();
	}

	// 建图
	while (getline(ifs, buf)) {
		size_t idx = buf.find(" ");
		unsigned int a = stoul(buf.substr(0, idx));
		unsigned int b = stoul(buf.substr(idx + 1));

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

		_adj[a].insert(b);
		_adj[b].insert(a);
	}
};

Graph::Graph(const Graph& graph) {
	_v = graph._v;
	_e = graph._e;
	_adj = new std::set<unsigned int>[_v];
	// 复制元素
	for (unsigned int i = 0; i < _v; i++) {
		for (auto v : graph._adj[i]) {
			_adj[i].insert(v);
		}
	}
};

// 移动构造函数
Graph::Graph(Graph&& graph) {
	_v = graph._v;
	graph._v = 0;
	_e = graph._e;
	graph._e = 0;
	_adj = graph._adj;		// 从graph中夺取元素
	graph._adj = nullptr;
};

Graph::~Graph() {
	if (_adj != nullptr) {
		delete[] _adj;
		_adj = nullptr;
	}
};

void Graph::_validateVertex(unsigned int v) {
	if (v < 0 || v >= _v) {
		std::string msg = "vertex " + v;
		msg += " is invalid!";
		throw std::invalid_argument(msg);
	}
};

bool Graph::hasEdge(unsigned int v, unsigned int w) {
	_validateVertex(v);
	_validateVertex(w);

	return _adj[v].find(w) != _adj[v].end();
};

std::set<unsigned int>& Graph::adj(unsigned int v) {
	_validateVertex(v);

	return _adj[v];
};

unsigned int Graph::degree(int v) {
	_validateVertex(v);

	return _adj[v].size();
};

unsigned int Graph::V() {
	return _v;
};

unsigned int Graph::E() {
	return _e;
};

Graph& Graph::operator=(const Graph& graph) {
	_v = graph._v;
	_e = graph._e;
	std::set<unsigned int>* adj = new std::set<unsigned int>[_v];
	for (unsigned int i = 0; i < _v; i++) {
		for (auto v : graph._adj[i]) {
			adj[i].insert(v);
		}
	}
	delete[] _adj;			// 删除旧元素
	_adj = adj;

	return *this;
};

Graph& Graph::operator=(Graph&& graph) {
	_v = graph._v;
	graph._v = 0;
	_e = graph._e;
	graph._e = 0;
	_adj = graph._adj;		// 从graph中夺取元素
	graph._adj = nullptr;
	return *this;
};

std::ostream& operator<<(std::ostream& os, Graph& set) {
	os << "V = " << set.V() << ", E = " << set.E() << "\n";
	unsigned int V = set.V();
	for (unsigned int i = 0; i < V; i++) {
		for (auto& v : set._adj[i]) {
			os << v << " ";
		}
		os << "\n";
	}
	return os;
};
