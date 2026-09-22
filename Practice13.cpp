#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int product;
        long long cnt[5];

        Node() {
            product = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, k;
    int size;
    vector<Node> tree;

    Node mergeNodes(const Node& a, const Node& b) {
        Node res;

        res.product = (a.product * b.product) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] = a.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int nr = (a.product * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    void update(int pos, int value) {
        pos += size;

        tree[pos] = Node();

        int r = value % k;
        tree[pos].product = r;
        tree[pos].cnt[r] = 1;

        pos >>= 1;

        while (pos) {
            tree[pos] = mergeNodes(tree[pos << 1], tree[pos << 1 | 1]);
            pos >>= 1;
        }
    }

    Node query(int l, int r) {
        l += size;
        r += size;

        Node leftResult;
        Node rightResult;

        while (l <= r) {
            if (l & 1) {
                leftResult = mergeNodes(leftResult, tree[l]);
                l++;
            }

            if (!(r & 1)) {
                rightResult = mergeNodes(tree[r], rightResult);
                r--;
            }

            l >>= 1;
            r >>= 1;
        }

        return mergeNodes(leftResult, rightResult);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;

        size = 1;
        while (size < n)
            size <<= 1;

        tree.resize(size * 2);

        for (int i = 0; i < n; i++) {
            int r = nums[i] % k;

            tree[size + i].product = r;
            tree[size + i].cnt[r] = 1;
        }

        for (int i = size - 1; i >= 1; i--) {
            tree[i] = mergeNodes(tree[i << 1], tree[i << 1 | 1]);
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(index, value);

            Node res = query(start, n - 1);

            answer.push_back((int)res.cnt[x]);
        }

        return answer;
    }
};