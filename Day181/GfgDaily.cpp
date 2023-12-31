class Solution {
    
    public:
int solve(int ind, int sum , int n, int coins[],vector<vector<int>>& dp) {
        if(ind==n) {
            if((sum%20==0 || sum%24==0 || sum==2024) && sum!=0) {
                return 1;
            }
            return 0;
        }
        if(dp[ind][sum]!=-1) {
            return dp[ind][sum];
        }
        int notTake = solve(ind+1,sum,n,coins,dp);
        int take = solve(ind+1,sum+coins[ind],n,coins,dp);
        return dp[ind][sum] = take || notTake;
    }
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>>dp(N,vector<int>(2024,-1));
        return solve(0,0,N,coins,dp);
    }
    
};

sa