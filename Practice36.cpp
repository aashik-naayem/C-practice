class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            bool ok = true;

            for (int j = 0; j < n; j++) {
                if (nums[(i + j) % n] != j) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans = min(ans, i);
            }

            ok = true;

            for (int j = 0; j < n; j++) {
                if (rev[(i + j) % n] != j) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans = min(ans, i + 1);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};