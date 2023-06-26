 class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total_cost = 0;
        priority_queue<int, vector<int>, greater<int>> left_candidates;
        priority_queue<int, vector<int>, greater<int>> right_candidates;
        int left = 0;
        int right = costs.size() - 1;
        for (int count = 0; count < k; ++count) {
            while (left_candidates.size() < candidates && left <= right) {
                left_candidates.push(costs[left]);
                ++left;
            }
            while (right_candidates.size() < candidates && left <= right) {
                right_candidates.push(costs[right]);
                --right;
            }
            if (right_candidates.empty() || (!left_candidates.empty() && left_candidates.top() <= right_candidates.top())) {
                total_cost += static_cast<long long>(left_candidates.top());
                left_candidates.pop();
            } else {
                total_cost += static_cast<long long>(right_candidates.top());
                right_candidates.pop();
            }
        }
        return total_cost;
    }
};