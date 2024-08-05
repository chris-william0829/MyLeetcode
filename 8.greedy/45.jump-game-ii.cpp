/*

https://leetcode.cn/problems/jump-game-ii/description/
2024-8-5

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int cover = 0;
        int maxCover = 0;
        int step = 0;
        for(int i=0;i<=cover;i++){
            if(i + nums[i] > maxCover){
                maxCover = i + nums[i];
            }
            if(i == cover){
                step++;
                cover = maxCover;
                if(maxCover >= nums.size() - 1) break;
            }
        }
        return step;
    }
};