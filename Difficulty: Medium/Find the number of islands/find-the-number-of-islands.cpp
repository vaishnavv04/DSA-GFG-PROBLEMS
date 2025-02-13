//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void trav(vector<vector<char>>& v, int i, int j, vector<vector<bool>>& visi) {
        visi[i][j] = true;
    
        // Define the 8 possible directions: 
        // (up, down, left, right, top-left, top-right, bottom-left, bottom-right)
        vector<int> dx = {-1, 1, 0, 0, -1, -1, 1, 1};
        vector<int> dy = {0, 0, -1, 1, -1, 1, -1, 1};
    
        for (int d = 0; d < 8; d++) {
            int newX = i + dx[d];
            int newY = j + dy[d];
    
            // Check boundaries and visit unvisited land cells
            if (newX >= 0 && newX < v.size() && newY >= 0 && newY < v[0].size() &&
                v[newX][newY] == '1' && !visi[newX][newY]) {
                trav(v, newX, newY, visi);
            }
        }
    }

    int numIslands(vector<vector<char>>& v) {
        // Code here
        int m = v.size() , n = v[0].size() , ans = 0;
        vector<vector<bool>> visi (m,vector<bool>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visi[i][j] && v[i][j]=='1')
                {
                    trav(v,i,j,visi);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends