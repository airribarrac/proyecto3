#include "diGraphmap.h"
#include <map>
using namespace std;

diGraphmap::diGraphmap(){

}

void diGraphmap::add(string u, string v){
	nodes[u] = true;
	nodes[v] = true;
}

bool diGraphmap::find(string s){
	cout << (nodes[s]?"Yes":"No") << endl;
	return nodes[s];
}
void diGraphmap::clique(){

}
void diGraphmap::compact(){

}
void diGraphmap::follow(){

}