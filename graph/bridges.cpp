#include <bits/stdc++.h>
using namespace std;




void findBridgesRecursive(int source, vector<int> adj[], vector<bool> &visited, int& timer, vector<int> &tin, vector<int> &low, int par = 0){
    visited[source] = 1;
    tin[source] = low[source] = ++timer; 
    
    for(int it: adj[source]){
        if(it==par) continue;
        
        if(visited[it]){
            low[source] = min(low[source], tin[it]);
        }else{
            findBridgesRecursive(it, adj, visited, timer, tin, low, source);
            low[source] = min(low[source], low[it]);
            // cout<<low[it]<<" "<<tin[source]<<endl;
            if(low[it]>tin[source]){
                cout<<source<<" "<<it<<endl;
            }
        }
        
        
        
        
        
    }
    
    
}

// bridges in graph
void findBridges(vector<int> adj[], int n){
    vector<bool> visited(n+1, false);
    vector<int> tin(n+1, INT_MAX), low(n+1, INT_MAX);
    int timer = 0;
    
    for(int i=1;i<=n;i++)
        if(visited[i]==false)
            findBridgesRecursive(i, adj, visited, timer, tin , low);
}

int main() {
    
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    int u, v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);    
        adj[v].push_back(u);
    }
    
    findBridges(adj, n);
	return 0;
}



// Input - 
// 9 9
// 1 2
// 2 3
// 3 4
// 4 5
// 4 6
// 5 6
// 7 8
// 8 9
// 8 3
// Output - 
// 3 4
// 8 7
// 8 9
// 3 8
// 2 3
// 1 2