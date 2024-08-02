//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        
        for(int i=0;i<M;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>vis(N);
        vector<int>dis(N,-1);
        queue<pair<int,int>>q;
        q.push({src,0});
        vis[src]=1;
        dis[src]=0;
        
        while(!q.empty()){
            int prev=q.front().first;
            int discov=q.front().second;
            if(dis[prev]==-1 || discov<dis[prev]){
                dis[prev]=discov;
            }
            q.pop();
            for(auto it:adj[prev]){
                if(!vis[it]){
                    q.push({it,discov+1});
                    vis[it]=1;
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends