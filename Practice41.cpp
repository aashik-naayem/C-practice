class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                               string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 17;
        vector<int> tin(n), tout(n), depth(n), parent(n);
        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> bit(n + 2, 0);
        int timer = 0;

        auto add = [&](int idx, int val) {
            for (; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto sum = [&](int idx) {
            int res = 0;
            for (; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];
            return res;
        };

        stack<pair<int, int>> st;
        st.push({0, 0});
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.top().first;
            int& state = st.top().second;

            if (state == 0) {
                tin[u] = ++timer;
                up[0][u] = parent[u];

                for (int k = 1; k < LOG; k++)
                    up[k][u] = up[k - 1][up[k - 1][u]];

                state = 1;
            } else if (state <= (int)adj[u].size()) {
                int v = adj[u][state - 1];
                state++;

                if (v == parent[u])
                    continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push({v, 0});
            } else {
                tout[u] = timer;
                st.pop();
            }
        }

        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            add(tin[u], mask);
            add(tout[u] + 1, mask);
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++)
                if (diff & (1 << k))
                    u = up[k][u];

            if (u == v)
                return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return parent[u];
        };

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int change = oldMask ^ newMask;

                add(tin[u], change);
                add(tout[u] + 1, change);
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);
                int mask = sum(tin[u]) ^ sum(tin[v])
                         ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};