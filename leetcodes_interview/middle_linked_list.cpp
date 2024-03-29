//https://leetcode.com/problems/middle-of-the-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cont = 0;
        ListNode* aux = head;
        while(aux != nullptr){
            aux = aux->next;
            cont++;
        }
        int middle = cont / 2;

        for(int i=0; i<middle; i++){
            head = head->next;
        }
        return head;
    }
};