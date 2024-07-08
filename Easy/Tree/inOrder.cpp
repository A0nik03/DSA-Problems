// 94. Binary Tree Inorder Traversal

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

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
private:
    void inorder_rec(TreeNode* node,vector<int>& inorde){
    if(node == NULL){
        return;
    }

    inorder_rec(node->left,inorde);
    inorde.push_back(node->val);
    inorder_rec(node->right,inorde);
    }

    vector<int> inorder_iter(TreeNode* node){
        vector<int> inorder;
        if(node == NULL){
            return inorder;
        }
        TreeNode* root = node;
        stack<TreeNode*> st;
        while(true){
            if(root != NULL){
                st.push(root);
                root = root -> left;
            }
            else{
                if(st.empty()){
                    break;
                }
                root = st.top();
                st.pop();
                inorder.push_back(root->val);
                root = root->right;
            }
        }
        return inorder;
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        return inorder_iter(root);
    }
};