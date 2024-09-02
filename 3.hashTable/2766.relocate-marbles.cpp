/*

https://leetcode.cn/problems/relocate-marbles/description/

*/


class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<moveFrom.size();i++){
            if(moveFrom[i] == moveTo[i]) continue;
            mp[moveTo[i]] += mp[moveFrom[i]];
            mp[moveFrom[i]] = 0;
        }
        vector<int> res;
        for(auto &it : mp){
            if(it.second != 0){
                res.push_back(it.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};