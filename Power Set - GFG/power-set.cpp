//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    int n = pow(2,s.length());
		    for(int  i=1;i<n;i++){
		       string str  = "";
		       int pos = 0;
		       int run = i;
		       while(run){
		           if(run&1){
		               str+=s[pos];
		           }
		           pos++;
		           run = run>>1;
		       }
		       ans.push_back(str);
		       str = "";
		    }
		    sort(ans.begin(),ans.end());
		    
		    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends