#pragma once

#include <string>
#include <fstream>
#include <map>
#include <set>

class WeightedGraph {
public:
	WeightedGraph(const std::string& filename, bool directed = false);
	WeightedGraph(int v, bool directed);
	// 拷贝构造函数
	WeightedGraph(const WeightedGraph& graph);
	// 移动构造函数
	WeightedGraph(WeightedGraph&& graph);
	~WeightedGraph();

	// 是否为有向图
	bool isDirected() const;

	// 往图中添加一条路径
	void addEdge(int a, int b, int weight);

	// 设置某条边的权值
	void setWeight(int v, int w, int weight);

	// 检测顶点v和顶点w之间是否存在一条边，时间复杂度为O(log(v))
	bool hasEdge(int v, int w);

	// 返回顶点v的邻接顶点，时间复杂度为O(degree(v))
	std::set<int> adj(int v);

	// 返回顶点v的度，时间复杂度为O(1)
	unsigned int degree(int v);

	void validateVertex(int v);
	int V();
	int E();
	int getWeight(int v, int w);

	// 友元函数
	friend std::ostream& operator<<(std::ostream& os, WeightedGraph& graph);

private:

	int _v;
	int _e;
	bool _directed;
	std::map<int, int>* _adj;
};

// 自定义WeightedGraph类的I/O
std::ostream& operator<<(std::ostream& os, WeightedGraph& graph);