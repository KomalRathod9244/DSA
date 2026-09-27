# include<iostream>
using namespace std;

typedef struct Node {
    long long data;
    struct Node* next;


    // code for constructor and all whatever required

} Node;

Node* reverse_ll(Node* head){

    // code to reverse

    return head;
}

Node* addTwoLists(Node* head1, Node* head2) {

    int carry =0;
    // reverse both LL
    head1 = reverse_ll(head1);
    head2 = reverse_ll(head2);
    
    // node wise addition , and store the result in a new ll
    Node* new_ll_head= new Node();
    Node* temp = new_ll_head;

    temp->data = head1->data + head2->data;
    head1 = head1->next;
    head2 = head2->next;

    while(head1 != NULL && head2 != NULL)
    {
        carry =0 ;
        // handling carry
        if(temp->data > 9){
            int data = temp->data ;
            carry = data/10;
        }

        temp->next = new Node();
        temp = temp->next; 
        temp->data = head1->data + head1->data + carry;
        head1= head1->next; 
        head2= head2->next;
    }

    while(head1 != NULL)
    {
        temp->next = new Node();
        temp = temp->next; 
        temp->data = head1->data + carry ;
        head1= head1->next; 

        // handling carry
        if(temp ->data > 9){
            int data = temp->data; 
            carry = data/10;
        }
        else
            carry = 0;
    }

    while(head2 != NULL)
    {
        temp->next = new Node();
        temp = temp->next; 
        temp->data = head2->data + carry;
        head2= head2->next; 

        // handling carry
        if(temp ->data > 9){
            int data = temp->data; 
            temp->data = data%10;
            carry = data/10;
        }
        else
            carry = 0;
    }

    // handling carry
    if(carry){
        temp->next= new Node();
        temp = temp->next;  
        temp->data = carry;
    }
    temp->next = NULL;
    
    // removing extra ending zeros

    // find last non-zero
    temp = new_ll_head;

    Node* last_non_zero = temp;
    while(temp != NULL)
    {
        if(temp->data == 0)
            temp=temp->next;
        else{
            last_non_zero=temp;
            temp=temp->next;
        }
    }

    // finally remove extra zeros
    Node* nodeToDelete = last_non_zero->next;
    Node* right_ll = NULL;
    
    last_non_zero->next = NULL;

    while(nodeToDelete != NULL)
    {
        right_ll = nodeToDelete->next;

        delete(nodeToDelete);
        nodeToDelete = right_ll;
    }


    // now reverse the sum LL
    return reverse_ll(new_ll_head);
    
}