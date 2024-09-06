//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int i , vector<vector<int>>& adj , vector<int>& vis, stack<int>& s){
	    vis[i]=1;
	    for(auto it: adj[i]){
	        if(!vis[it]) dfs(it, adj, vis,s);
	    }
	    s.push(i);
	}
	void dfs2(int i , vector<vector<int>>& adj , vector<int>& vis){
	    vis[i]=1;
	    for(auto it: adj[i]){
	        if(!vis[it]) dfs2(it, adj, vis);
	    }
	    
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V,0),vis2(V,0);
        stack<int> s;
        
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,vis,s);
        }
        
        vector<vector<int>> adj2(V);
        
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                adj2[it].push_back(i);
            }
        }
        
        int count=0;
        while(!s.empty()){
            int a=s.top();
            s.pop();
            
            if(!vis2[a]){
                dfs2(a,adj2,vis2);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends