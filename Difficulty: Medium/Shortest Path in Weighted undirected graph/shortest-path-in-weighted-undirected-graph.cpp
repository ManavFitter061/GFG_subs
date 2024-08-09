//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
    //     vector<pair<int,int>>adj[n+1];
    //     for(auto it: edges){
    //         adj[it[0]].push_back({it[1],it[2]});
    //         adj[it[1]].push_back({it[0],it[2]});
    //     }
        
    //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
    //     vector<int>dis(n+1,1e9),parent(n+1);
        
    //     for(int i=1;i<=n;i++)
    //     {
    //         parent[i]=i;
    //     }
        
    //     dis[1]=0;
    //     parent[1] = 1;
    //     pq.push({0,1});
        
    //     while(!pq.empty()){
    //         auto it=pq.top();
    //         int dist=it.first;
    //         int node=it.second;
    //         pq.pop();
    //         cout<<" node="<<node<<"dist="<<dist<<endl;
            
    //         for(auto i:adj[node])
    //         {
    //             int adjnode = i.first;
    //             int w=i.second;
    //             if(dist+w < dis[adjnode]){
    //                 dis[adjnode]=dist+w;
    //                 pq.push({dist+w,adjnode});
    //                 parent[adjnode]=node;
                
    //             }
    //         }
    //     }
    //     if(dis[n]==1e9) return {-1};
    //     for(int i=0;i<parent.size();i++){cout<<parent[i]<<" ";}
    //     cout<<endl;
    //     vector<int>path;
    //     int node=n;
    //     while(parent[node]!=node){
    //         path.push_back(node);
    //         node=parent[node];
    //     }
    //     path.push_back(1);
    //     for(int i=0;i<path.size();i++){cout<<path[i]<<" ";}
    //     cout<<endl;
    //     reverse(path.begin(),path.end());
    //   // cout<<"hello";
    //     return path;
        vector<pair<int,int>> adj[n+1];
        int i;
        
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[1]=0;
        
        vector<int> parent(n+1);
        // for(i=0;i<=n;i++)
        //     parent[i]=i;
        
        parent[1]=1;
        
        // 0 min distance and node 1
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int nodeDistance = pq.top().first;
            int node =pq.top().second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int neighbourNode = it.first;
                int neighbourWeight = it.second;
                if(nodeDistance + neighbourWeight < dist[neighbourNode])
                {
                    dist[neighbourNode] = nodeDistance + neighbourWeight;
                    pq.push({dist[neighbourNode],neighbourNode});
                    parent[neighbourNode] = node;
                }
            }
        }
        
        int node=n;
        if(dist[n]==INT_MAX)
            return {-1};
        
        //cout<<dist[n]<<endl;
        vector<int> path;
        
        while(node!=parent[node])
        {
            path.push_back(node);    
            node=parent[node];
        }
        
        path.push_back(1);
        path.push_back(dist[n]);
        
        reverse(path.begin(),path.end());
        // for(auto it:path)
        //     cout<<it<<" ";
        return path;
    }
    
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends