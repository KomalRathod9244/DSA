#include<iostream>
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

class Solution{
public:
    Node* cloneLinkedList(Node* head)
    {
        if (head == NULL)
            return NULL;

        // 1. Create clone nodes and interleave them
        Node* curr = head;

        while (curr != NULL)
        {
            Node* clone = new Node(curr->data);

            clone->next = curr->next;
            curr->next = clone;

            curr = clone->next;
        }

        // 2. Set random pointers of clone nodes
        curr = head;

        while (curr != NULL)
        {
            Node* clone = curr->next;

            if (curr->random != NULL)
                clone->random = curr->random->next;

            curr = clone->next;
        }

        // 3. Separate original and cloned lists
        curr = head;
        Node* cloneHead = head->next;

        while (curr != NULL)
        {
            Node* clone = curr->next;

            curr->next = clone->next;

            if (clone->next != NULL)
                clone->next = clone->next->next;

            curr = curr->next;
        }

        return cloneHead;
    }
};