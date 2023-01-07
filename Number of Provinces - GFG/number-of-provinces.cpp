//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet{
vector<int>rank,parent,size;
public:
DisjointSet(int n){
rank.resize(n+1,0);
parent.resize(n+1,0);
size.resize(n+1,0);
for(int i=0;i<=n;i++){
    parent[i]=i;
    size[i]=1;
}
}
int findPar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findPar(parent[node]);
}
void UnionByRank(int u,int v){
int find_ultimateu=findPar(u);
int find_ultimatev=findPar(v);
if(find_ultimateu==find_ultimatev)return;
 if(rank[find_ultimateu]<rank[find_ultimatev]){
    parent[find_ultimateu]=find_ultimatev;
}
else if(rank[find_ultimateu]>rank[find_ultimatev]){
     parent[find_ultimatev]=find_ultimateu;
}
else{
    parent[find_ultimatev]=find_ultimateu;
    rank[find_ultimateu]++;
}
}

void UnionBySize(int u,int v){
int find_ultimateu=findPar(u);
int find_ultimatev=findPar(v);
if(find_ultimateu==find_ultimatev)return;
 if(size[find_ultimateu] < size[find_ultimatev]) {
            parent[find_ultimateu] = find_ultimatev; 
            size[find_ultimatev] += size[find_ultimateu]; 
        }
        else {
            parent[find_ultimatev] = find_ultimateu;
            size[find_ultimateu] += size[find_ultimatev]; 
        }
}


};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj.size();j++){
                if(adj[i][j]==1){
                    ds.UnionBySize(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<V;i++){
            if(ds.findPar(i)==i){
                count++;
            }
        }
        return count;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends