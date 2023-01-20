#pragma once

#include "graph.h"

class SingleSourcePath {
public:
	SingleSourcePath(Graph g, int s);
	~SingleSourcePath();

	// 判断顶点t和源顶点是否联通
	bool isConnectedTo(int t);

	// 获取源顶点到顶点t的路径
	std::list<int> path(int t);

private:
	// 深度优先遍历，递归方式
	void _dfs(int v, int parent);
	// 深度优先遍历，非递归方式
	void _dfs2(unsigned int v, int parent);

	Graph _g;
	int _s;
	int* _pre;
};
