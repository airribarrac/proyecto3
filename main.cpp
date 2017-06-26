#include "diGraph.h"
#include <iostream>

using namespace std;

int main(){
	diGraph g;
	string fname;
	cout<<"Ingrese nombre de archivo a leer: ";
	cin>>fname;
	ifstream f(fname);
	string str;

	while(f>>str){
		if(str=="Add"){
			string u,v;
			cin>>u>>v;
			g.add(u,v);
		}else if(str=="Find"){
			string u;
			cin>>u;
			g.find(u);
		}else if(str=="Clique"){
			g.clique();
		}else if(str=="Compact"){
			g.compact();
		}else if(str=="Follow"){
			int n;
			cin>>n;
			g.follow(n);
		}
	}
	return 0;
}