#pragma once

#include <list>
#include "graph.h"

class GraphDFS {
public:
	GraphDFS(Graph g);
	~GraphDFS();

	// ������ȱ���(�ݹ鷽ʽ)
	void dfs(unsigned int v);

	// ������ȱ���(�ǵݹ鷽ʽ)
	void dfs2(unsigned int v);

	std::list<unsigned int>& pre();
	std::list<unsigned int>& post();

private:
	Graph _g;
	bool* _visited;
	std::list<unsigned int> _pre;		// ��������������
	std::list<unsigned int> _post;		// ������Ⱥ������
};
