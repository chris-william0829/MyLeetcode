class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> goal(n, 0);
        long long max_goal = 0;
        int result = -1;
        for(int i=0;i<n;i++){
            goal[edges[i]] += i;
            if(goal[edges[i]] > max_goal){
                max_goal = goal[edges[i]];
                result = edges[i];
            }else if(goal[edges[i]] == max_goal){
                if(edges[i] < result){
                    result = edges[i];
                }
            }
        }
        return result;
    }
};