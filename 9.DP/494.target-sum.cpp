/*

https://leetcode.cn/problems/target-sum/description/
2024-8-1

*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        if(abs(target) > sum) return 0;
        if ((target + sum) % 2 == 1) return 0;
        int n = (sum + target) / 2;
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i=0;i<nums.size();i++){
            for(int j=n;j>=nums[i];j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[n];
    }
};