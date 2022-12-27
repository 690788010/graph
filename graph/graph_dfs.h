#pragma once

#include <list>
#include "graph.h"

class GraphDFS {
public:
	GraphDFS(Graph g);
	~GraphDFS();

	// 深度优先遍历(递归方式)
	void dfs(unsigned int v);

	// 深度优先遍历(非递归方式)
	void dfs2(unsigned int v);

	std::list<unsigned int>& pre();
	std::list<unsigned int>& post();

private:
	Graph _g;
	bool* _visited;
	std::list<unsigned int> _pre;		// 深度优先先序遍历
	std::list<unsigned int> _post;		// 深度优先后序遍历
};
