/*

https://leetcode.cn/problems/valid-parentheses/description/
2024-8-1

*/


class Solution {
public:

    bool isValid(string s) {
        map<char, char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
            }else{
                if(stk.empty()){
                    return false;
                }
                char c = stk.top();
                stk.pop();
                if(mp[s[i]] != c){
                    return false;
                }
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};