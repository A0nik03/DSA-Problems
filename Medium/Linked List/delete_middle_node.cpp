// 2095. Delete the Middle Node of a Linked List

/*
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/

#include <bits/stdc++.h>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* brute(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* temp = head;
        int cnt = 0;
        while (temp != head) {
            cnt++;
            temp = temp->next;
        }
        int res = (cnt / 2) - 1;
        temp = head;
        while (temp != NULL) {
            res--;
            if (res == 0) {
                ListNode* middle = temp->next;
                temp->next = temp->next->next;
                free(middle);
                break;
            }
            temp = temp->next;
        }
        return head;
    }

    ListNode* optimal(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }

public:
    ListNode* deleteMiddle(ListNode* head) { return brute(head); }
};