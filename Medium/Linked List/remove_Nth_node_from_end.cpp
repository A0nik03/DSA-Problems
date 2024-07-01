// 19. Remove Nth Node From End of List

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
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
      ListNode *brute(ListNode *head, int n)
      {
          ListNode *temp = head;
          int cnt = 0;
          while (temp != NULL)
          {
              cnt++;
              temp = temp->next;
          }
          if (cnt == n)
          {
              ListNode *newHead = head->next;
              return newHead;
          }
          int res = cnt - n;
          temp = head;
          while (temp != NULL)
          {
              res--;
              if (res == 0)
              {
                  break;
              }
              temp = temp->next;
          }
          ListNode *delNode = temp->next;
          temp->next = temp->next->next;

          return head;
      }

      ListNode *optimal(ListNode *head, int n)
      {
          ListNode *fast = head;
          ListNode *slow = head;
          for (int i = 0; i < n; i++)
              fast = fast->next;

          if (fast == NULL)
          {
              ListNode *newHead = head->next;
              delete head;
              return newHead;
          }

          while (fast->next != NULL)
          {
              slow = slow->next;
              fast = fast->next;
          }
          ListNode *delNode = slow->next;
          slow->next = slow->next->next;
          delete delNode;
          return head;
      }

  public:
      ListNode *removeNthFromEnd(ListNode *head, int n)
      {
          return optimal(head, n);
      }
  };