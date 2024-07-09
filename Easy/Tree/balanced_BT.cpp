// 110. Balanced Binary Tree

/*
Given a binary tree, determine if it is 
height-balanced
.
*/



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

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:

// Naive Approach

    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + (max(left, right));
    }

    bool isBalanced_Naive(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        if (abs(lh - rh) > 1) {
            return false;
        }

        bool left = isBalanced_Naive(root->left);
        bool right = isBalanced_Naive(root->right);

        if (!left || !right) {
            return false;
        }
        return true;
    }

// Optimal Approach

    int dfsHeight(TreeNode* root) {
        if(root == NULL) return 0;
        int left = dfsHeight(root->left);
        if(left == -1) return -1;
        int right = dfsHeight(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1;
        return 1 + max(left,right);
    }


public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};