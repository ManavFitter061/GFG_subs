//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
  public:
    // void dfs(int i, int discov, vector<vector<pair<int,int>>>& adj,vector<int>&dis){
    //     if(dis[i]==-1){
    //         dis[i]=discov;
    //     }
    //     else {
    //         dis[i]=min(discov,dis[i]);
    //     }
        
        
    //     for(auto it : adj[i]){
    //         dfs(it.first,discov+it.second,adj,dis);
    //     }
    // }
    void toposort(int i,vector<vector<pair<int,int>>>& adj,vector<int>&vis,stack<int>&s){
        vis[i]=1;
        for(auto it: adj[i]){
            int v=it.first;
            if(!vis[v]){
                toposort(v,adj,vis,s);
            }
        }
        s.push(i);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        stack<int> s;
        vector<int>dis(N,-1);
        vector<int>vis(N);
        dis[0]=0;
        // dfs(0,0,adj,dis);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                toposort(i,adj,vis,s);
            }
        }
        
        while(s.top()!=0){
            s.pop();
        }
        
        
        
        while(!s.empty()){
            int prev=s.top();
            s.pop();
            
            for(auto it:adj[prev]){
                int v=it.first;
                int wt=it.second;
            
                if(dis[v]==-1 || dis[prev]+wt<dis[v]){
                    dis[v]=dis[prev]+wt;
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends