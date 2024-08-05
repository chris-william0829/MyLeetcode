/*

https://leetcode.cn/problems/subsets/description/
2024-8-5

*/


class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& nums, int start){
        result.push_back(path);
        for(int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return result;
    }
};