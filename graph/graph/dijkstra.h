#pragma once

#include "weighted_graph.h"
#include <climits>
#include <queue>

struct Node {

	int v;
	float weight;

	Node(int v, float weight);

	bool operator<(const Node& node) const;
};

class Dijkstra {
public:
	Dijkstra(WeightedGraph graph, int s);
	~Dijkstra();

	// 判断顶点v是否和源点联通
	bool isConnectedTo(int v);

	// 获取源点到顶点v的最短路径
	float disTo(int v);

private:

	WeightedGraph _g;
	bool* _visited;
	float* _dis;
	int _s;
};