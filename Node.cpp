#include "Node.h"

Node::Node(string str){
	name=str;
}

string Node::getName(){
	return name;
}

vector<Node*>* Node::getIn(){
	return in;
}

vector<Node*>* Node::getOut(){
	return out;
}

int Node::outDeg(){
	return out->size();
}

int Node::inDeg(){
	return in->size();
}