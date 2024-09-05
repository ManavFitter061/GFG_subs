//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
  public:
    vector<int> rank,size,parent;
    DisjointSet(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUpar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
            return;
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            return;
        }

    }
};


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<int>ans;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        int freq=0;
        
        for(auto it: operators){
            int x=it[0];
            int y=it[1];
            if(grid[x][y]==1){
                ans.push_back(freq);
                continue;
            }
            grid[x][y]=1;
            
            freq++;
            
            
            // cout<<x<<"-"<<y<<":"<<endl;
            for(int i=0;i<4;i++){
                int newx=x+dr[i];
                int newy=y+dc[i];
                // cout<<newx<<" - "<<newy<<endl;
                if(newx<n && newy<m &&newx>=0 && newy>=0 && grid[newx][newy]==1){
                    
                    if(ds.findUpar(x*m+y)!=ds.findUpar(newx*m+newy)){
                        ds.unionBySize(x*m+y,newx*m+newy);
                        // freq=max(--freq,1);
                        freq--;
                    }
                }
            }
            
            ans.push_back(freq);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends