#pragma once

#include "graph.h"

class CycleDetection {
public:
	CycleDetection(Graph g);

	// 图是否有环
	bool hasCycle();

private:
	// 深度优先遍历，递归方式
	bool _dfs(int v, int parent);
	// 深度优先遍历，非递归方式
	bool _dfs2(unsigned int v, int parent);

	Graph _g;
	bool* _visited;
	bool _hasCycle;
};
