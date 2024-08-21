/*

https://leetcode.cn/problems/decode-string/

*/


class Solution {
public:
    string analysis(string s, int& index) {
        string res;
        int num = 0;
        string temp;
        while (index < s.size()) {
            if (s[index] >= '0' && s[index] <= '9') {
                num = 10 * num + s[index] - '0';
            }
            else if (s[index] == '[') {
                temp = analysis(s, ++index);//碰到'[',开始递归
                for(int i=0;i<num;i++){
                    res += temp;
                }
                num = 0;//num置零
            }
            else if (s[index] == ']') break;//碰到']',结束递归
            else res += s[index];
            index++;
        }
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return analysis(s, index);
    }
};