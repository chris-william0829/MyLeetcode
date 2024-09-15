class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            nums[i]+=1;
        }
        for(int i=0;i<nums.size();i++){
            int temp = abs(nums[i]) - 1;
            if(nums[temp] < 0){
                result.push_back(temp);
            }else{
                nums[temp] = -nums[temp];
            }
        }
        return result;
    }
};