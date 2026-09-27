#include<iostream>
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
 
// Floyd loop detection method (slow and fast pointer)
Node* kReverse(Node* head, int k) {
    if(head==NULL)
        return NULL;

    // check if k no. of nodes exist
    Node* temp=head;
    int count=0;
    while(temp != NULL && count<k){
        temp=temp->next;
        count++;
    }

    if(count<k)
        return head;

    Node* next = NULL;
    Node* curr= head;
    Node* prev=NULL;
    count=0;

    while(curr != NULL && count<k){
        next=curr->next;
        curr->next = prev;

        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL)
        head->next=kReverse(next, k);

    return prev;
}


// Time complexity = O(n) , as we are travesring each node 

// space complexity = O(n/k)
// worst case k=1 = O(n)
// best case k=n = O(1)