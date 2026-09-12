#include <vector>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;

        for (int num = 100; num <= 999; num++) {
            
            // Number must be even
            if (num % 2 != 0)
                continue;

            int temp = num;

            int a = temp % 10;
            temp /= 10;

            int b = temp % 10;
            temp /= 10;

            int c = temp % 10;

            vector<int> needed = {a, b, c};
            vector<bool> used(digits.size(), false);

            bool possible = true;

            for (int d : needed) {
                bool found = false;

                for (int i = 0; i < digits.size(); i++) {
                    if (!used[i] && digits[i] == d) {
                        used[i] = true;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                count++;
        }

        return count;
    }
};