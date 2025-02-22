//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        stack<char> st;
        stack<int> pt;
        st.push('#');
        pt.push(-1);
        int maxVal=0;
        int n=str.size();
        for(int i=0;i<n;i++){
            if(str[i]==')' && !st.empty() && st.top()=='('){
                st.pop();
                pt.pop();
                maxVal=max(maxVal,i-pt.top());
            }
            else{
                st.push(str[i]);
                pt.push(i);
            }
        }
        return maxVal;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends