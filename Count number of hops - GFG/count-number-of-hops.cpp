//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        long long prev = 1, prev2 = 0, prev3 = 0, mod = 1e9+7;
        for(int i = 1; i<=n; i++){
            long long curr = 0;
            if(i-1 >=0) curr = (curr+prev)%mod;
            if(i-2>=0) curr = (curr+prev2)%mod;
            if(i-3>=0) curr = (curr+prev3)%mod;
            prev3 = prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
        
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