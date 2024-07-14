// 105. Construct Binary Tree from Preorder and Inorder Traversal

/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
*/
#include <iostream>
#include <vector>
#include <map>
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
    TreeNode* constructTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int> & inmap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inmap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = constructTree(preorder,preStart + 1,preStart + numsLeft,inorder,inStart,inRoot - 1,inmap);
        root->right = constructTree(preorder,preStart + numsLeft + 1,preEnd,inorder,inRoot + 1,inEnd,inmap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;

        for(int i = 0; i < inorder.size(); i++){
            inmap[inorder[i]] = i;
        }

        TreeNode* root = constructTree(preorder,0,preorder.size() - 1,inorder,0,inorder.size(),inmap);
        return root;
    }
};