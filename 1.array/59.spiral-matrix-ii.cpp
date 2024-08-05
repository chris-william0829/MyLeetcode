/*

https://leetcode.cn/problems/spiral-matrix-ii/
2024-8-5

*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int count = 1;
        int l = 0, r = n-1, t = 0, b = n-1;
        while(count <= n*n){
            for(int i=l;i<=r;i++){
                res[t][i] = count++;
            }
            t++;
            for(int i=t;i<=b;i++){
                res[i][r] = count++;
            }
            r--;
            for(int i=r;i>=l;i--){
                res[b][i] = count++;
            }
            b--;
            for(int i=b;i>=t;i--){
                res[i][l] = count++;
            }
            l++;
        }
        return res;
    }
};