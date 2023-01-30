//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        set<string> ans;
        int n=s.length();
        vector<vector<bool>> v(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            v[i][i]=true;
            ans.insert(s.substr(i,1));
        }
        for(int len=1;len<n;len++)
        {
            for(int i=0;i+len<n;i++)
            {
                if(s[i]==s[i+len]&&(i+1<=i+len-1?v[i+1][i+len-1]:true))
                {ans.insert(s.substr(i,len+1));
                v[i][i+len]=true;
                }
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends