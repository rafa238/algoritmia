//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/merge-two-sorted-linked-lists
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode 
        *head3 = new SinglyLinkedListNode(-1), 
        *curr = head3;
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    
    while(head1 != NULL){
        curr->next = head1;
        curr = curr->next;
        head1 = head1->next;
    }
    
    while(head2 != NULL){
        curr->next = head2;
        curr = curr->next;
        head2 = head2->next;
    }
    
    return head3->next;
}