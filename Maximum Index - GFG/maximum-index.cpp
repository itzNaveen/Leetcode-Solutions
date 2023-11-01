//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int N) 
    { 
        int ans = 0;
        vector<int>vmin(N),vmax(N);
        vmin[0] = arr[0];
        vmax[N-1] = arr[N-1];
        for(int i = 1; i<N; i++){
            vmin[i] = min(arr[i],vmin[i-1]);
            vmax[N-i-1] = max(vmax[N-i],arr[N-i-1]);
        }
        int i = 0, j = 0;
        while(i<N && j<N){
            if(vmin[i]<=vmax[j]){
                ans = max(ans,j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends