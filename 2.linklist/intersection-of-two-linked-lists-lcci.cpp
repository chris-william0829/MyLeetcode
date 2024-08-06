/*

https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
2024-8-6

*/


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != NULL && p2 != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1 != NULL){
            headA = headA->next;
            p1 = p1->next;
        }
        while(p2 != NULL){
            headB = headB->next;
            p2 = p2->next;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};