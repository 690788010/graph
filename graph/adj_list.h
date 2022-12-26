#pragma once

#include <string>
#include <fstream>
#include <list>

class AdjList {
public:
	AdjList(std::string filename);
	~AdjList();


private:
	// 验证顶点合法性
	void _validateVertex(unsigned int v);

	unsigned int _v;
	unsigned int _e;
	std::list<unsigned int>* _adj;
};
