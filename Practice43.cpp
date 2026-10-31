class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;

                for (int d = 0; d < 2; d++) {
                    int x = i, y = j;
                    int dx = (d == 0 ? 0 : 1);
                    int dy = (d == 0 ? 1 : 0);

                    while (true) {
                        x += dx;
                        y += dy;

                        if (x >= m || y >= n) break;
                        if (grid[x][y] == 0) {
                            dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                            break;
                        }

                        if (dx == 0) {
                            dx = 1;
                            dy = 0;
                        } else {
                            dx = 0;
                            dy = 1;
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};