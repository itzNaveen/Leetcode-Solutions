//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
     

long long countWays(int n){

        

        long long modulo = 1000000007;

        vector<long long int>dp(n+1);

 

        dp[0]=1;

        dp[1]=1;

        dp[2]=2;

        for(long long int i=3;i<=n;i++){

            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%modulo;

        }

 

        return dp[n];

    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends