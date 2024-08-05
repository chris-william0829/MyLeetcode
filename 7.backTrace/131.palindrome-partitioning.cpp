/*

https://leetcode.cn/problems/palindrome-partitioning/description/
2024-8-5

*/


class Solution {
public:

    vector<vector<string>> result;
    vector<string> path;

    bool isPalindrome(const string &s,int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    void dfs(const string &s, int start){
        if(start >= s.size()){
            result.emplace_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                string substr = s.substr(start,i-start+1);
                path.emplace_back(substr);
            }else{
                continue;
            }
            dfs(s,i+1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return result;
    }
};