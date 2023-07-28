//https://leetcode.com/problems/palindrome-linked-list/description/
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
    void recursive(ListNode* rhead, ListNode* &head, bool &ans){
        if(rhead == nullptr){
            return;
        }
        recursive(rhead->next, head, ans);
        cout<<rhead->val<<" "<<head->val<<"\n";
        ans = rhead->val == head->val && ans;
        head = head->next;
    }

    bool isPalindrome(ListNode* head) {
        bool ans = true;
        ListNode* aux = head;
        recursive(aux, head, ans);
        return ans;
    }
};