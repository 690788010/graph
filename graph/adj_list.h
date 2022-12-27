#pragma once

#include <string>
#include <fstream>
#include <list>

class AdjList {
public:
	AdjList(std::string filename);
	~AdjList();

	// ��ⶥ��v�Ͷ���w֮���Ƿ����һ���ߣ�ʱ�临�Ӷ�ΪO(degree(v))
	bool hasEdge(unsigned int v, unsigned int w);

	// ���ض���v���ڽӶ��㣬ʱ�临�Ӷ�ΪO(1)
	std::list<unsigned int> adj(unsigned int v);

	// ���ض���v�Ķȣ�ʱ�临�Ӷ�ΪO(1)
	unsigned int degree(int v);

	unsigned int V();
	unsigned int E();

	// ��Ԫ����
	friend std::ostream& operator<<(std::ostream& os, AdjList& matrix);

private:
	// ��֤����Ϸ���
	void _validateVertex(unsigned int v);

	unsigned int _v;
	unsigned int _e;
	std::list<unsigned int>* _adj;
};

// �Զ���AdjList���I/O
std::ostream& operator<<(std::ostream& os, AdjList& matrix);
