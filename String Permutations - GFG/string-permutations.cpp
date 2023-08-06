//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string>solve(string s, vector<string> &ans, int idx){
        // Base Case
        if(idx >= s.length()) ans.push_back(s);
        
        //Permutation
        for(int i = idx; i<s.length(); i++){
            swap(s[idx],s[i]);
            solve(s,ans,idx+1);
            swap(s[idx],s[i]);
        }
        return ans;
    }
    vector<string> permutation(string S)
    {
        vector<string>ans;
        solve(S,ans,0);
        sort(ans.begin(),ans.end());
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
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends