#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
vector<int> adj[10001], reverse_adj[10001]; //vector save adjacency list 
bool visited[10001]={}; //array marking vertices
stack<int> st; //storing topo sorting values of graph
vector<vector<int>> ans; //storing answer
int vertices, edges;
void input(){
    cin >> vertices >> edges;
	for(int i=0; i<edges; i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
        reverse_adj[y].push_back(x); //making transpose graph
	}
}
void fill_graph(int u){
    visited[u] = 1;
    for(int i=0; i<adj[u].size();i++){
        if(!visited[adj[u][i]]){
            fill_graph(adj[u][i]);
        }
    }
    st.push(u);
}
void fill_traverse_graph(int u, vector<int>&SCC){
    visited[u] = 1;
    SCC.push_back(u);
    for(int i=0; i<reverse_adj[u].size(); i++){
        if(!visited[reverse_adj[u][i]]){
            fill_traverse_graph(reverse_adj[u][i],SCC);
        }
    }
}
//Using Kosaraju Algorithm to find strongly connected component
//Step 1: Perform a DFS to fill the stack
//Step 2: Transpose the Graph(can build by input function)
//Step 3: Using DFS to traverse transpose graph base on topo stack 
void Kosaraju_algorithm(){
    //fill graph & store topo stack
    for(int i=1; i<=vertices; i++){
        if(!visited[i]){
            fill_graph(i);
        }
    }
    //reset visited array
    fill(visited, visited + vertices + 1, 0);
    //traverse transpose graph using DFS base on topo stack
    while(!st.empty()){
        int curr = st.top(); st.pop();
        if(!visited[curr]){
            vector<int> SCC;
            fill_traverse_graph(curr,SCC);
            ans.push_back(SCC);
        }
    }
}
void ouput(){
    cout<<"List of strongly connected component:\n";
    for(int i=0; i<ans.size();i++){
        cout<<i+1<<": ";
        for(int j=0; j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    input();
    Kosaraju_algorithm();
    ouput();
    /* 1 ⟶ 2         
       ↑    ↓         
       4 ⟵ 3 ⟶ 5 ⟶ 6 ⟵ 8    
                        ↘  ↗
                          7
    */
    /*
    8 9
    1 2 
    2 3 
    3 4 
    4 1
    3 5 
    5 6 
    6 7 
    7 8 
    8 6 
    ouput: List of strongly connected component:
            1: 1 4 3 2
            2: 5
            3: 6 8 7
    */
}