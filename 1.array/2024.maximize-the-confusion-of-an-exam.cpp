class Solution {
private:
    int solve(const string &s, int k, char target) {
        const int n = s.size();
        int ans = 0;

        for (int l = 0, r = 0; r < n; r++) {
            if (s[r] != target)
                k--;

            while (k < 0) {
                if (s[l] != target)
                    k++;

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
    }
};