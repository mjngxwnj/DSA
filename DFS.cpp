#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<long>adj[100001];
bool check[100001];
int cnt=1;
 void dfs(int u){
	++cnt;
	check[u]=true;
	for(int i=0;i<adj[u].size();i++){
		if(!check[adj[u][i]]){
			dfs(adj[u][i]);
		}
	}
} 
void bfs(int u){
	queue<int> q;
	q.push(u);
	check[u]=true;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int i=0;i<adj[v].size();i++){
			if(!check[adj[v][i]])
			{
					q.push(adj[v][i]);
				check[adj[v][i]]=true;
				++cnt;}
		}
	}
}
int main()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		for(int j=1;j<=x;j++){
			int res; cin>>res;
			adj[i].push_back(res);
			//adj[res].push_back(i);
		}
	}	
	memset(check,false,sizeof(check));
	bfs(k);
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++){
		if(check[i]) {
			cout<<i<<" ";
		}
	}
/*	for(int i=0;i<adj[1].size();i++)
	cout<<adj[1][i]<<" "; */
}
