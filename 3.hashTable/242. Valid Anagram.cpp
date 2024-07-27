/*
https://leetcode.cn/problems/valid-anagram/description/
2024-7-27
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int table[26];
        for(size_t i = 0; i < s.size(); i++){
            table[s[i]-'a']++;
        }
        for(size_t i = 0; i < t.size(); i++){
            table[t[i]-'a']--;
            if(table[t[i]-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};