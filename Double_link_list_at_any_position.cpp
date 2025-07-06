#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};



void print_forward(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}
void print_backward(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
     cout << "\n";
}

void insert_at_any_position(Node* head, int idx,int val){
    Node* newNode = new Node(val);
    for(int i = 0; i < idx - 1; i++){
        head = head->next;
    }
    newNode->prev = head;
    newNode->next = head->next;
    head->next = newNode;
    newNode->next->prev = newNode;
    
}



int main()
{
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    
    insert_at_any_position(head,1,100);
    insert_at_any_position(head,2,100);
    print_forward(head);
    print_backward(tail);

    return 0;
}
