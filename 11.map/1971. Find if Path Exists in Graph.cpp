/*

https://leetcode.cn/problems/find-if-path-exists-in-graph/
2024-07-27

*/

class Solution {
public:
    int find(vector<int> &father, int u){
        return u == father[u] ? u : father[u] = find(father, father[u]);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> father(n);
        for(int i=0;i<n;i++){
            father[i] = i;
        }
        for(int i=0;i<edges.size();i++){
            int x = find(father,edges[i][0]);
            int y = find(father,edges[i][1]);
            if(x==y) continue;
            father[y] = x;
        }
        int x = find(father, source);
        int y = find(father, destination);
        return x==y;
    }
};