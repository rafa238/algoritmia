//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/detect-whether-a-linked-list-contains-a-cycle
/*
Make that every node point to an auxiliar Pointer (dummy)
and if I get to that dummy point, I have an cycle

Complexity:
Space O(1)
Time O(n)

*/
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(-1000);
    
    while(head != NULL){
        if(head == dummy){
            return true;
        }
        
        SinglyLinkedListNode* aux = head->next;
        head->next = dummy;
        head = aux;
    }
    return false;
}