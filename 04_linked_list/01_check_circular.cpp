#include<iostream>
#include<vector>
using namespace std;

bool check(linkedListNode& head, linkedListNode& slow, linkedListNode& fast){
    if(fast->next== NULL || fast->next->next==NULL)
        return false;
    if(slow == fast)
        return true;
    
    return check(head,slow->next,fast->next->next);
}

bool is_circular(linkedListNode& head){
    if(head==NULL || head->next== NULL)
        return false;
    linkedListnode* slow=head;
    linkedListNode* fast=head;
    check(head,slow, fast);
}

int main(){

    return 0;
}