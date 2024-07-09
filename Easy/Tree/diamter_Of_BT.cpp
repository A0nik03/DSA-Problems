// 543. Diameter of Binary Tree

/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/

#include <bits/stdc++.h>
using namespace std;



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

// Brute - Force

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + (max(left,right));
    }

    void findMax(TreeNode* node, int & diameter){
        if(node == NULL){
            return;
        }

        int lh = maxDepth(node->left);
        int rh = maxDepth(node->right);

        diameter = max(diameter,lh + rh);

        findMax(node->left,diameter);
        findMax(node->right,diameter);
    }

// Optimal-Approach

    int diameterOfBT(TreeNode* node,int &diameter){
        if(node == NULL) return 0;
        int lh = diameterOfBT(node->left,diameter);
        int rh = diameterOfBT(node->right,diameter);

        diameter = max(diameter,lh + rh);
        return 1 + max(lh,rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameterOfBT(root,diameter);
        return diameter;
    }
};