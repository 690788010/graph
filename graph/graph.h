#pragma once

#include <string>
#include <set>
#include <list>
#include <stdexcept>
#include <fstream>

class Graph {
public:
	Graph(std::string filename);
	// �������캯��
	Graph(const Graph& graph);
	// �ƶ����캯��
	Graph(Graph&& graph);
	~Graph();

	// ��ⶥ��v�Ͷ���w֮���Ƿ����һ���ߣ�ʱ�临�Ӷ�ΪO(degree(v))
	bool hasEdge(unsigned int v, unsigned int w);

	// ���ض���v���ڽӶ��㣬ʱ�临�Ӷ�ΪO(degree(v))
	std::set<unsigned int>& adj(unsigned int v);

	// ���ض���v�Ķȣ�ʱ�临�Ӷ�ΪO(1)
	unsigned int degree(int v);

	unsigned int V();
	unsigned int E();

	// ������ֵ�����
	Graph& operator=(const Graph& graph);
	// �ƶ���ֵ�����
	Graph& operator=(Graph&& graph);

	// ��Ԫ����
	friend std::ostream& operator<<(std::ostream& os, Graph& matrix);
	// ��Ԫ��
	friend class CC;

private:
	// ��֤����Ϸ���
	void _validateVertex(unsigned int v);

	unsigned int _v;			// ������
	unsigned int _e;			// ����
	std::set<unsigned int>* _adj;
};

// �Զ���AdjSet���I/O
std::ostream& operator<<(std::ostream& os, Graph& set);
