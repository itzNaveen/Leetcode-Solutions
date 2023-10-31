//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // vector<int> dist(V,1e9);
        
        // pq.push({0,S}); // dist, node;
        // dist[S] = 0;
        
        // while(!pq.empty()) {
        //     auto p = pq.top();
        //     pq.pop();
            
        //     int distance = p.first, node = p.second;
            
        //     for(auto i: adj[node]) {
        //         int v = i[0], wt = i[1];
                
        //         if(distance + wt < dist[v]) {
        //             dist[v] = distance + wt;
        //             pq.push({dist[v], v});
        //         }
        //     }
        // }
        
        // return dist;
        set<pair<int,int>>s;
        vector<int>dist(V,INT_MAX);
        
        s.insert({0,S});
        dist[S] = 0;
        
        while(!s.empty()) {
            auto p = *(s.begin());
            int d = p.first, u = p.second;
            s.erase(p);
            
            for(auto i: adj[u]) {
                int v = i[0], wt = i[1];
                if(d + wt < dist[v]) {
                    if(dist[v] != INT_MAX) s.erase({dist[v], v});
                    dist[v] = d + wt;
                    s.insert({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};




//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends