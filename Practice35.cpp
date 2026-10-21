class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        if (s[0] == *min_element(s.begin(), s.end()) ||
            s[n - 1] == *max_element(s.begin(), s.end())) {
            return 1;
        }

        if (s[0] == *max_element(s.begin(), s.end()) &&
            s[n - 1] == *min_element(s.begin(), s.end())) {
            return 3;
        }

        return 2;
    }
};