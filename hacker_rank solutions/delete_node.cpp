//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/delete-a-node-from-a-linked-list
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    /*
        Exceptions:
         llist == nullptr
            return llist
         position == 0   
            return llist ->next
    */
    if(llist == NULL){
        return llist;
    }
    if(position == 0){
        return llist->next;
    }
    
    SinglyLinkedListNode *prev = NULL, *curr = llist;
    int cont = 0;
    while(curr != NULL){
       if(cont == position - 1){
           prev = curr;
       } else if(cont == position ){
           prev -> next = curr -> next;
       }
        cont++;
        curr = curr -> next;
    }
    return llist;
}
