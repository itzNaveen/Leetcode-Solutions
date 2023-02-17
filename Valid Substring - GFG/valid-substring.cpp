//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string str) {
       stack<pair<char,int>> st;
       st.push({'.',0});
       for(int i=0;i<str.length();i++){
           char ch = str[i];
           if(ch=='('){
               st.push({ch,0});
           }
           else{
               if(st.top().first=='('){
                   int n = st.top().second;
                   st.pop();
                   st.top().second+=2+n;
               }else{
                   st.push({ch,0});
               }
           }
       }
       int maxt = INT_MIN;
       while(st.size()!=0){
           maxt = max(maxt,st.top().second);
           st.pop();
       }
       return maxt;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends