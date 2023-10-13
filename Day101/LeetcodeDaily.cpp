class Solution {
public:
    int f(int index , vector<int> &cost  ,vector<int> &dp){
        if(index == cost.size()) return 0;
        if(index > cost.size()) return 1e9;
        if(dp[index] != -1) return dp[index];
        int one = f(index+1 , cost, dp);
        int two = f(index+2 , cost, dp);
        return dp[index] =  min(one , two) + cost[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() , -1);
        return min(f(0 , cost , dp) , f(1 , cost, dp));
    }
};