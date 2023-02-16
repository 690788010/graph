#pragma once

#include <string>
#include <fstream>
#include <map>
#include <set>

class WeightedGraph {
public:
	WeightedGraph(const std::string& filename, bool directed = false);
	WeightedGraph(int v, bool directed);
	// �������캯��
	WeightedGraph(const WeightedGraph& graph);
	// �ƶ����캯��
	WeightedGraph(WeightedGraph&& graph);
	~WeightedGraph();

	// �Ƿ�Ϊ����ͼ
	bool isDirected() const;

	// ��ͼ�����һ��·��
	void addEdge(int a, int b, int weight);

	// ����ĳ���ߵ�Ȩֵ
	void setWeight(int v, int w, int weight);

	// ��ⶥ��v�Ͷ���w֮���Ƿ����һ���ߣ�ʱ�临�Ӷ�ΪO(log(v))
	bool hasEdge(int v, int w);

	// ���ض���v���ڽӶ��㣬ʱ�临�Ӷ�ΪO(degree(v))
	std::set<int> adj(int v);

	// ���ض���v�Ķȣ�ʱ�临�Ӷ�ΪO(1)
	unsigned int degree(int v);

	void validateVertex(int v);
	int V();
	int E();
	int getWeight(int v, int w);

	// ��Ԫ����
	friend std::ostream& operator<<(std::ostream& os, WeightedGraph& graph);

private:

	int _v;
	int _e;
	bool _directed;
	std::map<int, int>* _adj;
};

// �Զ���WeightedGraph���I/O
std::ostream& operator<<(std::ostream& os, WeightedGraph& graph);