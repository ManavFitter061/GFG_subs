//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> rank,size,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        
        if(ulp_v==ulp_u){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            return;
        }
        else{
            parent[ulp_v]=parent[ulp_u];
            size[ulp_u]+=size[ulp_v];
            return;
        }
    }
    
    int findUpar(int n){
        if(n==parent[n]){
            return n;
        }
        
        return parent[n]=findUpar(parent[n]);
    }
    
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //PRIM ALGO
        // vector<int>vis(V,0);
        
        
        // priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // pq.push({0,0});
        
        // int ans=0;
        
        // while(!pq.empty()){
        //     int node=pq.top().second;
        //     int dis=pq.top().first;
        //     pq.pop();
            
            
        //     if(vis[node]) continue;
        //     if(!vis[node]){
        //         vis[node]=1;
        //         ans+=dis;
        //     }
            
        //     for(auto it: adj[node]){
        //         int newnode=it[0];
        //         int newdis=it[1];
        //         if(!vis[newnode]){
        //             pq.push({newdis,newnode});
        //         }
        //     }
        // }
        // return ans;
        
        
        //KRUSKAL ALGO
        
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int adjnode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjnode}});
                
                
                
            }
        }
        
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        
        int mst=0;
        
        for(auto it: edges){
            int w=it.first;
            int n1=it.second.first;
            int n2=it.second.second;
            // cout<<w<<"-"<<n1<<"-"<<n2<<endl;
            
            if(ds.findUpar(n1)!=ds.findUpar(n2)){
                mst+=w;
                // cout<<mst<<"-"<<w<<endl;
                ds.unionBySize(n1,n2);
            }
            
        }
        
        return mst;
        
        
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends