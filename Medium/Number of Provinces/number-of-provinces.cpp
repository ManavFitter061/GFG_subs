//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int i,vector<int>&vis,vector<vector<int>>& isConnected){
        vis[i]=1;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1 && vis[j]==0){
                dfs(j,vis,isConnected);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n=adj.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,adj);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends