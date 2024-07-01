// 160. Intersection of Two Linked Lists

/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/

#include <bits/stdc++.h>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *brute(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> mpp;
        ListNode* temp = headA;
        while(temp != NULL){
            mpp[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    ListNode* collision(ListNode* t1,ListNode* t2,int d){
        while(d){
            d--;
            t2 = t2->next;
        }
        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }


    ListNode *better(ListNode *headA, ListNode *headB) {
       ListNode* temp = headA;
       int cnt1 = 0,cnt2 = 0;
       while(temp!=NULL){
        cnt1++;
        temp = temp->next;
       }
       temp = headB;
       while(temp!=NULL){
        cnt2++;
        temp = temp->next;
       }
       if(cnt1<cnt2){
        return collision(headA,headB,cnt2-cnt1);
       }
       else{
        return collision(headB,headA,cnt1-cnt2);
       }
    }

    ListNode *optimal(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
       ListNode* temp1 = headA;
       ListNode* temp2 = headB;
       while(temp1 != temp2){
        temp1 = temp1 ->next;
        temp2 = temp2 -> next;
        if(temp1 == temp2) return temp1;
        if(temp1 == NULL) temp1 = headB;
        if(temp2 == NULL) temp2 = headA;
       }
       return temp1;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return optimal(headA,headB);
    }
};