/*

https://leetcode.cn/problems/4sum/description/
2024-8-6

*/



class Solution {
public:

    void quickSort(vector<int>& nums, int low, int high){
        if(low >= high) return;
        int pivot = nums[low];
        int i = low, j = high;
        while(i<j){
            while(i<j && nums[j] >= pivot){
                j--;
            }
            if(i<j) swap(nums[j],nums[i]);
            while(i<j && nums[i] <= pivot){
                i++;
            }
            if(i<j) swap(nums[i],nums[j]);
        }
        quickSort(nums,low,i-1);
        quickSort(nums,i+1,high);
        return;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        quickSort(nums,0,nums.size()-1);
        for(int i=0;i<nums.size();i++){
            if (nums[i] > target && nums[i] >= 0) {
            	break;
            }
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if (nums[j] + nums[i] > target && nums[j] + nums[i] >= 0) {
                    break;
                }
                if(j-i>1 && nums[j] == nums[j-1]){
                    continue;
                }
                int left = j+1;
                int right = nums.size()-1;
                while(left < right){
                    if((long) nums[i] + nums[j] + nums[left] + nums[right] < target){
                        left++;
                    }else if((long) nums[i] + nums[j] + nums[left] + nums[right] > target){
                        right--;
                    }else{
                        result.emplace_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while((left+1)<nums.size() && nums[left+1]==nums[left]){
                            left++;
                        }
                        while((right-1)>=0 && nums[right-1]==nums[right]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};