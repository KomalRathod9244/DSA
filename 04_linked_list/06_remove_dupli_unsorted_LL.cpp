#include<iostream>
#include<vector>
using namespace std;

// Following is the class structure of the Node class:
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* removeDuplicates(Node* head)
{
    if(head==NULL || head->next == NULL)
        return head;

    Node* current = head;
    int count=0;
    while(current != NULL){
        count+=1;
        current = current->next;
    }
    vector<bool> visited(count,false);

    Node* prev=head;
    current=head->next;
    visited[0]= true;

    while(1){
        if(visited[current->data] == false)
            visited[current->data] = true;
        else{   // means ye dupli hai, ise remove karo
            prev->next = current->next;
            delete(current);
        }
        if(current ->next == NULL)
            return head;
        prev = prev->next;
        current = prev->next;
    }
}