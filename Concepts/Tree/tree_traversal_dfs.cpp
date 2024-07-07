// Tree Traversals

/*
You have been given a Binary Tree of 'N'

nodes, where the nodes have integer values.



Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.
*/

// Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;

void inorder(TreeNode* node,vector<int>& inorde){
    if(node == NULL){
        return;
    }

    inorder(node->left,inorde);
    inorde.push_back(node->data);
    inorder(node->right,inorde);

}

void preorder(TreeNode* node,vector<int>& preorde){
    if(node == NULL){
        return;
    }

    preorde.push_back(node->data);
    preorder(node->left,preorde);
    preorder(node->right,preorde);

    
}

void postorder(TreeNode* node,vector<int>& postorde){
    if(node == NULL){
        return;
    }

    postorder(node->left,postorde);
    postorder(node->right,postorde);
    postorde.push_back(node->data);
   
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
   vector<vector<int>> ans;
   vector<int> inorde;
   vector<int> preorde;
   vector<int> postorde;
   inorder(root, inorde);
   preorder(root, preorde);
   postorder(root, postorde);
   ans.push_back(inorde);
   ans.push_back(preorde);
   ans.push_back(postorde);

   return ans;
}