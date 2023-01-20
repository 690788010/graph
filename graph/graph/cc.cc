#include "cc.h"

CC::CC(Graph g) : _g{std::move(g)} {
	unsigned int V = _g.V();
	_visited = new int[V];
	for (unsigned int i = 0; i < V; i++) {
		_visited[i] = -1;
	}
	_ccCount = 0;
	for (unsigned int v = 0; v < V; v++) {
		if (_visited[v] == -1) {
			_dfs(v, _ccCount);
			_ccCount++;			// ��ͨ����������1
		}
	}
};

CC::~CC() {
	if (_visited != nullptr) {
		delete[] _visited;
		_visited = nullptr;
	}
};

int CC::getCCCount() {
	unsigned int V = _g.V();
	for (unsigned int v = 0; v < V; v++) {
		std::cout << _visited[v] << " ";
	}
	std::cout << std::endl;

	return _ccCount;
};

bool CC::isConnected(unsigned int v, unsigned int w) {
	_g._validateVertex(v);
	_g._validateVertex(w);

	return _visited[v] == _visited[w];
};

std::unique_ptr<std::list<unsigned int>[]> CC::components() {
	// ��������һ��ָ�����ɴ洢�ϵĶ����ָ��ǳ�Σ�գ���Ϊ���������ܲ��ᱻ�ͷ��ڴ档
	// ��˲�Ҫ���ء���ָ�롱�����Ƿ���һ����׼��unique_ptr���������unique_ptr�뿪��
	// ������ʱ��unique_ptr���ͷŵ���ָ�Ķ���
	std::unique_ptr<std::list<unsigned int>[]> res{ new std::list<unsigned int>[_ccCount] };

	unsigned int V = _g.V();
	for (unsigned int v = 0; v < V; v++) {
		res[_visited[v]].push_back(v);
	}

	return res;
};

void CC::_dfs(unsigned int v, int ccid) {
	_visited[v] = ccid;

	for (auto& w : _g.adj(v)) {
		if (_visited[w] == -1) {
			_dfs(w, ccid);
		}
	}
}

void CC::_dfs2(unsigned int v, int ccid) {
	// ��ջ
	std::list<unsigned int> stack;
	stack.push_back(v);
	// ����ǰ�����ʶΪ�ѱ���
	_visited[v] = ccid;

	// ��ͣȡ��ջ��Ԫ�ر������ﵽ�����������Ч��
	while (!stack.empty()) {
		// ��ջ
		unsigned int s = stack.back();
		stack.pop_back();

		// ����ǰ������ڽӶ������ջ��
		for (auto& w : _g.adj(s)) {
			if (_visited[w] == -1) {
				stack.push_back(w);
				_visited[w] = ccid;
			}
		}
	}
};
