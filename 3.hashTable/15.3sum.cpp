/*

https://leetcode.cn/problems/3sum/description/
2024-7-28

*/

class Solution {
public:

    void quicksort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int i = low, j = high;
        int pivot = nums[low];
        while (i < j) {
            while (i < j && nums[j] >= pivot) {
                j--;
            }
            if (i < j) {
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] <= pivot) {
                i++;
            }
            if (i < j) {
                nums[j--] = nums[i];
            }
        }
        nums[i] = pivot;
        quicksort(nums, low, i - 1);
        quicksort(nums, i + 1, high);
        }
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        quicksort(nums, 0, n-1);
        int left = 0;
        int right = n-1;
        for(int i=0; i<n; i++){
            if (nums[i] > 0) {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};