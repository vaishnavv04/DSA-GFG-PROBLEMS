//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    int solve(vector<vector<int>>&mat){
        int n = mat.size();
        int ct = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    for(int k=1;k<=9;k++){
                        if(valid(k,i,j,mat)){
                            mat[i][j] = k;
                            int t = solve(mat);
                            if(t > 0)return 1;
                            mat[i][j] = 0;
                        }
                    }
                    return -1;
                }
                else{
                    ct++;
                }
            }
        }
        return (ct == n*n)?1:-1;
    }
    bool valid(int num,int i,int j,vector<vector<int>>&mat){
        int n = mat.size();
        for(int x=0;x<n;x++){
            if(mat[x][j] == num){
                return false;
            }
        }
        for(int y=0;y<n;y++){
            if(mat[i][y] == num){
                return false;
            }
        }
        i/=3;j/=3;
        i*=3;j*=3;
        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                if(mat[x][y] == num){
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        solve(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends