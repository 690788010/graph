#pragma once

#include <string>
#include <fstream>
#include <map>
#include <set>

class WeightedGraph {
public:
	WeightedGraph(const std::string& filename);
	// 拷贝构造函数
	WeightedGraph(const WeightedGraph& graph);
	// 移动构造函数
	WeightedGraph(WeightedGraph&& graph);
	~WeightedGraph();

	// 检测顶点v和顶点w之间是否存在一条边，时间复杂度为O(log(v))
	bool hasEdge(int v, int w);

	// 返回顶点v的邻接顶点，时间复杂度为O(degree(v))
	std::set<int> adj(int v);

	// 返回顶点v的度，时间复杂度为O(1)
	unsigned int degree(int v);

	void _validateVertex(int v);
	unsigned int V();
	unsigned int E();

	// 友元函数
	friend std::ostream& operator<<(std::ostream& os, WeightedGraph& graph);

private:

	int _v;
	int _e;
	std::map<int, int>* _adj;
};

// 自定义WeightedGraph类的I/O
std::ostream& operator<<(std::ostream& os, WeightedGraph& graph);