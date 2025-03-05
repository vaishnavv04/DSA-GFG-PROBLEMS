//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int find(int par[], int x) {
        if(par[x]==x)
        return x;
        return par[x] = find(par,par[x]);
    }

    void unionSet(int par[], int x, int z) {
        int parz = find(par,z);
        int parx = find(par,x);
        par[parx] = parz;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<vector<int>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                edges.push_back({it[1],i,it[0]});
            }
        }
        sort(edges.begin(),edges.end());
        int par[V];
        for(int i=0;i<V;i++)
        par[i] = i;
        int sum = 0;
        for(auto edge:edges)
        {
            int parz = find(par,edge[1]);
            int parx = find(par,edge[2]);
            if(parx==parz) continue;
            else
            {
                sum+=edge[0];
                unionSet(par,edge[1],edge[2]);
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends