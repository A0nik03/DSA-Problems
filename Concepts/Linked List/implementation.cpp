#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1, Node * next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrToll(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]);
        mover -> next = temp;
        mover = mover -> next;
    }
    return head;
}

void printll(Node *head){
    Node *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node* deleteFront(Node *head){
    if(head == NULL){
        return head;
    }
    Node *temp = head;
    head = head -> next;
    free(temp);
    return head;
}

Node *deleteTail(Node *head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node *temp = head;
    while(temp -> next->next != NULL){
        temp = temp -> next;
    }
    free(temp -> next);
    temp-> next = nullptr;
    return head;
}

Node *deleteK(Node *head,int k){
    if(head == NULL){
        return head;
    }
    

    if(k == 1){
        Node *temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;

    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node *deleteEl(Node *head,int val){
    if(head == NULL){
        return head;
    }
    

    if(head->data == val){
        Node *temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;

    while(temp != NULL){
        if(temp ->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* insertHead(Node *head,int el){
    Node *temp = new Node(el,head);
    return temp;
} 

Node *insertTail(Node *head, int el){
    if(head == NULL){
        return new Node(el);
    }

    Node *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node *newNode = new Node(el);
    temp->next = newNode;
    return head;
}

Node *insertK(Node *head,int k,int val){
    if(head == NULL){
        if(k == 1){
            return new Node(val,head);
        }
        else{
            cout<<"You Don't have enough elements in Linked List!"<<endl;;
        }
    }

    if(k == 1){
        return new Node(val,head);
    }
    Node *temp = head; 
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k - 1){
            Node *newElement = new Node(val);
            newElement->next = temp->next;
            temp->next = newElement;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertBeforeEl(Node *head,int El,int val){
    if(head == NULL){
        return NULL;
    }

    if(head->data == El){
        return new Node(val,head);
    }
    Node *temp = head; 
    while(temp->next != NULL){
        if(temp->next->data == El){
            Node *newElement = new Node(val);
            newElement->next = temp->next;
            temp->next = newElement;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2,4,5,6};
    Node *head = convertArrToll(arr);
    Node *newHead = insertBeforeEl(head,6,1000);
    printll(newHead);
}