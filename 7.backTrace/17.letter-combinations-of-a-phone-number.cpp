/*

https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
2024-7-30

*/


class Solution {
public:
    string digitToAlphat(char digit){
        if(digit == '2'){
            return "abc";
        }
        if(digit == '3'){
            return "def";
        }
        if(digit == '4'){
            return "ghi";
        }
        if(digit == '5'){
            return "jkl";
        }
        if(digit == '6'){
            return "mno";
        }if(digit == '7'){
            return "pqrs";
        }
        if(digit == '8'){
            return "tuv";
        }
        if(digit == '9'){
            return "wxyz";
        }
        return "";
    }

    vector<string> result;
    string path;

    void dfs(string digits, int index){
        if(index == digits.size()){
            result.emplace_back(path);
            return;
        }
        string alphat = digitToAlphat(digits[index]);
        for(int j = 0; j < alphat.size(); j++){
            path.push_back(alphat[j]);
            dfs(digits,index+1);
            path.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return result;
        }
        dfs(digits, 0);
        return result;
    }
};