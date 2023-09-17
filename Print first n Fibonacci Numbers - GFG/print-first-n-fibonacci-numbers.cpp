//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
   long long solve(int n,vector<long long> &dp)

    {

        if(n==0||n==1)    return dp[n]=n;

        if(dp[n]!=0)   return dp[n];

        

        return dp[n]=solve(n-1,dp)+solve(n-2,dp);

    }

    vector<long long> printFibb(int n) 

    {

        vector<long long>dp(n+1,0);

        solve(n,dp);

        dp.erase(dp.begin());

        return dp;

    }
};


//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends