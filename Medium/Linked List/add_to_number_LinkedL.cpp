// 2. Add Two Numbers

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        int carry = 0;
        while (t1 != NULL || t2 != NULL || carry)
        {
            int sum = carry;
            if (t1)
                sum += t1->val;
            if (t2)
                sum += t2->val;

            ListNode *newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newNode;
            if (t1)
                t1 = t1->next;
            if (t2)
                t2 = t2->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};