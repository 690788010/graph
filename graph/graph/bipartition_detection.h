#pragma once

#include "graph.h"

class BipartitionDetection {
public:
	BipartitionDetection(Graph g);
	~BipartitionDetection();

	// 是否为二分图
	bool isBipartite();

private:
	// 深度优先遍历，递归方式
	bool _dfs(int v, char color);
	// 深度优先遍历，非递归方式
	bool _dfs2(int v, char color);

	Graph _g;
	bool* _visited;
	char* _colors;
	bool _isBipartite;
};
