#pragma once

#include "graph.h"

class CycleDetection {
public:
	CycleDetection(Graph g);

	// ͼ�Ƿ��л�
	bool hasCycle();

private:
	// ������ȱ������ݹ鷽ʽ
	bool _dfs(int v, int parent);
	// ������ȱ������ǵݹ鷽ʽ
	bool _dfs2(unsigned int v, int parent);

	Graph _g;
	bool* _visited;
	bool _hasCycle;
};
