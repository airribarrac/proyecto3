#ifndef DIGRAPH
#define DIGRAPH

#include "diGraphADT.h"
#include <vector>

class diGraph: public diGraphADT{
public:
	void add(string,string)=0;
	bool find(string)=0;
	void clique()=0;
	void compact()=0;
	void follow()=0;
private:
	vector<vector<int> > in,out;
	
};

#endif