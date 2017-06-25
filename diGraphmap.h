#ifndef DIGRAPH
#define DIGRAPH

#include "diGraphADT.h"
#include <bits/stdc++.h>
using namespace std;

class diGraphmap: public diGraphADT{
public:
	diGraphmap();
	void add(string,string);
	bool find(string);
	void clique();
	void compact();
	void follow();
private:
	map<string,bool> nodes;
};

#endif