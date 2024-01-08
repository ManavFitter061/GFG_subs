//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        // map<int,int> d;
        // for(int i=0;i<size;){
        //     d[a[i]]++;
        // }
        // for(auto it: d){
        //     if(it.second>(size/2)){
        //         return it.first;
        //     }
        // }
        
        // return -1;
        
        if(size==1){
            return a[0];
        }
        sort(a,a+size);
        int ans=1;
        for(int i=1;i<size;i++){
            if(a[i]==a[i-1]){
                ans++;
            }
            if(a[i]!=a[i-1]){
                ans=1;
            }
            if(ans>size/2){
                return a[i];
            }
        }
        
        return -1; 
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends