// Find pairs with given sum in doubly linked list

/*
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
private:
    vector<pair<int, int>> brute(Node *head, int target)
    {
        vector<pair<int,int>> sum;
        Node* temp1 = head;
        
        while(temp1 != NULL){
            Node* temp2 = temp1->next;
            while(temp2 != NULL && temp1->data + temp2->data <= target){
                if(temp1->data + temp2->data == target){
                    sum.push_back({temp1->data,temp2->data});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return sum;
    }

    Node* tail(Node* head){
        Node* tailNode = head;
        while(tailNode->next != NULL){
            tailNode = tailNode->next;
        }
        return tailNode;
    }
    
    
    vector<pair<int, int>> optimal(Node *head, int target)
    {
        vector<pair<int,int>> sum;
        Node* left = head;
        Node* right = tail(head);
        
        while(left->data < right->data){
            if(left->data + right->data == target){
                sum.push_back({left->data,right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data < target){
                left = left -> next;
            }
            else{
                right = right -> prev;
            }
        }
        return sum;
    }
    
    
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        return optimal(head,target);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends