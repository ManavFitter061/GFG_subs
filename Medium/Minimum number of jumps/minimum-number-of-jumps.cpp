//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  
    int minJumps(int arr[], int n){
        // Your code here
       
        if(n==1)return 0;
        if(arr[0]<1)return -1;
        if(arr[0]>=n-1)return 1;
        
        int count=0;
        int i=0;
        while(i<n-1)
        {
            int index=0;
            int maxi=INT_MIN;
            for(int j=i+1;j<=i+arr[i];j++)
            {
                if(maxi<j+arr[j])
                {
                    maxi=j+arr[j];
                    index=j;
                }
            }
            if(arr[index]==0) return -1;
            if(maxi>=n-1) return (count+=2);
            i=index;
            count++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends