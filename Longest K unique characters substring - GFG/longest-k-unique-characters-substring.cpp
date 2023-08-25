//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        map<char,int>m;
        int i=0,j=0,ans=-1,cnt=0;
        while(j<s.size()){
            m[s[j]]++;
            if(m[s[j]]==1)cnt++;
            if(cnt<k)j++;
            else if(cnt==k){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                while(cnt>k){
                    m[s[i]]--;
                    if(m[s[i]]==0)cnt--;
                    i++;
                }
                j++;
            }   
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends