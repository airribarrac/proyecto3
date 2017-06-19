#ifndef NODE
#define NODE

class Node{
public:
	Node(string,int);
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