class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = values[0] + 0;
        for (int j = 1; j < values.size(); ++j) {
            ans = max(ans, mx + values[j] - j);
            // 边遍历边维护
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};