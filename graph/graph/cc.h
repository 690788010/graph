#pragma once

#include <iostream>
#include "graph.h"

class CC {
public:
	CC(Graph g);
	~CC();

	// ��ȡ��ͨ����������
	int getCCCount();

	// �ж����������Ƿ���ͨ
	bool isConnected(unsigned int v, unsigned int w);

	// ����������ͨ��������Ϣ
	std::unique_ptr<std::list<unsigned int>[]> components();

private:
	// ������ȱ������ݹ鷽ʽ
	void _dfs(unsigned int v, int ccid);
	// ������ȱ������ǵݹ鷽ʽ
	void _dfs2(unsigned int v, int ccid);

	Graph _g;
	int* _visited;
	int _ccCount;
};
