#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *convertArrToDLL(vector<int> &arr)
{

    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void *printDll(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *back = head;
    head = head->next;

    head->prev = nullptr;
    back->next = nullptr;
    free(back);
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    free(tail);
    return head;
}

Node *deleteKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }

    Node* prev = temp -> prev;
    Node* front = temp -> next;
    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev->prev == NULL){
        return deleteHead(head);
    }
    else if(front->next == NULL){
        return deleteTail(head);
    }

    prev->next = front;
    front->prev = prev;

    temp->next = nullptr;
    temp->prev = nullptr;

    free(temp);
    return head;
}

void deleteNode(Node *temp){
    Node* prev = temp->prev;
    Node* front = temp->next;

    if(front == NULL){
        prev -> next = nullptr;
        temp -> prev = nullptr;
        free(temp);
        return;
    }

    prev -> next = front;
    front -> prev = prev;

    temp->prev = temp->next = nullptr;
    free(temp);
}

Node *deleteNode_Two(Node* head,int val){
    Node* temp = head;
    if(head->data == val){
        cout<<"Val Can't be same as Head"<<endl;
        return NULL;
    }

    while(temp != NULL){
        if(temp->data == val){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp -> prev;
    Node* front = temp -> next;
    prev->next = front;
    front->prev = prev;

    temp->next = nullptr;
    temp->prev = nullptr;
    free(temp);
    return head;
}

Node* insertBeforeHead(Node* head,int val){
    Node* newHead = new Node(val,head,nullptr);
    head->prev = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head,int val){
    if(head->next == NULL){
        return insertBeforeHead(head,val);
    }

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->prev;

    Node *newEl = new Node(val,tail,prev);
    prev->next = newEl;
    tail->prev = newEl;
    return head;
}

int main()
{
    vector<int> arr = {25, 5, 40, 100, 56, 28};
    Node *head = convertArrToDLL(arr);
    head = insertBeforeTail(head,10);
    printDll(head);
}