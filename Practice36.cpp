class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                ok = false;
                break;
            }
        }

        int ans = ok ? pos : INT_MAX;

        int start = (pos + 1) % n;
        ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[(start - i + n) % n] != i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, start + 1);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};