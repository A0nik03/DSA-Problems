// 23. Merge k Sorted Lists

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
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

// Brute

     ListNode* convert(vector<int>& arr){
        if(arr.empty()) return NULL;
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for(int i = 1; i < arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }

    ListNode* brute_MergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                arr.push_back(temp->val);
                temp = temp -> next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* head = convert(arr);
        return head;
    }

// Better

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

    ListNode* better_MergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) return NULL;

        ListNode* head = lists[0];
        for(int i = 1;i < lists.size();i++){
            head = merge(head,lists[i]);
        }
        return head;
    }

// Optimal

    ListNode* optimal_MergeKLists(vector<ListNode*>& lists) {

        priority_queue<pair<int,ListNode*>,
        vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }

        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(it.second->next){
                pq.push({it.second->next->val,it.second->next});
            }
            temp->next = it.second;
            temp = temp->next;
        }
        return dNode->next;
    }


public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return optimal_MergeKLists(lists);
    }

};