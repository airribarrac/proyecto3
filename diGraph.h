#ifndef DIGRAPH
#define DIGRAPH

#include "diGraphADT.h"
#include <vector>
#include <iostream>
#include "Node.h"
#include <map>

using namespace std;

typedef vector<bool> vb;

class diGraph: public diGraphADT{
public:
	diGraph();
	void add(string,string);
	void find(string);
	void clique();
	void compact();
	void follow(int);
private:
	Node* dfs1(string);				//retorna nodo con el string
	Node* dfs2(string,Node*,vector<bool> &visited);
	bool find1(string s);
	bool find2(string s);
	map<string,bool> nodes;
	vector<Node*> ver;
	vector<vb> cliques;
	void BK(vb R,vb P,vb X);
	vb set_union(vb &a,vb &b);
	vb set_inter(vb &a,vb &b);
	vb set_subst(vb &a,vb &b);
	vb neighbors(int n);
	int count(vb &a);
	void set_print(vb &a);
};

#endif