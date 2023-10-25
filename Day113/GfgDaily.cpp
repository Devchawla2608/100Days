class Solution{
public:

    int f(int index , int wt[] , int val[] , int W , int n , vector<vector<int>> &dp){
        if(W  == 0) return 0;
        if(index == 0){
            if(wt[index] <= W) return val[index]*(W/wt[index]);
            return 0;
            
        }
        if(dp[index][W] != -1) return dp[index][W];
        int pick = INT_MIN;
        if(W >= wt[index]) pick =f(index , wt , val , W - wt[index] , n, dp) + val[index] ;
        int notPick = f(index-1 , wt , val , W , n, dp);
        return dp[index][W] = max(pick , notPick);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N , vector<int>(W+1 , -1));
        return f(N-1 , wt , val , W , N , dp);
    }
};