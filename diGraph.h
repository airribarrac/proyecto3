#ifndef DIGRAPH
#define DIGRAPH

#include "diGraphADT.h"
#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

class diGraph: public diGraphADT{
public:
	diGraph();
	void add(string,string);
	bool find(string);
	void clique();
	void compact();
	void follow(int);
private:
	Node* dfs1(string);				//retorna nodo con el string
	Node* dfs2(string,Node*,vector<bool> &visited);
	vector<Node*> ver;
};

#endif