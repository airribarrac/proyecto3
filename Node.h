#ifndef NODE
#define NODE

#include <vector>
#include <iostream>

using namespace std;

class Node{
public:
	Node(string,int);
	~Node();
	string getName();
	vector<Node*>* getIn();
	vector<Node*>* getOut();
	int outDeg();
	int inDeg();
	int getIndex();
	void addIn(Node*);
	void addOut(Node*);

private:
	vector<Node*> *in,*out;
	string name;
	int index;
};

#endif