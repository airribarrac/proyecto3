#include "diGraph.h"
#include <queue>
#include <vector>
#include <sstream>
#include <algorithm>

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
	diGraph compacted;
	vector<vb> vnodes;
	vector<string> names;
	vector<int> indexes(n);
	int x=0;
	int z=1;				//clique actual
	vector<int> vindex(n,-1);	//
	for(int i=0;i<cliques.size();i++){
		vb cli=set_subst(cliques[i],visited);
		if(count(cli)<3){		//si quedo un clique muy chico se salta
			continue;
		}
		vnodes.push_back(cli);  //almacenar los nodos virtuales validos
		visited=set_union(visited,cli);
		stringstream ss;
		ss<<"C"<<z++;
		string vname=ss.str();
		names.push_back(vname);
		for(int j=0;j<cli.size();j++){	//marcar nodos del clique con su nombre e indice
			if(cli[j]){
				
				vindex[j]=z-2;
				indexes[j]=x;
			}
		}
		x++;
	}
	
	for(int i=0;i<n;i++){
		if(visited[i]){
			continue;
		}
		//marcar nodos no visitados con su nombre;
		names.push_back(ver[i]->getName());
		indexes[i]=x++;
	}
	/*
	vector<vb> vin(vnodes.size(),vb(n,false));		//aristas entrando a un clique
	vector<vb> vout(vnodes.size(),vb(n,false));		//aristas saliendo de un clique
	for(int i=0;i<vnodes.size();i++){		//i-esimo clique
		for(int j=0;j<n;j++){				//para cada nodo del clique
			if(!vnodes[i][j]){
				continue;
			}
			Node *aux=ver[j];
			for(int k=0;k<aux->getOut()->size();k++){
				Node *sale=(*(aux->getOut()))[k];
				if(vnodes[i][sale->getIndex()]){	//el que sale esta dentro del clique
					continue;
				}
				vout[i][sale->getIndex()]=true;		//ese nodo sale
			}
			for(int k=0;k<aux->getIn()->size();k++){
				Node *sale=(*(aux->getIn()))[k];
				if(vnodes[i][sale->getIndex()]){	//el que entra esta dentro del clique
					continue;
				}
				vin[i][sale->getIndex()]=true;		//ese nodo entra
			}
		}
	}*/
	vector<vb> matrix(x,vb(x,false));	//matriz de adyacencia
	for(int i=0;i<ver.size();i++){
		Node *u=ver[i];
		int U=u->getIndex();
		int uu=indexes[U];
		for(int j=0;j<u->getOut()->size();j++){
			Node *v=(*(u->getOut()))[j];
			int V=v->getIndex();
			int vv=indexes[V];
			matrix[uu][vv]=true;
		}
	}
	vector<pair<string,string> > edges;
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(matrix[i][j] && i!=j){
				edges.push_back(make_pair(names[j],names[i]));
			}
		}
	}
	sort(edges.begin(),edges.end());
	for(int i=0;i<edges.size();i++){
		cout<<"("<<edges[i].first<<","<<edges[i].second<<")"<<endl;
	}
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
	if(count(P)==0 && count(X)==0 && count(R)>2){
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