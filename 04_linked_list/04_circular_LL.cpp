#include<iostream>
using namespace std;

// Following is the structure of class Node:

class Node{
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    
};


// floydDetectLoop
bool solve(Node* head, Node* slow, Node* fast)
{

    // means no cycle exist
    if(fast== NULL || fast->next == NULL)
        return false;

    // yes, it is CLL as per our condition
    if(fast==head || fast->next == head )
        return true;

    // No it's not CLL even it is circular
    if(fast==slow || fast->next==slow)
        return false; 

    return solve(head, slow->next, fast->next->next);
}

bool floydDetectLoop(Node* head)
{
    if(head==NULL) 
        return true;

    if(head->next == NULL)
        return false;

    Node* slow=head;
    Node* fast= head->next->next;
    return solve(head,slow, fast);
}


// Detect starting node of loop
Node* intersection(Node* head, Node* slow, Node* fast)
{

    // means no cycle exist
    if(fast== NULL || fast->next == NULL)
        return NULL;

    // yes, it is CLL 
    if(fast==head || fast->next == head )
        return head;

    // No it's not CLL even it is circular
    if(fast==slow || fast->next==slow)
        return fast; 

    return intersection(head, slow->next, fast->next->next);
}

Node* startNodeOfLoop(Node* head)
{
    if(head==NULL || head->next == NULL) 
        return NULL;

    Node* slow=head;
    Node* fast= head->next->next;
    Node* intersectionNode = intersection(head,slow, fast);

    slow=head;
    while(slow != intersectionNode){
        slow = slow->next;
        intersectionNode = intersectionNode->next;
    }
    return slow;
}


// Romove the loop
void removeLoop(Node* head){
    Node* loopStartNode = startNodeOfLoop(head);
    Node* temp = loopStartNode;
    
    while(temp->next != loopStartNode)
        temp=temp->next;

    temp->next = NULL;  
}