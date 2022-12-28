#pragma once

#include <string>
#include <set>
#include <list>
#include <stdexcept>
#include <fstream>

class Graph {
public:
	Graph(std::string filename);
	// 拷贝构造函数
	Graph(const Graph& graph);
	// 移动构造函数
	Graph(Graph&& graph);
	~Graph();

	// 检测顶点v和顶点w之间是否存在一条边，时间复杂度为O(degree(v))
	bool hasEdge(unsigned int v, unsigned int w);

	// 返回顶点v的邻接顶点，时间复杂度为O(degree(v))
	std::set<unsigned int>& adj(unsigned int v);

	// 返回顶点v的度，时间复杂度为O(1)
	unsigned int degree(int v);

	unsigned int V();
	unsigned int E();

	// 拷贝赋值运算符
	Graph& operator=(const Graph& graph);
	// 移动赋值运算符
	Graph& operator=(Graph&& graph);

	// 友元函数
	friend std::ostream& operator<<(std::ostream& os, Graph& matrix);
	// 友元类
	friend class CC;

private:
	// 验证顶点合法性
	void _validateVertex(unsigned int v);

	unsigned int _v;			// 顶点数
	unsigned int _e;			// 边数
	std::set<unsigned int>* _adj;
};

// 自定义AdjSet类的I/O
std::ostream& operator<<(std::ostream& os, Graph& set);
