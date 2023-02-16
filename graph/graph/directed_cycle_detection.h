#pragma once

#include "graph.h"

class DirectedCycleDetection {
public:
	DirectedCycleDetection(Graph g);
	~DirectedCycleDetection();

	// 图是否有环
	bool hasCycle();

private:
	// 深度优先遍历，递归方式
	bool _dfs(int v, int parent);
	// 深度优先遍历，非递归方式
	bool _dfs2(unsigned int v, int parent);

	Graph _g;
	bool* _visited;
	bool* _onPath;		// 记录各个顶点是否在当前路径上
	bool _hasCycle;
};
