// 101. Symmetric Tree

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool isSymmetericHelp(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) return left == right;

        if(left->val != right -> val) return false;

        return isSymmetericHelp(left->left,right->right) && isSymmetericHelp(left->right,right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return (root == NULL || isSymmetericHelp(root->left,root->right));
    }
};