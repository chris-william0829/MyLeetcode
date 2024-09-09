class Solution {
public:
/*
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int result = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i] - arr[j] == difference){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }
*/
    int longestSubsequence(vector<int> &arr, int difference) {
        int ans = 0;
        unordered_map<int, int> dp;
        for (int v: arr) {
            dp[v] = dp[v - difference] + 1;
            ans = max(ans, dp[v]);
        }
        return ans;
    }

};