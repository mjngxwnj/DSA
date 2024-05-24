#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> adj[10001]; //vector save adjacency list
bool visited[10001]={}; //array marking vertices
int degree[10001]={}; //array save degree of vertices 
vector<int> topo; //vector to store answer of topological sorting
int vertices, edges;
//input adjacency list
void input(){
	cin >> vertices >> edges;
	for(int i=0; i<edges; i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		++degree[y];
	}
}
//NOTE THAT KAHN ALGORITHM IS ONLY USED FOR DIRECTED ACYCLIC GRAPH
void Kahn_algorithm(){
	queue<int> q; //queue to store vertices with degree = 0
	//init
	for(int i=1; i<=vertices; i++){
		if(!degree[i]) q.push(i);
	}
	// push and pop vertices
	while(!q.empty()){
		int curr = q.front(); q.pop();
		topo.push_back(curr);
		for(int i=0; i<adj[curr].size(); i++){
			if(--degree[adj[curr][i]] == 0){
				q.push(adj[curr][i]);
			}
		}
	}
}
int main(){
	input();
	Kahn_algorithm();
	cout<<"Topo sort: ";
	for(int i=0; i<topo.size(); i++){
		cout<<topo[i]<<" ";
	}
	/* 1⮕⮕⮕⮕2⮕⮕⮕⮕⮕3⮕⮕⮕⮕5 
	   ⬇       ️⬇         ⬇      
	   6	   4 ⬅ 7    8 ⮕ 9    	*/
	/*9 8
	  1 2 
	  1 6
	  2 3 
	  2 4 
	  3 5 
	  3 8 
	  7 4
	  8 9 
	  ouput: Topo sort: 1 7 2 6 3 4 5 8 9 
	*/
				             
}