#include<iostream>
#include<vector>
using namespace std;

bool visited[10001]={}; //Array marking vertices
int vertices, edges;
vector<int> adj[10001]; //vector save adjacency list
//input adjacency list
void input(){
	cin >> vertices >> edges;
	for(int i=0; i<edges; i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
//DFS function
void DFS(int u){
	cout<<u<<" ";
	visited[u] = true; //marking vertice u is visited
	for(int i=0; i<adj[u].size();i++){
		//check adjacent vertices
		if(!visited[adj[u][i]]){
			DFS(adj[u][i]);
		}
	}
}
int main(){
	input();
	/*1-----2-----3-----6
	  |	      |	    |
	  9	      |     8
		      4---5---7*/
	/*9 8
	  1 2
	  1 9
	  2 3
	  2 4
	  3 6
	  3 8 
	  4 5
	  5 7
	  ouput: 1 2 3 6 8 4 5 7 9 
	*/
	DFS(1);
}
