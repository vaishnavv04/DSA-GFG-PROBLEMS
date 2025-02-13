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
    bool isCyclic(int n, vector<vector<int>> adj) {
        // code here
        // vector<int> vis(V),pathvis(V);
        // for(int i=0;i<V;i++)
        // {
        //     if(!vis[i])
        //     {
        //         if(dfs(adj,i,vis,pathvis))
        //         return 1;
        //     }
        // }
        // return 0;
        vector<int> in(n);
        queue<int> q;
        for(auto v:adj)
        {
            for(auto it:v)
            {
                in[it]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            q.push(i);
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
    
            for (int v : adj[node]) {
                in[v]--;
                if (in[v] == 0)
                    q.push(v);
            }
        }
    
        // If topological order contains all nodes, return it; otherwise, there's a cycle
        return (topo.size() == n) ? 0 : 1; 
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