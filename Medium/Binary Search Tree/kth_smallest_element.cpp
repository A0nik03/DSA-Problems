// 230. Kth Smallest Element in a BST

/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        TreeNode* curr = root;
        int cnt = 0;
        int ans = 0;
        while(curr){
            if(curr->left == NULL){
                cnt++;
                if (cnt == k) ans = curr->val;
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    cnt++;
                    if (cnt == k) ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};