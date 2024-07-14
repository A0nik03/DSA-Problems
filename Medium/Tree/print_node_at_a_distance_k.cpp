// 863. All Nodes Distance K in Binary Tree


/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track,TreeNode* target){

        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* current = queue.front(); queue.pop();
            if(current->left){
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParent(root,parent_track,target);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()){
            int size = queue.size();
            if(curr_level == k) break;
            curr_level++;
            for(int i = 0; i < size; i++){
                TreeNode* current = queue.front(); queue.pop();

                if(current->left && !visited[current->left]){
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }

        vector<int> res;
        while(!queue.empty()){
            TreeNode* curr = queue.front(); queue.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};