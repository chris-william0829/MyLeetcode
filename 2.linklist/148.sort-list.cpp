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
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* ptr = head;
        while(ptr != nullptr){
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }
        sort(nums.begin(), nums.end());
        ListNode* dummy = new ListNode();
        ptr = dummy;
        for(int i=0;i<nums.size();i++){
            ListNode* node = new ListNode(nums[i]);
            ptr->next = node;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};