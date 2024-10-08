/*

https://leetcode.cn/problems/search-in-rotated-sorted-array/description/

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if(nums[0] <= nums[mid]){
                if(nums[0] <= target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(nums[mid] < target && target <= nums.back()){
                    left = mid + 1;
                }else{
                    right = mid -1;
                }
            }
        }
        return -1;
    }
};