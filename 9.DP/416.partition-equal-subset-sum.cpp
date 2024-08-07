/*

https://leetcode.cn/problems/partition-equal-subset-sum/description/
2024-7-30

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        vector<int> dp(target + 1);
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if (dp[target] == target) return true;
        return false;
    }
};