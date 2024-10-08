/*

https://leetcode.cn/problems/simplify-path/

*/

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st;
        int n = path.size(), i = 0;
        while(i < n){
            if(i < n && path[i] == '/') i++;
            else{
                string temp;
                while(i < n && path[i] != '/') temp += path[i++];
                if(temp == ".." && !st.empty()) st.pop_back();
                else if(temp != ".." && temp != ".") st.push_back(temp); 
            }
        }
        string res = "/";
        while(!st.empty()){
            res += st.front() + "/";
            st.pop_front();
        }
        if(res.size() > 1) res.pop_back();
        return res;
    }
};