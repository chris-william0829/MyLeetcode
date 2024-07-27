/*

https://leetcode.cn/problems/daily-temperatures/description/
2024-7-27

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stk;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            int val = temperatures[i];
            while (!stk.empty() && val > temperatures[stk.back()]) {
                res[stk.back()] = i - stk.back();
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return res;
    }
};