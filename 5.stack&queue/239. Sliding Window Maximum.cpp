/*

https://leetcode.cn/problems/sliding-window-maximum/description/
2024-7-28

双端队列维护一个单调递减队列

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = k-1;
        deque<int> q;
        q.push_back(0);
        for(int i=1;i<k;i++){
            if(nums[i] > nums[q.back()]){
                while(!q.empty() && nums[i] > nums[q.back()]){
                    q.pop_back();
                }
            }
            q.push_back(i);
        }
        vector<int> result;
        result.push_back(nums[q.front()]);
        for(int i=k;i<n;i++){
            if(i - q.front() >= k){
                q.pop_front();
            }
            if(!q.empty() && nums[i] > nums[q.back()]){
                while(!q.empty() && nums[i] > nums[q.back()]){
                    q.pop_back();
                }
            }
            q.push_back(i);
            result.push_back(nums[q.front()]);
        }
        return result;
    }
};