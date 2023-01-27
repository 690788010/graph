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

	// �ж϶���v�Ƿ��Դ����ͨ
	bool isConnectedTo(int v);

	// ��ȡԴ�㵽����v�����·��
	float disTo(int v);

private:

	WeightedGraph _g;
	bool* _visited;
	float* _dis;
	int _s;
};