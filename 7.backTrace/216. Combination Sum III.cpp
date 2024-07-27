/*

https://leetcode.cn/problems/combination-sum-iii/description/
2024-7-27

*/

class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    void dfs(int target, int current, int k, int start){
        if(current == target && k == 0){
            result.emplace_back(path);
            return;
        }
        for(int i=start;i<9;i++){
            path.emplace_back(nums[i]);
            current += nums[i];
            dfs(target,current,k-1,i+1);
            current -= nums[i];
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(n,0,k,0);
        return result;
    }
};