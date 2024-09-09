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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* ptr = dummy->next;
        int temp = 0;
        while(ptr != nullptr){
            if(ptr->val == 0){
                if(temp != 0){
                    ListNode* node = new ListNode(temp);
                    pre->next = node;
                    pre = node;
                    temp = 0;
                }
            }else{
                temp += ptr->val;
            }
            ptr = ptr->next;
        }
        return dummy->next;
    }
};