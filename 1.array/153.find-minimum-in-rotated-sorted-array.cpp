/*

https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/

类似于33

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] < nums[right]){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return nums[left];
    }
};