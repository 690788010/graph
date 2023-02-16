#pragma once

#include <list>
#include <vector>
#include <algorithm>
#include <limits>
#include "weighted_graph.h"

class MaxFlow {
public:
	MaxFlow(WeightedGraph graph, int s, int t);
	
	// 获取最大流结果
	int result();

	// 获取某条路径的流量
	int flow(int v, int w);

	// 友元函数
	friend std::ostream& operator<<(std::ostream& os, MaxFlow& maxFlow);

private:
	// 找寻增广路径
	std::vector<int> _getAugmentingPath();


	WeightedGraph _network;
	WeightedGraph _rG;		// 残量图
	int _s;					// 源点
	int _t;					// 汇点
	int _maxFlow;			// 最大流
};

// 自定义MaxFlow类的I/O
std::ostream& operator<<(std::ostream& os, MaxFlow& maxFlow);
