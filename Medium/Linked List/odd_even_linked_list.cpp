// 328. Odd Even Linked List

/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *brute(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        vector<int> num;
        ListNode *temp = head;

        while (temp != NULL && temp->next != NULL)
        {
            num.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            num.push_back(temp->val);
        temp = head->next;
        while (temp != NULL && temp->next != NULL)
        {
            num.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp)
            num.push_back(temp->val);
        int i = 0;
        temp = head;
        while (temp != NULL)
        {
            temp->val = num[i++];
            temp = temp->next;
        }
        return head;
    }

    ListNode *optimal(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *temp = even;

        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = temp;
        return head;
    }

public:
    ListNode *oddEvenList(ListNode *head)
    {
        return optimal(head);
    }
};