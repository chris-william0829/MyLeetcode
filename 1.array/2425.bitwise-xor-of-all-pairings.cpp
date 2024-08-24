/*

https://leetcode.cn/problems/bitwise-xor-of-all-pairings/description/

*/


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int res = 0;
        if (l2 % 2 == 1)
            for (int i = 0; i < l1; i++) res ^= nums1[i];
        if (l1 % 2 == 1)
            for (int i = 0; i < l2; i++) res ^= nums2[i];
        return res;
    }
};