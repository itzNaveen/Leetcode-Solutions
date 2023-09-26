//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                int remain = target - nums[i] - nums[j];
                int st = j+1, end = n-1;
                while(st<end)
                {
                    if(nums[st] + nums[end] == remain)
                    {
                        ans.push_back({nums[i], nums[j], nums[st], nums[end]});
                        ++st;
                        --end;
                        while(st<end and nums[st-1] == nums[st]) ++st;
                    }
                    else if(nums[st] + nums[end] < remain)
                    {
                        ++st;
                    }
                    else{
                        --end;
                    }
                }
                while(j+1<n and nums[j] == nums[j+1]) ++j;
            }
            while(i+1<n and nums[i] == nums[i+1]) ++i;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends