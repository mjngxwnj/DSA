#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
    int u, v, w; 
    Edge(int s, int d, int w) : u(s), v(d), w(w) {}
};
vector<Edge> Edges;//List of edge
vector<Edge> MST; //Storing edges of Minimum Spanning Tree
int total_weight = 0;//weight of MST
int parent[10001]={}; //array marking parent 
int rnk[10001]={};//array storing rank of sets
int vertices, edges;
void input(){
    cin >> vertices >> edges;
	for(int i=0; i<edges; i++){
		int x,y,w; cin>>x>>y>>w;
        Edge e = Edge(x,y,w);
        Edges.push_back(e);
	}
}
//function for sorting edges by weight
bool compareEdge(Edge e1, Edge e2){
    return e1.w < e2.w;
}
//function to make Disjoint Set Union
void DSU(){
    for(int i=1; i<=vertices; i++){
        parent[i] = i;
        rnk[i] = 1;
    }
}
//find set that vertex u belongs to
int Find(int u){
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}
//Merge to disjoint set
void Union(int x,int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        if(rnk[x] < rnk[y]){
            parent[x] = y;
        }
        else if(rnk[x] > rnk[y]){
            parent[y] = x;
        }
        else{
            parent[x] = y;
            rnk[y]++;
        }
    }
}
//Kruskal Algorithm
void Kruskal_algorithm(){
    DSU();
    sort(Edges.begin(),Edges.end(),compareEdge);//sort edges by weight ascending
    for(int i=0; i<edges; i++){
        int u = Edges[i].u, v = Edges[i].v;
        int SetU = Find(u), SetV = Find(v);
        if(SetU != SetV){
            MST.push_back(Edges[i]);
            Union(SetU,SetV);
            total_weight += Edges[i].w;
        }
        if(MST.size() == vertices - 1) break; //complete MST
    }
}
void output(){
    cout<<"Weight of Minimum Spanning Tree: "<<total_weight<<endl;
    cout<<"List of edges:\n";
    for(int i=0; i<MST.size(); i++){
        cout<<"("<<MST[i].u<<","<<MST[i].v<<") "<<"Weight: "<<MST[i].w<<endl;
    }
}
int main(){
    input();
    Kruskal_algorithm();
    output();
}