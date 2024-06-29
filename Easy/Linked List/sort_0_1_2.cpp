// Sort a linked list of 0s, 1s and 2s


/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    
    private: 
    
    Node* brute(Node *head) {
        int cnt0 = 0,cnt1 = 0,cnt2 = 0;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                cnt0++;
            }
            else if(temp->data == 1){
                cnt1++;
            }
            else{
                cnt2++;
            }
            temp = temp -> next;
        }
        temp = head;
        while(temp!=NULL){
            if(cnt0){
                temp->data = 0;
                cnt0--;
            }
            else if(cnt1){
                temp->data = 1;
                cnt1--;
            }
            else{
                temp->data = 2;
                cnt2--;
            }
            temp = temp->next;
        }
        return head;
    }
    
    Node* optimal(Node *head) {
        
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        
        Node *temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp;
            }
            else if(temp->data == 1){
                one->next = temp;
                one = temp;
            }
            else{
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        zero->next = (oneHead->next)?(oneHead->next):twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;
        
        Node* newHead = zeroHead -> next;
        free(zeroHead);
        free(oneHead);
        free(twoHead);
    
        return newHead;
    }
    
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        return optimal(head);
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends