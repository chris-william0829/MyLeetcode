class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(char ch:s){
            if(isdigit(ch)){
                if(ans.empty()==0){
                    ans.pop_back();
                }
            }
            else ans.push_back(ch);
        }
        return ans;
    }
};