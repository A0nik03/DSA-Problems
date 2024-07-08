// 144. Binary Tree Preorder Traversal

// Given the root of a binary tree, return the preorder traversal of its nodes' values.

#include <bits/stdc++.h>
using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
private:
    void preorder_rec(TreeNode* node,vector<int>& preorde){
    if(node == NULL){
        return;
    }

    preorde.push_back(node->val);
    preorder_rec(node->left,preorde);
    preorder_rec(node->right,preorde);
}

    vector<int> preorder_iter(TreeNode* node){
        // root,left,right
        vector<int> preorder;
        if(node == NULL){
            return preorder;
        }
        stack<TreeNode*> st;
        st.push(node);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            preorder.push_back(temp->val);
            if(temp->right != NULL){
                st.push(temp->right);
            }
            if(temp->left != NULL){
                st.push(temp->left);
            }
        }
        return preorder;
}

public:
    vector<int> preorderTraversal(TreeNode* node) {
        return preorder_iter(node);
    }
};