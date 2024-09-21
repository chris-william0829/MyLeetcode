class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        int length = 1;
        int times = 1;
        int pre = nums[0];
        int idx = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == pre){
                times++;
                if(times <= 2){
                    nums[idx++] = nums[i];
                }
            }else{
                nums[idx++] = nums[i];
                pre = nums[i];
                times = 1;
            }
        }
        return idx;
    }
};