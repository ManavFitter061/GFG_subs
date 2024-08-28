//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
    int n=arr.size();
    int k=2;    
    int head=-1,tail=0;
    int ans=0;

    int cnt=0;
    int freq[100100];

    while(tail<n){
        while(head+1<n && (cnt<k || freq[arr[head+1]]>=1 )){
            head++;
            
            if(freq[arr[head]]==0){
                cnt++;
            }
            freq[arr[head]]++;
        }

        ans=max(ans,(head-tail+1));

        if(tail>head){
            tail++;
            head=tail-1;
        }

        else{
            freq[arr[tail]]--;
            if(freq[arr[tail]]==0){
                cnt--;
            }
            tail++;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends