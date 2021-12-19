/*void printLinkedList(SinglyLinkedListNode* head) {
     while(head!=nullptr){
         cout <<head->data<<endl;
         head=head->next;
     }
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode *head) {

    SinglyLinkedListNode* sig = nullptr;
    SinglyLinkedListNode* act = head;
    SinglyLinkedListNode* prev   = nullptr;

    while (act != nullptr){
        sig  = act->next;
        act->next = prev;
        prev = act;
        act = sig;
    }

    return prev;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedList *nuevaLista;
    while(head1 != nullptr || head2 != nullptr){
        if(head1 == nullptr) {
            nuevaLista->insert_node(head2->data);
            head2=head2->next;
        }
        if(head2 == nullptr) {
            nuevaLista->insert_node(head1->data);
            head1=head1->next;
        }
        if(head1 < head2){
            nuevaLista->insert_node(head1->data);
            head1=head1->next;
        } else if(head2 < head1){
            nuevaLista->insert_node(head2->data);
            head2=head2->next;
        } else if(head1 == head2){
            nuevaLista->insert_node(head1->data);
            head1=head1->next;
            nuevaLista->insert_node(head2->data);
            head2=head2->next;
        }
    }
    return nuevaLista->head;
}
*/
//void reverseLinkedList(){}
