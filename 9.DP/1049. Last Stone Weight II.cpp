/*

https://leetcode.cn/problems/last-stone-weight-ii/description/
2024-7-27

......
尽量让石头分成重量相同的两堆，相撞之后剩下的石头最小，这样就化解成01背包问题了。
总的石头为sum，从中选出最价值接近sum/2的

dp[j]表示容量（这里说容量更形象，其实就是重量）为j的背包，最多可以背最大重量为dp[j]。

*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += stones[i];
        }
        int target = sum / 2;
        vector<int> dp(15001, 0);
        for(int i=0;i<n;i++){
            for(int j=target;j>=stones[i];j--){
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};