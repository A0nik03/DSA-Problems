// 148. Sort List

// Given the head of a linked list, return the list after sorting it in ascending order.

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

// Brute
    ListNode* brute_SortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        vector<int> arr;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(),arr.end());
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->val = arr[i++];
            temp = temp->next;
        }
        return head;
    }

// Optimal

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* t1,ListNode* t2){
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if (t1) temp->next = t1;
        if (t2) temp->next = t2;

        return dNode->next;
    }

    ListNode* optimal_SortList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* middle = findMiddle(head);

        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        left = optimal_SortList(left);
        right = optimal_SortList(right);

        head = merge(left,right);
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        return optimal_SortList(head);
    }
};