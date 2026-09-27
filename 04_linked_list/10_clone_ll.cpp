#include <iostream>
#include <map>
using namespace std;


// Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};

class Solution 
{
  public:
    Node* cloneLinkedList(Node* head) 
    {
        // form a clone ll
        Node *cloneHead = NULL;
        Node *temp = head;
        Node *cloneTemp = cloneHead;

        if(head != NULL)
        {
            cloneHead = new Node(head->data);
            cloneHead->next = NULL;
            temp = head->next;
        }

        while(temp!= NULL)
        {
            cloneTemp->next = new Node(temp->data);
            cloneTemp = cloneTemp->next;
        }
        cloneTemp->next = NULL;

        // create mapping 
        map<Node* , Node* >mapping ;
        temp = head; 
        cloneTemp = cloneHead;
        
        while(temp != nullptr)
        {
            mapping.insert({temp, cloneTemp});
            temp = temp->next; 
            cloneTemp = cloneTemp->next; 
        }

        temp = head;
        cloneTemp = cloneHead;
        
        map<Node* , Node*> :: iterator iter; 
        
        for( iter=mapping.begin(); iter != mapping.end(); iter++)
        {
            Node* original = (*iter).first;
            Node* clone = (*iter).second;

            clone->random = mapping[original->random] ;
        }

        return cloneHead;
    }
};