/*

https://leetcode.cn/problems/minimum-rectangles-to-cover-points/description/
2024-7-31

*/

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), [](const vector<int>& a,const vector<int>& b){
            return a[0] < b[0];
        });
        int start = points[0][0];
        int result = 1;
        for(int i=0;i<points.size();i++){
            if(points[i][0] > (start + w)){
                result++;
                start = points[i][0];
            }
        }
        return result;
    }
};