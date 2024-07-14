// 114. Flatten Binary Tree to Linked List

/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten_recc(TreeNode* root) {
        if(root == NULL) return;

        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }

    void flatten_iter(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* previous = NULL;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(!st.empty()){
                curr->right = st.top();
            }
            curr->left = NULL;
        }
    }

    void flatten_morris(TreeNode* root){
        if(!root) return;

        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }

    void flatten(TreeNode* root) {
        flatten_morris(root);
    }
};