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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *vHead = new ListNode;
        ListNode *res = vHead;
        ListNode *ptr = head;
        int len = 0;
        while(ptr != nullptr){
            len++;
            ptr = ptr->next;
        }
        ptr = head;
        for(int i=0;i<len / k; i++){
            for(int j=0;j<k;j++){
                ListNode *next = ptr->next;
                ptr->next = vHead->next;
                vHead->next = ptr;
                ptr = next;
            }
            for(int j=0;j<k;j++){
                vHead = vHead->next;
            }
        }
        vHead->next = ptr;
        return res->next;
    }
};