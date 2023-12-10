//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) {
        vector<int>smaller(n);
        vector<int>right(n);
        
        int minIndex = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] <= arr[minIndex]) minIndex = i;
            smaller[i] = minIndex;
        }
        int maxIndex = n-1;
        for(int i = n-1; i>=0; i--){
            if(arr[i]>=arr[maxIndex]) maxIndex = i;
            right[i] = maxIndex;
        }
        // cout<<"Smaller elements: "<<endl;
        // for(auto it : smaller) cout<<it<<" ";
        // cout<<endl;
        // cout<<"Greater elements: "<<endl;
        // for(auto it : smaller) cout<<it<<" ";
        // cout<<endl;
        for(int i = 0; i<n; i++){
            if(smaller[i] != i && right[i] != i){
                return {arr[smaller[i]], arr[i], arr[right[i]]};
            }
        }
        return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends