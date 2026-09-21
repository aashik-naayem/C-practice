#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> ndp(k, 0);

            int val = nums[i] % k;

            // Start a new subarray at nums[i]
            ndp[val]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * val) % k;
                    ndp[newRemainder] += dp[r];
                }
            }

            dp = ndp;

            // Every subarray ending at i represents one operation
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};