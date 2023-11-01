//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    // Calculate the value without rotation
    int ans = 0, total = 0, sum = 0;
    for(int i = 0; i<N; i++){
        sum += A[i];
        total += A[i]*i;
    }
    ans = max(ans,total);
    
    // Now calculate the values for rotations
    int pref[N];
    pref[0] = total;
    for(int i = 1; i<N; i++){
        pref[i] = pref[i-1] + sum-N*A[N-i];
        ans = max(ans,pref[i]);
    }
    return ans;
}