#include <bits/stdc++.h>
using namespace std;
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1,SinglyLinkedListNode* head2){
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* temp = dummy;
    while(head1 && head2){
        if(head1->data < head2->data){
            temp->next = new SinglyLinkedListNode (head1->data);
            head1 = head1->next;
            temp = temp->next;
        }
        else{
            temp->next = new SinglyLinkedListNode (head2->data);
            head2 = head2->next;
            temp = temp->next;
        }
    }
    while(head1){
        temp->next = new SinglyLinkedListNode (head1->data);
        head1 = head1->next;
        temp = temp->next;
    }
    while(head2){
        temp->next = new SinglyLinkedListNode (head2->data);
        head2 = head2->next;
        temp = temp->next;
    }
    return dummy->next;
}
