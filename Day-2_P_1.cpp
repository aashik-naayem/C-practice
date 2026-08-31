#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> criticalPoints;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        // Check every middle node
        while (curr != NULL && curr->next != NULL) {

            // Local maxima or local minima
            if ((curr->val > prev->val &&
                 curr->val > curr->next->val) ||

                (curr->val < prev->val &&
                 curr->val < curr->next->val)) {

                criticalPoints.push_back(pos);
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Need at least 2 critical points
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }

        int minDistance = INT_MAX;

        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = min(minDistance,
                              criticalPoints[i] - criticalPoints[i - 1]);
        }

        int maxDistance =
            criticalPoints.back() - criticalPoints.front();

        return {minDistance, maxDistance};
    }
};


int main() {

    // Create: 5 -> 3 -> 1 -> 2 -> 5 -> 1 -> 2

    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);

    Solution s;

    vector<int> answer =
        s.nodesBetweenCriticalPoints(head);

    cout << "Min Distance = " << answer[0] << endl;
    cout << "Max Distance = " << answer[1] << endl;

    return 0;
}