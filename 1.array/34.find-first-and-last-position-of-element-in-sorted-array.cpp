class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int leftBorder = -2;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
                leftBorder = right;
            }
        }
        left = 0, right = nums.size() - 1;
        int rightBorder = -2;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] <= target){
                left = mid + 1;
                rightBorder = left;
            }else{
                right = mid - 1;
            }
        }
        if(leftBorder == -2 || rightBorder == -2){
            return vector<int>{-1,-1};
        }
        if (rightBorder - leftBorder > 1) {
            return vector<int>{leftBorder + 1, rightBorder - 1};
        }
        return vector<int>{-1, -1};
    }
};