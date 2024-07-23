//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int i,int parent,vector<int> adj[],vector<int> &vis){
        vis[i]=1;
        for(int it:adj[i]){
            if(!vis[it]){
                if(dfs(it,i,adj,vis)==true) return true;
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
            if(dfs(i,-1,adj,vis)==1){
                return 1;
            }}
        }
        return 0;
    }
    
    
    // bool bfs(int i,vector<int> adj[],vector<int> &vis){
    //     queue<pair<int,int>> q;
    //     q.push({i,-1});
    //     vis[i]=1;
        
    //     while(!q.empty()){
    //         int curr=q.front().first;
    //         int prev=q.front().second;
    //         q.pop();
            
    //         for(auto it:adj[curr]){
    //             if(!vis[it]){
    //                 vis[it]=1;
    //                 q.push({it,curr});
    //             }
    //             else if(it!=prev){
    //                 return 1;
    //             }
    //         }
    //     }
    //     return 0;
    // }
    // bool isCycle(int V, vector<int> adj[]) {
    //     vector<int>vis(V,0);
    //     for(int i=0;i<V;i++){
    //         if(vis[i]==0){
    //             if(bfs(i,adj,vis)==1){
    //                 return 1;
    //             }
    //         }
    //     }
    //     return 0;
    // }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends