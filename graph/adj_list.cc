#include "adj_list.h"

AdjList::AdjList(std::string filename) {
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
	_adj = new std::list<unsigned int>[_v];
	for (unsigned int i = 0; i < _v; i++) {
		_adj[i] = std::list<unsigned int>();
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
		if (find(_adj[a].begin(), _adj[a].end(), b) != _adj[a].end()) {
			throw std::invalid_argument("Parallel Edges are Detected!");
		}

		_adj[a].push_back(b);
		_adj[b].push_back(a);
	}
};

AdjList::~AdjList() {
	if (_adj != nullptr) {
		delete[] _adj;
		_adj = nullptr;
	}
};

bool AdjList::hasEdge(unsigned int v, unsigned int w) {
	_validateVertex(v);
	_validateVertex(w);

	return find(_adj[v].begin(), _adj[v].end(), w) != _adj[v].end();
};

std::list<unsigned int> AdjList::adj(unsigned int v) {
	_validateVertex(v);

	return _adj[v];
};

unsigned int AdjList::degree(int v) {
	return adj(v).size();
};

unsigned int AdjList::V() {
	return _v;
};

unsigned int AdjList::E() {
	return _e;
};

void AdjList::_validateVertex(unsigned int v) {
	if (v < 0 || v >= _v) {
		std::string msg = "vertex " + v;
		msg += " is invalid!";
		throw std::invalid_argument(msg);
	}
};

std::ostream& operator<<(std::ostream& os, AdjList& list) {
	os << "V = " << list.V() << ", E = " << list.E() << "\n";
	unsigned int V = list.V();
	for (unsigned int i = 0; i < V; i++) {
		for (auto& v : list._adj[i]) {
			os << v << " ";
		}
		os << "\n";
	}
	return os;
};
