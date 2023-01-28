//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
   unordered_map<string, bool> mp;
    
    bool solve(string a, string b){
        // base case
            
        if(a.compare(b) == 0)
            return true;
        
        if(a.length() <= 1)
            return false;
        
        // making a key
        string key = a;
        key += ' ' + b;
        
        if(mp.find(key) != mp.end())
            return mp[key];
        
        int n = a.length();
        bool flag = false;
        for(int i=1; i<=n-1; i++){
            bool swap =  solve(a.substr(0, i), b.substr(n-i, i)) and solve(a.substr(i, n-i), b.substr(0, n-i));

            bool unswap = solve(a.substr(0, i), b.substr(0, i)) and solve(a.substr(i, n-i), b.substr(i, n-i));
            
            if(swap || unswap){
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
    
    bool isScramble(string S1, string S2){
        if(S1.length() != S2.length())
            return false;
        
        if(S1.empty() && S2.empty())
            return true;

        mp.clear();
        return solve(S1, S2);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends