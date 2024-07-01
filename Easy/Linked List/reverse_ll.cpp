// 206. Reverse Linked List

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
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
        stack<int> st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        free(temp);
        return head;
    }

    ListNode* better(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        
        return prev;
    }

    ListNode* optimal(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = optimal(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        
        return newHead;
    }




public:
    ListNode* reverseList(ListNode* head) {
        return optimal(head);
    }
};