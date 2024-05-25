#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[10001]; //vector save adjacency list
bool color[10001]={}; //array marking vertices by colors
int vertices, edges;
//input adjacency list
void input(){
	cin >> vertices >> edges;
	for(int i=0; i<edges; i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
	}
}
bool directed_graph_is_cyclic(int u){
	color[u] = 1;
	for(int i=0; i<adj[u].size(); i++){
		if(color[adj[u][i]] == 1) return true;
		if(color[adj[u][i]] == 0 && directed_graph_is_cyclic(adj[u][i])) return true;
	}
	color[u] = 2;
	return false;
}
bool detect_cycle(){
	for(int i=1; i<=vertices; i++){
		if(!color[i]){
			if(directed_graph_is_cyclic(i)) return true;
		}
	}
	return false;
}
int main(){
	input();
	detect_cycle() ? cout<<"Directed Graph contains cycle" : cout<<"Directed Graph doesn't contain cycle";
	/* 1 ⟶ 2 ⟶ 3 
	   ↑    ↓      ↘
	   7 ⟵ 6        4 ⟶ 5 */
	/* 7 7
	   1 2 
	   2 3
	   2 6
	   3 4 
	   4 5
	   6 7 
	   7 1
	   output: Directed Graph contains cycle
	*/
}