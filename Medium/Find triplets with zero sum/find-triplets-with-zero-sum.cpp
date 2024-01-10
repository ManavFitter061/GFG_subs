//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        
        if(n<3){
            return 0;
        }
        if(n==3){
            return (arr[0]+arr[2]+arr[1]==0);
        }
        sort(arr,arr+n);
        for(int i=0;i<n-2;i++){
            int x=i+1;
            int j=n-1;
         
            while (x < j) {
         
                if (arr[x] + arr[j] == -arr[i])
                    return 1;
         
                else if (arr[x] + arr[j] < -arr[i])
                    x++;
         
                else
                    j--;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends