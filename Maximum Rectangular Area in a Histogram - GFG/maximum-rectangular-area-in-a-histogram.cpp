//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
 long long getMaxArea(long long arr[], int n)
   {
       stack<long long>st;
       long long ma=0;
       long long i=0;
       while(i<n)
       {
           if(st.empty() or arr[st.top()]<=arr[i])
           
               st.push(i++);
       
           else
           {
               long long tp=st.top();
               st.pop();
               long long ans=arr[tp]*(st.empty()? i:i-st.top()-1);
               ma=max(ma,ans);
           }
           }
           while(!st.empty())
           {
            long long tp=st.top();
               st.pop();
               long long ans=arr[tp]*(st.empty()? i:i-st.top()-1);
               ma=max(ma,ans);
           }   
           return ma;
       }
};




//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends