//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    bool static comp(Item a, Item b){
        return (a.value/(1.0*a.weight))>=(b.value/(1.0*b.weight));
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your co>de here
        
        sort(arr,arr+n,comp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(w>=arr[i].weight){
                // cout<<arr[i].value<<"-"<<arr[i].weight<<endl;
                ans+=arr[i].value;
                w-=arr[i].weight;
            }
            else{
                // cout<<arr[i].value<<"-"<<arr[i].weight<<endl;
                ans=ans+(arr[i].value/(1.0*arr[i].weight))*w;
                return ans;
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends