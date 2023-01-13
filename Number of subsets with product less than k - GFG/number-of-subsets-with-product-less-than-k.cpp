//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void solve(int i , long long int x ,int arr[] , int N , int K , int &count){
        if(i==N){
            if(x<=K)
            count++;
            return;
        }
        long long int y = arr[i] * x;
        if(y<=K){
            solve(i+1 , y ,arr,N,K,count );
            solve(i+1 , x ,arr,N,K,count );
        }
        else{
            solve(i+1 , x , arr,N ,K,count);
        }
    }
    int numOfSubsets(int arr[], int N, int K) {
        long long int x = 1;
        int count = 0 ;
        solve(0 , x , arr , N , K , count);
        return count-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends