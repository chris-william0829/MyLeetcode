class Solution {
public:

    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(abs(nums[i] - nums[j]) == k){
                    res++;
                }
            }
        }
        return res;
    }
};