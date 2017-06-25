#include "diGraph.h"
#include <queue>
#include <vector>

using namespace std;

typedef vector<bool> vb;

diGraph::diGraph(){

}

//agrega arista desde u hasta v
void diGraph::add(string u,string v){
	Node *uu=dfs1(u);
	Node *vv=dfs1(v);
	if(uu==NULL){
		uu=new Node(u,ver.size());
		ver.push_back(uu);
	}
	if(vv==NULL){
		vv=new Node(v,ver.size());
		ver.push_back(vv);
	}
	uu->addIn(vv);
	vv->addOut(uu);
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
	vector<Node*> *adj=a->getOut();
	for(int i=0;i<adj->size();i++){
		Node *b=(*adj)[i];
		int ind2=b->getIndex();
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

void diGraph::clique(){
	int n=ver.size();
	cliques.clear();
	BK(vb(n,false),vb(n,true),vb(n,false));
	for(int i=0;i<cliques.size();i++){
		set_print(cliques[i]);
	}
}

void diGraph::compact(){
	int n=ver.size();
	cliques.clear();
	BK(vb(n,false),vb(n,true),vb(n,false));
	vb visited(n,false);
	
	//crear grafo auxiliar e imprimirlo con dfs?
}

bool diGraph::find(string s){
	Node *v=dfs1(s);
	cout<<(v!=NULL?"Yes":"No")<<endl;
	return v!=NULL;
}

void diGraph::follow(int n){
	priority_queue<pair<int,pair<int,string> > > pq;
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

vb diGraph::set_union(vb &a,vb &b){
	vb res(a.size());
	for(int i=0;i<a.size();i++){
		res[i]=a[i]||b[i];
	}
	return res;
}

vb diGraph::set_inter(vb &a,vb &b){
	vb res(a.size());
	for(int i=0;i<a.size();i++){
		res[i]=a[i]&&b[i];
	}
	return res;
}

vb diGraph::set_subst(vb &a,vb &b){
	vb res(a.size());
	for(int i=0;i<a.size();i++){
		res[i]=a[i]&&!b[i];
	}
	return res;
}

vb diGraph::neighbors(int n){
	Node *node=ver[n];
	vb res(ver.size(),false);
	vector<Node*> *in=node->getIn();
	vector<Node*> *out=node->getOut();
	//se consideran vecinos los que entran y salen a la vez
	for(int i=0;i<in->size();i++){
		for(int j=0;j<out->size();j++){
			if((*in)[i]==(*out)[j]){
				res[(*in)[i]->getIndex()]=true;
			}
		}
	}
	return res;
}

int diGraph::count(vb &a){
	int res=0;
	for(int i=0;i<a.size();i++){
		if(a[i]){
			res++;
		}
	}
	return res;
}

void diGraph::set_print(vb &a){	
	bool first=true;
	for(int i=0;i<a.size();i++){
		if(a[i]){			//nodo i-esimo forma parte del subconjunto
			Node *aux=ver[i];
			cout<<(first?"":" ")<<aux->getName();
			first=false;
		}
	}
	cout<<endl;
}

void diGraph::BK(vb R,vb P,vb X){
	if(count(P)==0 && count(X)==0){
		cliques.push_back(R);
	}
	for(int i=0;i<P.size();i++){
		if(P[i]){			// para cada nodo en set P...
			vb newR=R;
			newR[i]=true;
			vb neigh=neighbors(i);
			vb newP=set_inter(P,neigh);
			vb newX=set_inter(X,neigh);
			BK(newR,newP,newX);
			P[i]=false;
			X[i]=true;
		}
	}
}