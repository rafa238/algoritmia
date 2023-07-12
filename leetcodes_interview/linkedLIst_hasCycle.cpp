//https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool answer = false;
        
        ListNode* dummy = new ListNode();
        while(head != nullptr && head->next != nullptr){
            if(head->next == dummy){
                answer = true;
                break;
            }
            ListNode* aux = head->next;
            head->next = dummy;
            head = aux;
            
        }
        return answer;
    }
};