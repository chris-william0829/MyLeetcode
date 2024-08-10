/*

https://leetcode.cn/problems/shortest-supersequence-lcci/

*/


class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        int n = big.size();
        vector<int> res;
        unordered_map<int, int> need;
        int minLen = n, diff = 0;
        for (auto& e : small) {
            need[e]++;
            diff++;
        }

        int l = 0, r = 0;
        for (; r < n; ++r) {
            if (need.find(big[r]) != need.end() && --need[big[r]] >= 0) --diff;
            while (diff == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    res = {l, r};
                }
                if (need.find(big[l]) != need.end() && ++need[big[l]] > 0) ++diff;
                ++l;
            }
        }

        return res;
    }
};