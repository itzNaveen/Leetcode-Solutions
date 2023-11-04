//{ Driver Code Starts
//Initial template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    int ExcelColumnNumber(string s)
    {
        int result=0, temp=1;
        for(int i=s.size()-1 ; i>=0 ; i--)
          {
              result+=(temp*(s[i]-'A'+1));
              temp*=26;
          }
        
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.ExcelColumnNumber(s)<<endl;
    }
}
// } Driver Code Ends