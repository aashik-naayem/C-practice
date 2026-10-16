
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1000000007;
        int n = nums.size();

        vector<int> last(100001, -1);
        long long sum = 0;
        long long sumSq = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long oldSum = sum;
            long long oldSumSq = sumSq;

            sum = (2 * oldSum + i + 1) % MOD;
            sumSq = (2 * oldSumSq + 2 * oldSum + i + 1) % MOD;

            if (last[nums[i]] != -1) {
                long long d = i - last[nums[i]];

                sum = (sum - d + MOD) % MOD;

                sumSq = (sumSq - 2 * d % MOD * (oldSum % MOD) % MOD
                         + MOD) % MOD;

                sumSq = (sumSq + d * d) % MOD;
            }

            last[nums[i]] = i;
            ans = (ans + sumSq) % MOD;
        }

        return ans;
    }
};
