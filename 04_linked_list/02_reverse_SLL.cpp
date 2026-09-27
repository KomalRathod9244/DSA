# include<iostream>
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

Node* solve(Node* prev, Node* curr, Node* next){
    if(next == NULL)
        return prev;
    next=curr->next;
    curr->next=prev;

    prev=curr;
    curr=curr->next;
    solve(prev, curr, next);
}

Node* revese(Node* head){
    if(head==nullptr || head->next == nullptr)
        return head;
    Node* prev=NULL;
    Node* current=head;
    Node* next = current;
    return solve(prev, current , next);
}

int main(){
    
    return 0;
}