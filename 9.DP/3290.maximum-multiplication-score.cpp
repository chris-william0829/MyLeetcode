class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        const long long INF = 1e18;
        vector<vector<long long>> dp(n+1, vector<long long>(5, -INF));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=4;j++){
                dp[i][j] = dp[i-1][j];
                if(j > 0){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1LL * a[j-1] * b[i-1]);
                }
            }
        }
        return dp[n][4];
    }
};
