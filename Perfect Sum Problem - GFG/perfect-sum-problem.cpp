//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
{
    int mod = (int) 1000000007;
    vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
    prev[0] = curr[0] = 1; // target becomes zero
    if(arr[0] <= sum) prev[arr[0]] = 1;
    
    if(arr[0] == 0) prev[0] = 2;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= sum; j++) {
            int notPick = prev[j];
            int pick = 0;
            if(arr[i] <= j)
                pick = prev[j - arr[i]];
            curr[j] = (pick + notPick) % mod;
        }
        prev = curr;
    }
    
    return prev[sum] % mod;
}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends