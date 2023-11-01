//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution {
public:
    vector<int> matrixDiagonally(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;
        int n = matrix.size(), m = matrix[0].size();
        bool up = true;

        for (int sum = 0; sum <= n + m - 2; ++sum) {
            if (up) {
                for (int i = 0; i <= sum; ++i) {
                    int row = i;
                    int col = sum - i;
                    if (row < n && col < m) {
                        ans.push_back(matrix[col][row]);
                    }
                }
            } else {
                for (int i = 0; i <= sum; ++i) {
                    int row = sum - i;
                    int col = i;
                    if (row < n && col < m) {
                        ans.push_back(matrix[col][row]);
                    }
                }
            }
            up = !up;
        }

        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends