// Add 1 to a number represented as linked list

/*
A number n is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it. Returns the head of the modified linked list. The driver code prints the number.

Note: The head represents the left-most digit of the number.
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    
    Node* reverse(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* newHead = reverse(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
        
    
    Node* brute(Node *head) 
    {
        reverse(head);
        Node* temp = head;
        int carry = 1;
        while(temp != NULL){
            temp->data = temp->data + carry;
            if(temp->data < 10){
                carry = 0;
                break;
            }
            else{
                temp->data = 0;
                carry = 1;
            }
            temp = temp->next;
        }
        if(carry == 1){
            Node* extra = new Node(1);
            head = reverse(head);
            extra->next = head;
            return extra;
        }
        head = reverse(head);
        return head;
    }
    
   int helper(Node* temp){
        if(temp == NULL){
            return 1;
        }
        int carry = helper(temp->next);
        temp->data += carry;
        if(temp->data < 10){
            return 0;
        }
      
        temp->data = 0;
        return 1;
        
    }
    
    Node* optimal(Node* head){
        int carry = helper(head);
        if(carry == 1){
            Node* extra = new Node(1);
            extra->next = head;
            head = extra;
        }
        return head;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        return optimal(head);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends