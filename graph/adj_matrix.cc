#include "adj_matrix.h"

AdjMatrix::AdjMatrix(std::string filename) {
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

	// 初始化邻接矩阵
	_adj = new bool* [_v];
	for (unsigned int i = 0; i < _v; i++) {
		_adj[i] = new bool[_v];
		for (unsigned int j = 0; j < _v; j++) {
			_adj[i][j] = false;
		}
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
		if (_adj[a][b]) {
			throw std::invalid_argument("Parallel Edges are Detected!");
		}

		_adj[a][b] = true;
		_adj[b][a] = true;
	}
};

AdjMatrix::~AdjMatrix() {
	if (_adj != nullptr) {
		for (unsigned int i = 0; i < _v; i++) {
			delete[] _adj[i];
		}
		delete _adj;
	}
}

// 检测顶点v和顶点w之间是否存在一条边， 时间复杂度为O(1)。
bool AdjMatrix::hasEdge(unsigned int v, unsigned int w) {
	_validateVertex(v);
	_validateVertex(w);

	return _adj[v][w];
};

// 返回顶点v的邻接顶点，时间复杂度为O(v)。
std::list<unsigned int> AdjMatrix::adj(unsigned int v) {
	_validateVertex(v);

	std::list<unsigned int> res;
	for (unsigned int i = 0; i < _v; i++) {
		if (_adj[v][i]) {
			res.push_back(i);
		}
	}
	return res;
};

unsigned int AdjMatrix::degree(int v) {
	return adj(v).size();
};

unsigned int AdjMatrix::V() {
	return _v;
};

unsigned int AdjMatrix::E() {
	return _e;
};

void AdjMatrix::_validateVertex(unsigned int v) {
	if (v < 0 || v >= _v) {
		std::string msg = "vertex " + v;
		msg += " is invalid!";
		throw std::invalid_argument(msg);
	}
};

std::ostream& operator<<(std::ostream& os, AdjMatrix& matrix) {
	os << "V = " << matrix.V() << ", E = " << matrix.E() << "\n";
	unsigned int v = matrix.V();
	for (unsigned int i = 0; i < v; i++) {
		for (unsigned int j = 0; j < v; j++) {
			os << matrix._adj[i][j] << " ";
		}
		os << "\n";
	}
	return os;
};
