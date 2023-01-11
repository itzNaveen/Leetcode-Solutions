//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<int> ans;
        vector<bool>isPrime(n+1, true);
        for(int i = 2; i*i <= n; i++){
            for(int j = 2*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
        for(int i = 2; i<=n; i++){
            if(isPrime[i] == true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends