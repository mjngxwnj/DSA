#include<iostream>
#include<vector>
using namespace std;
int vertices, edges; 
vector<int> adj[10001]; //vector save adjacency list
bool visited[10001]={}; //array marking vertices
int parent[10001]={}; //array marking parent 
int count = 0;

//input adjacency list
void input(){
	cin >> vertices >> edges;
	for(int i=0; i<edges; i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void Fill(int u){
    visited[u] = 1;
    for(int i=0; i<adj[u].size();i++){
        if(!visited[adj[u][i]]){
            Fill(adj[u][i]);
        }
    }
}
void Count_connected_component(){
    for(int i=1; i<=vertices; i++){
        if(!visited[i]){
            ++count;
            Fill(i);
        }
    }
}
int main(){
    input();
    /*1-----2-----3        5-----6
             \    |              |
              \__ 4              7
                      8-----9               */
    /*9 7
      1 2
      2 3
      2 4
      3 4
      5 6
      6 7
      8 9
      ouput: 3
    */
   Count_connected_component();
   cout<<"Connected component: "<<count<<endl;
}
