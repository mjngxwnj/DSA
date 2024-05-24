#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> adj[10001]; //vector save adjacency list
bool visited[10001]={}; //array marking vertices
int parent[10001]={}; //array marking parent
int shortest_path[10001]={}; //array save shortest path from source
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
void Find_shortest(int &source){
    //first vertice
	queue<int> q;
	q.push(source);
	visited[source] = true;
	//loop
    while(!q.empty()){
		int curr = q.front(); q.pop();
		for(int i=0; i<adj[curr].size();i++){
			if(!visited[adj[curr][i]]){
                		parent[adj[curr][i]] = curr;
                		shortest_path[adj[curr][i]] = shortest_path[curr] + 1;
				visited[adj[curr][i]] = 1;
                		q.push(adj[curr][i]);
			}
		}
	}
}
void Print_shortest_path(int &source, int &dest){
    vector<int> path;
    while(source!=dest){
        path.push_back(dest);
        dest = parent[dest];
    }
    cout<<"Path: "<<source<<" ";
    for(int i=path.size()-1; i>=0; i--){
        cout<<path[i]<<" ";
    }
}
int main(){
    input();
    // source & destination vertex
    int source, dest; 
    cout<<"Input source and destination: ";
    cin >> source >> dest;
    /*  1---2-----3-----5
         \   \           \
          \   4-----------9
           \             /
            6-----7-----8           */
    /*9 10
    1 2 
    1 6
    2 3
    2 4 
    3 5 
    4 9
    5 9 
    6 7 
    7 8 
    8 9 
    input source and destination: 1 9
    output: 3
    path: 1 2 4 9
    */
   Find_shortest(source);
   cout<<"Shortest path from "<<source<<" to "<<dest<<": "<<shortest_path[dest]<<endl;
   Print_shortest_path(source, dest);
}
