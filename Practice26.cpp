
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(nums1.size());
        long long k = 1LL * k1 + k2;
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
        }

        if (sum <= k) return 0;

        int left = 0, right = 100000;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k) right = mid;
            else left = mid + 1;
        }

        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            int reduced = min(d, left);
            ans += 1LL * reduced * reduced;
            used += d - reduced;
        }

        long long remaining = k - used;

        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= left && left > 0) {
                ans -= 1LL * left * left;
                ans += 1LL * (left - 1) * (left - 1);
                remaining--;
            }
        }

        return ans;
    }
};
