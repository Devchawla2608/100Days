// Total Cost to Hire K Workers
You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
// A worker can only be chosen once.
// Return the total cost to hire exactly k workers.
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