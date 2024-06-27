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

int main(){
    int arr[] = {2,4,5,6};
    Node *head = new Node(arr[0]);
    cout<<head<<endl;
    Node *mover = head;
    cout<<mover<<endl;
    for(int i = 1; i < 4; i++){
        cout<<mover<<" Before "<<endl;
        Node *temp = new Node(arr[i]);
        mover -> next = temp;
        cout<<mover<<" after: "<<endl;
         cout<<mover->next<<" Before "<<endl;
        mover = temp;
        cout<<mover<<" after2: "<<endl;
         cout<<mover->next<<" After "<<endl;
    }
}