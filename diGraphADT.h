#ifndef DIGRAPHADT
#define DIGRAPHADT

class diGraphADT{
public:
	virtual void add(string,string)=0;
	virtual bool find(string)=0;
	virtual void clique()=0;
	virtual void compact()=0;
	virtual void follow()=0;
};

#endif