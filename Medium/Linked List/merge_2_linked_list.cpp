//  Merge Two Sorted Linked Lists

/*
You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list. You need to return the head of the final linked list.

Note:

The given linked lists may or may not be null.
For example:

If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL

The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL
*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

// Following is the linked list node structure.

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *convert(vector<int> arr)
{
    Node<int> *head = new Node<int>(arr[0]);
    Node<int> *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node<int> *node = new Node<int>(arr[i]);
        temp->next = node;
        temp = node;
    }
    return head;
}

Node<int> *brute(Node<int> *first, Node<int> *second)
{
    vector<int> ans;
    Node<int> *temp = first;
    while (temp != NULL)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    temp = second;
    while (temp != NULL)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    sort(ans.begin(), ans.end());
    Node<int> *list = convert(ans);
    return list;
}

Node<int> *optimal(Node<int> *first, Node<int> *second)
{
    Node<int> *t1 = first;
    Node<int> *t2 = second;
    Node<int> *dNode = new Node<int>(-1);
    Node<int> *temp = dNode;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if (t1)
        temp->next = t1;
    else
        temp->next = t2;
    return dNode->next;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    return optimal(first, second);
}
