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

bool find(string s){
	Node *v=dfs1(s);
	cout<<(v!=NULL?"Yes":"No")<<endl;
	return v!=NULL;
}

void follow(int n){
	priority_queue<pair<int,pair<int,string> > pq;
	for(int i=0;i<ver.size();i++){
		Node *a=ver[i];
		pq.push(make_pair(a->outDeg(),make_pair(-a->inDeg(),a->getName())));
	}
	for(int i=0;i<n;i++){
		string str=pq.top().second.second;
		pq.pop();
		cout<<str<<endl;
	}
}