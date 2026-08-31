#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if complement already exists
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution sol;

    int n;
    
    // Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input target
    int target;
    cout << "Enter target: ";
    cin >> target;

    // Find result
    vector<int> result = sol.twoSum(nums, target);

    // Output
    if (!result.empty()) {
        cout << "Output indices: [" 
             << result[0] << ", " 
             << result[1] << "]" << endl;
    } 
    else {
        cout << "No two numbers found that add up to the target." << endl;
    }

    return 0;
}
