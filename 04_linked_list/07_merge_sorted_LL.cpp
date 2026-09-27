#include<iostream>
using namespace std;

// Following is the linked list node structure.

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* newHead=NULL;   
    Node<int>* current=NULL; 


    if(first->data < second->data){
        newHead=first;
        current=newHead;
        first=first->next;
    }else{
        newHead=second;
        current=newHead;
        second=second->next;
    }

    while(first != NULL && second != NULL && first->data != -1 && second->data != -1){
        if(first->data < second->data){
            current->next = first;
            current=first;
            first=first->next;
        }else{
            current->next = second;
            current=second;
            second=second->next;
        }
    }
    
    if(first != NULL && first->data != -1)
        current->next=first;
    else
        current->next =second;

    delete current;
    return newHead; 
}
