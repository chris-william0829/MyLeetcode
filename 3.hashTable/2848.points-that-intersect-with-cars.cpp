class Solution {
public:
//哈希set
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int>index;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=nums[i][0];j<=nums[i][1];j++)
            {
                index.insert(j);
            }
        }
        return index.size();
    }
};