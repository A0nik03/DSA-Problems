// 138. Copy List with Random Pointer

/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{

private:
    // Brute

    Node *brute_copyRandomList(Node *head)
    {
        map<Node *, Node *> mpp;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            Node *copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
    }

    // Optimal

    void insertCopyNode(Node *head)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
    }

    void pointRandomNode(Node *head)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            Node *copyNode = temp->next;
            if (temp->random)
            {
                copyNode->random = temp->random->next;
            }
            else
            {
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node *getDeepCopy(Node *head)
    {
        Node *temp = head;
        Node *dNode = new Node(-1);
        Node *res = dNode;

        while (temp != NULL)
        {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        Node *deepCopy = dNode->next;
        delete dNode; // Free the dummy node
        return deepCopy;
    }

    Node *optimal_copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        insertCopyNode(head);
        pointRandomNode(head);
        return getDeepCopy(head);
    }

public:
    Node *copyRandomList(Node *head) { return optimal_copyRandomList(head); }
};