# include<iostream>
# include<vector>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
/*
// Standard approach
Node* Reverse(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node* newhead=Reverse(head->next);

    head->next->next=head;
    head->next = nullptr;

    return newhead;
}

// my code 
void solve(Node*& head,  Node* prev, Node* next){
    if(next==nullptr){
        head=prev;
        return ;
    }
    solve(head, prev->next, next->next);
    
    prev->next=next->next;
    next->next=prev;
}

Node* Reverse(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    solve(head, head, head->next);
    return head;
}
*/


Node* Reverse(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node* newhead=Reverse(head->next);

    head->next->next=head;
    head->next = nullptr;

    return newhead;
}


Node* kReverse(Node* head, int k) {
    
}