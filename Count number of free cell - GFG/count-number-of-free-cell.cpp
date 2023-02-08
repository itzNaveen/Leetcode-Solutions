//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long int >row(n,0); //VISITED ARRAY FOR ROWS
      vector<long long int>col(n,0);  //VISITED ARRAY FOR COL
       vector<long long int> result;
      long long int tot = n*n;
      long long int count =0;
       long long int crow =0; //CURRENT NUMBER OF ROWS VISITED
        long long int ccol =0; // CURRENT NUMBER OF COL VISITED
      for(auto x:arr){
          
          if(row[x[0]-1]!=1){
             count+=(n-ccol);
             crow++;
             row[x[0]-1]=1;
          }
          if(col[x[1]-1]!=1){
             count+=(n-crow);
             ccol++;
             col[x[1]-1]=1;
          }
          
         
          
          result.push_back(tot-count);
      }
      return result;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends