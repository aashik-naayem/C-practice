#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        const int INF = INT_MAX;
        int best = INF;

        // Case 1: ascending rotation
        int k = nums[0];
        bool asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) { asc = false; break; }
        }
        if (asc) {
            if (k == 0) best = 0;
            else best = min(best, min((n - k) % n, k + 2));
        }

        // Case 2: descending rotation
        int c = nums[0];
        bool desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != ((c - i) % n + n) % n) { desc = false; break; }
        }
        if (desc) {
            best = min(best, 1 + (n - c - 1) % n);
            best = min(best, (c + 1) % n + 1);
        }

        return best == INF ? -1 : best;
    }
};