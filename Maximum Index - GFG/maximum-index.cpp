//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        //Make two vectors one for minimum and other for maximum
        vector<int>vmin(n), vmax(n);
        vmin[0] = arr[0];
        vmax[n-1] = arr[n-1];
        for(int i = 1; i<n; i++){
            vmin[i] = min(vmin[i-1],arr[i]);
            vmax[n-i-1] = max(vmax[n-i],arr[n-i-1]);
        }
        
        // Now check for the value using these two vectors
        int ans = 0, i = 0, j = 0;
        while(i<n && j<n){
            if(vmin[i]<=vmax[j]){
                ans = max(ans,j-i);
                j++;
            }else i++;
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends