#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            int reversedValue = 'z' - s[i] + 1;
            int position = i + 1;

            sum += reversedValue * position;
        }

        return sum;
    }
};