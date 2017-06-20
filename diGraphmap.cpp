#include "diGraphmap.h"
#include <map>
using namespace std;

diGraphmap::diGraphmap(){

}

void diGraphmap::add(string u, string v){
	nodes[u] = 1;
	nodes[v] = 1;
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