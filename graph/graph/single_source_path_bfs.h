#pragma once

#include "graph.h"

class SingleSourcePathBFS {
public:
	SingleSourcePathBFS(Graph g, int s);
	~SingleSourcePathBFS();

	// �ж϶���t��Դ�����Ƿ���ͨ
	bool isConnectedTo(int t);

	// ��ȡԴ���㵽����t��·��
	std::list<int> path(int t);

private:
	void _bfs(int v);

	Graph _g;
	int _s;
	bool* _visited;
	int* _pre;
};
