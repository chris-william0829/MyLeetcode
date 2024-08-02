/*

https://leetcode.cn/problems/4sum-ii/description/
2024-8-2

*/


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                umap[nums1[i]+nums2[j]]++;
            }
        }
        int result = 0;
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                if(umap.find(-(nums3[i]+nums4[j])) != umap.end()){
                    result += umap[-(nums3[i]+nums4[j])];
                }
            }
        }
        return result;
    }
};