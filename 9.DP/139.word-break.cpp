/*

https://leetcode.cn/problems/word-break/description/
2024-8-5

*/


class Solution {
public:

    bool isSame(string s1, string s2){
        return s1 == s2;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        dp[0] = true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<wordDict.size();j++){
                if(i>=wordDict[j].size()){
                    dp[i] = dp[i] || (dp[i-wordDict[j].size()] && isSame(s.substr(i-wordDict[j].size(),wordDict[j].size()),wordDict[j]));
                }
            }
        }
        return dp[s.size()];
    }
};