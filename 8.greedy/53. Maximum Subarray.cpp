/*

https://leetcode.cn/problems/maximum-subarray/description/
2024-7-27

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            cnt += nums[i];
            if(cnt > result){
                result = cnt;
            }
            if(cnt < 0) cnt = 0;
        }
        return result;
    }
};