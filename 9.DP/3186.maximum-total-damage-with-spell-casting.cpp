class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        vector<int> counts(n);
        sort(power.begin(), power.end());
        int index = 0;
        counts[index] = 1;
        for (int i = 1; i < n; i++) {
            if (power[i] == power[i - 1]) {
                counts[index]++;
            } else {
                index++;
                counts[index] = 1;
                power[index] = power[i];
            }
        }
        vector<long long> dp(index + 1);
        for (int i = 0; i <= index; i++) {
            long long count = (long long)power[i] * counts[i];
            dp[i] = count;
            int j = i - 1;
            for ( ; j >= 0; j--) {
                if (power[i] - power[j] <= 2) {
                    dp[i] = max(dp[i], dp[j]);
                } else {
                    dp[i] = max(dp[i], dp[j] + count);
                    break;
                }
            }
        }
        return dp[index];
    }
};