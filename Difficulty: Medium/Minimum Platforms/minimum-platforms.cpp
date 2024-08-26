//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,char>>ans;
    	for(int i=0;i<n;i++){
    	    ans.push_back({arr[i],'A'});
    	    ans.push_back({dep[i],'D'});
    	}
    	sort(ans.begin(),ans.end());
    	
    	int maxcount=0;
        // int l=0;r=0;
        int count=0;
    	
    	for(int i=0;i<2*n;i++){
    	    if(ans[i].second=='A'){
    	        count++;
    	    }
    	    else if(ans[i].second=='D'){
    	        count--;
    	    }
    	    maxcount=max(count,maxcount);
    	}
        
        // while(r<n-1){
        //     for(int i=l;i<=r;i++){
        //         if()
        //     }
        // }
    	return maxcount;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends