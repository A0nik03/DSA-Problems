// 103. Binary Tree Zigzag Level Order Traversal

/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> queuesNode;
        queuesNode.push(root);
        bool leftToRight = true;

        while (!queuesNode.empty()) {

            int size = queuesNode.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = queuesNode.front();
                queuesNode.pop();

                // Finding Positions to Place;

                int index = (leftToRight) ? i : size - i - 1;
                row[index] = node->val;

                if (node->left) {
                    queuesNode.push(node->left);
                }

                if (node->right) {
                    queuesNode.push(node->right);
                }
            }
            
            // After this Level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};