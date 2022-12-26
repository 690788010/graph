#include "adj_list.h"

AdjList::AdjList(std::string filename) {
	std::ifstream ifs;
	ifs.open(filename, std::ios::in);
	if (!ifs.is_open()) {
		throw std::invalid_argument("�ļ���ʧ��!");
	}

	std::string buf;

	std::string buf;

	// ��ȡ��������
	getline(ifs, buf);
	_v = stoul(buf);
	if (_v < 0) {
		throw std::invalid_argument("V must be non-negative!");
	}

	// ��ȡ������
	getline(ifs, buf);
	_e = stoul(buf);
	if (_e < 0) {
		throw std::invalid_argument("E must be non-negative!");
	}

	// ��ʼ���ڽӱ�
	_adj = new std::list<unsigned int>[_v];
	for (unsigned int i = 0; i < _v; i++) {
		_adj[i] = std::list<unsigned int>();
	}

	// ��ͼ
	while (getline(ifs, buf)) {
		size_t idx = buf.find(" ");
		unsigned int a = stoul(buf.substr(0, idx));
		unsigned int b = stoul(buf.substr(idx + 1));

		// ��֤����Ϸ���
		_validateVertex(a);
		_validateVertex(b);

		// �Ի��߼��
		if (a == b) {
			throw std::invalid_argument("Self Loop is Detected!");
		}

		// ƽ�б߼��
		;
		if (find(_adj[a].begin(), _adj[a].end(), b) != _adj[a].end()) {
			throw std::invalid_argument("Parallel Edges are Detected!");
		}

		_adj[a].push_back(b);
		_adj[b].push_back(a);
	}
};

AdjList::~AdjList() {

};

void AdjList::_validateVertex(unsigned int v) {
	if (v < 0 || v >= _v) {
		std::string msg = "vertex " + v;
		msg += " is invalid!";
		throw std::invalid_argument(msg);
	}
};
