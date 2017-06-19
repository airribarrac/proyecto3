#ifndef NODE
#define NODE

class Node{
public:
	Node(string);
	string getName();
	vector<Node*>* getIn();
	vector<Node*>* getOut();
	int outDeg();
	int inDeg();

private:
	vector<Node*> *in,*out;
	string name;
};

#endif