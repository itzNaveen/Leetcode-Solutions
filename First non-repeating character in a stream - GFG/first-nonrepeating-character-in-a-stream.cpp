//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		   int n=str.size();
		   unordered_map<char,int>mp;
		   queue<char>q;
		   string ans;
		    for(int i=0;i<n;i++){
		        mp[str[i]]++;
		        if(mp[str[i]]==1)
		            q.push(str[i]);
		        while(!q.empty() and mp[q.front()]>1)
		            q.pop();
		            
		      q.empty()?ans+='#' : ans+=q.front();
		    }
        return ans;		    
		}

};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends