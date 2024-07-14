// 145. Binary Tree Postorder Traversal

// Given the root of a binary tree, return the postorder traversal of its nodes' values.

#include <iostream>
#include <vector>
#include <stack>
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
    void postorder_iter(TreeNode* node, vector<int>& postorde) {
        if (node == NULL) {
            return;
        }

        postorder_iter(node->left, postorde);
        postorder_iter(node->right, postorde);
        postorde.push_back(node->val);
    }

    vector<int> postorder_iter_one(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) {
            return postorder;
        }
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while (!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);

            if (root->left != NULL)
                st1.push(root->left);
            if (root->right != NULL)
                st1.push(root->right);
        }
        while (!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }

    vector<int> postorder_iter_two(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) {
            return postorder;
        }
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top()->right;
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        return postorder;
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        return postorder_iter_two(root);
    }
};