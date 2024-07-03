//  Rotate List


/*
Given the head of a linked list, rotate the list to the right by k places.
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
public:
    ListNode* kthPlace(ListNode* head,int k){
        int cnt = 1;
        ListNode* temp = head;
        while(temp != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        if(k % len == 0) return head;

        k = k % len;

        ListNode* kthplace = kthPlace(head,len - k);
        tail->next = head;

        head = kthplace->next;
        
        kthplace->next = NULL;

        return head;
    }
    
};