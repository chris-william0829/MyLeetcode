class Solution {
public:
    string removeStars(string s) {
        deque<char> stk;
        for(int i=0;i<s.size();i++){
            if(s[i] != '*'){
                stk.push_back(s[i]);
            }else{
                if(!stk.empty()){
                    stk.pop_back();
                }
            }
        }
        string ss;
        while(!stk.empty()){
            ss += stk.front();
            stk.pop_front();
        }
        return ss;
    }
};