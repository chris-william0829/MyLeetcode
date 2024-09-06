class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        /*
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int max_time = 0;
        for(auto it = m.begin();it != m.end();++it){
            if(it->second > max_time){
                max_time = it->second;
            }
        }
        return max_time + k;
        */
        /*
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        int f = k;
        int pre;
        int res = 0;
        for(int i=0;i<n;i++){
            pre = nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j] == pre){
                    dp[i][j] = dp[i][j-1] + 1;
                }else{
                    if(f > 0){
                        dp[i][j] = dp[i][j-1] + 1;
                        pre = nums[j];
                        f--;
                    }else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
            if(dp[i][n-1] > res) res = dp[i][n-1];
            f = k;
        }
        return res;
        */
        unordered_map<int, vector<int>> fs;
        vector<int> mx(k + 2);
        for (int x : nums) {
            auto& f = fs[x];
            f.resize(k + 1);
            for (int j = k; j >= 0; j--) {
                f[j] = max(f[j], mx[j]) + 1;
                mx[j + 1] = max(mx[j + 1], f[j]);
            }
        }
        return mx[k + 1];

    }
};