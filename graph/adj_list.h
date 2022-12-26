#pragma once

#include <string>
#include <fstream>
#include <list>

class AdjList {
public:
	AdjList(std::string filename);
	~AdjList();


private:
	// ��֤����Ϸ���
	void _validateVertex(unsigned int v);

	unsigned int _v;
	unsigned int _e;
	std::list<unsigned int>* _adj;
};
