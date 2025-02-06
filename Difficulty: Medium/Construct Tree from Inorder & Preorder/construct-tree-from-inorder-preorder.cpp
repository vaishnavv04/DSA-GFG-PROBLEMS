//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &in, vector<int> &pre) {
        // code here
        
    if (in.empty() || pre.empty()) return NULL;

    Node* root = new Node(pre[0]); // Root is always the first element of preorder

    // Find root index in inorder
    auto it = find(in.begin(), in.end(), pre[0]);
    int index = distance(in.begin(), it);

    // Left and right subtrees
    vector<int> leftIn(in.begin(), it);
    vector<int> leftPre(pre.begin() + 1, pre.begin() + 1 + index);
    vector<int> rightIn(it + 1, in.end());
    vector<int> rightPre(pre.begin() + 1 + index, pre.end());

    root->left = buildTree(leftIn, leftPre);
    root->right = buildTree(rightIn, rightPre);

    return root;
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends