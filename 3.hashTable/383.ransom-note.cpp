/*

https://leetcode.cn/problems/ransom-note/submissions/
2024-8-1

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int table[26];
        for(int i=0;i<magazine.size();i++){
            table[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.size();i++){
            table[ransomNote[i]-'a']--;
            if(table[ransomNote[i]-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};