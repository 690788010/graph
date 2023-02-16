#pragma once

#include <list>
#include <vector>
#include <algorithm>
#include <limits>
#include "weighted_graph.h"

class MaxFlow {
public:
	MaxFlow(WeightedGraph graph, int s, int t);
	
	// ��ȡ��������
	int result();

	// ��ȡĳ��·��������
	int flow(int v, int w);

	// ��Ԫ����
	friend std::ostream& operator<<(std::ostream& os, MaxFlow& maxFlow);

private:
	// ��Ѱ����·��
	std::vector<int> _getAugmentingPath();


	WeightedGraph _network;
	WeightedGraph _rG;		// ����ͼ
	int _s;					// Դ��
	int _t;					// ���
	int _maxFlow;			// �����
};

// �Զ���MaxFlow���I/O
std::ostream& operator<<(std::ostream& os, MaxFlow& maxFlow);
