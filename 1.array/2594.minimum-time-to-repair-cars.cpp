class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars) {
        int min_r = *min_element(ranks.begin(), ranks.end());
        long long left = 0, right = 1LL * min_r * cars * cars;
        while (left + 1 < right) { // 开区间
            long long mid = (left + right) / 2, s = 0;
            for (int r : ranks)
                s += sqrt(mid / r);
            (s >= cars ? right : left) = mid;
        }
        return right;
    }
};