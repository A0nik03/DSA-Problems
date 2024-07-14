// Burning Tree

/*
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <map>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    
    Node* markParents(Node* root,map<Node*,Node*> & parent,int target){
        
        queue<Node*> q;
        q.push(root);
        
        Node* targetNode;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->data == target) targetNode = curr;
            
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }
    
    int findTime(Node*root,map<Node*,Node*>& parent,Node* targetNode){
        queue<Node*> q;
        q.push(targetNode);
        map<Node*,bool> vis;
        vis[targetNode] = true;
        
        int timer = 0;
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    flag = true;
                    vis[node->left] = true;
                    q.push(node->left);
                }
                
                if(node->right && !vis[node->right]){
                    flag = true;
                    vis[node->right] = true;
                    q.push(node->right);
                }
                
                if(parent[node] && !vis[parent[node]]){
                    flag = true;
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            if(flag) timer++;
        }
        return timer;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*> parent;
        Node* targetNode = markParents(root,parent,target);
        int timer = findTime(root,parent,targetNode);
        return timer;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends