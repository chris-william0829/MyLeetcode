/*

https://leetcode.cn/problems/permutations-ii/description/
2024-8-2

*/


class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            result.emplace_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){            
            if((i > 0 && nums[i] == nums[i-1] && used[i-1] == false) || used[i] == true){
                continue;
            }
            path.emplace_back(nums[i]);
            used[i] = true;
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        dfs(nums, used);
        return result;
    }
};