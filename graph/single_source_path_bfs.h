#pragma once

#include "graph.h"

class SingleSourcePathBFS {
public:
	SingleSourcePathBFS(Graph g, int s);
	~SingleSourcePathBFS();

	// 判断顶点t和源顶点是否联通
	bool isConnectedTo(int t);

	// 获取源顶点到顶点t的路径
	std::list<int> path(int t);

private:
	void _bfs(int v);

	Graph _g;
	int _s;
	bool* _visited;
	int* _pre;
};
