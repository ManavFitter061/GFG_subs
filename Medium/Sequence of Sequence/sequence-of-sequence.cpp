//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int ans(int m,int n){
        if(m<n) return 0;
        if(n==0) return 1;
        
        return ans(m/2,n-1)+ans(m-1,n);
    }
    int numberSequence(int m, int n){
        // code here
        return ans(m,n);
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends