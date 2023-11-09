//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	queue<string>q;
	vector<string>result;
	q.push("1");
	while(N--){
	    string s1 = q.front();
	    q.pop();
	    result.push_back(s1);
	    
	    string s2 = s1;
	    q.push(s1.append("0"));
	    q.push(s2.append("1"));
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