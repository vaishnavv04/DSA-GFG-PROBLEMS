//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void helper(vector<vector<int>> &mat,int row,int col,string path,vector<string>&ans,
    vector<vector<bool>>&vis)
    {
        int n=mat.size();
          
        if (row < 0 || row >= n || col < 0 || col >= n || mat[row][col] == 0 || vis[row][col]) {
            return;
        }
            
        if(row==n-1 && col==n-1){
            ans.push_back(path);
            return;
        }
    
        vis[row][col]=true;
        //downward
        helper(mat,row+1,col,path+'D',ans,vis);
    
        //Upward
        helper(mat,row-1,col,path+'U',ans,vis);
    
        //Left
        helper(mat,row,col-1,path+'L',ans,vis);
    
        //Right
        helper(mat,row,col+1,path+'R',ans,vis);
        
        vis[row][col]=0;
    }
        vector<string> findPath(vector<vector<int>> &mat) {
            // code here
            int n=mat.size();
            vector<vector<bool>>vis(n,vector<bool>(n));
            vector<string>ans;
            string path="";
            helper(mat,0,0,path,ans,vis);
            return ans;
        }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends