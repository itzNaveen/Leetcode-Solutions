//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
     vector<int> singleNumber(vector<int> nums) 
    {
       vector<int> ans;
       unordered_map<int,int> m;
       for(int i=0;i<nums.size();i++){
           m[nums[i]]++;
       }
       for(auto i: m){
           if(i.second==1){
               ans.push_back(i.first);
           }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends