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

void print_forward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}
void print_backward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << "\n";
}

void delete_at_any_position(Node *head, int idx)
{
    
    for(int i = 0; i < idx - 1; i++){
        head = head->next;
    }
    Node *deleteNode = head->next;
    
    head->next = head->next->next;
    head->next->prev = head;
    delete deleteNode;

}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;
    delete_at_any_position(head,1);
    print_forward(head);
    print_backward(tail);

    return 0;
}
