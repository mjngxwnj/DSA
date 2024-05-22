#include<iostream>
#include<vector>
using namespace std;
int vertices, edges; 
vector<int> adj[10001]; //vector save adjacency list
bool visited[10001]={}; //array marking vertices
int parent[10001]={}; //array marking parent 
//input adjacency list
void input(){
	cin >> vertices >> edges;
	for(int i=0; i<edges; i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
bool isCycle(int u){
    visited[u] = true;
    for(int i=0; i<adj[u].size();i++){
        if(!visited[adj[u][i]]){
            parent[adj[u][i]] = u;  
            if(isCycle(adj[u][i])) return true;
        }
        else if(adj[u][i]!=parent[u]) return true;
    }
    return false;
}
int main(){
    input();
    /*1-----2-----3-----4-----7 
                 / \
                8   5-----6*/
    /*8 7
      1 2 
      2 3
      3 4
      3 5 
      3 8
      4 7
      5 6 
      output: Graph doesn't contain cycle
    */
   /*1-----2-----3-----4-----7
            \          |
             6-------- 5*/
    /*7 7
      1 2 
      2 3 
      2 6 
      3 4 
      4 7 
      4 5 
      5 6 
      output: Graph contains cycle
    */
    isCycle(1)? cout<<"Graph contains cycle\n" : cout<<"Graph doesn't contain cycle\n";
}