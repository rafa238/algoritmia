//https://leetcode.com/problems/add-two-numbers/
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
    ListNode* reverse(ListNode* head) {
        ListNode *aux, *curr = head, *prev = nullptr;
        while(curr != nullptr){
            aux = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aux;
        }
        return prev;
    }
    
    ListNode* sumLinkedList(ListNode *l1, ListNode *l2){
        ListNode *answer = new ListNode(-1);
        ListNode *ansHead = answer;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int currentSum = l1->val + l2->val + carry;
            answer->next = new ListNode(currentSum % 10);
            carry = currentSum/10;
            answer = answer->next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != nullptr){
            int currSum = l1->val + carry;
            answer->next = new ListNode(currSum % 10);
            carry = floor(currSum / 10);
            answer = answer->next;
            l1 = l1 -> next;
        }

        while(l2 != nullptr){
            int currSum = l2->val + carry;
            answer->next = new ListNode(currSum % 10);
            carry = floor(currSum / 10);
            answer = answer->next;
            l2 = l2 -> next;
        }

        if(carry != 0){
            answer->next = new ListNode(carry);
        }
        
        return ansHead->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return sumLinkedList(l1, l2);
    }
};