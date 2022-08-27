#include <bits/stdc++.h>
using namespace std;




void findShortestPathToAllNodesDjikstra(vector<pair<int,int>> adj[], int n, int source){
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[source]=0;
    pq.push({0, source});
    
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int wt = it.second;
            int adjNode = it.first;
            
            if(dis+wt<dist[adjNode]) {
                dist[adjNode] = dis+wt;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }
    // TO print the distance of source node to all other nodes.
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
        
    // To print the path of dest to source;
    
    int dest = n;
    vector<int> vec;
    while(dest!=-1){
        vec.push_back(dest);
        dest = parent[dest];
    }
    
    reverse(vec.begin(), vec.end());
    for(int i:vec)  cout<<i<<" ";
    
}


int main() {
    
    int n,m;
    cin>>n>>m;

    vector<pair<int, int>> adj[n+1];
    int u, v, w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v, w});    
        adj[v].push_back({u, w});
    }
    
    int source;
    cin>>source;
    
    findShortestPathToAllNodesDjikstra(adj, n, source);
        
    
	return 0;
}




// Input - 
// 6 9
// 1 2 4
// 2 4 3
// 4 6 6
// 1 3 2
// 2 3 1
// 3 4 5
// 3 5 1
// 4 5 1
// 5 6 3
// 1
// Output - 
// 0 3 2 4 3 6 
// 1 3 5 6 