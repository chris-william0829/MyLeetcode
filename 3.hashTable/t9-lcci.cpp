/*

https://leetcode.cn/problems/t9-lcci/description/

*/


class Solution {
public:

    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<char> mp{'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
        vector<string> result;
        for(int i=0;i<words.size();i++){
            string temp = words[i];
            if(temp.size() != num.size()){
                continue;
            }
            bool flag = true;
            for(int j=0;j<temp.size();j++){
                if(mp[temp[j]-'a'] != num[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                result.push_back(temp);
            }
        }
        return result;
    }
};