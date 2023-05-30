//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int A[], int N)
    {
       int maxi=INT_MIN;
       if(N==1){
           return 0;
       }
       for(int i=0;i<N-1;i++){
            int count=0;
            int  j=i;
            while(A[j]<A[j+1] && j<N-1){
                count++;
                j++;
            }
            maxi=max(count,maxi);
       }    
       
       return maxi;
    }
};




//{ Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout << ob.maxStep(a, n) << endl;
	}
	return 0;
}
// } Driver Code Ends