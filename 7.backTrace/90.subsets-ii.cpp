/*

https://leetcode.cn/problems/subsets-ii/description/
2024-8-5

*/


class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& nums, int start){
        result.push_back(path);
        for(int i=start;i<nums.size();i++){
             if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return result;
    }
};