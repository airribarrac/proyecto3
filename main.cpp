#include "diGraph.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	diGraph g;
	string fname;
	cout<<"Ingrese nombre de archivo a leer: ";
	cin>>fname;
	ifstream f(fname);
	while(!f){
		cout<<"Nombre invalido, ingrese otro: ";
		cin>>fname;
		f.open(fname);
	}
	string str;
	while(f>>str){
		if(str=="Add"){
			string u,v;
			f>>u>>v;
			g.add(u,v);
		}else if(str=="Find"){
			string u;
			f>>u;
			g.find(u);
		}else if(str=="Clique"){
			g.clique();
		}else if(str=="Compact"){
			g.compact();
		}else if(str=="Follow"){
			int n;
			f>>n;
			g.follow(n);
		}
	}
	return 0;
}