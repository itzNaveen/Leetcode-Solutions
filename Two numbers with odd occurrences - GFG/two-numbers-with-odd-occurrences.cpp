//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        vector<long long int>ans;
        int Xor = 0, res1 = 0, res2 = 0;
        for(int i = 0; i<n; i++){
            Xor ^= arr[i];
        }
        int sn = Xor & ~(Xor-1);
        for(int i = 0; i<n; i++){
            if((arr[i]&sn) != 0){
                res1 = res1^arr[i];
            }else{
                res2 = res2^arr[i];
            }
        }
        if(res1<res2){
            swap(res1,res2);
        }
        ans.push_back(res1);
        ans.push_back(res2);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends