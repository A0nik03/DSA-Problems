#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> preInPost(TreeNode* root){
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    if(root == NULL){
        return;
    }
    vector<int> pre,in,post;

    while(!st.empty()){
        auto it = st.top();
        st.pop();
// Preorder
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL){
                st.push({it.first->left,1});
            }

        }
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL){
                st.push({it.first->right,1});
            }

        }
        else{
            post.push_back(it.first->data);
        }

    }

}