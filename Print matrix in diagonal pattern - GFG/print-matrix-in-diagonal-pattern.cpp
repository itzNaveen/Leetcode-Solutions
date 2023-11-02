//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        vector<int>ans;
        bool up = true;
        int n = mat.size(), m = mat[0].size();
        for(int i =0; i<=n+m-1; i++){
            if(up){
                for(int j = 0; j<=i; j++){
                    int row = i-j;
                    int col = j;
                    if(row<n && col<m) ans.push_back(mat[row][col]);
                }
            }
            else{
                for(int j = 0; j<=i; j++){
                    int row = j;
                    int col = i-j;
                    if(row<n and col<m) ans.push_back(mat[row][col]);
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