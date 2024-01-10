//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    map<int,int> track;
	    int ans=0;
	    track.insert({0,-1});
	    vector<int> sum,remn;
	    int gus=0;
	    int rem;
	    for(int i=0;i<n;i++){
	        gus+=arr[i];
	        sum.push_back(gus);
	        rem=gus%k;
	        remn.push_back(rem);
	        
	        if(rem<0){
	            rem+=k;
	        }
	        if(track.find(rem)!=track.end()){
	            int index=track[rem];
	            int length=i-index;
	            if(length>ans){
	                ans=length;
	            }
	                
	        }
	        else{
	            track.insert({rem,i});
	        }
	        
	    }
	    
	    return ans;
	    
	    
	   // for(int i=0;i<n;i++){
	   //     cout<<sum[i]<<" ";
	   
	   // }
	   // cout<<endl;
	   // for(int i=0;i<n;i++){
	   //     cout<<remn[i]<<" - ";
	   // }
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends