class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> people(n+1,0);
        unordered_set<int> s;
        for(int i=0;i<trust.size();i++){
            s.insert(trust[i][0]);
            people[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(people[i] == n-1 && s.find(i) == s.end()){
                return i;
            }
        }
        return -1;
    }
};