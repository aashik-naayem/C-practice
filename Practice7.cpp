#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        long long score;
        vector<int> indices;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0])
                return x[0] < y[0];
            return x[1] < y[1];
        });

        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                Node skip = dp[i + 1][k];

                Node take;
                take.score = a[i][2] + dp[next[i]][k - 1].score;
                take.indices = dp[next[i]][k - 1].indices;
                take.indices.push_back((int)a[i][3]);

                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].indices;
    }
};