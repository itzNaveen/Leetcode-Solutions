//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void printPat(int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
    printPat(n);
    cout<<endl;
	}
}
// } Driver Code Ends


/*You are required to complete this method*/
void printPat(int n)
{
    for(int i = n; i>0; i--){
        int element = n;
        while(element){
            int k = i;
            while(k){
                cout<<element<<" ";
                k--;
            }
            element--;
        }
        cout<<"$";
    }
}