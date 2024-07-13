// 106. Construct Binary Tree from Inorder and Postorder Traversal

/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
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
private:
    TreeNode* constructTree(vector<int>& postorder, int ps, int pe,vector<int>& inorder, int is, int ie,map<int,int>& mpp) {
        if(ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = mpp[postorder[pe]];
        int leftNums = inRoot - is;

        root->left = constructTree(postorder,ps,ps + leftNums - 1,inorder,is,inRoot-1,mpp);
        root->right = constructTree(postorder,ps + leftNums,pe - 1,inorder,inRoot+1,ie,mpp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;

        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return constructTree(postorder, 0, postorder.size() - 1, inorder, 0,inorder.size() - 1, mpp);
    }
};