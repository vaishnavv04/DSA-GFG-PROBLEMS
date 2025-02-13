//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<vector<int>> adj,int v,vector<int>&vis,vector<int>&pathvis)
    {
        vis[v] = 1;
        pathvis[v] = 1;
        for(auto it:adj[v])
        {
            if(!vis[it])
            {
                if(dfs(adj,it,vis,pathvis))
                return 1;
            }
            else if(pathvis[it])
            return 1;
        }
        pathvis[v] = 0;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> vis(V),pathvis(V);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,i,vis,pathvis))
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends