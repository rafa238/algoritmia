//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> freq;
        ListNode *aux = head, *prev, *ans;
        while(aux != nullptr){
            freq[aux->val]++;
            aux = aux->next;
        }
        ans = new ListNode(-101);
        prev = ans;
        aux  = head;
        while(aux != nullptr){
            if(freq[aux->val] <= 1){
                prev->next = aux;
                prev = prev->next;
            }
            aux = aux->next;
        }
        prev->next = aux;
        return ans -> next;
    }
};
