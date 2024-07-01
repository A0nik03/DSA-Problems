// 876. Middle of the Linked List

/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
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
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp ->next;
        }
        int middle = cnt/2 + 1;
        temp = head;
        while(temp!= NULL){
            middle--;
            if(middle == 0){
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    ListNode* optimal(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
           slow = slow->next;
           fast = fast->next->next;
        }
        return slow;
    }
public:
    ListNode* middleNode(ListNode* head) {
        return optimal(head);
    }
};