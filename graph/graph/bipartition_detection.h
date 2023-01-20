#pragma once

#include "graph.h"

class BipartitionDetection {
public:
	BipartitionDetection(Graph g);
	~BipartitionDetection();

	// �Ƿ�Ϊ����ͼ
	bool isBipartite();

private:
	// ������ȱ������ݹ鷽ʽ
	bool _dfs(int v, char color);
	// ������ȱ������ǵݹ鷽ʽ
	bool _dfs2(int v, char color);

	Graph _g;
	bool* _visited;
	char* _colors;
	bool _isBipartite;
};
