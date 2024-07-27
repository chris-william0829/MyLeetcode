/*
https://leetcode.cn/problems/remove-linked-list-elements/description/

2024.7.27

*/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        ListNode *ptr = head;
        ListNode *newHead = new ListNode();
        newHead->next = ptr;
        ListNode *pre = newHead;
        while(ptr != nullptr){
            if(ptr->val == val){
                pre->next = ptr->next;
            }else{
                pre = ptr;
            }
            ptr = ptr->next;
        }
        return newHead->next;
    }
};