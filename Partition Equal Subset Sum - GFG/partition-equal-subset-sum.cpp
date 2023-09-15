//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int subsetSum(int n,int arr[],int sum,vector<vector<int>>&dp){
    if(n==0)
        return 0;
    if(sum==0)
        return 1;
    
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    
    if(arr[n-1]<=sum){
        return dp[n][sum] = subsetSum(n-1,arr,sum-arr[n-1],dp)||subsetSum(n-1,arr,sum,dp);
    }
    else
        return dp[n][sum] = subsetSum(n-1,arr,sum,dp);
}
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum =0;
        for(int i =0; i<n;i++){
            sum+=arr[i];
        }
        
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
        
        if(sum%2!=0)
            return 0;
        else
            return subsetSum(n,arr,sum/2,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends