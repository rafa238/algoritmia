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
//https://leetcode.com/problems/reverse-linked-list/description/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *aux, *curr = head, *prev = nullptr;
        while(curr != nullptr){
            aux = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aux;
        }
        return prev;
    }
};