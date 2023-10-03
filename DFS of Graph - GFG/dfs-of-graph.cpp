//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int v,vector<int> adj[],vector<int>& ans,bool* visited,int k){
                ans.push_back(k);
                visited[k]=1;
        for(int i=0;i<adj[k].size();i++){
            if(!visited[adj[k][i]]){
                dfs(v,adj,ans,visited,adj[k][i]);
            }
        }
    }
    
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        
        bool visited[v]={0};
        vector<int> ans;
        dfs(v,adj,ans,visited,0);
        return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends