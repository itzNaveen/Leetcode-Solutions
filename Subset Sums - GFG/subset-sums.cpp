//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private:
    void Solve(int ind,int sum, vector<int>&arr, int n, vector<int>&ans){
        if(ind == n){
            ans.push_back(sum);
            return ;
        }
        
        // Picking the element
        Solve(ind+1, sum + arr[ind], arr,n,ans);
        
        // Not picking the element
        Solve(ind+1, sum, arr, n, ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int>ans;
        Solve(0,0,arr,n,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends