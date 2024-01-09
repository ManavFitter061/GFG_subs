//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            string temp;
            int n=txt.size();
            int m=pat.size();
            vector<int> ans;
            // if(m>n){
            //     return ans;
            // }
            // if(m==n){
            //     if(txt==pat){
            //         ans.push_back(1);
            //         return ans;
            //     }
            // }
            // for (int i = 0; i < m; i++){
            //     temp.push_back(txt[i]);
            // }
            // if(temp==pat){
            //     ans.push_back(1);
            // }
            // for(int i=m;i<n;i++){
            //     char c=temp.erase(temp.begin());
            //     temp.push_back(txt[i]);
            //     if(temp==pat){
            //         ans.push_back(i-m+2);
            //     }
            // }
            for(int i=0;i<=n-m;i++){
                if(txt[i]==pat[0]){
                    temp=txt.substr(i,m);
                    if(temp==pat){
                        ans.push_back(i+1);
                    }
                }
            }
            
            
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends