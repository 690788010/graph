#pragma once

#include <string>
#include <fstream>
#include <list>

class AdjMatrix {
public:
	AdjMatrix(std::string filename);
	~AdjMatrix();

	// 检测顶点v和顶点w之间是否存在一条边， 时间复杂度为O(1)。
	bool hasEdge(unsigned int v, unsigned int w);

	// 返回顶点v的邻接顶点，时间复杂度为O(v)。
	std::list<unsigned int> adj(unsigned int v);

	// 返回顶点v的度，时间复杂度为O(v)。
	unsigned int degree(int v);

	unsigned int V();
	unsigned int E();

	// 友元函数
	friend std::ostream& operator<<(std::ostream& os, AdjMatrix& matrix);

private:
	// 验证顶点合法性
	void _validateVertex(unsigned int v);

	unsigned int _v;
	unsigned int _e;
	bool** _adj;
};

// 自定义AdjMatrix类的I/O
std::ostream& operator<<(std::ostream& os, const AdjMatrix& matrix);
