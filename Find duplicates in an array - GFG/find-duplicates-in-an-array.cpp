//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        unordered_map<int,int> mp;
        vector<int> ans ;
        vector<int> temp{-1};
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto it: mp)
        {
            if(it.second >= 2)
            {
                ans.push_back(it.first);
                count++;
            }
        }
        sort(ans.begin(),ans.end());
        if(count>=1)
           return ans;
        else
          return temp;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends