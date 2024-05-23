#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> adj[10001]; //vector save adjacency list
bool visited[10001]={}; //array marking vertices
int vertices, edges;
//input adjacency list
void input(){
	cin >> vertices >> edges;
	for(int i=0; i<edges; i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
//BFS function
void BFS(int u){
	//first vertice
	queue<int> q;
	q.push(u);
	visited[u] = true;
	//loop
	while(!q.empty()){
		int curr = q.front(); q.pop();
		cout<<curr<<" ";
		for(int i=0; i<adj[curr].size();i++){
			if(!visited[adj[curr][i]]){
				q.push(adj[curr][i]);
				visited[adj[curr][i]] = 1;
			}
		}
	}
}
int main(){
	input();
	BFS(1);
	/*1-----2-----5-----6
	  |\  	      |
	  4 3         7-----8
	   	      |
		      9*/
	/*9 8
	  1 2
	  1 3
	  1 4
	  2 5
	  5 6
	  5 7 
	  7 8
	  7 9
	  output: 1 2 3 4 5 6 7 8 9 
	*/
}