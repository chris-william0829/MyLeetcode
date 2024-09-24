class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxv = INT_MIN, minv = INT_MAX;
        for(int num : nums){
            maxv = max(maxv, num);
            minv = min(minv, num);
        }
        if(maxv - minv <= 1){
            return maxv - minv;
        }
        int n = nums.size();
        int d = (maxv-minv+n-2) / (n-1);
        vector<pair<int,int>> buckets((maxv - minv) / d + 1, {INT_MAX, INT_MIN});
        for(int num : nums){
            auto& [mn, mx] = buckets[(num-minv) / d];
            mn = min(mn,num);
            mx = max(mx,num);
        }
        int diff = 0;
        int pre_max = INT_MAX;
        for(auto [mn, mx] : buckets){
            if(mn != INT_MAX){
                diff = max(diff, mn-pre_max);
                pre_max = mx;
            }
        }
        return diff;
    }
};