#include "diGraph.h"
#include <queue>
using namespace std;

diGraph::diGraph(){

}

//agrega arista desde u hasta v
void diGraph::add(string u,string v){
	Node *uu=dfs1(u);
	Node *vv=dfs1(v);
	if(uu==NULL){
		uu=new Node(u,ver.size());
	}
	if(vv==NULL){
		vv=new Node(v,ver.size());
	}
}

//retorna puntero a nodo que coincide
Node* diGraph::dfs1(string u){
	Node *res=NULL;
	vector<bool> visited(ver.size(),false);
	for(int i=0;i<ver.size();i++){
		if(!visited[i]){
			Node* a=ver[i];
			Node* aux=dfs2(u,a,visited);
			res=aux!=NULL?aux:res;
			if(res!=NULL){
				break;
			}
		}
	}
	return res;
}

Node* diGraph::dfs2(string u,Node *a,vector<bool> &visited){
	if(a->getName()==u){
		return a;
	}
	Node *res=NULL;
	int ind=a->getIndex();
	visited[ind]=true;
	vector<Node*> adj=a->getOut();
	for(int i=0;i<adj->size();i++){
		Node *b=adj[i];
		int ind2=b->getIndex;
		if(!visited[ind2]){	
			Node *aux=dfs2(u,b,visited);
			res=aux!=NULL?aux:res;
		}
		if(res!=NULL){
			break;
		}
	}
	return res;
}