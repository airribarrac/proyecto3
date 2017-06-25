#ifndef DIGRAPHADT
#define DIGRAPHADT

#include <iostream>

using namespace std;

class diGraphADT{
public:
	virtual void add(string,string)=0;
	virtual void find(string)=0;
	virtual void clique()=0;
	virtual void compact()=0;
	virtual void follow(int)=0;
};

#endif