/*

https://leetcode.cn/problems/combination-sum/description/
2024-8-1

*/


class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum > target) return;
        if(sum == target){
            result.push_back(path);
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            path.push_back(candidates[i]);
            dfs(candidates,target,sum+candidates[i],i);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0,0);
        return result;
    }
};