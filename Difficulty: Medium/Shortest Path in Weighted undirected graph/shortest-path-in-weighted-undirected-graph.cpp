//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        if(m==0) return {-1};
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        set<pair<int,int>> st;
        st.insert({0,1});
        vector<int> dist(n+1,INT_MAX),par(n+1);
        for(int i=1;i<n+1;i++)
        par[i] = i;
        dist[1] = 0;
        while(!st.empty())
        {
            auto p = *st.begin();
            int node = p.second,dis=p.first;
            st.erase(p);
            for(auto it:adj[node])
            {
                if(dis+it.second<dist[it.first])
                {
                    if(dist[it.first]!=1e9)
                    {
                        st.erase({dist[it.first],it.first});
                    }
                    dist[it.first]= dis+it.second;
                    st.insert({dist[it.first],it.first});
                    par[it.first] = node;
                }
            }
        }
        if(dist[n]==INT_MAX) return {-1};
        int i = n;
        vector<int> ans;
        while(par[i]!=i)
        {
            ans.push_back(i);
            i = par[i];
        }
        ans.push_back(1);
        ans.push_back(dist[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends