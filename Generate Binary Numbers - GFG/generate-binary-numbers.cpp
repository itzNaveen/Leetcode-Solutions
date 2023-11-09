//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	vector<string>result;
	for(int i = 1; i<=N; i++){
	    int num = i;
	    string binary = "";
	    while(num){
	        binary += (num%2) + 48;
	        num /= 2;
	    }
	    reverse(binary.begin(),binary.end());
	    result.push_back(binary);
	}
	return result;
}



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends