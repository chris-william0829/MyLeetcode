class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        string prefix = "";
        int i = 0;
        while(1){
            char c = strs[0][i];
            bool flag = true;
            for(int j=1;j<strs.size();j++){
                if(i >= strs[j].size()){
                    flag = false;
                    break;
                }
                if(strs[j][i] != c){
                    flag = false;
                    break;
                }
            }
            if(flag){
                prefix+=c;
                i++;
            }else{
                break;
            }
        }
        return prefix;
    }
};