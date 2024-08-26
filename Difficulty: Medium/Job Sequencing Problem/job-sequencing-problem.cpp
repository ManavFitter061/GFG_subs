//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    bool static comp(Job a,Job b){
        if(a.profit>b.profit){
            return true;
        }
        else return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> ans;
        int count=0;
        int tp=0;
        
        sort(arr,arr+n,comp);
        int maxdl=0;
        for(int i=0;i<n;i++){
            maxdl=max(arr[i].dead,maxdl);
        }
        vector<int> hash(maxdl+1,-1);
        
        for(int i=0;i<n;i++){
            // cout<<arr[i].dead<<"-"<<arr[i].profit<<":";
            for(int j=arr[i].dead ;j>0;j--){
                // cout<<"("<<hash[j]<<")";
                if(hash[j]==-1){
                    count++;
                    hash[j]=arr[i].id;
                    tp+=arr[i].profit;
                    break;
                }
            }
            // cout<<endl;
            
            
        }
        return {count,tp};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends