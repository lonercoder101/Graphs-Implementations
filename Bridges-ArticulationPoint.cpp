#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    
    int timer = 0; bool flag;
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
      flag = false;
     vector<int> tin(V,-1), low(V,-1), vis(V,0); 
           for(int i=0; i< V ; i++){
            if(!vis[i]){
                
                dfs( i ,-1 ,adj ,c ,d , tin ,low ,vis);
            }
        }
       return flag;
    }
       void dfs(int node, int p, vector<int> adj[], int c, int d,vector<int>&tin,vector<int>&low,vector<int>&vis){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto it:adj[node]){
            if(it==p) continue;
            if(!vis[it]){
                dfs(it,node,adj,c,d,tin,low,vis);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node] and ( (it==c  and node == d) or (it==d and node==c) )) flag = true;
            }
            else low[node] = min(low[node],tin[it]);
        }

    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
