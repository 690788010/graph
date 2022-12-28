#pragma once

#include "graph.h"

class SingleSourcePath {
public:
	SingleSourcePath(Graph g, int s);
	~SingleSourcePath();

	// �ж϶���t��Դ�����Ƿ���ͨ
	bool isConnectedTo(int t);

	// ��ȡԴ���㵽����t��·��
	std::list<int> path(int t);

private:
	// ������ȱ������ݹ鷽ʽ
	void _dfs(int v, int parent);
	// ������ȱ������ǵݹ鷽ʽ
	void _dfs2(unsigned int v, int parent);

	Graph _g;
	int _s;
	int* _pre;
};
