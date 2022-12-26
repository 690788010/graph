#pragma once

#include <string>
#include <fstream>
#include <list>

class AdjMatrix {
public:
	AdjMatrix(std::string filename);
	~AdjMatrix();

	// ��ⶥ��v�Ͷ���w֮���Ƿ����һ���ߣ� ʱ�临�Ӷ�ΪO(1)��
	bool hasEdge(unsigned int v, unsigned int w);

	// ���ض���v���ڽӶ��㣬ʱ�临�Ӷ�ΪO(v)��
	std::list<unsigned int> adj(unsigned int v);

	// ���ض���v�Ķȣ�ʱ�临�Ӷ�ΪO(v)��
	unsigned int degree(int v);

	unsigned int V();
	unsigned int E();

	// ��Ԫ����
	friend std::ostream& operator<<(std::ostream& os, AdjMatrix& matrix);

private:
	// ��֤����Ϸ���
	void _validateVertex(unsigned int v);

	unsigned int _v;
	unsigned int _e;
	bool** _adj;
};

// �Զ���AdjMatrix���I/O
std::ostream& operator<<(std::ostream& os, const AdjMatrix& matrix);
