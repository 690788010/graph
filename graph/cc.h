#pragma once

#include <iostream>
#include "graph.h"

class CC {
public:
	CC(Graph g);
	~CC();

	// 获取联通分量的数量
	int getCCCount();

	// 判断两个顶点是否联通
	bool isConnected(unsigned int v, unsigned int w);

	// 返回所有联通分量的信息
	std::unique_ptr<std::list<unsigned int>[]> components();

private:
	// 深度优先遍历，递归方式
	void _dfs(unsigned int v, int ccid);
	// 深度优先遍历，非递归方式
	void _dfs2(unsigned int v, int ccid);

	Graph _g;
	int* _visited;
	int _ccCount;
};
