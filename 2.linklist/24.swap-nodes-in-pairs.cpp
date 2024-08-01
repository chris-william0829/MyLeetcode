/*

https://leetcode.cn/problems/swap-nodes-in-pairs/description/
2024-8-1

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* ptr = dummy;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(1){
            pre->next = cur->next;
            cur->next = pre;
            ptr->next = cur;
            ptr = pre;
            if(pre->next==nullptr || pre->next->next == nullptr){
                break;
            }else{
                pre = pre->next;
                cur = pre->next;
            }
        }
        return dummy->next;
    }
};