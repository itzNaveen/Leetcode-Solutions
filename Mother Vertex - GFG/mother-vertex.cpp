//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
   private:
    void dfs(int node, vector<bool> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node]=true;
        for(int neigh: adj[node]) {
            if(!vis[neigh]) dfs(neigh,vis,st,adj);
        }
        st.push(node);
    }
    
    void check(int node, vector<bool> &vis, int &cnt, vector<int> adj[])
    {
        vis[node]=true;
        cnt++;
        for(int neigh: adj[node]) {
            if(!vis[neigh]) check(neigh,vis,cnt,adj);
        }
    }
    
public:
	int findMotherVertex(int V, vector<int> adj[])
	{
	    vector<bool> vis(V,false);
	    stack<int> st;
	    int cnt=0;
	    
	    // Get the topological sort
	    for(int i=0; i<V; i++) {
	        if(!vis[i]) dfs(i,vis,st,adj);
	    }
	    
	    // mark all vertices unvisited
	    for(int i=0; i<V; i++)    vis[i]=false;
	    
	    // check if the top most element can visit all the vertices
	    check(st.top(),vis,cnt,adj);
	    
	    if(cnt==V)  return st.top();
	    return -1;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends