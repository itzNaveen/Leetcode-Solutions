//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    return search(arr, 0, n - 1);
	}
	
	int search(int arr[], int L, int R) {
	    while (L < R) {
	        int mid = L + ((R - L) >> 1);
	        int cur = arr[mid], next = arr[mid + 1];
	        
	        if (cur < next)
	            L = mid + 1;
	        else
	            R = mid;
	    }  
	    
	    return arr[L];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends