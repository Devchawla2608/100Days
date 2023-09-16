    int mod= 1e9+7;
    long long f(int index , vector<long long> &dp){
        if(index<0) return 0;
        if(index == 0) return 1;
        if(dp[index] != -1) return dp[index];
        long long one = f(index-1, dp)%mod;
        long long two = f(index-2, dp)%mod;
        long long three = f(index-3, dp)%mod;
        return dp[index] =  (one+two+three)%mod;
    }
    long long countWays(int n)
    {   
        vector<long long> dp(n+1 , -1);
        return f(n, dp);
    }