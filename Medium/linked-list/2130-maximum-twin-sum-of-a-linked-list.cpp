// 2130. Maximum Twin Sum of a Linked List
// Difficulty: Medium
// Topics: Linked List, Two Pointers, Stack
// Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    int pairSum(ListNode* head) {
        if(!head) return 0;
        ListNode* l = head;
        ListNode* k = head;
        int twin_sum = 0;
        
        stack<int> stk;
        while(k){
            stk.push(k->val); 
            k = k->next;
        }

        while(l){
            int sum = l->val + stk.top();
            twin_sum = max(twin_sum, sum);
            l = l->next;
            stk.pop();
        }
        return twin_sum;

    }
};