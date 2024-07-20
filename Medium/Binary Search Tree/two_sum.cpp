#include <bits/stdc++.h>
using namespace std;

// 653. Two Sum IV - Input is a BST

/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator{
    stack<TreeNode*> mystack;
    // reverse -> true -> before
    // reverse-> false -> after

    bool reverse = true;

public:
    BSTIterator(TreeNode* root, bool IsReverse){
        reverse = IsReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !mystack.empty();
    }

    int next(){
        TreeNode* tmp = mystack.top();
        mystack.pop();
        if(!reverse) pushAll(tmp->right);
        else pushAll(tmp->left);
        return tmp->val;
    }

private:
    void pushAll(TreeNode* node){
        while(node != NULL){
            mystack.push(node);
            if(reverse == true){
                node = node->right;
            }
            else{
                node = node->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i + j == k){
                return true;
            }
            else if(i + j < k){
                i = l.next();
            }
            else{
                j = r.next();
            }
        }
        return false;
    }
};